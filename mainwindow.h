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


namespace Ui {
class MainWindow;
}

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

private:
    Ui::MainWindow *ui;

    void render_Miniature_Image();

    void show_Text_UI(QString r, QString g, QString b);

    void action_Filter_Select(QImage image);

};

#endif // MAINWINDOW_H
