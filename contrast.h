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

private:
    QGraphicsScene *scene;

    int histograma[256];

};

#endif // CONTRAST_H
