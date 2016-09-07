#ifndef PROCESS_H
#define PROCESS_H

#include <QImage>
#include <QColor>
#include <QString>
#include <QDebug>
#include <math.h>


double r,g,b;

QImage convertToRGB(QImage image, char channel='a')
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
                image.invertPixels(QImage::InvertRgb);
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

QImage convertToYUV(QImage image, char channel='a')
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
            u = 0.439 * (b - y);
            v = 0.877 * (r - y);

            if (channel == 'a')
            {
                value = qRgb(y,u,v);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'y')
            {
                value = qRgb(y,y,y);
                image.setPixelColor(i,j,value);
            }
            // channel U
            if (channel == 'u')
            {
                value = qRgb(u,u,u);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'v')
            {
                value = qRgb(v,v,v);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}
// http://www.easyrgb.com/index.php?X=MATH&H=12#text12
// http://www.rapidtables.com/convert/color/rgb-to-cmyk.htm

QImage convertToCMY(QImage image, char channel='a')
{
    QRgb value;
    double c,m,y,k,minone,mintwo, min;


    for(int i = 0; i < image.width(); i++)
    {

        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();
//            const uchar *a = image.constScanLine(j);
//            QColor b = QColor(image.pixelColor(i,j));
//            qDebug()<<a<<" = "<<b;



            // Format CMY
            c = 255 - r;
            m = 255 - g;
            y = 255 - b;


//          QString a = QString::number(r,16).toUpper();
//          QString s = QString::number(g,16).toUpper();
//          QString d = QString::number(b,16).toUpper();
//          QString total = a+s+d;


//            c = QColor(image.pixel(i,j)).cyan();
//            m = QColor(image.pixel(i,j)).magenta();
//            y = QColor(image.pixel(i,j)).yellow();
//            k = QColor(image.pixel(i,j)).black();

            /*
             * Formula
             */
/*
            r = r/255;
            g = g/255;
            b = b/255;


            minone = qMin(r,g);
            mintwo = qMin(g,b);

            if (minone > mintwo)
            {
                min = mintwo;
            }
            else
            {
                min = minone;
            }

            k = 1 - min;

            if((1-min)==0){
                c = 0;
                m = 0;
                y = 0;
            }
            else
            {
                c = (1 - r - k) / 1 - k;
                m = (1 - g - k) / 1 - k;
                y = (1 - b - k) / 1 - k;
            }
            c = round(c * 100);
            m = round(m * 100);
            y = round(y * 100);
            k = round(k * 100);


            if (c<0){c=c*-1;}
            if (m<0){m=m*-1;}
            if (y<0){y=y*-1;}


            qDebug()<<c<<" "<<m<<" "<<y<<" "<<k<<" maximo: "<<min;
*/


            if (channel == 'a')
            {
                value = qRgb(c,m,y);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'c')
            {
                value = qRgb(c,c,c);
                image.setPixelColor(i,j,value);
            }
            // channel U
            if (channel == 'm')
            {
                value = qRgb(m,m,m);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'y')
            {
                value = qRgb(y,y,y);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}

QImage convertToHSV(QImage image, char channel='a')
{
    QRgb value;
    double h,s,v;
    QColor hsv;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // convierto a formato HSV usando la funcion de QColor toHsv()
            hsv = QColor(image.pixel(i,j)).toHsv();


            //hsv = QColor(image.pixel(i,j)).convertTo(QColor::Hsv);

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();
            qDebug()<<r<<" "<<g<<" "<<b;

            // Format HSV
            h = hsv.hue();
            s = hsv.saturation();
            v = hsv.value();
            qDebug()<<h<<" "<<s<<" "<<v;


            if (channel == 'a')
            {
                value = qRgb(h,s,v);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'h')
            {
                value = qRgb(h,h,h);
                image.setPixelColor(i,j,value);
            }
            // channel U
            if (channel == 's')
            {
                value = qRgb(s,s,s);
                image.setPixelColor(i,j,value);
            }
            // channel V
            if (channel == 'v')
            {
                value = qRgb(v,v,v);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}





#endif // PROCESS_H
