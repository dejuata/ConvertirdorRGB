#ifndef RESOURCES_H
#define RESOURCES_H

#include "mainwindow.h"
#include "ui_mainwindow.h"


// namespace de qtconcurrent para poder usar el metodo run y poder correr procesos en diferentes hilos
using namespace QtConcurrent;

// Resize a la imagen original
QSize resizeImage(int width, int height)
{
    width = width/2;
    height = height/2;

    return QSize(width,height);
}

// Funcion que valida que la imagen cargada no sea nula y si es falso ejecuta una serie de funciones
void MainWindow::convert_Image_To_Space_Color(QString r, QString g, QString b, int spaceColor)
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Variable que almacena el nombre de los canales para poder mostrarlos en el histograma
        channelR = r, channelG = g, channelB = b;
        // Show Message status bar Processing image to
        show_Message_Status_Bar(3);
        // Funcion que selecciona que transformacion de color voy a realizar
        select_Space_Colors_Convert(spaceColor);
        //Funcion que crea el histograma para los cuatro canales
        setearHistograma(4);
        run(createHistograma,imageT,4).result();
        // Funcion que muestra las imagenes convertidas en miniatura
        if(spaceColor == 1){render_Miniature_Image(false);}
        else{render_Miniature_Image(true);}
        // Muestra en el label principal la imagen original por defecto
        ui->origin->setPixmap(QPixmap::fromImage(imageT));
        imageLabel = &imageT;
        channel = 0;
        // Muestra en los botones de las imagenes miniaturas, las iniciales de los espacio de color
        if(spaceColor == 8){show_Text_UI(r.mid(0,2),g.mid(0,2),b.mid(0,2));}
        else{show_Text_UI(r.mid(0,1),g.mid(0,1),b.mid(0,1));}
        // Muestra el histograma promedio por defecto
        show_Label_Image_Hide_Histograma(0);
        // Show Message status bar Ready!
        show_Message_Status_Bar(4);
    }
}
// Funcion para limpiar labels cuando se desea cambiar la imagen a procesar
void MainWindow::clear_Label_Miniature_Image()
{
    ui->before->clear();
    ui->r->clear();
    ui->g->clear();
    ui->b->clear();
}
// funcion para mostra la imagen en el label origin al igual que almacenar las imagenes en el puntero para trabajar con ellas
void MainWindow::show_Image_In_Label(QImage &image, int index)
{
    // Almaceno en un puntero la imagen que selecciona el usuario para poder aplicar las diferentes operaciones
    imageLabel = &image;
    // Almaceno una referencia de que canales trabajo para pasarlo como argumento en algunas funciones
    channel = index;
    // Muestra la imagen en el Label
    ui->origin->setPixmap(QPixmap::fromImage(*imageLabel));
    // Crea y muestra el histograma dependiendo del canal seleccionado
    // 0 -> T / 1 -> R / 2 -> G / 3 -> B
    show_Label_Image_Hide_Histograma(index);
    // Show Message status bar channel RGB
    show_Message_Status_Bar(index+6);
}
// Funcion para renderizar las imagenes procesadas en miniatura
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
// Funcion para mostrar los textos en los btn de la pestaña convert, dependiendo
// del tipo de formato de imagen a procesar
void MainWindow::show_Text_UI(QString r, QString g, QString b)
{
    // Seteo el valor de los btn
    ui->btn_transform->setText("CHANNEL " + r + g + b);
    ui->btn_one->setText("CHANNEL " + r);
    ui->btn_two->setText("CHANNEL " + g);
    ui->btn_three->setText("CHANNEL " + b);   
}
// Funciones para procesar las conversiones en diferentes hilos
void MainWindow::select_Space_Colors_Convert(int index)
{
    switch(index)
    {
        case 0:
        {
            futureT = run(convertToRGB,image,'a');futureR = run(convertToRGB,image,'r');
            futureG = run(convertToRGB,image,'g');futureB = run(convertToRGB,image,'b');
        }
        break;
        case 1:
        {
            futureT = run(convertToYYY,image);futureR = futureT;futureG = futureT;futureB = futureT;
        }
        break;
        case 2:
        {
            futureT = run(convertToYUV,image,'a');futureR = run(convertToYUV,image,'y');
            futureG = run(convertToYUV,image,'u');futureB = run(convertToYUV,image,'v');
        }
        break;
        case 3:
        {
            futureT = run(convertToYIQ,image,'a');futureR = run(convertToYIQ,image,'y');
            futureG = run(convertToYIQ,image,'i');futureB = run(convertToYIQ,image,'q');
        }
        break;
        case 4:
        {
            futureT = run(convertToCMY,image,'a');futureR = run(convertToCMY,image,'c');
            futureG = run(convertToCMY,image,'m');futureB = run(convertToCMY,image,'y');
        }
        break;
        case 5:
        {
            futureT = run(convertToHSV,image,'a');futureR = run(convertToHSV,image,'h');
            futureG = run(convertToHSV,image,'s');futureB = run(convertToHSV,image,'v');
        }
        break;
        case 6:
        {
            futureT = run(convertToHSL,image,'a');futureR = run(convertToHSL,image,'h');
            futureG = run(convertToHSL,image,'s');futureB = run(convertToHSL,image,'l');
        }
        break;
        case 7:
        {
            futureT = run(convertToXYZ,image,'a');futureR = run(convertToXYZ,image,'x');
            futureG = run(convertToXYZ,image,'y');futureB = run(convertToXYZ,image,'z');
        }
        break;
        case 8:
        {
            futureT = run(convertToOOO,image,'a');futureR = run(convertToOOO,image,'x');
            futureG = run(convertToOOO,image,'y');futureB = run(convertToOOO,image,'z');
        }
        break;

        default: qDebug()<< "Usted ha ingresado una opción incorrecta";
    }

    imageT = futureT.result();imageR = futureR.result();imageG = futureG.result();imageB = futureB.result();
}
// Funcion que muestra los input dependiendo del tamaño de kernel que seleccione el usuario 3x3 5x5
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
// Funcion que setea los input de la pestaña de operaciones morfologicas
void MainWindow::clean_Input()
{
    ui->e_0_0->clear();ui->e_0_1->clear();ui->e_0_2->clear();ui->e_0_3->clear();ui->e_0_4->clear();
    ui->e_1_0->clear();ui->e_1_1->clear();ui->e_1_2->clear();ui->e_1_3->clear();ui->e_1_4->clear();
    ui->e_2_0->clear();ui->e_2_1->clear();ui->e_2_2->clear();ui->e_2_3->clear();ui->e_2_4->clear();
    ui->e_3_0->clear();ui->e_3_1->clear();ui->e_3_2->clear();ui->e_3_3->clear();ui->e_3_4->clear();
    ui->e_4_0->clear();ui->e_4_1->clear();ui->e_4_2->clear();ui->e_4_3->clear();ui->e_4_4->clear();
}
// Funcion que inserta en los input de la pestaña de operaciones morfologicas,
// los diferentes kernel que viene por defecto en un lista
void MainWindow::show_Structure(QStringList lists)
{
    clean_Input();

    if(ui->sizeEstruc->currentIndex() == 1)
    {
        ui->e_1_1->insert(lists[0]);ui->e_1_2->insert(lists[1]);ui->e_1_3->insert(lists[2]);
        ui->e_2_1->insert(lists[3]);ui->e_2_2->insert(lists[4]);ui->e_2_3->insert(lists[5]);
        ui->e_3_1->insert(lists[6]);ui->e_3_2->insert(lists[7]);ui->e_3_3->insert(lists[8]);
    }
    if(ui->sizeEstruc->currentIndex() == 2)
    {
       ui->e_0_0->insert(lists[0]);ui->e_0_1->insert(lists[1]);ui->e_0_2->insert(lists[2]);ui->e_0_3->insert(lists[3]);ui->e_0_4->insert(lists[4]);
       ui->e_1_0->insert(lists[5]);ui->e_1_1->insert(lists[6]);ui->e_1_2->insert(lists[7]);ui->e_1_3->insert(lists[8]);ui->e_1_4->insert(lists[9]);
       ui->e_2_0->insert(lists[10]);ui->e_2_1->insert(lists[11]);ui->e_2_2->insert(lists[12]);ui->e_2_3->insert(lists[13]);ui->e_2_4->insert(lists[14]);
       ui->e_3_0->insert(lists[15]);ui->e_3_1->insert(lists[16]);ui->e_3_2->insert(lists[17]);ui->e_3_3->insert(lists[18]);ui->e_3_4->insert(lists[19]);
       ui->e_4_0->insert(lists[20]);ui->e_4_1->insert(lists[21]);ui->e_4_2->insert(lists[22]);ui->e_4_3->insert(lists[23]);ui->e_4_4->insert(lists[24]);
    }
}
// Funcion que muestra los diferentes mensajes en la QStatusBar
void MainWindow::show_Message_Status_Bar(int index)
{
    if(index == 1)ui->statusBar->showMessage(" Image loaded!");
    if(index == 2)ui->statusBar->showMessage(" Image saved!");
    if(index == 3)ui->statusBar->showMessage(" Transforming image to "+channelR.mid(0,1)+channelG.mid(0,1)+channelB.mid(0,1)+"...");
    if(index == 4)ui->statusBar->showMessage(" Ready!");

    if(index == 5)ui->statusBar->showMessage(" Original image selected!");
    if(index == 6)ui->statusBar->showMessage(" Channel "+channelR.mid(0,1)+channelG.mid(0,1)+channelB.mid(0,1)+" selected!");
    if(index == 7)ui->statusBar->showMessage(" Channel "+channelR.mid(0,1)+" selected!");
    if(index == 8)ui->statusBar->showMessage(" Channel "+channelG.mid(0,1)+" selected!");
    if(index == 9)ui->statusBar->showMessage(" Channel "+channelB.mid(0,1)+" selected!");

    if(index == 10)ui->statusBar->showMessage(" Applying filter...");
    if(index == 11)ui->statusBar->showMessage(" Saving...");
    if(index == 12)ui->statusBar->showMessage(" Saved!");
    if(index == 13)ui->statusBar->showMessage(" Calculated threshold...");
    if(index == 14)ui->statusBar->showMessage(" White background selected!");
    if(index == 15)ui->statusBar->showMessage(" Black background selected!");

    if(index == 16)ui->statusBar->showMessage(" Equalizing histogram...");
    if(index == 17)ui->statusBar->showMessage(" Calculated gamma...");
    if(index == 18)ui->statusBar->showMessage(" Applying...");
    if(index == 19)ui->statusBar->showMessage(" Normalizing histogram...");

}

#endif // RESOURCES_H
