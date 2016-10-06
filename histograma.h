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
int histograma[256];

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
    for(int i = 0; i < lengthArray(histograma); i++ )
    {
        histograma[i] = 0;

    }
    // Cuento dependiendo de la posicion del arreglo igual al valor del pixel

    for (int i = 0; i < image.width(); i++)
    {
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
            if (channel == 0)
            {
                histograma[QColor(image.pixel(i,j)).red()] = histograma[QColor(image.pixel(i,j)).red()]++;
                histograma[QColor(image.pixel(i,j)).green()] = histograma[QColor(image.pixel(i,j)).green()]++;
                histograma[QColor(image.pixel(i,j)).blue()] = histograma[QColor(image.pixel(i,j)).blue()]++;
            }
            if (channel == 1)
            {
                histograma[QColor(image.pixel(i,j)).red()] = histograma[QColor(image.pixel(i,j)).red()]++;
            }
            if (channel == 2)
            {
                histograma[QColor(image.pixel(i,j)).green()] = histograma[QColor(image.pixel(i,j)).green()]++;
            }
            if (channel == 3)
            {
                histograma[QColor(image.pixel(i,j)).blue()] = histograma[QColor(image.pixel(i,j)).blue()]++;
            }

        }
    }
    // Hallar el histograma promedio
//    if (channel == 0)
//    {
//        for (int i = 0; i < lengthArray(histograma); i++)
//        {
//            histograma[i] = round(histograma[i]/3);
//        }
//    }
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

    render_Histograma(maximum,color,selectChannel);
}
QImage MainWindow::equalization_Histograma(QImage image, int channel)
{
    double newPixel = 0;
    QImage result = image;
    int size = image.width() * image.height();

    for(int x = 0; x < lengthArray(histograma); x++)
    {
        newPixel = histograma[x];
        newPixel = (newPixel/size)*(255*255);

//        qDebug()<<histograma[x]<<size<<newPixel;

        for (int i = 0; i < image.width(); i++)
        {
            for (int j = 0; j < image.height(); j++)
            {
                if(channel == 1 && QColor(image.pixel(i,j)).red() == x)
                {
                    result.setPixel(i,j,qRgb(newPixel,0,0));
                }
                if(channel == 2 && QColor(image.pixel(i,j)).green() == x)
                {
                    result.setPixel(i,j,qRgb(0,newPixel,0));
                }
                if(channel == 3 && QColor(image.pixel(i,j)).blue() == x)
                {
                    result.setPixel(i,j,qRgb(0,0,newPixel));
                }
            }
        }

    }
    return result;
}

void MainWindow::render_Histograma(bool maximum, QColor color, QString channel)
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
    for(int i = 0; i < lengthArray(histograma); i++ )
    {
        *series0 << QPointF(i, histograma[i]);
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
