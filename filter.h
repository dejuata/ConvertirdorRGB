#ifndef FILTER_H
#define FILTER_H

#include <QDebug>
#include <QColor>
#include <math.h>
#include "globals.h"

QString stringAverage = "1 1 1 1 1 1 1 1 1";
QString stringGaussiano = "1 2 1 2 4 2 1 2 1";
// por default trabaja con el kernel promedio
QStringList listAverage = stringAverage.split(' ');
QStringList listGaussiano = stringGaussiano.split(' ');

// Almaceno el tamano del kernel, si es 0 trabaja con el kernel default de [3][3]
int sizeList = 0;

/* Defino los kernel con los que puedo trabajar, cada kernel es pasado como parametro
 * a la funcion de convolucion, dependiendo del tamaño del kernel de entrada del txt
 */
int kernelThree [3][3];
int kernelFive  [5][5];
int kernelSeven [7][7];
int kernelNine  [9][9];

// variable que me controla el estado de la aplicacion de acuerdo al filtro que seleccion en settings
int selectFilter = 0;

/*
 * Funcion para convertir un string a una matriz de 3x3 5x5 7x7 9x9
 */
void createMatriz(QStringList list)
{
    int count = 0, number;
    sizeList = sqrt(list.length());

    for(int i = 0 ; i < sizeList; i++)
    {
        for(int j = 0 ; j < sizeList; j++)
        {
            number = list[count].toInt();

            if(sizeList == 3)kernelThree[i][j] = number;

            if(sizeList == 5)kernelFive[i][j] = number;

            if(sizeList == 7)kernelSeven[i][j] = number;

            if(sizeList == 9)kernelNine[i][j] = number;

            count++;
        }
    }
}
int numberDivisorIfAverageOrGaussiano(int sizeKernel, QString typeFilter)
{
    int average = 0;

    if(typeFilter == "average")
    {
        average = sizeKernel * sizeKernel;
    }
    if(typeFilter == "gaussiano")
    {
        for (int i = 0; i < sizeKernel; i++)
        {
            for (int j = 0; j < sizeKernel; j++)
            {
                if(sizeKernel == 3)average += kernelThree[i][j];

                if(sizeKernel == 5)average += kernelFive[i][j];

                if(sizeKernel == 7)average += kernelSeven[i][j];

                if(sizeKernel == 9)average += kernelNine[i][j];
            }
        }
    }
    return average;
}
/* Funcion para el filtro promedio, recibe como parametro la imagen, y un entero que define
 * con que kernel voy a trabajar, es decir si sizeKernel == 5 entonces el kernel con el
 * que se trabaja es el KernelFive definido anteriormente
 */
QImage filterAverageAndGaussiano (QImage image, int sizeKernel, QString typeFilter)
{
    int mitad,average,mm,nn,ii,jj,r,g,b;
    QImage result = image;
    QRgb value;
    mitad = sizeKernel / 2;

    average = numberDivisorIfAverageOrGaussiano(sizeKernel, typeFilter);
    qDebug()<<"Average: "<<average;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo valores r g b a 0
            r = 0;
            g = 0;
            b = 0;

            // Filas del Kernel
            for (int m = 0; m < sizeKernel; m++)
            {
                // Indice de la fila del kernel alrevez
                mm = sizeKernel - 1 - m;

                // Columnas del kernel
                for (int n = 0; n < sizeKernel; n++)
                {
                    // Indice de la columna del kernel alrevez
                    nn = sizeKernel - 1 - n;
                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        if(sizeKernel == 3)
                        {
                            r += QColor(image.pixel(ii,jj)).red() * kernelThree[mm][nn];
                            g += QColor(image.pixel(ii,jj)).green() * kernelThree[mm][nn];
                            b += QColor(image.pixel(ii,jj)).blue() * kernelThree[mm][nn];
                        }
                        if(sizeKernel == 5)
                        {
                            r += QColor(image.pixel(ii,jj)).red() * kernelFive[mm][nn];
                            g += QColor(image.pixel(ii,jj)).green() * kernelFive[mm][nn];
                            b += QColor(image.pixel(ii,jj)).blue() * kernelFive[mm][nn];
                        }
                        if(sizeKernel == 7)
                        {
                            r += QColor(image.pixel(ii,jj)).red() * kernelSeven[mm][nn];
                            g += QColor(image.pixel(ii,jj)).green() * kernelSeven[mm][nn];
                            b += QColor(image.pixel(ii,jj)).blue() * kernelSeven[mm][nn];
                        }
                        if(sizeKernel == 9)
                        {
                            r += QColor(image.pixel(ii,jj)).red() * kernelNine[mm][nn];
                            g += QColor(image.pixel(ii,jj)).green() * kernelNine[mm][nn];
                            b += QColor(image.pixel(ii,jj)).blue() * kernelNine[mm][nn];
                        }
                    }
                }
            }
            value = qRgb(r/average,g/average,b/average);
            result.setPixelColor(i,j,value);
        }
    }
    return result;
}




#endif // FILTER_H
