#ifndef MORPHOLOGICAL_H
#define MORPHOLOGICAL_H

#include <QImage>

QString arrayStructure[7] = {"0 0 0 0 1 1 0 0 0",
                             "0 0 0 1 1 0 0 0 0",
                             "0 0 0 1 1 1 0 0 0",
                             "0 1 0 0 1 0 0 0 0",
                             "0 0 0 0 1 0 0 1 0",
                             "0 1 0 0 1 0 0 1 0",
                             "0 1 0 1 1 1 0 1 0"};

int kernel3x3[3][3];

void createMatrizStructure(QStringList list)
{
    int count = 0, number;
    int sizeList = sqrt(list.length());

    for(int i = 0 ; i < sizeList; i++)
    {
        for(int j = 0 ; j < sizeList; j++)
        {
            number = list[count].toInt();

//            if(sizeList == 2)kernelTwo[i][j] = number;

            if(sizeList == 3)kernel3x3[i][j] = number;

//            if(sizeList == 5)kernelFive[i][j] = number;

//            if(sizeList == 7)kernelSeven[i][j] = number;

//            if(sizeList == 9)kernelNine[i][j] = number;

            count++;
        }
    }
}
// funcion para invertir el kernel y poder aplicar la erosion,
// ya que el algoritmo da como resultado una imagen pero con el kernel invertido
// asi que para que no pase eso, lo invierto y es como si estuviera trabajando
// con el kernel que ingreso el usuario
void mirrorMatrizForErosion(int mitad, int sizeKernel)
{
    int espejo[3][3];
    int size = sizeKernel - 1;

    for(int x = 0; x < lengthArray(espejo); x++)
    {
        for(int y = 0; y < lengthArray(espejo); y++)
        {
           espejo[x][y] = y < mitad ? kernel3x3[x][size-y] : y == mitad ? kernel3x3[x][mitad] : y > mitad ? kernel3x3[x][size-y] : 1;
        }
    }
    for(int x = 0; x < lengthArray(espejo); x++)
    {
        for(int y = 0; y < lengthArray(espejo); y++)
        {
           kernel3x3[x][y] = x < mitad ? espejo[size-x][y] : x == mitad ? espejo[mitad][y] : x > mitad ? espejo[size-x][y] : 1;
        }
    }
}
// retorna el numero de elementos del kernel
int valueKernel()
{
    int sumKernel = 0;

    for(int x = 0; x < lengthArray(kernel3x3); x++)
    {
        for(int y = 0; y < lengthArray(kernel3x3); y++)
        {
            sumKernel += kernel3x3[x][y];
        }
    }

    return sumKernel;
}

// debe recibir una imagen binaria que sea de fondo negro
// true -> dilation
// false -> erosion
QImage dilationOrErosion(QImage image, bool flag)
{
    int mitad,mm,nn,ii,jj,r,g,b;
    QImage result = image;
    int sizeKernel = lengthArray(kernel3x3);
    mitad = sizeKernel / 2;
    int erosion = 0;

    if(!flag)
    {
        mirrorMatrizForErosion(mitad,sizeKernel);
        erosion = valueKernel() * 255;
    }

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
                            r += QColor(image.pixel(ii,jj)).red() * kernel3x3[mm][nn];
                            g += QColor(image.pixel(ii,jj)).green() * kernel3x3[mm][nn];
                            b += QColor(image.pixel(ii,jj)).blue() * kernel3x3[mm][nn];
                        }
                    }
                }
            }
            if(flag)
            {
                if(r >= 255 && g >=255 && b >=255)
                {
                    result.setPixelColor(i,j,qRgb(255,255,255));
                }
                else
                {
                    result.setPixelColor(i,j,qRgb(0,0,0));
                }
            }
            else
            {
                if(r == erosion)
                {
                    result.setPixelColor(i,j,qRgb(255,255,255));
                }
                else
                {
                     result.setPixelColor(i,j,qRgb(0,0,0));
                }
            }

        }
        qDebug()<<endl;
    }
    return result;
}

#endif // MORPHOLOGICAL_H
