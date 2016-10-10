#ifndef CONVERTSPACECOLOR_H
#define CONVERTSPACECOLOR_H

#include <QImage>
#include <QFuture>
#include <QtConcurrent>
#include <math.h>


class ConvertSpaceColor
{
private:

    QImage img;

    QFuture<QImage> ThreadOne;
    QFuture<QImage> ThreadTwo;
    QFuture<QImage> ThreadThree;
    QFuture<QImage> ThreadFor;


public:
    ConvertSpaceColor(QImage image);

    QFuture<QImage> imageToRGB();
    QFuture<QImage> imageToR();
    QFuture<QImage> imageToG();
    QFuture<QImage> imageToB();

    QFuture<QImage> imageToYUV();
    QFuture<QImage> imageToY();
    QFuture<QImage> imageToU();
    QFuture<QImage> imageToV();

    QFuture<QImage> imageToYIQ();
    QFuture<QImage> imageToI();
    QFuture<QImage> imageToQ();

    QFuture<QImage> imageToCMY();
    QFuture<QImage> imageToC();
    QFuture<QImage> imageToM();
    QFuture<QImage> imageTocmY();

    QFuture<QImage> imageToHSV();
    QFuture<QImage> imageToH();
    QFuture<QImage> imageToS();
    QFuture<QImage> imageTohsV();

    QFuture<QImage> imageToHSL();
    QFuture<QImage> imageToL();

    QFuture<QImage> imageToXYZ();
    QFuture<QImage> imageToX();
    QFuture<QImage> imageToxYz();
    QFuture<QImage> imageToZ();

    QFuture<QImage> imageToOOO();
    QFuture<QImage> imageToO1();
    QFuture<QImage> imageToO2();
    QFuture<QImage> imageToO3();


};

#endif // CONVERTSPACECOLOR_H
