#ifndef THRESHOLD_H
#define THRESHOLD_H


#include <algorithm> // std::min_element, std::max_element
#include <math.h>
#include <QDebug>


//#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

using namespace QtConcurrent;

double accHistogramaBack[256];
double accHistogramaFore[256];
double weightBack[256];
double weightFore[256];
double meanBack[256];
double meanFore[256];
double varianceBack[256];
double varianceFore[256];
double classVariance[256];

void calculateAccHistograma(double histograma[])
{
    int sumB = 0;
    int sumF = 0;
    int size = 256;

    accHistogramaBack[0] = 0;
    for(int i = 1; i < size; i++)
    {
        sumB += histograma[i-1];
        accHistogramaBack[i] = sumB;
    }
    for(int i = size - 1; i >= 0 ; i--)
    {
        sumF += histograma[i];
        accHistogramaFore[i] = sumF;
    }    
}
void calculateWeight(double histograma[], int sizeImage)
{
    double sumB = 0;
    double sumF = 0;
    int size = 256;

    weightBack[0] = sumB;

    for(int i = 1; i < size; i++)
    {
        sumB += histograma[i-1] / sizeImage;
        weightBack[i] = sumB;
    }

    for(int i = size - 1; i >= 0 ; i--)
    {
        sumF += histograma[i] / sizeImage;
        weightFore[i] = sumF;
    }
}
void calculateMean(double histograma[])
{
    int sumB = 0;
    int sumF = 0;
    int size = 256;

    meanBack[0] = 0;
    for(int i = 1; i < size; i++)
    {
        sumB += (i - 1) * histograma[i - 1];
        meanBack[i] = sumB / accHistogramaBack[i];
    }

    for(int i = size - 1; i >= 0 ; i--)
    {
        sumF += i * histograma[i];
        meanFore[i] = sumF / accHistogramaFore[i];
    }
}
void calculateVariance(double histograma[])
{
    int countB = 0;
    int countF = lengthArray(histogramaT);
    int size = 256;
    double sumB;
    double sumF;

    varianceBack[0] = 0;

    for(int i = 1; i < size; i++)
    {
        sumB = 0;
        countB = countB + 1;

        for(int j = 0; j < countB; j++)
        {
            sumB += pow(j - meanBack[i] , 2) * histograma[j];
        }
        varianceBack[i] = sumB / accHistogramaBack[i];
    }

    for(int i = size - 1; i >= 0  ; i--)
    {
        sumF = 0;
        countF = countF - 1;//9-8

        for(int j = size - 1; j >= countF; j--)
        {
            sumF += pow(j - meanFore[i] , 2) * histograma[j];
        }
        varianceFore[i] = sumF / accHistogramaFore[i];

    }

    // calcula la within class variance y almacena los valores en un arreglo
    for(int i = 0; i < size; i++)
    {
        classVariance[i] = (weightBack[i] * varianceBack[i]) + (weightFore[i] * varianceFore[i]);
    }
}

// Funcion que realiza el llamado de las anteriores funciones
// y retorna el threshold de acuerdo al algoritmo de otsu
int thresholdOtsu(double histograma[], int sizeImage)
{
    double minClassVariance;
    int threshold;

    // Funcion que calcula el histograma acumulado
    calculateAccHistograma(histograma);
    // Funcion que calcula el promedio y lo almacena en un array
    calculateWeight(histograma, sizeImage);
    // Funcion que calcula la media
    calculateMean(histograma);
    // Funcion que calcula la varianza
    calculateVariance(histograma);

    // hallar la varianza minima
    minClassVariance = *std::min_element(classVariance,classVariance+lengthArray(classVariance));

    // Hallar el indice de la varianza minima, para poder asociarlos con el pixel que seria el threshold
    for(int i = 0; i < lengthArray(classVariance); i++)
    {
        if(classVariance[i] == minClassVariance)threshold = i;
    }

    return threshold;
}

void thresholdIsodata()
{
//    calculateWeight(histogra);

//    for(int i = 0; i < lengthArray(histogramaT); i++ )
//    {
////        qDebug()<<"W1:"<<weightBack[i]<<"W2: "<<weightFore[i]<<"WF: "<<(weightBack[i] + weightFore[i])/2;
//    }

}

#endif // THRESHOLD_H
