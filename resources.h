#ifndef RESOURCES_H
#define RESOURCES_H

#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"

#define lengthArray(x) (sizeof(x)/sizeof(x[0]))

using namespace QtCharts;


// Por defecto el histograma muestra el channel rojo
int selectChannelHistograma = 0;

/*
 * Funcion para renderizar las imagenes procesadas en miniatura
 */
void MainWindow::render_Miniature_Image()
{
    ui->before->setPixmap(QPixmap::fromImage(imageT));
    ui->r->setPixmap(QPixmap::fromImage(imageR));
    ui->g->setPixmap(QPixmap::fromImage(imageG));
    ui->b->setPixmap(QPixmap::fromImage(imageB));
}
/*
 * Funcion para mostrar los textos de la interfaz en zonas como convert y filter, dependiendo
 * del tipo de formato de imagen a procesar
 */
void MainWindow::show_Text_UI(QString r, QString g, QString b)
{
    // Seteo el valor de los btn
    ui->btn_transform->setText("CHANNEL " + r + g + b);
    ui->btn_one->setText("CHANNEL " + r);
    ui->btn_two->setText("CHANNEL " + g);
    ui->btn_three->setText("CHANNEL " + b);

    // Setear el texto de los filtros
    ui->actionTransform->setText("Filter to " + r + g + b);
    ui->actionChannel_One->setText("Filter to " + r);
    ui->actionChannel_Two->setText("Filter to " + g);
    ui->actionChannel_Three->setText("Filter to " + b);
}

// Limpiar el archivo txt de espacios y rotuladores
QString firstLineFilterTxt;

QStringList cleanMatriz(QString text){

    QStringList list = text.split("\r\n");
    QStringList cleanList;
    firstLineFilterTxt = list[0];

    for(int i = 1; i < list.length(); i++)
    {
        cleanList.append(list[i].split(' '));
    }

    return cleanList;
}

void MainWindow::action_Filter_Select(QImage image)
{
    // Si selecciona el filtro promedio, llama a la funcion para transformar imageT
    if(sizeList >= 0 && selectFilter == 0)
    {
        createMatriz(listAverage);
        ui->origin->setPixmap(QPixmap::fromImage(filterAverageAndGaussiano(image, 3, "average")));
    }
    // Si selecciona el filtro gaussiano, llama a la funcion para transformar imageT
    if(sizeList >= 0 && selectFilter == 1)
    {
        createMatriz(listGaussiano);
        ui->origin->setPixmap(QPixmap::fromImage(filterAverageAndGaussiano(image, 3, "gaussiano")));
    }
    // Si selecciona el filtro minimo, llama a la función para transformar imageT
    if(sizeList >= 0 && selectFilter == 2)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(image, 0)));
    }
    // Si selecciona el filtro mediano, llama a la función para transformar imageT
    if(sizeList >= 0 && selectFilter == 3)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(image, 1)));
    }
    // Si selecciona el filtro maximo, llama a la función para transformar imageT
    if(sizeList >= 0 && selectFilter == 4)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterMinMedMax(image, 2)));
    }
    if(sizeList >= 0 && selectFilter == 5)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterSigma(image,numberSigma)));
    }
    if(sizeList >= 0 && selectFilter == 6)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterNagao(image)));
    }
    /* Diferentes opciones de kernel por si el usuario llega a cargar un kernel diferente,
     * por defecto trabaja con el promedio
     */
    if(selectFilter == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(filterAverageAndGaussiano(image, sizeList, firstLineFilterTxt)));
    }
}

void MainWindow::create_Histograma(QImage image, int channel, bool maximum)
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

    QGraphicsScene *scene = new QGraphicsScene(this);

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


    if (channel == 1)
    {
        series->setName("Red");
        QPen penR(Qt::red);
        QBrush BrushR(Qt::red);
        penR.setWidth(2);
        series->setPen(penR);
        series->setBrush(BrushR);
    }
    if (channel == 2)
    {
        series->setName("Green");
        QPen penG(Qt::green);
        QBrush BrushG(Qt::green);
        penG.setWidth(2);
        series->setPen(penG);
        series->setBrush(BrushG);
    }
    if (channel == 3)
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
    if(maximum)
    {
        chart->createDefaultAxes();
        chart->axisX()->setRange(0, 255);
    }

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    if(maximum)
    {
        chartView->setFixedSize(1000,600);
    }


    scene->addWidget(chartView);

}

void MainWindow::show_Label_Image_Hide_Histograma(int index)
{
    ui->histograma->hide();
    ui->origin->show();
    ui->selectChannelHistograma->setCurrentIndex(index);
}

#endif // RESOURCES_H
