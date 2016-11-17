#ifndef THRESHOLD_H
#define THRESHOLD_H

#include <iostream>
#include <algorithm> // std::min_element, std::max_element
#include <math.h>
#include <QtConcurrent>
#include <QDebug>
#include "globals.h"

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

void calculateAccHistograma()
{
    int sumB = 0;
    int sumF = 0;

    accHistogramaBack[0] = 0;
    for(int i = 1; i < lengthArray(histogramaT); i++)
    {
        sumB += histogramaT[i-1];
        accHistogramaBack[i] = sumB;
    }
    for(int i = lengthArray(histogramaT) - 1; i >= 0 ; i--)
    {
        sumF += histogramaT[i];
        accHistogramaFore[i] = sumF;
    }
}
void calculateWeight()
{
    double sumB = 0;
    double sumF = 0;

    weightBack[0] = sumB;

    for(int i = 1; i < lengthArray(histogramaT); i++)
    {
        sumB += histogramaT[i-1] / sizeImage;
        weightBack[i] = sumB;
    }

    for(int i = lengthArray(histogramaT) - 1; i >= 0 ; i--)
    {
        sumF += histogramaT[i] / sizeImage;
        weightFore[i] = sumF;
    }
}
void calculateMean()
{
    int sumB = 0;
    int sumF = 0;

    meanBack[0] = 0;
    for(int i = 1; i < lengthArray(histogramaT); i++)
    {
        sumB += (i - 1) * histogramaT[i - 1];
        meanBack[i] = sumB / accHistogramaBack[i];
    }

    for(int i = lengthArray(histogramaT) - 1; i >= 0 ; i--)
    {
        sumF += i * histogramaT[i];
        meanFore[i] = sumF / accHistogramaFore[i];
    }
}
void calculateVariance()
{
    int countB = 0;
    int countF = lengthArray(histogramaT);
    double sumB;
    double sumF;

    varianceBack[0] = 0;

    for(int i = 1; i < lengthArray(histogramaT); i++)
    {
        sumB = 0;
        countB = countB + 1;

        for(int j = 0; j < countB; j++)
        {
            sumB += pow(j - meanBack[i] , 2) * histogramaT[j];
        }
        varianceBack[i] = sumB / accHistogramaBack[i];
    }

    for(int i = lengthArray(histogramaT) - 1; i >= 0  ; i--)
    {
        sumF = 0;
        countF = countF - 1;//9-8

        for(int j = lengthArray(histogramaT) - 1; j >= countF; j--)
        {
            sumF += pow(j - meanFore[i] , 2) * histogramaT[j];
        }
        varianceFore[i] = sumF / accHistogramaFore[i];

    }

    // calcula la within class variance y almacena los valores en un arreglo
    for(int i = 0; i < lengthArray(histogramaT); i++)
    {
        classVariance[i] = (weightBack[i] * varianceBack[i]) + (weightFore[i] * varianceFore[i]);
    }
}

// Funcion que realiza el llamado de las anteriores funciones
// y retorna el threshold de acuerdo al algoritmo de otsu
int thresholdOtsu()
{
    double minClassVariance;
    int threshold;

    // Funcion que calcula el histograma acumulado
    calculateAccHistograma();
    // Funcion que calcula el promedio y lo almacena en un array
    calculateWeight();
    // Funcion que calcula la media
    calculateMean();
    // Funcion que calcula la varianza
    calculateVariance();

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
    calculateWeight();

    for(int i = 0; i < lengthArray(histogramaT); i++ )
    {
//        qDebug()<<"W1:"<<weightBack[i]<<"W2: "<<weightFore[i]<<"WF: "<<(weightBack[i] + weightFore[i])/2;
    }

}

#endif // THRESHOLD_H
