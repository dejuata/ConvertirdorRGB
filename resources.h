#ifndef RESOURCES_H
#define RESOURCES_H

#include <QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
QStringList cleanMatriz(QString text){

    QStringList list = text.split("\r\n");
    QStringList cleanList;

    for(int i = 0; i < list.length(); i++)
    {
        cleanList.append(list[i].split(' '));
    }

    return cleanList;
}

#endif // RESOURCES_H
