#ifndef FILTERMINMEDMAX_H
#define FILTERMINMEDMAX_H

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

#include <QDebug>
#include <QColor>
#include <math.h>       // floor
#include <algorithm>    // sort
#include <vector>       // vector

using namespace std;

/* Funcion para aplicar los filtros de orden, min, med, max a una imagen que
 * contenga infomacion en los tres canales, en este caso la imagen que recibe
 * como parametro es la variable QImage llamada imageT
 */
QImage filterMinMedMax (QImage image, int operation)
{
    int mm,nn,ii,jj,mitad;
    int countArray,countVectorR,countVectorG,countVectorB;
    int minR,maxR,medioR,minG,maxG,medioG,minB,maxB,medioB;
    int size = 3;

    QImage result = image;
    QRgb value;
    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo arreglos para valores rgb
            int arrayR[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256};
            int arrayG[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256};
            int arrayB[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256};

            countArray = 0;

            // Filas del Kernel
            for (int m = 0; m < size; m++)
            {
                // Indice de la fila del kernel alrevez
                mm = size - 1 - m;

                // Columnas del kernel
                for (int n = 0; n < size; n++)
                {
                    // Indice de la columna del kernel alrevez
                    nn = size - 1 - n;

                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        arrayR[countArray] = QColor(image.pixel(ii,jj)).red();
                        arrayG[countArray] = QColor(image.pixel(ii,jj)).green();
                        arrayB[countArray] = QColor(image.pixel(ii,jj)).blue();

                        countArray++;//
                    }
                }
            }

            // combrobar el tamaño del vector con los pixeles maximos y no con el numero 1256
            countVectorR = 0, countVectorG = 0, countVectorB = 0;

            for(int x = 0; x < lengthArray(arrayR); x++)
                if(arrayR[x] != 1256)countVectorR++;

            for(int y = 0; y < lengthArray(arrayG); y++)
                if(arrayG[y] != 1256)countVectorG++;

            for(int z = 0; z < lengthArray(arrayB); z++)
                if(arrayB[z] != 1256)countVectorB++;

            // Inicializo los vectores para manipular los pixeles R, G, B
            vector<int> myvectorR (arrayR, arrayR+countVectorR);
            vector<int> myvectorG (arrayG, arrayG+countVectorG);
            vector<int> myvectorB (arrayB, arrayB+countVectorB);

            // Ordeno los vectores de acuerdo al tamaño de numeros validos, es decir descarto 1256
            sort (myvectorR.begin(), myvectorR.begin()+countVectorR);
            sort (myvectorG.begin(), myvectorG.begin()+countVectorG);
            sort (myvectorB.begin(), myvectorB.begin()+countVectorB);

            /*
             * Almaceno los valores del array que corresponden al min,max,medio para cada canal
             * y los asigno a la imagen result de acuerdo a cada caso
             */
            if(operation == 0)
            {
                minR = myvectorR[0];
                minG = myvectorG[0];
                minB = myvectorB[0];

                value = qRgb(minR,minG,minB);
                result.setPixelColor(i,j,value);
            }
            if(operation == 1)
            {
                medioR = myvectorR[floor(myvectorR.size()/2)];
                medioG = myvectorG[floor(myvectorG.size()/2)];
                medioB = myvectorB[floor(myvectorB.size()/2)];

                value = qRgb(medioR,medioG,medioB);
                result.setPixelColor(i,j,value);
            }
            if(operation == 2)
            {
                maxR = myvectorR[myvectorR.size()-1];
                maxG = myvectorG[myvectorG.size()-1];
                maxB = myvectorB[myvectorB.size()-1];

                value = qRgb(maxR,maxG,maxB);
                result.setPixelColor(i,j,value);
            }
        }
    }
    return result;
}
/* Funcion para aplicar los filtros de orden, min, med, max a una imagen que
 * contenga infomacion en uno de los tres canales, en este caso la imagen que recibe
 * como parametro pueden ser la variable QImage llamada imageR, imageG, imageB
 */
QImage filterMinMedMaxByChannel (QImage image, int operation, char channel)
{
    int mm,nn,ii,jj,mitad;
    int countArray,countVector;
    int min,max,medio;
    int size = 3;

    QImage result = image;
    QRgb value;
    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo arreglos para valores rgb
            int array[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256};

            countArray = 0;

            // Filas del Kernel
            for (int m = 0; m < size; m++)
            {
                // Indice de la fila del kernel alrevez
                mm = size - 1 - m;

                // Columnas del kernel
                for (int n = 0; n < size; n++)
                {
                    // Indice de la columna del kernel alrevez
                    nn = size - 1 - n;

                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        if(channel == 'r')
                        {
                            array[countArray] = QColor(image.pixel(ii,jj)).red();
                        }
                        if(channel == 'g')
                        {
                            array[countArray] = QColor(image.pixel(ii,jj)).green();
                        }
                        if(channel == 'b')
                        {
                            array[countArray] = QColor(image.pixel(ii,jj)).blue();
                        }

                        countArray++;
                    }
                }
            }

            // combrobar el tamaño del vector con los pixeles maximos y no con el numero 1256
            countVector = 0;

            for(int x = 0; x < lengthArray(array); x++)
                if(array[x] != 1256)countVector++;

            // Inicializo los vectores para manipular los pixeles dependiendo del canal
            vector<int> myvector (array, array+countVector);

            // Ordeno los vectores de acuerdo al tamaño de numeros validos, es decir descarto 1256
            sort (myvector.begin(), myvector.begin()+countVector);

            /*
             * Almaceno los valores del array que corresponden al min,max,medio para cada canal
             * y los asigno a la imagen result de acuerdo a cada caso
             */
            if(operation == 0)
            {
                min = myvector[0];

                if(channel == 'r')
                {
                    value = qRgb(min,0,0);
                }
                if(channel == 'g')
                {
                    value = qRgb(0,min,0);
                }
                if(channel == 'b')
                {
                    value = qRgb(0,0,min);
                }

                result.setPixelColor(i,j,value);
            }
            if(operation == 1)
            {
                medio = myvector[floor(myvector.size()/2)];

                if(channel == 'r')
                {
                    value = qRgb(medio,0,0);
                }
                if(channel == 'g')
                {
                    value = qRgb(0,medio,0);
                }
                if(channel == 'b')
                {
                    value = qRgb(0,0,medio);
                }

                result.setPixelColor(i,j,value);
            }
            if(operation == 2)
            {
                max = myvector[myvector.size()-1];

                if(channel == 'r')
                {
                    value = qRgb(max,0,0);
                }
                if(channel == 'g')
                {
                    value = qRgb(0,max,0);
                }
                if(channel == 'b')
                {
                    value = qRgb(0,0,max);
                }

                result.setPixelColor(i,j,value);
            }
        }
    }
    return result;
}

#endif // FILTERMINMEDMAX_H
