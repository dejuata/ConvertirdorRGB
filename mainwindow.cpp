#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsfilter.h"
#include "ui_settingsfilter.h"

#include "process.h"
#include "filter.h"
#include "resources.h"

using namespace std;

QImage image;
QImage imageT;
QImage imageR ;
QImage imageG ;
QImage imageB ;

QStringList lists;
QString str = "1 1 1 1 1 1 1 1 1";
QString strg = "1 2 1 2 4 2 1 2 1";
QStringList promedio = str.split(' ');
QStringList gauss = strg.split(' ');


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

   // this->setWindowState(Qt::WindowMaximized);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
   QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp)"));

   image.load(file);


   if (!file.isEmpty())
   {
       if (!image.load(file))
       {
           QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
           return;
       }
    }

    ui->after->setPixmap(QPixmap::fromImage(image));
    ui->origin->setPixmap(QPixmap::fromImage(image));    

}

void MainWindow::on_actionSave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Open File"), "", tr("Images (*.png)"));

    if (!fileName.isEmpty())
    {
        if (!image.save(fileName))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
        imageT.save(fileName);
     }
}
/*
 * Metodos que llaman a las funciones de convercion de formatos RGB -> RGB, YUV, YIQ, CMY, HSV, HSL, XYZ, O1O2O3
 */

void MainWindow::on_actionRGB_to_RGB_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label miniatura, ademas las almaceno en variables globales
        // para poderlas renderizar en el label origin ademas de que se puedan enviar como parametros
        // a distintas funciones
        imageT = convertToRGB(image, 'a');
        imageR = convertToRGB(image, 'r');
        imageG = convertToRGB(image, 'g');
        imageB = convertToRGB(image, 'b');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL RGB");
        ui->btn_one->setText("CHANNEL R");
        ui->btn_two->setText("CHANNEL G");
        ui->btn_three->setText("CHANNEL B");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to RGB");
        ui->actionChannel_One->setText("Filter to R");
        ui->actionChannel_Two->setText("Filter to G");
        ui->actionChannel_Three->setText("Filter to B");

    }
}

void MainWindow::on_actionRGB_to_YUV_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label        
        imageT = convertToYUV(image, 'a');
        imageR = convertToYUV(image, 'y');
        imageG = convertToYUV(image, 'u');
        imageB = convertToYUV(image, 'v');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL YUV");
        ui->btn_one->setText("CHANNEL Y");
        ui->btn_two->setText("CHANNEL U");
        ui->btn_three->setText("CHANNEL V");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to YUV");
        ui->actionChannel_One->setText("Filter to Y");
        ui->actionChannel_Two->setText("Filter to U");
        ui->actionChannel_Three->setText("Filter to V");
    }
}

void MainWindow::on_actionRGB_to_YIQ_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToYIQ(image, 'a');
        imageR = convertToYIQ(image, 'y');
        imageG = convertToYIQ(image, 'i');
        imageB = convertToYIQ(image, 'q');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL YIQ");
        ui->btn_one->setText("CHANNEL Y");
        ui->btn_two->setText("CHANNEL I");
        ui->btn_three->setText("CHANNEL Q");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to YIQ");
        ui->actionChannel_One->setText("Filter to Y");
        ui->actionChannel_Two->setText("Filter to I");
        ui->actionChannel_Three->setText("Filter to Q");
    }
}

void MainWindow::on_actionRGB_to_CMY_triggered()
{
    QString cmy,c,m,y;
    cmy = "CHANNEL CMY";
    c = "CHANNEL C";
    m = "CHANNEL M";
    y = "CHANNEL Y";

    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToCMY(image, 'a');
        imageR = convertToCMY(image, 'c');
        imageG = convertToCMY(image, 'm');
        imageB = convertToCMY(image, 'y');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText(cmy);
        ui->btn_one->setText(c);
        ui->btn_two->setText(m);
        ui->btn_three->setText(y);

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to CMY");
        ui->actionChannel_One->setText("Filter to C");
        ui->actionChannel_Two->setText("Filter to M");
        ui->actionChannel_Three->setText("Filter to Y");
    }
}

void MainWindow::on_actionRGB_to_HSV_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToHSV(image, 'a');
        imageR = convertToHSV(image, 'h');
        imageG = convertToHSV(image, 's');
        imageB = convertToHSV(image, 'v');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL HSV");
        ui->btn_one->setText("CHANNEL H");
        ui->btn_two->setText("CHANNEL S");
        ui->btn_three->setText("CHANNEL V");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to HSV");
        ui->actionChannel_One->setText("Filter to H");
        ui->actionChannel_Two->setText("Filter to S");
        ui->actionChannel_Three->setText("Filter to V");
    }
}

void MainWindow::on_actionRGB_to_HSL_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToHSL(image, 'a');
        imageR = convertToHSL(image, 'h');
        imageG = convertToHSL(image, 's');
        imageB = convertToHSL(image, 'l');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL HSL");
        ui->btn_one->setText("CHANNEL H");
        ui->btn_two->setText("CHANNEL S");
        ui->btn_three->setText("CHANNEL L");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to HSL");
        ui->actionChannel_One->setText("Filter to H");
        ui->actionChannel_Two->setText("Filter to S");
        ui->actionChannel_Three->setText("Filter to L");
    }
}

void MainWindow::on_actionRGB_to_XYZ_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToXYZ(image, 'a');
        imageR = convertToXYZ(image, 'x');
        imageG = convertToXYZ(image, 'y');
        imageB = convertToXYZ(image, 'z');

        ui->before->setPixmap(QPixmap::fromImage(imageT));        
        ui->r->setPixmap(QPixmap::fromImage(imageR));        
        ui->g->setPixmap(QPixmap::fromImage(imageG));        
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL XYZ");
        ui->btn_one->setText("CHANNEL X");
        ui->btn_two->setText("CHANNEL Y");
        ui->btn_three->setText("CHANNEL Z");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to XYZ");
        ui->actionChannel_One->setText("Filter to X");
        ui->actionChannel_Two->setText("Filter to Y");
        ui->actionChannel_Three->setText("Filter to Z");
    }
}

void MainWindow::on_actionRGB_to_O1O2O3_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToOOO(image, 'a');
        imageR = convertToOOO(image, 'x');
        imageG = convertToOOO(image, 'y');
        imageB = convertToOOO(image, 'z');

        ui->before->setPixmap(QPixmap::fromImage(imageT));
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL O1O2O3");
        ui->btn_one->setText("CHANNEL O1");
        ui->btn_two->setText("CHANNEL O2");
        ui->btn_three->setText("CHANNEL O3");

        // Setear el texto de los filtros
        ui->actionTransform->setText("Filter to O1O2O3");
        ui->actionChannel_One->setText("Filter to O1");
        ui->actionChannel_Two->setText("Filter to O2");
        ui->actionChannel_Three->setText("Filter to O3");
    }
}

/* ------------------------------------------------------------------------ */

/*
 * Muestro la imagen en el label origin cada vez que se da clic al btn de la miniatura
 */
void MainWindow::on_btn_origin_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::on_btn_transform_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageT));
}

void MainWindow::on_btn_one_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageR));
}

void MainWindow::on_btn_two_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageG));
}

void MainWindow::on_btn_three_clicked()
{
    ui->origin->setPixmap(QPixmap::fromImage(imageB));
}

/* ------------------------------------------------------------------------ */

// Crea y muestra la ventana de configuracion de filtros
void MainWindow::on_actionSettings_triggered()
{
    SettingsFilter *averange = new SettingsFilter(this);
    averange->setModal(true);

    averange->show();
}

// Configuracion de filtros por default
void SettingsFilter::on_comboBox_currentIndexChanged(int index)
{
    if(index == 1)
    {
        // por default trabaja con el kernel promedio
        selectKernel = 0;
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(promedio, 1);
    }
    if(index == 2)
    {
        selectKernel = 1;
        qDebug()<<"Seleccione kernel gaussiano";
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(gauss, 1);
    }
}

// cargar filtros externos en archivos txt
void SettingsFilter::on_pushButton_clicked()
{
    QString text;

    // cargo el txt con el filtro
    QFile file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.txt)"));
    file.open(QIODevice::ReadOnly);

    QTextStream result(&file);

    text = result.readAll();

    // Limpiar el string
    lists = cleanMatriz(text);

    if (lists.length() == 9)
    {
        on_selectFilter_currentIndexChanged(1);
        show_value_kernel(lists, 1);
    }
    if (lists.length() == 25)
    {
        on_selectFilter_currentIndexChanged(2);
        show_value_kernel(lists, 2);
    }
    if (lists.length() == 49)
    {
        on_selectFilter_currentIndexChanged(3);
        show_value_kernel(lists, 3);
    }
    if (lists.length() == 81)
    {
        on_selectFilter_currentIndexChanged(3);
        show_value_kernel(lists, 3);
    }


    qDebug()<<"list: "<<lists;

    // Asignar a la matriz los valores del string
    createMatriz(lists);

    // Asigno este valor para indicar que el programa trabaje con la matriz cargada
    selectKernel = 9;

    ui->loaded->show();

    qDebug()<<"CARGO FILTRO";

    file.close();

}


void MainWindow::on_actionTransform_triggered()
{
    if(sizeList >= 0 && selectKernel == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernel)));
    }
    if(sizeList >= 0 && selectKernel == 1)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelGauss)));
    }
    if(sizeList == 3 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelThree)));
    }
    if(sizeList == 5 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelFive)));
    }
    if(sizeList == 7 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelSeven)));
    }
    if(sizeList == 9 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelNine)));
    }
}

void MainWindow::on_actionChannel_One_triggered()
{
    if(sizeList >= 0 && selectKernel == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernel)));
    }
    if(sizeList >= 0 && selectKernel == 1)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelGauss)));
    }
    if(sizeList == 3 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelThree)));
    }
    if(sizeList == 5 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelFive)));
    }
    if(sizeList == 7 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelSeven)));
    }
    if(sizeList == 9 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelNine)));
    }
}

void MainWindow::on_actionChannel_Two_triggered()
{
    if(sizeList >= 0 && selectKernel == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernel)));
    }
    if(sizeList >= 0 && selectKernel == 1)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelGauss)));
    }
    if(sizeList == 3 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelThree)));
    }
    if(sizeList == 5 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelFive)));
    }
    if(sizeList == 7&& selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelSeven)));
    }
    if(sizeList == 9 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelNine)));
    }
}

void MainWindow::on_actionChannel_Three_triggered()
{
    if(sizeList >= 0 && selectKernel == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernel)));
    }
    if(sizeList >= 0 && selectKernel == 1)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelGauss)));
    }
    if(sizeList == 3 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelThree)));
    }
    if(sizeList == 5 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelFive)));
    }
    if(sizeList == 7 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelSeven)));
    }
    if(sizeList == 9 && selectKernel == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelNine)));
    }
}


