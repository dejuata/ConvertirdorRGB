#ifndef RESOURCES_H
#define RESOURCES_H

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "globals.h"

using namespace QtConcurrent;

// Funcion para limpiar labels cuando se desea cambiar la imagen a procesar
void MainWindow::clear_Label_Miniature_Image()
{
    ui->before->clear();
    ui->r->clear();
    ui->g->clear();
    ui->b->clear();
}

/*
 * Funcion para renderizar las imagenes procesadas en miniatura
 */
void MainWindow::render_Miniature_Image(bool NoGrayscale)
{
    ui->before->setPixmap(QPixmap::fromImage(imageT));

    if(NoGrayscale)
    {
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        ui->btn_one->setEnabled(NoGrayscale);
        ui->btn_two->setEnabled(NoGrayscale);
        ui->btn_three->setEnabled(NoGrayscale);
    }
    else
    {
        ui->r->clear();
        ui->g->clear();
        ui->b->clear();

        ui->btn_one->setEnabled(NoGrayscale);
        ui->btn_two->setEnabled(NoGrayscale);
        ui->btn_three->setEnabled(NoGrayscale);
    }
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

void MainWindow::show_hide_Input_Morphologic(int index)
{
    ui->structure->show();


    if(index == 0)
    {
         ui->structure->hide();
         clean_Input();
    }
    if(index == 1)
    {
        clean_Input();
        ui->e_0_0->hide();ui->e_0_1->hide();ui->e_0_2->hide();ui->e_0_3->hide();ui->e_0_4->hide();
        ui->e_1_0->hide();ui->e_1_4->hide();
        ui->e_2_0->hide();ui->e_2_4->hide();
        ui->e_3_0->hide();ui->e_3_4->hide();
        ui->e_4_0->hide();ui->e_4_1->hide();ui->e_4_2->hide();ui->e_4_3->hide();ui->e_4_4->hide();
    }
    if(index == 2)
    {
        clean_Input();
        ui->e_0_0->show();ui->e_0_1->show();ui->e_0_2->show();ui->e_0_3->show();ui->e_0_4->show();
        ui->e_1_0->show();ui->e_1_4->show();
        ui->e_2_0->show();ui->e_2_4->show();
        ui->e_3_0->show();ui->e_3_4->show();
        ui->e_4_0->show();ui->e_4_1->show();ui->e_4_2->show();ui->e_4_3->show();ui->e_4_4->show();
    }
}
void MainWindow::clean_Input()
{
    ui->e_0_0->clear();ui->e_0_1->clear();ui->e_0_2->clear();ui->e_0_3->clear();ui->e_0_4->clear();
    ui->e_1_0->clear();ui->e_1_1->clear();ui->e_1_2->clear();ui->e_1_3->clear();ui->e_1_4->clear();
    ui->e_2_0->clear();ui->e_2_1->clear();ui->e_2_2->clear();ui->e_2_3->clear();ui->e_2_4->clear();
    ui->e_3_0->clear();ui->e_3_1->clear();ui->e_3_2->clear();ui->e_3_3->clear();ui->e_3_4->clear();
    ui->e_4_0->clear();ui->e_4_1->clear();ui->e_4_2->clear();ui->e_4_3->clear();ui->e_4_4->clear();
}

void MainWindow::show_Structure(QStringList lists)
{
    clean_Input();

    /*if(ui->sizeEstruc->currentIndex() == 0)
    {
        clean_Input();
    }*/
    if(ui->sizeEstruc->currentIndex() == 1)
    {
        ui->e_1_1->insert(lists[0]);ui->e_1_2->insert(lists[1]);ui->e_1_3->insert(lists[2]);
        ui->e_2_1->insert(lists[3]);ui->e_2_2->insert(lists[4]);ui->e_2_3->insert(lists[5]);
        ui->e_3_1->insert(lists[6]);ui->e_3_2->insert(lists[7]);ui->e_3_3->insert(lists[8]);
    }
}


#endif // RESOURCES_H
