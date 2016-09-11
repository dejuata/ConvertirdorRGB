#ifndef FILTER_H
#define FILTER_H

#define length(x) (sizeof(x)/sizeof(x[0]))

#include <QDebug>
#include <iostream>
#include <vector>
#include <QImage>
#include <QColor>

using namespace std;

QImage convolucion (QImage image, int kernel[][7], int size)
{

    int mitad,average,mm,nn,ii,jj,r,g,b;
    QImage result = image;
    QRgb value;
    average = size * size;
    mitad = size / 2;

    /* Proceso de convolucion
     * Recorro la imagen en los dos primeros for, al igual que el kernel
     * en la variable mm hallo el indice de la fila del kernel alrevez, al
     * igual que la variable nn, almacena la columna del kernel alrevez,
     * las variables ii,jj son para almacenar la posicion de las imagenes tomando
     * en cuenta su limite exterior es decir i-1, j-1,la variable acumulador almacena el resultado
     * que luego es asignado en la posicion de la imagen resultante
     */

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
