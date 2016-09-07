#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"

using namespace std;

QImage image;
//QImage &rgb = image;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setWindowState(Qt::WindowMaximized);


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
        image.save(fileName);
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
        ui->before->setPixmap(QPixmap::fromImage(convertToRGB(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToRGB(image, 'r')));
        ui->g->setPixmap(QPixmap::fromImage(convertToRGB(image, 'g')));
        ui->b->setPixmap(QPixmap::fromImage(convertToRGB(image, 'b')));
        // Seteo el valor de los label
        ui->label_before->setText("CHANNEL RGB");
        ui->label_r->setText("CHANNEL R");
        ui->label_g->setText("CHANNEL G");
        ui->label_b->setText("CHANNEL B");
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
        ui->before->setPixmap(QPixmap::fromImage(convertToYUV(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToYUV(image, 'y')));
        ui->g->setPixmap(QPixmap::fromImage(convertToYUV(image, 'u')));
        ui->b->setPixmap(QPixmap::fromImage(convertToYUV(image, 'v')));
        // Seteo el valor de los label
        ui->label_before->setText("CHANNEL YUV");
        ui->label_r->setText("CHANNEL Y");
        ui->label_g->setText("CHANNEL U");
        ui->label_b->setText("CHANNEL V");
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
        ui->before->setPixmap(QPixmap::fromImage(convertToCMY(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToCMY(image, 'c')));
        ui->g->setPixmap(QPixmap::fromImage(convertToCMY(image, 'm')));
        ui->b->setPixmap(QPixmap::fromImage(convertToCMY(image, 'y')));
        // Seteo el valor de los label
        ui->label_before->setText("CHANNEL CMY");
        ui->label_r->setText("CHANNEL C");
        ui->label_g->setText("CHANNEL M");
        ui->label_b->setText("CHANNEL Y");

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
        ui->before->setPixmap(QPixmap::fromImage(convertToHSV(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToHSV(image, 'h')));
        ui->g->setPixmap(QPixmap::fromImage(convertToHSV(image, 's')));
        ui->b->setPixmap(QPixmap::fromImage(convertToHSV(image, 'v')));
        // Seteo el valor de los label
        ui->label_before->setText("CHANNEL HSV");
        ui->label_r->setText("CHANNEL H");
        ui->label_g->setText("CHANNEL S");
        ui->label_b->setText("CHANNEL V");

    }
}
