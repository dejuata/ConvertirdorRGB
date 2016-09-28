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

//            qDebug()<<arrayVariance[0]<<arrayVariance[1]<<arrayVariance[2];
//            qDebug()<<arrayAverage[0]<<arrayAverage[1]<<arrayAverage[2];
//            qDebug()<<"varianza1: "<<QColor(varianceOne).red()<<QColor(varianceOne).green()<<QColor(varianceOne).blue();
//            qDebug()<<"varianza2: "<<QColor(varianceTwo).red()<<QColor(varianceTwo).green()<<QColor(varianceTwo).blue();
//            qDebug()<<"varianza3: "<<QColor(varianceThree).red()<<QColor(varianceThree).green()<<QColor(varianceThree).blue();

//            qDebug()<<"Minimo: "<<minVariace;
//            qDebug()<<"Promedio: "<<arrayAverage[index];
//            qDebug()<<"Suma  "<<rOne<<gOne<<bOne;
//            qDebug()<<endl;



            result.setPixelColor(i,j,arrayAverage[index]);
        }
    }
    return result;
}
#endif // FILTERMINMEDMAX_H
