#ifndef RESOURCES_H
#define RESOURCES_H

#include <QString>
#include <QFuture>
#include <QtConcurrent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"


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

void MainWindow::futureOOO()
{
    futureT = QtConcurrent::run(convertToOOO1,image,'a');
    futureR = QtConcurrent::run(convertToOOO1,image,'x');
    futureG = QtConcurrent::run(convertToOOO1,image,'y');
    futureB = QtConcurrent::run(convertToOOO1,image,'z');

    imageT = t.result();
    imageR = r.result();
    imageG = g.result();
    imageB = b.result();
}



#endif // RESOURCES_H
