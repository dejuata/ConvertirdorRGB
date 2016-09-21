#ifndef FILTERMINMEDMAX_H
#define FILTERMINMEDMAX_H

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

#include <QDebug>
#include <QColor>
#include <math.h>       // floor
#include <algorithm>    // sort
#include <vector>       // vector

using namespace std;

/* Funcion para aplicar los filtros de orden, min, med, max a una imagen ,
 * en este caso la imagen que recibe como parametro la variable QImage llamada
 * imageT, imageR, imageG, imageB, ademas un entero que define la operacion a
 * realizar
 * 0 -> minimum
 * 1 -> medium
 * 2 -> maximum
 */
QImage filterMinMedMax(QImage image, int operation)
{
    int mm,nn,ii,jj,mitad;
    int countArray,countVector;
    double min,max,medio;
    int size = 3;

    QImage result = image;
    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo arreglos para valores rgb
            double array[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256};

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
                      array[countArray] = image.pixel(ii,jj);
                      countArray++;
                    }
                }
            }
            // combrobar el tamaño del vector con los pixeles maximos y no con el numero 1256
            countVector = 0;

            for(int x = 0; x < lengthArray(array); x++)
                if(array[x] != 1256)countVector++;

            // Inicializo los vectores para manipular los pixeles
            vector<double> myvector (array, array+countVector);

            // Ordeno los vectores de acuerdo al tamaño de numeros validos, es decir descarto 1256
            sort (myvector.begin(), myvector.begin()+countVector);

            /*
             * Almaceno los valores del array que corresponden al min,max,medio para cada pixel
             * y los asigno a la imagen result de acuerdo a cada caso
             */
            if(operation == 0)
            {
                min = myvector[0];
                result.setPixelColor(i,j,min);
            }
            if(operation == 1)
            {
                medio = myvector[floor(myvector.size()/2)];
                result.setPixelColor(i,j,medio);
            }
            if(operation == 2)
            {
                max = myvector[myvector.size()-1];
                result.setPixelColor(i,j,max);
            }
        }
    }
    return result;
}

#endif // FILTERMINMEDMAX_H
