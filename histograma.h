#ifndef HISTOGRAMA_H
#define HISTOGRAMA_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QGraphicsScene>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>

using namespace QtCharts;

QGraphicsScene createHistograma(QImage image, char channel)
{
    int histograma[256];

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
            if (channel == 'r')
            {
                histograma[QColor(image.pixel(i,j)).red()] = histograma[QColor(image.pixel(i,j)).red()]++;
            }
            if (channel == 'g')
            {
                histograma[QColor(image.pixel(i,j)).green()] = histograma[QColor(image.pixel(i,j)).green()]++;
            }
            if (channel == 'b')
            {
                histograma[QColor(image.pixel(i,j)).blue()] = histograma[QColor(image.pixel(i,j)).blue()]++;
            }

        }
    }

    QGraphicsScene *scene;

    QLineSeries *series0 = new QLineSeries();

    // recorro el arreglo para enviar los valores a la grafica
    for(int i = 0; i < lengthArray(histograma); i++ )
    {
        *series0 << QPointF(i, histograma[i]);
    }

    QAreaSeries *series = new QAreaSeries(series0);


    if (channel == 'r')
    {
        series->setName("Red");
        QPen penR(Qt::red);
        QBrush BrushR(Qt::red);
        penR.setWidth(2);
        series->setPen(penR);
        series->setBrush(BrushR);
    }
    if (channel == 'g')
    {
        series->setName("Green");
        QPen penG(Qt::green);
        QBrush BrushG(Qt::green);
        penG.setWidth(2);
        series->setPen(penG);
        series->setBrush(BrushG);
    }
    if (channel == 'b')
    {
        series->setName("Blue");
        QPen penB(Qt::blue);
        QBrush BrushB(Qt::blue);
        penB.setWidth(2);
        series->setPen(penB);
        series->setBrush(BrushB);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 255);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//    chartView->AdjustIgnored;
    chartView->setFixedSize(1000,600);

    scene->addWidget(chartView);

    return scene;

}

#endif // HISTOGRAMA_H
