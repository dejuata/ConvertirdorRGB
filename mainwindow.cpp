#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"


using namespace std;


QImage image;
QImage imageT;
QImage imageR ;
QImage imageG ;
QImage imageB ;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowState(Qt::WindowMaximized);


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

void MainWindow::on_actionRGB_to_RGB_triggered()
{


    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToRGB(image, 'a');
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToRGB(image, 'r');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToRGB(image, 'g');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToRGB(image, 'b');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL RGB");
        ui->btn_one->setText("CHANNEL R");
        ui->btn_two->setText("CHANNEL G");
        ui->btn_three->setText("CHANNEL B");

//        if (ui->btn_origin->)
//        on_btn_origin_clicked(imageR);



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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToYUV(image, 'y');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToYUV(image, 'u');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToYUV(image, 'v');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL YUV");
        ui->btn_one->setText("CHANNEL Y");
        ui->btn_two->setText("CHANNEL U");
        ui->btn_three->setText("CHANNEL V");

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToYIQ(image, 'y');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToYIQ(image, 'i');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToYIQ(image, 'q');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL YIQ");
        ui->btn_one->setText("CHANNEL Y");
        ui->btn_two->setText("CHANNEL I");
        ui->btn_three->setText("CHANNEL Q");

    }
}

void MainWindow::on_actionRGB_to_CMY_triggered()
{
    if (image.isNull())
    {
        QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
        return;
    }
    else
    {
        // Renderizo imagenes en label
        imageT = convertToCMY(image, 'a');
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToCMY(image, 'c');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToCMY(image, 'm');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToCMY(image, 'y');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL CMY");
        ui->btn_one->setText("CHANNEL C");
        ui->btn_two->setText("CHANNEL M");
        ui->btn_three->setText("CHANNEL Y");

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToHSV(image, 'h');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToHSV(image, 's');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToHSV(image, 'v');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL HSV");
        ui->btn_one->setText("CHANNEL H");
        ui->btn_two->setText("CHANNEL S");
        ui->btn_three->setText("CHANNEL V");

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToHSL(image, 'h');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToHSL(image, 's');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToHSL(image, 'l');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL HSL");
        ui->btn_one->setText("CHANNEL H");
        ui->btn_two->setText("CHANNEL S");
        ui->btn_three->setText("CHANNEL L");

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToXYZ(image, 'x');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToXYZ(image, 'y');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToXYZ(image, 'z');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL XYZ");
        ui->btn_one->setText("CHANNEL X");
        ui->btn_two->setText("CHANNEL Y");
        ui->btn_three->setText("CHANNEL Z");

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToOOO(image, 'x');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToOOO(image, 'y');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToOOO(image, 'z');
        ui->b->setPixmap(QPixmap::fromImage(imageB));

        // Seteo el valor de los btn
        ui->btn_transform->setText("CHANNEL O1O2O3");
        ui->btn_one->setText("CHANNEL O1");
        ui->btn_two->setText("CHANNEL O2");
        ui->btn_three->setText("CHANNEL O3");

    }
}

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












