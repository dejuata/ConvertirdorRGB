#ifndef RESOURCES_H
#define RESOURCES_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"

using namespace QtConcurrent;

/*
 * Funcion para renderizar las imagenes procesadas en miniatura
 */
void MainWindow::render_Miniature_Image()
{
    ui->before->setPixmap(QPixmap::fromImage(futureT));
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
// Funciones para procesar las conversiones en diferentes hilos
void MainWindow::futureRGB()
{
    futureT = run(convertToRGB,image,'a');
    futureR = run(convertToRGB,image,'r');
    futureG = run(convertToRGB,image,'g');
    futureB = run(convertToRGB,image,'b');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureYYY()
{
    futureT = run(convertToYYY,image);

    imageT = futureT.result();
    imageR = futureT.result();
    imageG = futureT.result();
    imageB = futureT.result();
}
void MainWindow::futureYUV()
{
    futureT = run(convertToYUV,image,'a');
    futureR = run(convertToYUV,image,'y');
    futureG = run(convertToYUV,image,'u');
    futureB = run(convertToYUV,image,'v');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureYIQ()
{
    futureT = run(convertToYIQ,image,'a');
    futureR = run(convertToYIQ,image,'y');
    futureG = run(convertToYIQ,image,'i');
    futureB = run(convertToYIQ,image,'q');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureCMY()
{
    futureT = run(convertToCMY,image,'a');
    futureR = run(convertToCMY,image,'c');
    futureG = run(convertToCMY,image,'m');
    futureB = run(convertToCMY,image,'y');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureHSV()
{
    futureT = run(convertToHSV,image,'a');
    futureR = run(convertToHSV,image,'h');
    futureG = run(convertToHSV,image,'s');
    futureB = run(convertToHSV,image,'v');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureHSL()
{
    futureT = run(convertToHSL,image,'a');
    futureR = run(convertToHSL,image,'h');
    futureG = run(convertToHSL,image,'s');
    futureB = run(convertToHSL,image,'l');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureXYZ()
{
    futureT = run(convertToXYZ,image,'a');
    futureR = run(convertToXYZ,image,'x');
    futureG = run(convertToXYZ,image,'y');
    futureB = run(convertToXYZ,image,'z');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}
void MainWindow::futureOOO()
{
    futureT = run(convertToOOO,image,'a');
    futureR = run(convertToOOO,image,'x');
    futureG = run(convertToOOO,image,'y');
    futureB = run(convertToOOO,image,'z');

    imageT = futureT.result();
    imageR = futureR.result();
    imageG = futureG.result();
    imageB = futureB.result();
}




#endif // RESOURCES_H
