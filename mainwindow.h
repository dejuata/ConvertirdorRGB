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




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionRGB_to_RGB_triggered();

    void on_actionRGB_to_YUV_triggered();


    void on_actionRGB_to_CMY_triggered();

    void on_actionRGB_to_HSV_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
