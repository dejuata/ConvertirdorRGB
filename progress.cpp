#include "progress.h"
#include "ui_progress.h"

Progress::Progress(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Progress)
{
    ui->setupUi(this);
//    ui->info->hide();
}

Progress::~Progress()
{
    delete ui;
}

// cargar imagen a comparar
void Progress::on_open_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp *.tif *.gif)"));

    imageB.load(file);


    if (!file.isEmpty())
    {
        if (!imageB.load(file))
        {
            QMessageBox::critical(this, tr("Error"), tr("Could not open file"));
            return;
        }
    }

    ui->imageB->setPixmap(QPixmap::fromImage(imageB));

}
// mostrar imagen procesada en el label A
void Progress::showImageA(QImage image)
{
    imageA = image;
    ui->imageA->setPixmap(QPixmap::fromImage(imageA));
}
// Vena / Vena
void Progress::matrizDeConfusion()
{
    // procesada
    int sizeA = imageA.width() * imageA.height();
    // prediccion
    int sizeB = imageB.width() * imageB.height();

    double a = 0;
    double b = 0;
    double c = 0;
    double d = 0;

    if(sizeA == sizeB)
    {
        for(int i = 0; i < imageA.width(); i++)
        {
            for(int j = 0; j < imageA.height(); j++)
            {
                // No vena - No vena
                if(imageA.pixel(i,j) == qRgb(0,0,0) && imageB.pixel(i,j) == qRgb(0,0,0))
                {
                    a++;
                }
                // No vena - vena
                if(imageA.pixel(i,j) == qRgb(0,0,0) && imageB.pixel(i,j) == qRgb(255,255,255))
                {
                    b++;
                }
                // vena - No vena
                if(imageA.pixel(i,j) == qRgb(255,255,255) && imageB.pixel(i,j) == qRgb(0,0,0))
                {
                    c++;
                }
                // vena - vena
                if(imageA.pixel(i,j) == qRgb(255,255,255) && imageB.pixel(i,j) == qRgb(255,255,255))
                {
                    d++;
                }
            }
        }
    }

    // Calcular porcentaje
    int pa = a*100 / sizeA;
    int pb = b*100 / sizeA;
    int pc = c*100 / sizeA;
    int pd = d*100 / sizeA;

    ui->a->setText(QString::number(a)+" - "+QString::number(pa)+"%");
    ui->b->setText(QString::number(b)+" - "+QString::number(pb)+"%");
    ui->c->setText(QString::number(c)+" - "+QString::number(pc)+"%");
    ui->d->setText(QString::number(d)+" - "+QString::number(pd)+"%");


    int AC = ((a+d)/(a+b+c+d))*100;

    int TP = (d/(c+d))*100;

    int FP = (b/(a+b))*100;

    int TN = (a/(a+b))*100;

    int FN = (c/(c+d))*100;

    int P = (d/(b+d))*100;

    qDebug()<<P<<(d/b+d)*100;

    ui->ac->setText(QString::number(AC)+"%");
    ui->tp->setText(QString::number(TP)+"%");
    ui->fp->setText(QString::number(FP)+"%");
    ui->tn->setText(QString::number(TN)+"%");
    ui->fn->setText(QString::number(FN)+"%");
    ui->p->setText(QString::number(P)+"%");
}



/******************************Info**********************************/



// inciar el calculo
void Progress::on_calculated_clicked()
{
    matrizDeConfusion();  
}


