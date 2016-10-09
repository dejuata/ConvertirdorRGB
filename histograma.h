#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"
#include "math.h"

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

using namespace QtCharts;

// Por defecto el histograma muestra un histograma vacio
int selectChannelHistograma = 0;
// Defino el tamaño del histograma
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
    for(int i = 0; i < lengthArray(histogramaR); i++ )
    {
        histogramaR[i] = 0;
        histogramaG[i] = 0;
        histogramaB[i] = 0;
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
QImage MainWindow::equalization_Histograma(QImage image)
{
    int newR = 0, newG = 0, newB = 0, r = 0, g = 0, b = 0, sumR = 0, sumG = 0, sumB = 0;

    int size = image.width() * image.height();

    int accuHistogramaR[256];
    int accuHistogramaG[256];
    int accuHistogramaB[256];

    QImage result = image;

    // Calcular histograma acumulado
    accuHistogramaR[0] = histogramaR[0];
    accuHistogramaG[0] = histogramaG[0];
    accuHistogramaB[0] = histogramaB[0];

    for(int i = 1; i < lengthArray(histogramaR); i++)
    {
        accuHistogramaR[i] = histogramaR[i] + accuHistogramaR[i-1];
        accuHistogramaG[i] = histogramaG[i] + accuHistogramaG[i-1];
        accuHistogramaB[i] = histogramaB[i] + accuHistogramaB[i-1];
    }

    for(int x = 0; x < lengthArray(histogramaR); x++)
    {
        newR = histogramaR[x];
        newG = histogramaG[x];
        newB = histogramaB[x];

        sumR = accuHistogramaR[x];
        sumG = accuHistogramaG[x];
        sumB = accuHistogramaB[x];

        newR = (255 * sumR) / size;
        newG = (255 * sumG) / size;
        newB = (255 * sumB) / size;

        for (int i = 0; i < image.width(); i++)
        {
            for (int j = 0; j < image.height(); j++)
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
    for(int i = 0; i < lengthArray(histogramaR); i++ )
    {
        if(spaceColor == 0)
        {
            *series0 << QPointF(i, histogramaR[i]) << QPointF(i, histogramaG[i]) << QPointF(i, histogramaB[i]) ;
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
}

#endif // HISTOGRAMA_H
