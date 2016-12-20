#ifndef FILTER_H
#define FILTER_H

#include <QDebug>
#include <QColor>
#include <QRgb>
#include <math.h>
#include <algorithm>    // sort
#include <vector>       // vector

using namespace std;

// Kernel para filtros de paso bajo
QString stringAverage3x3 = "1 1 1 1 1 1 1 1 1";
QString stringAverage5x5 = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
QString stringAverage7x7 = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";
QString stringAverage9x9 = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";

QString stringGaussiano3x3 = "1 2 1 2 4 2 1 2 1";
QString stringGaussiano5x5 = "0 1 2 1 0 1 3 5 3 1 2 5 9 5 2 1 3 5 3 1 0 1 2 1 0";
QString stringGaussiano7x7 = "0 0 1 2 1 0 0 0 3 13 22 13 3 0 1 13 59 97 59 13 1 2 22 97 159 97 22 2 1 13 59 97 59 13 1 0 3 13 22 13 3 0 0 0 1 2 1 0 0";
QString stringGaussiano9x9 = "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1";

QString stringLaplaciano3x3 = "0 1 0 1 -4 1 0 1 0";
QString stringLaplaciano5x5 = "0 0 -1 0 0 0 -1 -2 -1 0 -1 -2 16 -2 -1 0 -1 -2 -1 0 0 0 -1 0 0";

QStringList listAverage = stringAverage3x3.split(' ');
QStringList listGaussiano = stringGaussiano3x3.split(' ');
QStringList listLaplaciano = stringLaplaciano3x3.split(' ');

// Kernel para filtros de paso alto
int sobelX[3][3] = {{1,2,1},{0,0,0},{-1,-2,-1}};
int sobelY[3][3] = {{1,0,-1},{2,0,-2},{1,0,-1}};
int prewittX[3][3] = {{1,1,1},{0,0,0},{-1,-1,-1}};
int prewittY[3][3] = {{1,0,-1},{1,0,-1},{1,0,-1}};
// esto kernel son de 2x2 pero los constituyo de 3x3
// debido a la funcion que los recibe como parametro
int robertX[3][3] = {{0,1,0},{-1,0,0},{0,0,0}};
int robertY[3][3] = {{-1,0,0},{0,1,0},{0,0,0}};

// Prueba filtros norte y este
int norte[3][3] = {{1,1,1},{1,-2,1},{-1,-1,-1}};
int este[3][3] = {{-1,1,1},{-1,-2,1},{-1,1,1}};


// Funcion que setea la lista dependiendo del tamaño del kernel que escoja para promedio o gaussiano
QStringList sizeKernelAverageOrGaussiano(int size, QString filter)
{
    QStringList lista;

    if(filter == "average")
    {
        switch(size)
        {
            case 1: lista = stringAverage3x3.split(' ');
            break;
            case 2: lista = stringAverage5x5.split(' ');
            break;
            case 3: lista = stringAverage7x7.split(' ');
            break;
            case 4: lista = stringAverage9x9.split(' ');
            break;
        }
    }
    if(filter == "gaussiano")
    {
        switch(size)
        {
            case 1: lista = stringGaussiano3x3.split(' ');
            break;
            case 2: lista = stringGaussiano5x5.split(' ');
            break;
            case 3: lista = stringGaussiano7x7.split(' ');
            break;
            case 4: lista = stringGaussiano9x9.split(' ');
            break;
        }
    }

    return lista;
}

// Almaceno el tamano del kernel, si es 0 trabaja con el kernel default de [3][3]
int sizeList = 0;

/* Defino los kernel con los que puedo trabajar, cada kernel es pasado como parametro
 * a la funcion de convolucion, dependiendo del tamaño del kernel de entrada del txt
 */
int kernelTwo   [2][2];
int kernelThree [3][3];
int kernelFive  [5][5];
int kernelSeven [7][7];
int kernelNine  [9][9];

// variable que me controla el estado de la aplicacion de acuerdo al filtro que seleccion en settings
int selectFilter = 0;
// numero sigma por default
int numberSigma = 5;


// Funcion para convertir un string a una matriz de 3x3 5x5 7x7 9x9
void createMatriz(QStringList list)
{
    int count = 0, number;
    sizeList = sqrt(list.length());

    for(int i = 0 ; i < sizeList; i++)
    {
        for(int j = 0 ; j < sizeList; j++)
        {
            number = list[count].toInt();

            if(sizeList == 2)kernelTwo[i][j] = number;

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

/* Funcion para aplicar los filtros de orden, min, med, max a una imagen ,
 * en este caso la imagen que recibe como parametro la variable QImage llamada
 * imageT, imageR, imageG, imageB, ademas un entero que define la operacion a
 * realizar
 * 0 -> minimum
 * 1 -> medium
 * 2 -> maximum
 */
QImage filterMinMedMax(QImage image, int size, int operation)
{
    int mm,nn,ii,jj,mitad;
    int countArray,countVector;
    double min,max,medio;    
    QImage result = image;
    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo arreglos para valores rgb
            double array[] = {1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256,
                              1256,1256,1256,1256,1256,1256,1256,1256,1256};

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

QImage filterSigma(QImage image, int sigma)
{
    int mm,nn,ii,jj,mitad,countArray,average,plusR,plusG,plusB;
    int size = 5;
    QRgb rest,operation;
    QRgb number = qRgb(sigma,sigma,sigma);
    QImage result = image;
    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
//            // Incializo arreglos para valores rgb

            QRgb array[] = { 1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256,1256};

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
                      rest = fabs(array[countArray] - image.pixel(i,j));//aqui hay un problema con el valor absoluto revisar como van los pixel en red, green y blue
                      array[countArray] = rest >= 0 && rest <= number ? array[countArray] : 1256;

                      countArray++;
                    }
                }
            }

            plusR = 0, plusG = 0, plusB = 0, average = 0;

            for(int x = 0; x < lengthArray(array); x++)
            {
                if(array[x] != 1256)
                {
                    plusR += QColor(array[x]).red();
                    plusG += QColor(array[x]).green();
                    plusB += QColor(array[x]).blue();
                    average++;
                }
            }

            if(average == 0)
            {
                operation = qRgb(0,0,0);
            }
            else
            {
                operation = qRgb(plusR/average,plusG/average,plusB/average);
            }

            result.setPixelColor(i,j,operation);
        }
    }
    return result;
}

QRgb variance(int r, int g, int b, int n)
{
    QRgb value = qRgb(
                        (r/n) > 255 ? 255 : round(r/n),
                        (g/n) > 255 ? 255 : round(g/n),
                        (b/n) > 255 ? 255 : round(b/n)
                            );
    return value;
}

QImage filterNagao(QImage image)
{
    int mm,nn,ii,jj,mitad,countArray, index, size = 5;

    int rOne,rTwo,rThree,rFour,rFive,rSix,rSeven,rEight,rNine;
    int gOne,gTwo,gThree,gFour,gFive,gSix,gSeven,gEight,gNine;
    int bOne,bTwo,bThree,bFour,bFive,bSix,bSeven,bEight,bNine;

    double sumROne,sumRTwo,sumRThree,sumRFour,sumRFive,sumRSix,sumRSeven,sumREight,sumRNine;
    double sumGOne,sumGTwo,sumGThree,sumGFour,sumGFive,sumGSix,sumGSeven,sumGEight,sumGNine;
    double sumBOne,sumBTwo,sumBThree,sumBFour,sumBFive,sumBSix,sumBSeven,sumBEight,sumBNine;

    QRgb arrayVariance[9], arrayAverage[9], minVariace;

    QImage result = image;

    mitad = size / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {

        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            // Incializo arreglos para valores rgb
            rOne = 0, rTwo = 0, rThree = 0, rFour = 0, rFive = 0, rSix = 0, rSeven = 0, rEight = 0, rNine = 0;
            gOne = 0, gTwo = 0, gThree = 0, gFour = 0, gFive = 0, gSix = 0, gSeven = 0, gEight = 0, gNine = 0;
            bOne = 0, bTwo = 0, bThree = 0, bFour = 0, bFive = 0, bSix = 0, bSeven = 0, bEight = 0, bNine = 0;

            sumROne = 0, sumRTwo = 0, sumRThree = 0, sumRFour = 0, sumRFive = 0, sumRSix = 0, sumRSeven = 0, sumREight = 0, sumRNine = 0;
            sumGOne = 0, sumGTwo = 0, sumGThree = 0, sumGFour = 0, sumGFive = 0, sumGSix = 0, sumGSeven = 0, sumGEight = 0, sumGNine = 0;
            sumBOne = 0, sumBTwo = 0, sumBThree = 0, sumBFour = 0, sumBFive = 0, sumBSix = 0, sumBSeven = 0, sumBEight = 0, sumBNine = 0;

            QRgb modelOne[]   = {1,1,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1};
            QRgb modelTwo[]   = {1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1};
            QRgb modelThree[] = {1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1};
            QRgb modelFour[]  = {1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,1,1,0,0,0,1};
            QRgb modelFive[]  = {1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1};
            QRgb modelSix[]   = {0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1};
            QRgb modelSeven[] = {1,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1};
            QRgb modelEight[] = {1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,0,0,0,1,1,1,0,0};
            QRgb modelNine[]  = {1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,0,0,0,1,1,0,0,1,1,1};

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
                        // Insercion de datos al primer modelo
                        if(modelOne[countArray] != 1)
                        {
                            modelOne[countArray] = image.pixel(ii,jj);
                            rOne += QColor(image.pixel(ii,jj)).red();
                            gOne += QColor(image.pixel(ii,jj)).green();
                            bOne += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al segundo modelo
                        if(modelTwo[countArray] != 1)
                        {
                            modelTwo[countArray] = image.pixel(ii,jj);
                            rTwo += QColor(image.pixel(ii,jj)).red();
                            gTwo += QColor(image.pixel(ii,jj)).green();
                            bTwo += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al tercer modelo
                        if(modelThree[countArray] != 1)
                        {
                            modelThree[countArray] = image.pixel(ii,jj);
                            rThree += QColor(image.pixel(ii,jj)).red();
                            gThree += QColor(image.pixel(ii,jj)).green();
                            bThree += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al cuarto modelo
                        if(modelFour[countArray] != 1)
                        {
                            modelFour[countArray] = image.pixel(ii,jj);
                            rFour += QColor(image.pixel(ii,jj)).red();
                            gFour += QColor(image.pixel(ii,jj)).green();
                            bFour += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al quinto modelo
                        if(modelFive[countArray] != 1)
                        {
                            modelFive[countArray] = image.pixel(ii,jj);
                            rFive += QColor(image.pixel(ii,jj)).red();
                            gFive += QColor(image.pixel(ii,jj)).green();
                            bFive += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al sexto modelo
                        if(modelSix[countArray] != 1)
                        {
                            modelSix[countArray] = image.pixel(ii,jj);
                            rSix += QColor(image.pixel(ii,jj)).red();
                            gSix += QColor(image.pixel(ii,jj)).green();
                            bSix += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al septimo modelo
                        if(modelSeven[countArray] != 1)
                        {
                            modelSeven[countArray] = image.pixel(ii,jj);
                            rSeven += QColor(image.pixel(ii,jj)).red();
                            gSeven += QColor(image.pixel(ii,jj)).green();
                            bSeven += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al octavo modelo
                        if(modelEight[countArray] != 1)
                        {
                            modelEight[countArray] = image.pixel(ii,jj);
                            rEight += QColor(image.pixel(ii,jj)).red();
                            gEight += QColor(image.pixel(ii,jj)).green();
                            bEight += QColor(image.pixel(ii,jj)).blue();
                        }
                        // Insercion de datos al noveno modelo
                        if(modelNine[countArray] != 1)
                        {
                            modelNine[countArray] = image.pixel(ii,jj);
                            rNine += QColor(image.pixel(ii,jj)).red();
                            gNine += QColor(image.pixel(ii,jj)).green();
                            bNine += QColor(image.pixel(ii,jj)).blue();
                        }

                      countArray++;
                    }
                }
            }

            // Calcular promedio para cada modelo y sumatoria de varianza
            for(int x = 0; x < lengthArray(modelOne); x++)
            {
                if(modelOne[x] != 1)
                {
                    arrayAverage[0] = qRgb(round(rOne/9),round(gOne/9),round(bOne/9));

                    sumROne += pow(QColor(modelOne[x]).red() - round(rOne/9),2);
                    sumGOne += pow(QColor(modelOne[x]).green() - round(gOne/9),2);
                    sumBOne += pow(QColor(modelOne[x]).blue() - round(bOne/9),2);
                }
                if(modelTwo[x] != 1)
                {
                    arrayAverage[1] = qRgb(round(rTwo/7),round(gTwo/7),round(bTwo/7));

                    sumRTwo += pow(QColor(modelTwo[x]).red() - round(rTwo/7),2);
                    sumGTwo += pow(QColor(modelTwo[x]).green() - round(gTwo/7),2);
                    sumBTwo += pow(QColor(modelTwo[x]).blue() - round(bTwo/7),2);
                }
                if(modelThree[x] != 1)
                {
                    arrayAverage[2] = qRgb(round(rThree/7),round(gThree/7),round(bThree/7));

                    sumRThree += pow(QColor(modelThree[x]).red() - round(rThree/7),2);
                    sumGThree += pow(QColor(modelThree[x]).green() - round(gThree/7),2);
                    sumBThree += pow(QColor(modelThree[x]).blue() - round(bThree/7),2);
                }
                if(modelFour[x] != 1)
                {
                    arrayAverage[3] = qRgb(round(rFour/7),round(gFour/7),round(bFour/7));

                    sumRFour += pow(QColor(modelFour[x]).red() - round(rFour/7),2);
                    sumGFour += pow(QColor(modelFour[x]).green() - round(gFour/7),2);
                    sumBFour += pow(QColor(modelFour[x]).blue() - round(bFour/7),2);
                }
                if(modelFive[x] != 1)
                {
                    arrayAverage[4] = qRgb(round(rFive/7),round(gFive/7),round(bFive/7));

                    sumRFive += pow(QColor(modelFive[x]).red() - round(rFive/7),2);
                    sumGFive += pow(QColor(modelFive[x]).green() - round(gFive/7),2);
                    sumBFive += pow(QColor(modelFive[x]).blue() - round(bFive/7),2);
                }
                if(modelSix[x] != 1)
                {
                    arrayAverage[5] = qRgb(round(rSix/7),round(gSix/7),round(bSix/7));

                    sumRSix += pow(QColor(modelSix[x]).red() - round(rSix/7),2);
                    sumGSix += pow(QColor(modelSix[x]).green() - round(gSix/7),2);
                    sumBSix += pow(QColor(modelSix[x]).blue() - round(bSix/7),2);
                }
                if(modelSeven[x] != 1)
                {
                    arrayAverage[6] = qRgb(round(rSeven/7),round(gSeven/7),round(bSeven/7));

                    sumRSeven += pow(QColor(modelSeven[x]).red() - round(rSeven/7),2);
                    sumGSeven += pow(QColor(modelSeven[x]).green() - round(gSeven/7),2);
                    sumBSeven += pow(QColor(modelSeven[x]).blue() - round(bSeven/7),2);
                }
                if(modelEight[x] != 1)
                {
                    arrayAverage[7] = qRgb(round(rEight/7),round(gEight/7),round(bEight/7));

                    sumREight += pow(QColor(modelEight[x]).red() - round(rEight/7),2);
                    sumGEight += pow(QColor(modelEight[x]).green() - round(gEight/7),2);
                    sumBEight += pow(QColor(modelEight[x]).blue() - round(bEight/7),2);
                }
                if(modelNine[x] != 1)
                {
                    arrayAverage[8] = qRgb(round(rNine/7),round(gNine/7),round(bNine/7));

                    sumRNine += pow(QColor(modelNine[x]).red() - round(rNine/7),2);
                    sumGNine += pow(QColor(modelNine[x]).green() - round(gNine/7),2);
                    sumBNine += pow(QColor(modelNine[x]).blue() - round(bNine/7),2);
                }
            }
            // problema si el pixel de origen es 0 0 0 -> revisar, se desborda la sumatoria-> posible solucion, multiplicar los elementos por la ventana del kernel
            arrayVariance[0] = variance(sumROne,sumGOne,sumBOne,9);

            arrayVariance[1] = variance(sumRTwo,sumGTwo,sumBTwo,7);

            arrayVariance[2] = variance(sumRThree,sumGThree,sumBThree,7);

            arrayVariance[3] = variance(sumRFour,sumGFour,sumBFour,7);

            arrayVariance[4] = variance(sumRFive,sumGFive,sumBFive,7);

            arrayVariance[5] = variance(sumRSix,sumGSix,sumBSix,7);

            arrayVariance[6] = variance(sumRSeven,sumGSeven,sumBSeven,7);

            arrayVariance[7] = variance(sumREight,sumGEight,sumBEight,7);

            arrayVariance[8] = variance(sumRNine,sumGNine,sumBNine,7);

            // Calcular la varianza minima de los 9 modelos
            minVariace = *std::min_element(arrayVariance,arrayVariance+9);
            // Hallar el indice de la varianza minima, para poder asociarlos con su respectivo promedio
            for(int x = 0; x < lengthArray(arrayVariance); x++)
            {
                if(arrayVariance[x] == minVariace)index = x;
            }

            result.setPixelColor(i,j,arrayAverage[index]);
        }
    }
    return result;
}

/* Edge Detection*/
QImage filterEdgeDetection(QImage image, int kernelX[][3], int kernelY[][3] ,int sizeKernel, int threshold, bool background = true)
{
    int mitad,mm,nn,ii,jj;
    int x1,x2,x3,y1,y2,y3,xy1,xy2,xy3;       
    QImage result = image;
    QRgb value;
    mitad = sizeKernel / 2;

    // Filas
    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {            
            // Incializo valores r g b a 0
            x1 = 0, x2 = 0, x3 = 0, y1 = 0, y2 = 0, y3 = 0;

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
                        x1 += QColor(image.pixel(ii,jj)).red() * kernelX[mm][nn];
                        x2 += QColor(image.pixel(ii,jj)).green() * kernelX[mm][nn];
                        x3 += QColor(image.pixel(ii,jj)).blue() * kernelX[mm][nn];

                        y1 += QColor(image.pixel(ii,jj)).red() * kernelY[mm][nn];
                        y2 += QColor(image.pixel(ii,jj)).green() * kernelY[mm][nn];
                        y3 += QColor(image.pixel(ii,jj)).blue() * kernelY[mm][nn];

                        if(background)
                        {
                            xy1 = fabs(x1) + fabs(y1) >= threshold ? 0 : 255;
                            xy2 = fabs(x2) + fabs(y2) >= threshold ? 0 : 255;
                            xy3 = fabs(x3) + fabs(y3) >= threshold ? 0 : 255;
                        }
                        else
                        {
                            xy1 = fabs(x1) + fabs(y1) >= threshold ? 255 : 0;
                            xy2 = fabs(x2) + fabs(y2) >= threshold ? 255 : 0;
                            xy3 = fabs(x3) + fabs(y3) >= threshold ? 255 : 0;
                        }
                    }
                }
            }
            value = qRgb(xy1,xy2,xy3);
            result.setPixelColor(i,j,value);            
        }
    }
    return result;
}

QImage filterLaplaciano(QImage image, int sizeKernel, int threshold)
{
    int mitad,average,mm,nn,ii,jj,r,g,b;
    QImage result = image;
    QRgb value;
    mitad = sizeKernel / 2;

    average = 1;

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

                            r = fabs(r)  >= threshold ? 0 : 255;
                            g = fabs(g)  >= threshold ? 0 : 255;
                            b = fabs(b)  >= threshold ? 0 : 255;
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
