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
                value = qRgb(y,y,y);
                image.setPixelColor(i,j,value);
            }
            // channel I
            if (channel == 'i')
            {
                value = qRgb(ii,ii,ii);
                image.setPixelColor(i,j,value);
            }
            // channel Q
            if (channel == 'q')
            {
                value = qRgb(q,q,q);
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
            // convierto a formato HSV usando la funcion de QColor toHsv()
//            hsv = QColor(image.pixel(i,j)).toHsv();


            //hsv = QColor(image.pixel(i,j)).convertTo(QColor::Hsv);

            // get pixels
//            r = QColor(image.pixel(i,j)).red();
//            g = QColor(image.pixel(i,j)).green();
//            b = QColor(image.pixel(i,j)).blue();

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
                value = qRgb(h,h,h);
                image.setPixelColor(i,j,value);
            }
            // channel S
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

QImage convertToHSL(QImage image, char channel)
{
    QRgb value;
    double h,s,l;;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // get pixels
//            r = QColor(image.pixel(i,j)).red();
//            g = QColor(image.pixel(i,j)).green();
//            b = QColor(image.pixel(i,j)).blue();

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
                value = qRgb(h,h,h);
                image.setPixelColor(i,j,value);
            }
            // channel S
            if (channel == 's')
            {
                value = qRgb(s,s,s);
                image.setPixelColor(i,j,value);
            }
            // channel L
            if (channel == 'l')
            {
                value = qRgb(l,l,l);
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
                value = qRgb(x,x,x);
                image.setPixelColor(i,j,value);
            }
            // channel Y
            if (channel == 'y')
            {
                value = qRgb(y,y,y);
                image.setPixelColor(i,j,value);
            }
            // channel Z
            if (channel == 'z')
            {
                value = qRgb(z,z,z);
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
                value = qRgb(a,a,a);
                image.setPixelColor(i,j,value);
            }
            // channel O2
            if (channel == 'y')
            {
                value = qRgb(b,b,b);
                image.setPixelColor(i,j,value);
            }
            // channel O3
            if (channel == 'z')
            {
                value = qRgb(c,c,c);
                image.setPixelColor(i,j,value);
            }
        }
    }

    return image;
}




#endif // PROCESS_H
