#ifndef PROGRESS_H
#define PROGRESS_H

#include <QDialog>
#include <QImage>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QDebug>

namespace Ui {
class Progress;
}

class Progress : public QDialog
{
    Q_OBJECT

public:
    explicit Progress(QWidget *parent = 0);
    ~Progress();

    QImage imageA;
    QImage imageB;

    void showImageA(QImage image);

    Ui::Progress *ui;

private slots:
    void on_open_clicked();

    void on_calculated_clicked();

private:

    void matrizDeConfusion();
    void matrizDeConfusionTwo();


};

#endif // PROGRESS_H
