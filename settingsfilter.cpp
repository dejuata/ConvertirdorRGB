//#include "settingsfilter.h"
//#include "ui_settingsfilter.h"
//#include <QDebug>
//#include <QLineEdit>
//#include <QString>
//#include <QFile>
//#include <QFileDialog>
//#include <QTextStream>
//#include <QRegExp>


////int kernelThree [3][3];
////int kernelFive  [5][5];
////int kernelSeven [7][7];
////int kernelNine  [9][9];


//SettingsFilter::SettingsFilter(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::SettingsFilter)
//{
//    ui->setupUi(this);
//    ui->show->hide();
//}

//SettingsFilter::~SettingsFilter()
//{
//    delete ui;
//}



//void SettingsFilter::on_selectFilter_currentIndexChanged(int index)
//{
//    ui->show->show();

//    if(index == 1)
//    {
//        // Oculto los file input
//        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->hide();ui->f_0_4->hide();ui->f_0_5->hide();ui->f_0_6->hide();ui->f_0_7->hide();ui->f_0_8->hide();
//        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->hide();ui->f_1_4->hide();ui->f_1_5->hide();ui->f_1_6->hide();ui->f_1_7->hide();ui->f_1_8->hide();
//        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->hide();ui->f_2_4->hide();ui->f_2_5->hide();ui->f_2_6->hide();ui->f_2_7->hide();ui->f_2_8->hide();
//        ui->f_3_0->hide();ui->f_3_1->hide();ui->f_3_2->hide();ui->f_3_3->hide();ui->f_3_4->hide();ui->f_3_5->hide();ui->f_3_6->hide();ui->f_3_7->hide();ui->f_3_8->hide();
//        ui->f_4_0->hide();ui->f_4_1->hide();ui->f_4_2->hide();ui->f_4_3->hide();ui->f_4_4->hide();ui->f_4_5->hide();ui->f_4_6->hide();ui->f_4_7->hide();ui->f_4_8->hide();
//        ui->f_5_0->hide();ui->f_5_1->hide();ui->f_5_2->hide();ui->f_5_3->hide();ui->f_5_4->hide();ui->f_5_5->hide();ui->f_5_6->hide();ui->f_5_7->hide();ui->f_5_8->hide();
//        ui->f_6_0->hide();ui->f_6_1->hide();ui->f_6_2->hide();ui->f_6_3->hide();ui->f_6_4->hide();ui->f_6_5->hide();ui->f_6_6->hide();ui->f_6_7->hide();ui->f_6_8->hide();
//        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
//        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();

////        for(int i = 0; i < 3; i++)
////        {
////           for(int j = 0; j < 3; j++)
////           {
////                kernelThree[i][j] = ;
////           }
////        }

//    }
//    if(index == 2)
//    {
//        // Muestro los file input
//        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->hide();ui->f_0_6->hide();ui->f_0_7->hide();ui->f_0_8->hide();
//        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->hide();ui->f_1_6->hide();ui->f_1_7->hide();ui->f_1_8->hide();
//        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->hide();ui->f_2_6->hide();ui->f_2_7->hide();ui->f_2_8->hide();
//        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->hide();ui->f_3_6->hide();ui->f_3_7->hide();ui->f_3_8->hide();
//        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->hide();ui->f_4_6->hide();ui->f_4_7->hide();ui->f_4_8->hide();
//        ui->f_5_0->hide();ui->f_5_1->hide();ui->f_5_2->hide();ui->f_5_3->hide();ui->f_5_4->hide();ui->f_5_5->hide();ui->f_5_6->hide();ui->f_5_7->hide();ui->f_5_8->hide();
//        ui->f_6_0->hide();ui->f_6_1->hide();ui->f_6_2->hide();ui->f_6_3->hide();ui->f_6_4->hide();ui->f_6_5->hide();ui->f_6_6->hide();ui->f_6_7->hide();ui->f_6_8->hide();
//        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
//        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();
//    }
//    if(index == 3)
//    {
//        // Muestro los file input
//        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->show();ui->f_0_6->show();ui->f_0_7->hide();ui->f_0_8->hide();
//        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->show();ui->f_1_6->show();ui->f_1_7->hide();ui->f_1_8->hide();
//        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->show();ui->f_2_6->show();ui->f_2_7->hide();ui->f_2_8->hide();
//        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->show();ui->f_3_6->show();ui->f_3_7->hide();ui->f_3_8->hide();
//        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->show();ui->f_4_6->show();ui->f_4_7->hide();ui->f_4_8->hide();
//        ui->f_5_0->show();ui->f_5_1->show();ui->f_5_2->show();ui->f_5_3->show();ui->f_5_4->show();ui->f_5_5->show();ui->f_5_6->show();ui->f_5_7->hide();ui->f_5_8->hide();
//        ui->f_6_0->show();ui->f_6_1->show();ui->f_6_2->show();ui->f_6_3->show();ui->f_6_4->show();ui->f_6_5->show();ui->f_6_6->show();ui->f_6_7->hide();ui->f_6_8->hide();
//        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
//        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();

//    }
//    if(index == 4)
//    {
//        // Oculto los file input
//        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->show();ui->f_0_6->show();ui->f_0_7->show();ui->f_0_8->show();
//        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->show();ui->f_1_6->show();ui->f_1_7->show();ui->f_1_8->show();
//        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->show();ui->f_2_6->show();ui->f_2_7->show();ui->f_2_8->show();
//        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->show();ui->f_3_6->show();ui->f_3_7->show();ui->f_3_8->show();
//        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->show();ui->f_4_6->show();ui->f_4_7->show();ui->f_4_8->show();
//        ui->f_5_0->show();ui->f_5_1->show();ui->f_5_2->show();ui->f_5_3->show();ui->f_5_4->show();ui->f_5_5->show();ui->f_5_6->show();ui->f_5_7->show();ui->f_5_8->show();
//        ui->f_6_0->show();ui->f_6_1->show();ui->f_6_2->show();ui->f_6_3->show();ui->f_6_4->show();ui->f_6_5->show();ui->f_6_6->show();ui->f_6_7->show();ui->f_6_8->show();
//        ui->f_7_0->show();ui->f_7_1->show();ui->f_7_2->show();ui->f_7_3->show();ui->f_7_4->show();ui->f_7_5->show();ui->f_7_6->show();ui->f_7_7->show();ui->f_7_8->show();
//        ui->f_8_0->show();ui->f_8_1->show();ui->f_8_2->show();ui->f_8_3->show();ui->f_8_4->show();ui->f_8_5->show();ui->f_8_6->show();ui->f_8_7->show();ui->f_8_8->show();
//    }
//}

//void SettingsFilter::on_pushButton_clicked()
//{
//    QString text;
//    // cargo el txt con el filtro
//    QFile file = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Image Files (*.txt)"));
//    file.open(QIODevice::ReadOnly);

//    QTextStream result(&file);

//    text = result.readAll();

//    // Limpiar el string
//    QRegExp rx("(\\d+)");
//    QString str = text;
//    QStringList list;

//    int pos = 0;

//    while ((pos = rx.indexIn(str, pos)) != -1) {
//        list << rx.cap(1);
//        pos += rx.matchedLength();
//    }

//    // Asignar a la matriz los valores del string

//    int count = 0;
//    int sizeList = sqrt(list.length());

//    for(int i = 0 ; i < sizeList; i++)
//    {
//        for(int j = 0 ; j < sizeList; j++)
//        {
//            if(sizeList == 3)
//            {
//                kernelThree[i][j] = list[count].toInt();
//            }
//            if(sizeList == 5)
//            {
//                kernelFive[i][j] = list[count].toInt();
//            }
//            if(sizeList == 7)
//            {
//                kernelSeven[i][j] = list[count].toInt();
//            }
//            if(sizeList == 9)
//            {
//                kernelNine[i][j] = list[count].toInt();
//            }

//           count++;
//      }
//    }
////    for(int i = 0 ; i < sqrt(list.length());i++){
////        for(int j = 0 ; j < sqrt(list.length());j++){
////            if(sizeList == 3)
////            {
////                qDebug()<<kernelThree[i][j]<<" ";
////            }
////            if(sizeList == 5)
////            {
////                qDebug()<<kernelFive[i][j]<<" ";
////            }

////        }
////    }

//    file.close();


//}
