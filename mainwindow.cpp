#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process.h"
#include "filter.h"

using namespace std;

QImage image;
QImage imageT;
QImage imageR ;
QImage imageG ;
QImage imageB ;

int kernelThree [3][3];
int kernelFive  [5][5];
int kernelSeven [7][7];
int kernelNine  [9][9];
// Almaceno el tamano del kernel, si es 0 trabaja con el kernel default de [3][3]
int sizeList = 0;


int kernel[3][3] = {
                    {1, 1, 1},
                    {1, 1, 1},
                    {1, 1, 1}
                };

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
        ui->before->setPixmap(QPixmap::fromImage(imageT));
        imageR = convertToCMY(image, 'c');
        ui->r->setPixmap(QPixmap::fromImage(imageR));
        imageG = convertToCMY(image, 'm');
        ui->g->setPixmap(QPixmap::fromImage(imageG));
        imageB = convertToCMY(image, 'y');
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



void MainWindow::on_actionTransform_triggered()
{
    if(sizeList == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernel)));
    }
    if(sizeList == 3)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelThree)));
    }
    if(sizeList == 5)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelFive)));
    }
    if(sizeList == 7)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelSeven)));
    }
    if(sizeList == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageT, kernelNine)));
    }
}

void MainWindow::on_actionChannel_One_triggered()
{
    if(sizeList == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernel)));
    }
    if(sizeList == 3)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelThree)));
    }
    if(sizeList == 5)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelFive)));
    }
    if(sizeList == 7)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelSeven)));
    }
    if(sizeList == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageR, kernelNine)));
    }
}

void MainWindow::on_actionChannel_Two_triggered()
{
    if(sizeList == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernel)));
    }
    if(sizeList == 3)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelThree)));
    }
    if(sizeList == 5)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelFive)));
    }
    if(sizeList == 7)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelSeven)));
    }
    if(sizeList == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageG, kernelNine)));
    }
}

void MainWindow::on_actionChannel_Three_triggered()
{
    if(sizeList == 0)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernel)));
    }
    if(sizeList == 3)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelThree)));
    }
    if(sizeList == 5)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelFive)));
    }
    if(sizeList == 7)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelSeven)));
    }
    if(sizeList == 9)
    {
        ui->origin->setPixmap(QPixmap::fromImage(convolucion(imageB, kernelNine)));
    }
}

void MainWindow::on_actionSettings_triggered()
{
//    SettingsFilter *averange = new SettingsFilter(this);
//    averange->setModal(true);

//    averange->show();
}



void MainWindow::on_actionLoad_Filter_triggered()
{
    QString text;
    // cargo el txt con el filtro
    QFile file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.txt)"));
    file.open(QIODevice::ReadOnly);

    QTextStream result(&file);

    text = result.readAll();

    // Limpiar el string
    QRegExp rx("(\\d+)");
    QString str = text;
    QStringList lists;

    int pos = 0;

    while ((pos = rx.indexIn(str, pos)) != -1) {
        lists << rx.cap(1);
        pos += rx.matchedLength();
    }

    // Asignar a la matriz los valores del string

    int count = 0;
    sizeList = sqrt(lists.length());

    for(int i = 0 ; i < sizeList; i++)
    {
        for(int j = 0 ; j < sizeList; j++)
        {
            if(sizeList == 3)
            {
                kernelThree[i][j] = lists[count].toInt();
            }
            if(sizeList == 5)
            {
                kernelFive[i][j] = lists[count].toInt();
            }
            if(sizeList == 7)
            {
                kernelSeven[i][j] = lists[count].toInt();
            }
            if(sizeList == 9)
            {
                kernelNine[i][j] = lists[count].toInt();
            }

           count++;
      }
    }

    qDebug()<<"CARGO FILTRO";

    file.close();
}
