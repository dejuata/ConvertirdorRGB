#ifndef CONTRAST_H
#define CONTRAST_H

#include <QDialog>
#include <QGraphicsScene>
#include <QImage>

namespace Ui {
class Contrast;
}

class Contrast : public QDialog
{
    Q_OBJECT

public:
    explicit Contrast(QWidget *parent = 0);
    ~Contrast();
    Ui::Contrast *ui;

    void createHistograma(QImage image);

    QGraphicsScene *scene;

    int histogramaR[256];
    int histogramaG[256];
    int histogramaB[256];

private:




};

#endif // CONTRAST_H
