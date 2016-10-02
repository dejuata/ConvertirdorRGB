#include "contrast.h"
#include "ui_contrast.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QBarSet>
#include <QDebug>

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

using namespace QtCharts;

Contrast::Contrast(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Contrast)
{
    ui->setupUi(this);
}
void Contrast::createHistograma(QImage image)
{

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
        // Columnas
        for (int j = 0; j < image.height(); j++)
        {
           histogramaR[QColor(image.pixel(i,j)).red()] = histogramaR[QColor(image.pixel(i,j)).red()]++;
           histogramaG[QColor(image.pixel(i,j)).green()] = histogramaG[QColor(image.pixel(i,j)).green()]++;
           histogramaB[QColor(image.pixel(i,j)).blue()] = histogramaB[QColor(image.pixel(i,j)).blue()]++;
        }
    }

    scene = new QGraphicsScene(this);
    ui->render->setScene(scene);


    QLineSeries *seriesR = new QLineSeries();
    QLineSeries *seriesG = new QLineSeries();
    QLineSeries *seriesB = new QLineSeries();

    // recorro el arreglo para enviar los valores a la grafica
    for(int i = 0; i < lengthArray(histogramaR); i++ )
    {
        *seriesR << QPointF(i, histogramaR[i]);
        *seriesG << QPointF(i, histogramaG[i]);
        *seriesB << QPointF(i, histogramaB[i]);
    }

    QAreaSeries *seriesCR = new QAreaSeries(seriesR);
    QAreaSeries *seriesCG = new QAreaSeries(seriesG);
    QAreaSeries *seriesCB = new QAreaSeries(seriesB);

    seriesCR->setName("R");
    seriesCG->setName("G");
    seriesCB->setName("B");

    QPen penR(Qt::red);
    QPen penG(Qt::green);
    QPen penB(Qt::blue);

    penR.setWidth(2);
    penG.setWidth(2);
    penB.setWidth(2);

    seriesCR->setPen(penR);
    seriesCG->setPen(penG);
    seriesCB->setPen(penB);

    seriesCR->setBrush(Qt::red);
    seriesCG->setBrush(Qt::green);
    seriesCB->setBrush(Qt::blue);

    QChart *chart = new QChart();

    chart->addSeries(seriesCR);
    chart->addSeries(seriesCG);
    chart->addSeries(seriesCB);

    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 255);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
//    chartView->setFixedSize(550,350);

    scene->addWidget(chartView);

//    return scene;

}

Contrast::~Contrast()
{
    delete ui;
}
