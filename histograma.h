#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include <algorithm>    // sort
#include <vector>       // vector
#include "math.h"
#include <QtConcurrent>

using namespace QtCharts;

// Defino el tamaño del histograma
double histogramaT[256];
double histogramaR[256];
double histogramaG[256];
double histogramaB[256];

double maximoHistograma = 0;

// Funciones que retorna un color para pintar el histograma dependiendo del canal
QColor selectColorR(QString channel)
{
    QColor color(255,0,0);
    if(channel == "Cyan")color.setRgb(qRgb(0,255,255));
    return color;
}
QColor selectColorG(QString channel)
{
    QColor color(0,255,0);
    if(channel == "Magenta")color.setRgb(qRgb(255,0,255));
    return color;
}
QColor selectColorB(QString channel)
{
    QColor color(0,0,255);
    if(channel == "Yellow")color.setRgb(qRgb(255,255,0));
    return color;
}
// Funcion que setea los valores en cero de los array para cada canal del histograma
void setearHistograma(int channel)
{
    // seteo los valores del arreglo con 0
    for(int i = 0; i < lengthArray(histogramaT); i++ )
    {
        switch(channel)
        {
            case 0: histogramaT[i] = 0;
            break;
            case 1: histogramaR[i] = 0;
            break;
            case 2: histogramaG[i] = 0;
            break;
            case 3: histogramaB[i] = 0;
            break;
            default: histogramaT[i] = 0, histogramaR[i] = 0, histogramaG[i] = 0, histogramaB[i] = 0;
        }
    }
}
// Devuelve el valor maximo del histograma


// Funcion que crea el histograma para los cuatros canales y tambien tiene la
// opcion para crearlo en un canal especifico
int createHistograma(QImage image, int channel)
{
    // Cuento dependiendo de la posicion del arreglo igual al valor del pixel
    for (int i = 0; i < image.width(); i++)
    {
        for (int j = 0; j < image.height(); j++)
        {
            switch(channel)
            {
                case 0:
                {
                    histogramaT[QColor(image.pixel(i,j)).red()] = histogramaT[QColor(image.pixel(i,j)).red()]++;
                    histogramaT[QColor(image.pixel(i,j)).green()] = histogramaT[QColor(image.pixel(i,j)).green()]++;
                    histogramaT[QColor(image.pixel(i,j)).blue()] = histogramaT[QColor(image.pixel(i,j)).blue()]++;
                }
                break;
                case 1:
                {
                    histogramaR[QColor(image.pixel(i,j)).red()] = histogramaR[QColor(image.pixel(i,j)).red()]++;
                }
                break;
                case 2:
                {
                    histogramaG[QColor(image.pixel(i,j)).green()] = histogramaG[QColor(image.pixel(i,j)).green()]++;
                }
                break;
                case 3:
                {
                    histogramaB[QColor(image.pixel(i,j)).blue()] = histogramaB[QColor(image.pixel(i,j)).blue()]++;
                }
                break;
                default:
                {
                    histogramaT[QColor(image.pixel(i,j)).red()] = histogramaT[QColor(image.pixel(i,j)).red()]++;
                    histogramaT[QColor(image.pixel(i,j)).green()] = histogramaT[QColor(image.pixel(i,j)).green()]++;
                    histogramaT[QColor(image.pixel(i,j)).blue()] = histogramaT[QColor(image.pixel(i,j)).blue()]++;
                    histogramaR[QColor(image.pixel(i,j)).red()] = histogramaR[QColor(image.pixel(i,j)).red()]++;
                    histogramaG[QColor(image.pixel(i,j)).green()] = histogramaG[QColor(image.pixel(i,j)).green()]++;
                    histogramaB[QColor(image.pixel(i,j)).blue()] = histogramaB[QColor(image.pixel(i,j)).blue()]++;
                }

            }
        }
    }

    // maximo elemento del histograma
    double maximo = 0;

    // Inicializo los vectores para manipular los pixeles
    vector<double> myvectorT (histogramaT, histogramaT+256);
    vector<double> myvectorR (histogramaR, histogramaR+256);
    vector<double> myvectorG (histogramaG, histogramaG+256);
    vector<double> myvectorB (histogramaB, histogramaB+256);

    switch(channel)
    {
        case 0:
        {
            sort (myvectorT.begin(), myvectorT.begin()+256);
            maximo = myvectorT[0];
        }
        break;
        case 1:
        {
            sort (myvectorR.begin(), myvectorR.begin()+256);
            maximo = myvectorR[0];
        }
        break;
        case 2:
        {
            sort (myvectorG.begin(), myvectorG.begin()+256);
            maximo = myvectorG[0];
        }
        break;
        case 3:
        {
            sort (myvectorB.begin(), myvectorB.begin()+256);
            maximo = myvectorB[0];
        }
        break;
    }

    maximoHistograma = maximo;

    return 0;
}
// Funcion que renderiza el histograma dependiendo del canal
void MainWindow::render_Histograma(bool maximum, QColor color, QString channel, int spaceColor, int otsu)
{
    scene = new QGraphicsScene(this);


    if(maximum)
    {
        ui->histograma->setScene(scene);
    }
    else{
        ui->minHistograma->setScene(scene);
    }

    QLineSeries *series0 = new QLineSeries();
    QLineSeries *seriesOtsu = new QLineSeries();

    if(otsu != 0)
    {
        *seriesOtsu << QPointF(otsu, 1000);
    }

    qDebug()<<maximoHistograma;
    // recorro el arreglo para enviar los valores a la grafica
    for(int i = 0; i < lengthArray(histogramaT); i++ )
    {
        if(spaceColor == 0)*series0 << QPointF(i, histogramaT[i]);

        if(spaceColor == 1)*series0 << QPointF(i, histogramaR[i]);

        if(spaceColor == 2)*series0 << QPointF(i, histogramaG[i]);

        if(spaceColor == 3)*series0 << QPointF(i, histogramaB[i]);
    }

    QAreaSeries *series = new QAreaSeries(series0);
    QAreaSeries *series1 = new QAreaSeries(seriesOtsu);

    if (channel == "Histograma Promedio")
    {
        series->setName(channel);
    }
    else
    {
        series->setName(channel);
    }

    QPen penR(color);
    QBrush BrushR(color);
    penR.setWidth(2);
    series->setPen(penR);
    series->setBrush(BrushR);


    chart = new QChart();
    chart->addSeries(series);
    if(otsu != 0)
    {
        QPen pen(Qt::gray);
        QBrush Brush(Qt::gray);
        pen.setWidth(3);
        series1->setPen(pen);
        series1->setBrush(Brush);

        chart->addSeries(series1);
        chart->legend()->hide();
    }
    chart->legend()->hide();


    if(maximum)
    {
        chart->createDefaultAxes();
        chart->legend()->show();
        chart->setAcceptHoverEvents(true);
        chart->resize(1000,600);        
    }

    scene->addItem(chart);
}
// Funcion para llevar los valores del histograma al rango de 0 a 1
void normalizeHistograma()
{
    double maxR, maxG, maxB;

    // transformo el array a vector
    vector<double> vectorR (histogramaR, histogramaR+256);
    vector<double> vectorG (histogramaG, histogramaG+256);
    vector<double> vectorB (histogramaB, histogramaB+256);

    // Ordeno los vectores para sacar el numero maximo
    sort (vectorR.begin(), vectorR.begin()+256);
    sort (vectorG.begin(), vectorG.begin()+256);
    sort (vectorB.begin(), vectorB.begin()+256);

    // Almaceno los valores maximos para cada canal
    maxR = vectorR[255], maxG = vectorG[255], maxB = vectorB[255];

    for (int i = 0; i < lengthArray(histogramaT); i++)
    {
        histogramaR[i] = histogramaR[i] / maxR;
        histogramaG[i] = histogramaG[i] / maxG;
        histogramaB[i] = histogramaB[i] / maxB;
    }
}
// Funcion que retorna una imagen equalizada dependiendo del canal
QImage MainWindow::equalization_Histograma(QImage image, int channel)
{
    int newR = 0, newG = 0, newB = 0, r = 0, g = 0, b = 0, sumR = 0, sumG = 0, sumB = 0;

    int size = image.width() * image.height();

    int accuHistogramaR[256], accuHistogramaG[256], accuHistogramaB[256];

    QImage result = image;

    // Calcular histograma acumulado
    accuHistogramaR[0] = histogramaR[0];
    accuHistogramaG[0] = histogramaG[0];
    accuHistogramaB[0] = histogramaB[0];


    for(int i = 1; i < lengthArray(histogramaT); i++)
    {
        accuHistogramaR[i] = histogramaR[i] + accuHistogramaR[i-1];
        accuHistogramaG[i] = histogramaG[i] + accuHistogramaG[i-1];
        accuHistogramaB[i] = histogramaB[i] + accuHistogramaB[i-1];
    }

    for(int x = 0; x < lengthArray(histogramaT); x++)
    {

        newR = histogramaR[x], newG = histogramaG[x], newB = histogramaB[x];

        sumR = accuHistogramaR[x], sumG = accuHistogramaG[x], sumB = accuHistogramaB[x];

        newR = (255 * sumR) / size, newG = (255 * sumG) / size, newB = (255 * sumB) / size;

        for (int i = 0; i < image.width(); i++)
        {
            for (int j = 0; j < image.height(); j++)
            {
                if(channel == 0)
                {
                    if(QColor(image.pixel(i,j)).red() == x)
                    {
                        g = QColor(image.pixel(i,j)).green();
                        b = QColor(image.pixel(i,j)).blue();
                        result.setPixel(i,j,qRgb(newR,g,b));
                    }
                    if(QColor(image.pixel(i,j)).green() == x)
                    {
                        r = QColor(result.pixel(i,j)).red();
                        b = QColor(result.pixel(i,j)).blue();
                        result.setPixel(i,j,qRgb(r,newG,b));
                    }
                    if(QColor(image.pixel(i,j)).blue() == x)
                    {
                        r = QColor(result.pixel(i,j)).red();
                        g = QColor(result.pixel(i,j)).green();
                        result.setPixel(i,j,qRgb(r,g,newB));
                    }
                }
                if(channel == 1 && QColor(image.pixel(i,j)).red() == x)
                {
                    result.setPixel(i,j,qRgb(newR,g,b));
                }
                if(channel == 2 && QColor(image.pixel(i,j)).green() == x)
                {
                    result.setPixel(i,j,qRgb(r,newG,b));
                }
                if(channel == 3 && QColor(image.pixel(i,j)).blue() == x)
                {
                    result.setPixel(i,j,qRgb(r,g,newB));
                }


            }
        }

    }
    return result;
}
// Funcion que actua como tercero para renderizar el canal y controla algunos
// datos como el tamaño, el nombre y el color con el cual quiero que se pinte el histograma
void MainWindow::render_Histograma_Min_Or_Max(bool maximum, int spaceColor, int otsu)
{
    QString channel;
    QColor color(0,0,0);

    if(channel == 0)channel = "Histograma Promedio";

    if(spaceColor == 1){channel = channelR;color = selectColorR(channelR);}

    if(spaceColor == 2){channel = channelG;color = selectColorG(channelG);}

    if(spaceColor == 3){channel = channelB;color = selectColorB(channelB);}

    render_Histograma(maximum, color, channel, spaceColor, otsu);
}
// Funcion que se llama cuando se da clic al boton de una image y lo que hace es que oculta
// el QGraphisScene del histograma, muestra el label de la imagen, actualiza el combox de seleccion
// del histograma de la pestaña histograma y pinta un histograma por defecto
void MainWindow::show_Label_Image_Hide_Histograma(int index)
{
    ui->histograma->hide();
    ui->origin->show();
    ui->selectChannelHistograma->setCurrentIndex(index);
    // Llamo este metodo para cuando se haga una transformacion de color
    // por defecto se muestre algo en el histograma miniatura
    render_Histograma_Min_Or_Max(false,index);
}

/************************ Operaciones con histograma *************************/

QImage gammaConstImage(QImage image, double number)
{
    int r,g,b;

    for (int i = 0; i < image.width(); i++)
    {
        for (int j = 0; j < image.height(); j++)
        {

                r = QColor(image.pixel(i,j)).red();
                g = QColor(image.pixel(i,j)).green();
                b = QColor(image.pixel(i,j)).blue();

                r = round(pow(r,number)) >= 255 ? 255 : round(pow(r,number));
                g = round(pow(g,number)) >= 255 ? 255 : round(pow(g,number));
                b = round(pow(b,number)) >= 255 ? 255 : round(pow(b,number));

                image.setPixel(i,j,qRgb(r,g,b));
        }
    }
    return image;
}
QImage sumConstImage(QImage image, double number, int channel)
{
    int r,g,b;

    for (int i = 0; i < image.width(); i++)
    {
        for (int j = 0; j < image.height(); j++)
        {
            if(channel == 0)
            {
                r = QColor(image.pixel(i,j)).red();
                g = QColor(image.pixel(i,j)).green();
                b = QColor(image.pixel(i,j)).blue();

                r = round(r + number) >= 255 ? 255 : round(r + number);
                g = round(g + number) >= 255 ? 255 : round(g + number);
                b = round(b + number) >= 255 ? 255 : round(b + number);                

                image.setPixel(i,j,qRgb(r,g,b));
            }
            if(channel == 1)
            {
                r = QColor(image.pixel(i,j)).red();
                r = round(r + number) >= 255 ? 255 : round(r + number);
                image.setPixel(i,j,qRgb(r,0,0));
            }
            if(channel == 2)
            {
                g = QColor(image.pixel(i,j)).green();
                g = round(g + number) >= 255 ? 255 : round(g + number);
                image.setPixel(i,j,qRgb(0,g,0));
            }
            if(channel == 3)
            {
                b = QColor(image.pixel(i,j)).blue();
                b = round(b + number) >= 255 ? 255 : round(b + number);
                image.setPixel(i,j,qRgb(0,0,b));
            }
        }
    }
    return image;
}
QImage susbtractConstImage(QImage image, double number, int channel)
{
    int r,g,b;

    for (int i = 0; i < image.width(); i++)
    {
        for (int j = 0; j < image.height(); j++)
        {
            if(channel == 0)
            {
                r = QColor(image.pixel(i,j)).red();
                g = QColor(image.pixel(i,j)).green();
                b = QColor(image.pixel(i,j)).blue();

                r = round(r - number) <= 0 ? 0 : round(r - number);
                g = round(g - number) <= 0 ? 0 : round(g - number);
                b = round(b - number) <= 0 ? 0 : round(b - number);

                image.setPixel(i,j,qRgb(r,g,b));
            }
            if(channel == 1)
            {
                r = QColor(image.pixel(i,j)).red();
                r = round(r - number) <= 0 ? 0 : round(r - number);
                image.setPixel(i,j,qRgb(r,0,0));
            }
            if(channel == 2)
            {
                g = QColor(image.pixel(i,j)).green();
                g = round(g - number) <= 0 ? 0 : round(g - number);
                image.setPixel(i,j,qRgb(0,g,0));
            }
            if(channel == 3)
            {
                b = QColor(image.pixel(i,j)).blue();
                b = round(b - number) <= 0 ? 0 : round(b - number);
                image.setPixel(i,j,qRgb(0,0,b));
            }
        }
    }
    return image;
}

#endif // HISTOGRAMA_H
