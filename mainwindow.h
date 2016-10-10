#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QImage>
#include <QMessageBox>
#include <iostream>
#include <QDebug>
#include <QPixmap>
#include <QColor>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QRegExp>
#include <QGraphicsScene>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QGraphicsView>
#include "convertspacecolor.h"
#include <QFuture>
#include <QtConcurrent>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class ConvertSpaceColor;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QImage image;
    QImage imageT;
    QImage imageR;
    QImage imageG;
    QImage imageB;
    QImage *histograma;

    QString channelR;
    QString channelG;
    QString channelB;

    QChart *chart;
    QGraphicsScene *scene;

    QFuture<QImage> futureT;
    QFuture<QImage> futureR;
    QFuture<QImage> futureG;
    QFuture<QImage> futureB;

    void show_histograma();

    Ui::MainWindow *ui;
    ConvertSpaceColor *convertImage;


private slots:

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionRGB_to_RGB_triggered();

    void on_actionRGB_to_YUV_triggered();

    void on_actionRGB_to_CMY_triggered();

    void on_actionRGB_to_HSV_triggered();

    void on_btn_origin_clicked();

    void on_btn_transform_clicked();

    void on_btn_one_clicked();

    void on_btn_two_clicked();

    void on_btn_three_clicked();

    void on_actionRGB_to_HSL_triggered();

    void on_actionRGB_to_XYZ_triggered();

    void on_actionRGB_to_YIQ_triggered();

    void on_actionRGB_to_O1O2O3_triggered();    

    void on_actionTransform_triggered();

    void on_actionChannel_One_triggered();

    void on_actionChannel_Two_triggered();

    void on_actionChannel_Three_triggered();

    void on_actionSettings_triggered();

    void on_btn_histograma_clicked();

    void on_selectChannelHistograma_currentIndexChanged(int index);    

    void on_equalizarHistograma_clicked();

    void on_btnAverage_clicked();

private:

    void render_Miniature_Image();

    void show_Text_UI(QString r, QString g, QString b);

    void action_Filter_Select(QImage image);

    void create_Histograma(QImage image, int channel, bool maximum);

    void show_Label_Image_Hide_Histograma(int index);

    QImage equalization_Histograma(QImage image, int channel);

    void render_Histograma(bool maximum,  QColor color, QString channel, int spaceColor);

    void render_Histograma_Min_Or_Max(bool maximum);

    void futureOOO();

//    void resizeEvent(QResizeEvent *event);

//    void mouseMoveEvent(QMouseEvent *event);





};

#endif // MAINWINDOW_H
