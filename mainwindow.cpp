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
        ui->before->setPixmap(QPixmap::fromImage(convertToRGB(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToRGB(image, 'r')));
        ui->g->setPixmap(QPixmap::fromImage(convertToRGB(image, 'g')));
        ui->b->setPixmap(QPixmap::fromImage(convertToRGB(image, 'b')));
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
        ui->before->setPixmap(QPixmap::fromImage(convertToYUV(image)));
        ui->r->setPixmap(QPixmap::fromImage(convertToYUV(image, 'y')));
        ui->g->setPixmap(QPixmap::fromImage(convertToYUV(image, 'u')));
        ui->b->setPixmap(QPixmap::fromImage(convertToYUV(image, 'v')));
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
//        ui->before->setPixmap(QPixmap::fromImage(convertToRGB(image, 2)));
//        ui->r->setPixmap(QPixmap::fromImage(convertToChannels(image, 2, 'c')));
//        ui->g->setPixmap(QPixmap::fromImage(convertToChannels(image, 2, 'm')));
//        ui->b->setPixmap(QPixmap::fromImage(convertToChannels(image, 2, 'y')));

    }
}
