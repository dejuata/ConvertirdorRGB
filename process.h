#ifndef PROCESS_H
#define PROCESS_H

#include <QImage>
#include <QColor>
#include <QString>
#include <QDebug>
#include <math.h>


double r,g,b;

QImage convertToRGB(QImage image, char channel)
{
    QRgb value;


    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            //.pixel es un metodo ineficaz cuando hay mucho pixeles en la imagen, solucionar esto
            //const uchar *a = image.constScanLine(j);

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();


            // Format RGB
            if (channel == 'a')
            {
                //return image;
//                image.invertPixels(QImage::InvertRgb);
            }
            // channel R
            if (channel == 'r')
            {
                value = qRgb(r,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel G
            if (channel == 'g')
            {
                value = qRgb(0,g,0);
                image.setPixelColor(i,j,value);
            }
            // channel B
            if (channel == 'b')
            {
                value = qRgb(0,0,b);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToYUV(QImage image, char channel)
{
    QRgb value;
    double y,u,v;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels            
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();
            //QPixelFormat::YUV


            // Format YUV
            y = (0.299 * r) + (0.587 * g) + (0.114 * b );
            u = (-0.147 * r) + (-0.289 * g) + (0.436 * b);
            v = (0.615 * r) + (-0.515 * g) + (-0.100 * b);

            if (channel == 'a')
            {
                value = qRgb(y,u,v);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'y')
            {
                value = qRgb(y,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel U
            if (channel == 'u')
            {
                value = qRgb(0,u,0);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'v')
            {
                value = qRgb(0,0,v);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToYIQ(QImage image, char channel)
{
    QRgb value;
    double y,ii,q;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();



            // Format YIQ
            y = (0.299 * r) + (0.587 * g) + (0.114 * b );
            ii = (0.596 * r) - (0.274 * g) - (0.322 * b);
            q = (0.212 * r) - (0.523 * g) + (0.311 * b);

            if (channel == 'a')
            {
                value = qRgb(y,ii,q);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'y')
            {
                value = qRgb(y,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel I
            if (channel == 'i')
            {
                value = qRgb(0,ii,0);
                image.setPixelColor(i,j,value);
            }
            // channel Q
            if (channel == 'q')
            {
                value = qRgb(0,0,q);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}
// http://www.easyrgb.com/index.php?X=MATH&H=12#text12
// http://www.rapidtables.com/convert/color/rgb-to-cmyk.htm

QImage convertToCMY(QImage image, char channel)
{
    QRgb value;
    double c,m,y;


    for(int i = 0; i < image.width(); i++)
    {

        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            // Format CMY
            c = 255 - r;
            m = 255 - g;
            y = 255 - b;

            if (channel == 'a')
            {
                value = qRgb(c,m,y);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'c')
            {
                value = qRgb(0,c,c);
                image.setPixelColor(i,j,value);
            }
            // channel U
            if (channel == 'm')
            {
                value = qRgb(m,0,m);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'y')
            {
                value = qRgb(y,y,0);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToHSV(QImage image, char channel)
{
    QRgb value;
    double h,s,v;
//    QColor hsv;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // Format HSV
            h = QColor(image.pixel(i,j)).hue();
            s = QColor(image.pixel(i,j)).saturation();
            v = QColor(image.pixel(i,j)).value();


            if (channel == 'a')
            {
                value = qRgb(h,s,v);
                image.setPixelColor(i,j,value);
            }
            // channel H
            if (channel == 'h')
            {
                value = qRgb(h,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel S
            if (channel == 's')
            {
                value = qRgb(0,s,0);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'v')
            {
                value = qRgb(0,0,v);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToHSL(QImage image, char channel)
{
    QRgb value;
    double h,s,l;;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // Format HSL
            h = QColor(image.pixel(i,j)).hue();
            s = QColor(image.pixel(i,j)).saturation();
            l = QColor(image.pixel(i,j)).lightness();


            if (channel == 'a')
            {
                value = qRgb(h,s,l);
                image.setPixelColor(i,j,value);
            }
            // channel H
            if (channel == 'h')
            {
                value = qRgb(h,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel S
            if (channel == 's')
            {
                value = qRgb(0,s,0);
                image.setPixelColor(i,j,value);
            }
            // channel L
            if (channel == 'l')
            {
                value = qRgb(0,0,l);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToXYZ(QImage image, char channel)
{
    QRgb value;
    double x,y,z;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            // Format XYZ
            x = (0.431 * r) + (0.342 * g) + (0.178 * b);
            y = (0.222 * r) + (0.707 * g) + (0.071 * b);
            z = (0.020 * r) + (0.130 * g) + (0.939 * b);


            if (channel == 'a')
            {
                value = qRgb(x,y,z);
                image.setPixelColor(i,j,value);
            }
            // channel X
            if (channel == 'x')
            {
                value = qRgb(x,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'y')
            {
                value = qRgb(0,y,0);
                image.setPixelColor(i,j,value);
            }
            // channel Z
            if (channel == 'z')
            {
                value = qRgb(0,0,z);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}
QImage convertToOOO(QImage image, char channel)
{
    QRgb value;
    double x,y,z,l,m,s,a,b,c;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            // Format RGB to XYZ
            x = (0.431 * r) + (0.342 * g) + (0.178 * b);
            y = (0.222 * r) + (0.707 * g) + (0.071 * b);
            z = (0.020 * r) + (0.130 * g) + (0.939 * b);

            // XYZ to LMS
            l = (0.2430 * x) + (0.8560 * y) + (-0.0440 * z);
            m = (-0.3910 * x) + (1.1650 * y) + (0.0870 * z);
            s = (0.0100 * x) + (-0.0080 * y) + (0.5630 * z);

            // O1 O2 O3
            a = (1 * l) + (0 * m) + (0 * s) ;
            b = (-0.59 * l) + (0.80 * m) + (-0.12 * s);
            c = (-0.34 * l) + (-0.11 * m) + (0.93 * s);


            if (channel == 'a')
            {
                value = qRgb(a,b,c);
                image.setPixelColor(i,j,value);
            }
            // channel O1
            if (channel == 'x')
            {
                value = qRgb(a,0,0);
                image.setPixelColor(i,j,value);
            }
            // channel O2
            if (channel == 'y')
            {
                value = qRgb(0,b,0);
                image.setPixelColor(i,j,value);
            }
            // channel O3
            if (channel == 'z')
            {
                value = qRgb(0,0,c);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}




#endif // PROCESS_H
