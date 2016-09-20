#include "settingsfilter.h"
#include "ui_settingsfilter.h"
#include "globals.h"


SettingsFilter::SettingsFilter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsFilter)
{
    ui->setupUi(this);
    ui->show->hide();
    ui->loaded->hide();
    qDebug()<<demo;
}

SettingsFilter::~SettingsFilter()
{
    delete ui;
}

void SettingsFilter::on_selectFilter_currentIndexChanged(int index)
{
    ui->show->show();




    if(index == 1)
    {
        // Oculto los file input
        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->hide();ui->f_0_4->hide();ui->f_0_5->hide();ui->f_0_6->hide();ui->f_0_7->hide();ui->f_0_8->hide();
        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->hide();ui->f_1_4->hide();ui->f_1_5->hide();ui->f_1_6->hide();ui->f_1_7->hide();ui->f_1_8->hide();
        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->hide();ui->f_2_4->hide();ui->f_2_5->hide();ui->f_2_6->hide();ui->f_2_7->hide();ui->f_2_8->hide();
        ui->f_3_0->hide();ui->f_3_1->hide();ui->f_3_2->hide();ui->f_3_3->hide();ui->f_3_4->hide();ui->f_3_5->hide();ui->f_3_6->hide();ui->f_3_7->hide();ui->f_3_8->hide();
        ui->f_4_0->hide();ui->f_4_1->hide();ui->f_4_2->hide();ui->f_4_3->hide();ui->f_4_4->hide();ui->f_4_5->hide();ui->f_4_6->hide();ui->f_4_7->hide();ui->f_4_8->hide();
        ui->f_5_0->hide();ui->f_5_1->hide();ui->f_5_2->hide();ui->f_5_3->hide();ui->f_5_4->hide();ui->f_5_5->hide();ui->f_5_6->hide();ui->f_5_7->hide();ui->f_5_8->hide();
        ui->f_6_0->hide();ui->f_6_1->hide();ui->f_6_2->hide();ui->f_6_3->hide();ui->f_6_4->hide();ui->f_6_5->hide();ui->f_6_6->hide();ui->f_6_7->hide();ui->f_6_8->hide();
        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();

    }
    if(index == 2)
    {
        // Muestro los file input
        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->hide();ui->f_0_6->hide();ui->f_0_7->hide();ui->f_0_8->hide();
        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->hide();ui->f_1_6->hide();ui->f_1_7->hide();ui->f_1_8->hide();
        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->hide();ui->f_2_6->hide();ui->f_2_7->hide();ui->f_2_8->hide();
        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->hide();ui->f_3_6->hide();ui->f_3_7->hide();ui->f_3_8->hide();
        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->hide();ui->f_4_6->hide();ui->f_4_7->hide();ui->f_4_8->hide();
        ui->f_5_0->hide();ui->f_5_1->hide();ui->f_5_2->hide();ui->f_5_3->hide();ui->f_5_4->hide();ui->f_5_5->hide();ui->f_5_6->hide();ui->f_5_7->hide();ui->f_5_8->hide();
        ui->f_6_0->hide();ui->f_6_1->hide();ui->f_6_2->hide();ui->f_6_3->hide();ui->f_6_4->hide();ui->f_6_5->hide();ui->f_6_6->hide();ui->f_6_7->hide();ui->f_6_8->hide();
        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();
    }
    if(index == 3)
    {
        // Muestro los file input
        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->show();ui->f_0_6->show();ui->f_0_7->hide();ui->f_0_8->hide();
        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->show();ui->f_1_6->show();ui->f_1_7->hide();ui->f_1_8->hide();
        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->show();ui->f_2_6->show();ui->f_2_7->hide();ui->f_2_8->hide();
        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->show();ui->f_3_6->show();ui->f_3_7->hide();ui->f_3_8->hide();
        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->show();ui->f_4_6->show();ui->f_4_7->hide();ui->f_4_8->hide();
        ui->f_5_0->show();ui->f_5_1->show();ui->f_5_2->show();ui->f_5_3->show();ui->f_5_4->show();ui->f_5_5->show();ui->f_5_6->show();ui->f_5_7->hide();ui->f_5_8->hide();
        ui->f_6_0->show();ui->f_6_1->show();ui->f_6_2->show();ui->f_6_3->show();ui->f_6_4->show();ui->f_6_5->show();ui->f_6_6->show();ui->f_6_7->hide();ui->f_6_8->hide();
        ui->f_7_0->hide();ui->f_7_1->hide();ui->f_7_2->hide();ui->f_7_3->hide();ui->f_7_4->hide();ui->f_7_5->hide();ui->f_7_6->hide();ui->f_7_7->hide();ui->f_7_8->hide();
        ui->f_8_0->hide();ui->f_8_1->hide();ui->f_8_2->hide();ui->f_8_3->hide();ui->f_8_4->hide();ui->f_8_5->hide();ui->f_8_6->hide();ui->f_8_7->hide();ui->f_8_8->hide();

    }
    if(index == 4)
    {
        // Oculto los file input
        ui->f_0_0->show();ui->f_0_1->show();ui->f_0_2->show();ui->f_0_3->show();ui->f_0_4->show();ui->f_0_5->show();ui->f_0_6->show();ui->f_0_7->show();ui->f_0_8->show();
        ui->f_1_0->show();ui->f_1_1->show();ui->f_1_2->show();ui->f_1_3->show();ui->f_1_4->show();ui->f_1_5->show();ui->f_1_6->show();ui->f_1_7->show();ui->f_1_8->show();
        ui->f_2_0->show();ui->f_2_1->show();ui->f_2_2->show();ui->f_2_3->show();ui->f_2_4->show();ui->f_2_5->show();ui->f_2_6->show();ui->f_2_7->show();ui->f_2_8->show();
        ui->f_3_0->show();ui->f_3_1->show();ui->f_3_2->show();ui->f_3_3->show();ui->f_3_4->show();ui->f_3_5->show();ui->f_3_6->show();ui->f_3_7->show();ui->f_3_8->show();
        ui->f_4_0->show();ui->f_4_1->show();ui->f_4_2->show();ui->f_4_3->show();ui->f_4_4->show();ui->f_4_5->show();ui->f_4_6->show();ui->f_4_7->show();ui->f_4_8->show();
        ui->f_5_0->show();ui->f_5_1->show();ui->f_5_2->show();ui->f_5_3->show();ui->f_5_4->show();ui->f_5_5->show();ui->f_5_6->show();ui->f_5_7->show();ui->f_5_8->show();
        ui->f_6_0->show();ui->f_6_1->show();ui->f_6_2->show();ui->f_6_3->show();ui->f_6_4->show();ui->f_6_5->show();ui->f_6_6->show();ui->f_6_7->show();ui->f_6_8->show();
        ui->f_7_0->show();ui->f_7_1->show();ui->f_7_2->show();ui->f_7_3->show();ui->f_7_4->show();ui->f_7_5->show();ui->f_7_6->show();ui->f_7_7->show();ui->f_7_8->show();
        ui->f_8_0->show();ui->f_8_1->show();ui->f_8_2->show();ui->f_8_3->show();ui->f_8_4->show();ui->f_8_5->show();ui->f_8_6->show();ui->f_8_7->show();ui->f_8_8->show();
    }
}

void SettingsFilter::show_value_kernel(QStringList lists, int value)
{
    ui->f_0_0->clear();ui->f_0_1->clear();ui->f_0_2->clear();ui->f_0_3->clear();ui->f_0_4->clear();ui->f_0_5->clear();ui->f_0_6->clear();ui->f_0_7->clear();ui->f_0_8->clear();
    ui->f_1_0->clear();ui->f_1_1->clear();ui->f_1_2->clear();ui->f_1_3->clear();ui->f_1_4->clear();ui->f_1_5->clear();ui->f_1_6->clear();ui->f_1_7->clear();ui->f_1_8->clear();
    ui->f_2_0->clear();ui->f_2_1->clear();ui->f_2_2->clear();ui->f_2_3->clear();ui->f_2_4->clear();ui->f_2_5->clear();ui->f_2_6->clear();ui->f_2_7->clear();ui->f_2_8->clear();
    ui->f_3_0->clear();ui->f_3_1->clear();ui->f_3_2->clear();ui->f_3_3->clear();ui->f_3_4->clear();ui->f_3_5->clear();ui->f_3_6->clear();ui->f_3_7->clear();ui->f_3_8->clear();
    ui->f_4_0->clear();ui->f_4_1->clear();ui->f_4_2->clear();ui->f_4_3->clear();ui->f_4_4->clear();ui->f_4_5->clear();ui->f_4_6->clear();ui->f_4_7->clear();ui->f_4_8->clear();
    ui->f_5_0->clear();ui->f_5_1->clear();ui->f_5_2->clear();ui->f_5_3->clear();ui->f_5_4->clear();ui->f_5_5->clear();ui->f_5_6->clear();ui->f_5_7->clear();ui->f_5_8->clear();
    ui->f_6_0->clear();ui->f_6_1->clear();ui->f_6_2->clear();ui->f_6_3->clear();ui->f_6_4->clear();ui->f_6_5->clear();ui->f_6_6->clear();ui->f_6_7->clear();ui->f_6_8->clear();
    ui->f_7_0->clear();ui->f_7_1->clear();ui->f_7_2->clear();ui->f_7_3->clear();ui->f_7_4->clear();ui->f_7_5->clear();ui->f_7_6->clear();ui->f_7_7->clear();ui->f_7_8->clear();
    ui->f_8_0->clear();ui->f_8_1->clear();ui->f_8_2->clear();ui->f_8_3->clear();ui->f_8_4->clear();ui->f_8_5->clear();ui->f_8_6->clear();ui->f_8_7->clear();ui->f_8_8->clear();



    if(value == 1)
    {
        ui->f_0_0->insert(lists[0]);ui->f_0_1->insert(lists[1]);ui->f_0_2->insert(lists[2]);
        ui->f_1_0->insert(lists[3]);ui->f_1_1->insert(lists[4]);ui->f_1_2->insert(lists[5]);
        ui->f_2_0->insert(lists[6]);ui->f_2_1->insert(lists[7]);ui->f_2_2->insert(lists[8]);
    }
    if(value == 2)
    {
        ui->f_0_0->insert(lists[0]);ui->f_0_1->insert(lists[1]);ui->f_0_2->insert(lists[2]);ui->f_0_3->insert(lists[3]);ui->f_0_4->insert(lists[4]);
        ui->f_1_0->insert(lists[5]);ui->f_1_1->insert(lists[6]);ui->f_1_2->insert(lists[7]);ui->f_1_3->insert(lists[8]);ui->f_1_4->insert(lists[9]);
        ui->f_2_0->insert(lists[10]);ui->f_2_1->insert(lists[11]);ui->f_2_2->insert(lists[12]);ui->f_2_3->insert(lists[13]);ui->f_2_4->insert(lists[14]);
        ui->f_3_0->insert(lists[15]);ui->f_3_1->insert(lists[16]);ui->f_3_2->insert(lists[17]);ui->f_3_3->insert(lists[18]);ui->f_3_4->insert(lists[19]);
        ui->f_4_0->insert(lists[20]);ui->f_4_1->insert(lists[21]);ui->f_4_2->insert(lists[22]);ui->f_4_3->insert(lists[23]);ui->f_4_4->insert(lists[24]);
    }
    if(value == 3)
    {
        ui->f_0_0->insert(lists[0]);ui->f_0_1->insert(lists[1]);ui->f_0_2->insert(lists[2]);ui->f_0_3->insert(lists[3]);ui->f_0_4->insert(lists[4]);ui->f_0_5->insert(lists[5]);ui->f_0_6->insert(lists[6]);
        ui->f_1_0->insert(lists[7]);ui->f_1_1->insert(lists[8]);ui->f_1_2->insert(lists[9]);ui->f_1_3->insert(lists[10]);ui->f_1_4->insert(lists[11]);ui->f_1_5->insert(lists[12]);ui->f_1_6->insert(lists[13]);
        ui->f_2_0->insert(lists[14]);ui->f_2_1->insert(lists[15]);ui->f_2_2->insert(lists[16]);ui->f_2_3->insert(lists[17]);ui->f_2_4->insert(lists[18]);ui->f_2_5->insert(lists[19]);ui->f_2_6->insert(lists[20]);
        ui->f_3_0->insert(lists[21]);ui->f_3_1->insert(lists[22]);ui->f_3_2->insert(lists[23]);ui->f_3_3->insert(lists[24]);ui->f_3_4->insert(lists[25]);ui->f_3_5->insert(lists[26]);ui->f_3_6->insert(lists[27]);
        ui->f_4_0->insert(lists[28]);ui->f_4_1->insert(lists[29]);ui->f_4_2->insert(lists[30]);ui->f_4_3->insert(lists[31]);ui->f_4_4->insert(lists[32]);ui->f_4_5->insert(lists[33]);ui->f_4_6->insert(lists[34]);
        ui->f_5_0->insert(lists[35]);ui->f_5_1->insert(lists[36]);ui->f_5_2->insert(lists[37]);ui->f_5_3->insert(lists[38]);ui->f_5_4->insert(lists[39]);ui->f_5_5->insert(lists[40]);ui->f_5_6->insert(lists[41]);
        ui->f_6_0->insert(lists[42]);ui->f_6_1->insert(lists[43]);ui->f_6_2->insert(lists[44]);ui->f_6_3->insert(lists[45]);ui->f_6_4->insert(lists[46]);ui->f_6_5->insert(lists[47]);ui->f_6_6->insert(lists[48]);
    }
    if(value == 4)
    {
        ui->f_0_0->insert(lists[0]);ui->f_0_1->insert(lists[1]);ui->f_0_2->insert(lists[2]);ui->f_0_3->insert(lists[3]);ui->f_0_4->insert(lists[4]);ui->f_0_5->insert(lists[5]);ui->f_0_6->insert(lists[6]);ui->f_0_7->insert(lists[7]);ui->f_0_8->insert(lists[8]);
        ui->f_1_0->insert(lists[9]);ui->f_1_1->insert(lists[10]);ui->f_1_2->insert(lists[11]);ui->f_1_3->insert(lists[12]);ui->f_1_4->insert(lists[13]);ui->f_1_5->insert(lists[14]);ui->f_1_6->insert(lists[15]);ui->f_1_7->insert(lists[16]);ui->f_1_8->insert(lists[17]);
        ui->f_2_0->insert(lists[18]);ui->f_2_1->insert(lists[19]);ui->f_2_2->insert(lists[20]);ui->f_2_3->insert(lists[21]);ui->f_2_4->insert(lists[22]);ui->f_2_5->insert(lists[23]);ui->f_2_6->insert(lists[24]);ui->f_2_7->insert(lists[25]);ui->f_2_8->insert(lists[26]);
        ui->f_3_0->insert(lists[27]);ui->f_3_1->insert(lists[28]);ui->f_3_2->insert(lists[29]);ui->f_3_3->insert(lists[30]);ui->f_3_4->insert(lists[31]);ui->f_3_5->insert(lists[32]);ui->f_3_6->insert(lists[33]);ui->f_3_7->insert(lists[34]);ui->f_3_8->insert(lists[35]);
        ui->f_4_0->insert(lists[36]);ui->f_4_1->insert(lists[37]);ui->f_4_2->insert(lists[38]);ui->f_4_3->insert(lists[39]);ui->f_4_4->insert(lists[40]);ui->f_4_5->insert(lists[41]);ui->f_4_6->insert(lists[42]);ui->f_4_7->insert(lists[43]);ui->f_4_8->insert(lists[44]);
        ui->f_5_0->insert(lists[45]);ui->f_5_1->insert(lists[46]);ui->f_5_2->insert(lists[47]);ui->f_5_3->insert(lists[48]);ui->f_5_4->insert(lists[49]);ui->f_5_5->insert(lists[50]);ui->f_5_6->insert(lists[51]);ui->f_5_7->insert(lists[52]);ui->f_5_8->insert(lists[53]);
        ui->f_6_0->insert(lists[54]);ui->f_6_1->insert(lists[55]);ui->f_6_2->insert(lists[56]);ui->f_6_3->insert(lists[57]);ui->f_6_4->insert(lists[58]);ui->f_6_5->insert(lists[59]);ui->f_6_6->insert(lists[60]);ui->f_6_7->insert(lists[61]);ui->f_6_8->insert(lists[62]);
        ui->f_7_0->insert(lists[63]);ui->f_7_1->insert(lists[64]);ui->f_7_2->insert(lists[65]);ui->f_7_3->insert(lists[66]);ui->f_7_4->insert(lists[67]);ui->f_7_5->insert(lists[68]);ui->f_7_6->insert(lists[69]);ui->f_7_7->insert(lists[70]);ui->f_7_8->insert(lists[71]);
        ui->f_8_0->insert(lists[72]);ui->f_8_1->insert(lists[73]);ui->f_8_2->insert(lists[74]);ui->f_8_3->insert(lists[75]);ui->f_8_4->insert(lists[76]);ui->f_8_5->insert(lists[77]);ui->f_8_6->insert(lists[78]);ui->f_8_7->insert(lists[79]);ui->f_8_8->insert(lists[80]);
    }
}







