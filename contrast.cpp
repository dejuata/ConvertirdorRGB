#include "contrast.h"
#include "ui_contrast.h"
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
           histograma[QColor(image.pixel(i,j)).red()] = histograma[QColor(image.pixel(i,j)).red()]++;
        }
    }

    scene = new QGraphicsScene(this);
    ui->render->setScene(scene);

    QLineSeries *series0 = new QLineSeries();

    // recorro el arreglo para enviar los valores a la grafica
    for(int i = 0; i < lengthArray(histograma); i++ )
    {
        *series0 << QPointF(i, histograma[i]);
    }

    QAreaSeries *series = new QAreaSeries(series0);
    series->setName("Red");
    QPen pen(Qt::red);
    pen.setWidth(2);
    series->setPen(pen);

    QBrush redBrush(Qt::red);

    series->setBrush(redBrush);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axisX()->setRange(0, 255);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setFixedSize(550,350);


    scene->addWidget(chartView);

}

Contrast::~Contrast()
{
    delete ui;
}
