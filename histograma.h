#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"
#include "math.h"

//#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

using namespace QtCharts;

// Por defecto el histograma muestra un histograma vacio
int selectChannelHistograma = 0;
// Inicializo la variable de la constante para las operaciones del histograma en cero
double numberOperationsHistograma = 0;

// Defino el tamaño del histograma
double histogramaT[256];
int histogramaR[256];
int histogramaG[256];
int histogramaB[256];

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


void MainWindow::create_Histograma(QImage image, int channel, bool maximum)
{
    QString selectChannel;
    QColor color(0,0,0);

    // seteo los valores del arreglo con 0
    for(int i = 0; i < lengthArray(histogramaT); i++ )
    {
        histogramaT[i] = 0, histogramaR[i] = 0, histogramaG[i] = 0, histogramaB[i] = 0;
    }

    // Cuento dependiendo de la posicion del arreglo igual al valor del pixel
    for (int i = 0; i < image.width(); i++)
    {        
        for (int j = 0; j < image.height(); j++)
        {
            histogramaR[QColor(image.pixel(i,j)).red()] = histogramaR[QColor(image.pixel(i,j)).red()]++;
            histogramaG[QColor(image.pixel(i,j)).green()] = histogramaG[QColor(image.pixel(i,j)).green()]++;
            histogramaB[QColor(image.pixel(i,j)).blue()] = histogramaB[QColor(image.pixel(i,j)).blue()]++;
        }
    }

    if(channel == 0)
    {
        selectChannel = "Histograma Promedio";
    }
    if(channel == 1)
    {
        selectChannel = channelR;
        color = selectColorR(channelR);
    }
    if(channel == 2)
    {
        selectChannel = channelG;
        color = selectColorG(channelG);
    }
    if(channel == 3)
    {
        selectChannel = channelB;
        color = selectColorB(channelB);
    }

    render_Histograma(maximum,color,selectChannel,channel);
}

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

void MainWindow::render_Histograma(bool maximum, QColor color, QString channel, int spaceColor)
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

    // recorro el arreglo para enviar los valores a la grafica
    for(int i = 0; i < lengthArray(histogramaT); i++ )
    {
        if(spaceColor == 0)
        {
            histogramaT[i] = (histogramaR[i] + histogramaG[i] + histogramaB[i])/3;
            *series0 << QPointF(i, histogramaT[i]);
        }
        if(spaceColor == 1)
        {
            *series0 << QPointF(i, histogramaR[i]);
        }
        if(spaceColor == 2)
        {
            *series0 << QPointF(i, histogramaG[i]);
        }
        if(spaceColor == 3)
        {
            *series0 << QPointF(i, histogramaB[i]);
        }
    }

    QAreaSeries *series = new QAreaSeries(series0);

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

void MainWindow::show_Label_Image_Hide_Histograma(int index)
{
    ui->histograma->hide();
    ui->origin->show();
    ui->selectChannelHistograma->setCurrentIndex(index);
    render_Histograma_Min_Or_Max(false);
}

void MainWindow::render_Histograma_Min_Or_Max(bool maximum)
{
    if(selectChannelHistograma == 0)
    {
        create_Histograma(imageT, selectChannelHistograma, maximum);
    }
    if(selectChannelHistograma == 1)
    {
        create_Histograma(imageR, selectChannelHistograma, maximum);
    }
    if(selectChannelHistograma == 2)
    {
        create_Histograma(imageG, selectChannelHistograma, maximum);
    }
    if(selectChannelHistograma == 3)
    {
        create_Histograma(imageB, selectChannelHistograma, maximum);
    }
}


// Sumar una constante al histograma
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

QImage gammaConstImage(QImage image, double number, int channel)
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

                r = round(pow(r,1/number)) >= 255 ? 255 : round(pow(r,1/number));
                g = round(pow(g,1/number)) >= 255 ? 255 : round(pow(g,1/number));
                b = round(pow(b,1/number)) >= 255 ? 255 : round(pow(b,1/number));

                image.setPixel(i,j,qRgb(r,g,b));
            }
            if(channel == 1)
            {
                r = QColor(image.pixel(i,j)).red();
                r = round(pow(r,1/number)) >= 255 ? 255 : round(pow(r,1/number));
                image.setPixel(i,j,qRgb(r,0,0));
            }
            if(channel == 2)
            {
                g = QColor(image.pixel(i,j)).green();
                g = round(pow(g,1/number)) >= 255 ? 255 : round(pow(g,1/number));
                image.setPixel(i,j,qRgb(0,g,0));
            }
            if(channel == 3)
            {
                b = QColor(image.pixel(i,j)).blue();
                b = round(pow(b,1/number)) >= 255 ? 255 : round(pow(b,1/number));
                image.setPixel(i,j,qRgb(0,0,b));
            }
        }
    }
    return image;
}

#endif // HISTOGRAMA_H
