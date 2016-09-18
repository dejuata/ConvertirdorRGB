#ifndef FILTER_H
#define FILTER_H

//#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

#include <QDebug>
#include <QColor>
#include <math.h>
#include <algorithm>    // std::sort
#include <vector>       // std::vector


/*
 *  Variables para la funcionalidad de filtros
 */

// Almaceno el tamano del kernel, si es 0 trabaja con el kernel default de [3][3]
int sizeList = 0;
// Defino los kernel con los que puedo trabajar, cada kernel es pasado como parametro
// a la funcion de convolucion, dependiendo del tamaño del kernel de entrada del txt
int kernelThree [3][3];
int kernelFive  [5][5];
int kernelSeven [7][7];
int kernelNine  [9][9];
// por default trabaja con el kernel promedio
int kernel[3][3] = {
                    {1, 1, 1},
                    {1, 1, 1},
                    {1, 1, 1}
                };
// kernel gaussiano
int kernelGauss[3][3] = {
                    {1, 2, 1},
                    {2, 4, 2},
                    {1, 2, 1}
                };

// variable que cambia al seleccionar un kernel por default
int selectFilter = 0;

using namespace std;

/*
 * Funcion para convertir un string a una matriz de 3x3 5x5 7x7 9x9
 */
void createMatriz(QStringList list)
{
    int count = 0;
    int number;
    sizeList = sqrt(list.length());

    for(int i = 0 ; i < sizeList; i++)
    {
        for(int j = 0 ; j < sizeList; j++)
        {
            number = list[count].toInt();

            if(sizeList == 3)
            {
                kernelThree[i][j] = number;
            }
            if(sizeList == 5)
            {
                kernelFive[i][j] = number;
            }
            if(sizeList == 7)
            {
                kernelSeven[i][j] = number;
            }
            if(sizeList == 9)
            {
                kernelNine[i][j] = number;
            }

           count++;
      }
    }
}


/*
 * Funcion de Convolucion
 */
QImage convolucion (QImage image, int kernel[][3])
{
    int mitad,average,mm,nn,ii,jj,r,g,b;
    int size = 3, suma = 0;
    QImage result = image;
    QRgb value;
    average = size * size;
    mitad = size / 2;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            suma += kernel[i][j];
        }
    }
    qDebug()<<"esta es la suma"<<suma;

    for (int i = 0; i < image.width(); i++) // Filas
    {
        for (int j = 0; j < image.height(); j++) // Columnas
        {
            // Incializo valores r g b a 0
            r = 0;
            g = 0;
            b = 0;

            for (int m = 0; m < size; m++) // Filas del Kernel
            {
                mm = size - 1 - m; // Indice de la fila del kernel alrevez

                for (int n = 0; n < size; n++) // Columnas del kernel
                {
                    nn = size - 1 - n; // Indice de la columna del kernel alrevez
                    ii = i + (m - mitad);
                    jj = j + (n - mitad);


                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        r += QColor(image.pixel(ii,jj)).red() * kernel[mm][nn];
                        g += QColor(image.pixel(ii,jj)).green() * kernel[mm][nn];
                        b += QColor(image.pixel(ii,jj)).blue() * kernel[mm][nn];
                    }
                }
            }            
            value = qRgb(r/suma,g/suma,b/suma);
            result.setPixelColor(i,j,value);
        }
    }

    return result;
}

QImage convolucion (QImage image, int kernel[][5])
{
    int mitad,mm,nn,ii,jj,r,g,b,average;
    int size = 5;
    QImage result = image;
    QRgb value;    
    mitad = size / 2;

    for (int i = 0; i < image.width(); ++i) // Filas
    {
        for (int j = 0; j < image.height(); ++j) // Columnas
        {
            // Incializo valores r g b a 0
            r = 0;
            g = 0;
            b = 0;

            for (int m = 0; m < size; ++m) // Filas del Kernel
            {
                mm = size - 1 - m; // Indice de la fila del kernel alrevez

                for (int n = 0; n < size; ++n) // Columnas del kernel
                {
                    nn = size - 1 - n; // Indice de la columna del kernel alrevez
                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        r += QColor(image.pixel(ii,jj)).red() * kernel[mm][nn];
                        g += QColor(image.pixel(ii,jj)).green() * kernel[mm][nn];
                        b += QColor(image.pixel(ii,jj)).blue() * kernel[mm][nn];
                    }
                }
            }
            value = qRgb(r/average,g/average,b/average);
            result.setPixelColor(i,j,value);
        }
    }

    return result;
}

QImage convolucion (QImage image, int kernel[][7])
{
    int mitad,average,mm,nn,ii,jj,r,g,b;
    int size = 7;
    QImage result = image;
    QRgb value;
    average = size * size;
    mitad = size / 2;

    for (int i = 0; i < image.width(); ++i) // Filas
    {
        for (int j = 0; j < image.height(); ++j) // Columnas
        {
            // Incializo valores r g b a 0
            r = 0;
            g = 0;
            b = 0;

            for (int m = 0; m < size; ++m) // Filas del Kernel
            {
                mm = size - 1 - m; // Indice de la fila del kernel alrevez

                for (int n = 0; n < size; ++n) // Columnas del kernel
                {
                    nn = size - 1 - n; // Indice de la columna del kernel alrevez
                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        r += QColor(image.pixel(ii,jj)).red() * kernel[mm][nn];
                        g += QColor(image.pixel(ii,jj)).green() * kernel[mm][nn];
                        b += QColor(image.pixel(ii,jj)).blue() * kernel[mm][nn];
                    }
                }
            }
            value = qRgb(r/average,g/average,b/average);
            result.setPixelColor(i,j,value);
        }
    }

    return result;
}

QImage convolucion (QImage image, int kernel[][9])
{
    int mitad,average,mm,nn,ii,jj,r,g,b;
    int size = 9;
    QImage result = image;
    QRgb value;
    average = size * size;
    mitad = size / 2;

    for (int i = 0; i < image.width(); ++i) // Filas
    {
        for (int j = 0; j < image.height(); ++j) // Columnas
        {
            // Incializo valores r g b a 0
            r = 0;
            g = 0;
            b = 0;

            for (int m = 0; m < size; ++m) // Filas del Kernel
            {
                mm = size - 1 - m; // Indice de la fila del kernel alrevez

                for (int n = 0; n < size; ++n) // Columnas del kernel
                {
                    nn = size - 1 - n; // Indice de la columna del kernel alrevez
                    ii = i + (m - mitad);
                    jj = j + (n - mitad);

                    // validar limites de la imagen 00000
                    if (ii >= 0 && ii < image.width() && jj >= 0 && jj < image.height())
                    {
                        r += QColor(image.pixel(ii,jj)).red() * kernel[mm][nn];
                        g += QColor(image.pixel(ii,jj)).green() * kernel[mm][nn];
                        b += QColor(image.pixel(ii,jj)).blue() * kernel[mm][nn];
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
