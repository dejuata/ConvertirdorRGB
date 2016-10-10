#include "convertspacecolor.h"

ConvertSpaceColor::ConvertSpaceColor(QImage image)
{
    this->img = image;
}

int channelOne(int r, int g, int b, char channel)
{
    int channelOne;

    // Format YUV || YIQ
    if(channel == 'y')
    {
        channelOne = round((0.299 * r) + (0.587 * g) + (0.114 * b));
    }
    // Format CMY
    if(channel == 'c')
    {
        channelOne = 255 - r;
    }
    // Format XYZ
    if(channel == 'x')
    {
        channelOne = round((0.431 * r) + (0.342 * g) + (0.178 * b));
    }
    return channelOne;
}
int channelTwo(int r, int g, int b, char channel)
{
    int channelTwo;

    // Format YUV
    if(channel == 'u')
    {
        channelTwo = round((-0.147 * r) + (-0.289 * g) + (0.436 * b));
    }
    // Format YIQ
    if(channel == 'i')
    {
        channelTwo = round((0.596 * r) - (0.274 * g) - (0.322 * b));
    }
    // Format CMY
    if(channel == 'm')
    {
        channelTwo = 255 - g;
    }
    // Format XYZ
    if(channel == 'y')
    {
        channelTwo = round((0.222 * r) + (0.707 * g) + (0.071 * b));
    }
    return channelTwo;
}
int channelThree(int r, int g, int b, char channel)
{
    int channelThree;

    // Format YUV
    if(channel == 'v')
    {
        channelThree = round((0.615 * r) + (-0.515 * g) + (-0.100 * b));
    }
    // Format YIQ
    if(channel == 'q')
    {
        channelThree = round((0.212 * r) - (0.523 * g) + (0.311 * b));
    }
    // Format CMY
    if(channel == 'y')
    {
        channelThree = 255 - b;
    }
    // Format XYZ
    if(channel == 'z')
    {
        channelThree = round((0.020 * r) + (0.130 * g) + (0.939 * b));
    }
    return channelThree;
}

// Funciones de conversion a diferentes espacios de color
QImage convertToRGB(QImage image, char channel)
{
    int r,g,b;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            //.pixel es un metodo ineficaz cuando hay mucho pixeles en la imagen, solucionar esto
            //const uchar *a = image.constScanLine(j);

            // Format RGB
            if (channel == 'a')
            {
                return image;
            }
            // channel R
            if (channel == 'r')
            {
                r = QColor(image.pixel(i,j)).red();
                image.setPixelColor(i,j,qRgb(r,0,0));
            }
            // channel G
            if (channel == 'g')
            {
                g = QColor(image.pixel(i,j)).green();
                image.setPixelColor(i,j,qRgb(0,g,0));
            }
            // channel B
            if (channel == 'b')
            {
                b = QColor(image.pixel(i,j)).blue();
                image.setPixelColor(i,j,qRgb(0,0,b));
            }
        }
    }
    return image;
}
QImage convertToYUV(QImage image, char channel)
{
    int r,g,b,y,u,v;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            if (channel == 'a')
            {
                // Format YUV
                y = channelOne(r,g,b,'y');
                u = channelTwo(r,g,b,'u');
                v = channelThree(r,g,b,'v');

                image.setPixelColor(i,j,qRgb(y,u,v));
            }
            // channel Y
            if (channel == 'y')
            {
                y = channelOne(r,g,b,'y');
                image.setPixelColor(i,j,qRgb(y,0,0));
            }
            // channel U
            if (channel == 'u')
            {
                u = channelTwo(r,g,b,'u');
                image.setPixelColor(i,j,qRgb(0,u,0));
            }
            // channel V
            if (channel == 'v')
            {
                v = channelThree(r,g,b,'v');
                image.setPixelColor(i,j,qRgb(0,0,v));
            }
        }
    }

    return image;
}
QImage convertToYIQ(QImage image, char channel)
{
    int r,g,b,y,ii,q;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            if (channel == 'a')
            {
                // Format YIQ
                y = channelOne(r,g,b,'y');
                ii = channelTwo(r,g,b,'i');
                q = channelThree(r,g,b,'q');

                image.setPixelColor(i,j,qRgb(y,ii,q));
            }
            // channel Y
            if (channel == 'y')
            {
                y = channelOne(r,g,b,'y');
                image.setPixelColor(i,j,qRgb(y,0,0));
            }
            // channel I
            if (channel == 'i')
            {
                ii = channelTwo(r,g,b,'i');
                image.setPixelColor(i,j,qRgb(0,ii,0));
            }
            // channel Q
            if (channel == 'q')
            {
                q = channelThree(r,g,b,'q');
                image.setPixelColor(i,j,qRgb(0,0,q));
            }
        }
    }
    return image;
}
QImage convertToCMY(QImage image, char channel)
{
    int r,g,b,c,m,y;

    for(int i = 0; i < image.width(); i++)
    {

        for(int j = 0; j < image.height(); j++)
        {
            if (channel == 'a')
            {
                // get pixels
                r = QColor(image.pixel(i,j)).red();
                g = QColor(image.pixel(i,j)).green();
                b = QColor(image.pixel(i,j)).blue();

                // Format CMY
                c = channelOne(r,g,b,'c');
                m = channelTwo(r,g,b,'m');
                y = channelThree(r,g,b,'y');

                image.setPixelColor(i,j,qRgb(c,m,y));
            }
            // channel C
            if (channel == 'c')
            {
                r = QColor(image.pixel(i,j)).red();
                c = channelOne(r,0,0,'c');
                image.setPixelColor(i,j,qRgb(0,c,c));
            }
            // channel M
            if (channel == 'm')
            {
                g = QColor(image.pixel(i,j)).green();
                m = channelTwo(0,g,0,'m');
                image.setPixelColor(i,j,qRgb(m,0,m));
            }
            // channel Y
            if (channel == 'y')
            {
                b = QColor(image.pixel(i,j)).blue();
                y = channelThree(0,0,b,'y');
                image.setPixelColor(i,j,qRgb(y,y,0));
            }
        }
    }
    return image;
}
QImage convertToHSV(QImage image, char channel)
{
    int h,s,v;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            if (channel == 'a')
            {
                // Format HSV
                h = QColor(image.pixel(i,j)).hue();
                s = QColor(image.pixel(i,j)).saturation();
                v = QColor(image.pixel(i,j)).value();

                image.setPixelColor(i,j,qRgb(h,s,v));
            }
            // channel H
            if (channel == 'h')
            {
                h = QColor(image.pixel(i,j)).hue();
                image.setPixelColor(i,j,qRgb(h,0,0));
            }
            // channel S
            if (channel == 's')
            {
                s = QColor(image.pixel(i,j)).saturation();
                image.setPixelColor(i,j,qRgb(0,s,0));
            }
            // channel V
            if (channel == 'v')
            {
                v = QColor(image.pixel(i,j)).value();
                image.setPixelColor(i,j,qRgb(0,0,v));
            }
        }
    }
    return image;
}
QImage convertToHSL(QImage image, char channel)
{
    int h,s,l;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            if (channel == 'a')
            {
                // Format HSL
                h = QColor(image.pixel(i,j)).hue();
                s = QColor(image.pixel(i,j)).saturation();
                l = QColor(image.pixel(i,j)).lightness();

                image.setPixelColor(i,j,qRgb(h,s,l));
            }
            // channel H
            if (channel == 'h')
            {
                h = QColor(image.pixel(i,j)).hue();
                image.setPixelColor(i,j,qRgb(h,0,0));
            }
            // channel S
            if (channel == 's')
            {
                s = QColor(image.pixel(i,j)).saturation();
                image.setPixelColor(i,j,qRgb(0,s,0));
            }
            // channel L
            if (channel == 'l')
            {
                l = QColor(image.pixel(i,j)).lightness();
                image.setPixelColor(i,j,qRgb(0,0,l));
            }
        }
    }
    return image;
}
QImage convertToXYZ(QImage image, char channel)
{
    int r,g,b,x,y,z;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            if (channel == 'a')
            {
                x = channelOne(r,g,b,'x');
                y = channelTwo(r,g,b,'y');
                z = channelThree(r,g,b,'z');

                image.setPixelColor(i,j,qRgb(x,y,z));
            }
            // channel X
            if (channel == 'x')
            {
                x = channelOne(r,g,b,'x');
                image.setPixelColor(i,j,qRgb(x,0,0));
            }
            // channel Y
            if (channel == 'y')
            {
                y = channelTwo(r,g,b,'y');
                image.setPixelColor(i,j,qRgb(0,y,0));
            }
            // channel Z
            if (channel == 'z')
            {
                z = channelThree(r,g,b,'z');
                image.setPixelColor(i,j,qRgb(0,0,z));
            }
        }
    }
    return image;
}
QImage convertToOOO(QImage image, char channel)
{
    int r,g,b,x,y,z;
    double l,m,s,a,f,c;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {

            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            // Format RGB to XYZ
            x = channelOne(r,g,b,'x');
            y = channelTwo(r,g,b,'y');
            z = channelThree(r,g,b,'z');

            // XYZ to LMS
            l = (0.2430 * x) + (0.8560 * y) + (-0.0440 * z);
            m = (-0.3910 * x) + (1.1650 * y) + (0.0870 * z);
            s = (0.0100 * x) + (-0.0080 * y) + (0.5630 * z);

            if (channel == 'a')
            {
                // O1 O2 O3
                a = round((1 * l) + (0 * m) + (0 * s));
                f = round((-0.59 * l) + (0.80 * m) + (-0.12 * s));
                c = round((-0.34 * l) + (-0.11 * m) + (0.93 * s));

                image.setPixelColor(i,j,qRgb(a,f,c));
            }
            // channel O1
            if (channel == 'x')
            {
                a = round((1 * l) + (0 * m) + (0 * s));
                image.setPixelColor(i,j,qRgb(a,0,0));
            }
            // channel O2
            if (channel == 'y')
            {
                f = round((-0.59 * l) + (0.80 * m) + (-0.12 * s));
                image.setPixelColor(i,j,qRgb(0,f,0));
            }
            // channel O3
            if (channel == 'z')
            {
                c = round((-0.34 * l) + (-0.11 * m) + (0.93 * s));
                image.setPixelColor(i,j,qRgb(0,0,c));
            }
        }
    }
    return image;
}

// Funciones ejecutadas en hilos
QFuture<QImage> ConvertSpaceColor::imageToRGB()
{
    ThreadOne = QtConcurrent::run(convertToRGB,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToR()
{
    ThreadTwo = QtConcurrent::run(convertToRGB,img,'r');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToG()
{
    ThreadThree = QtConcurrent::run(convertToRGB,img,'g');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageToB()
{
    ThreadFor = QtConcurrent::run(convertToRGB,img,'b');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToYUV()
{
    ThreadOne = QtConcurrent::run(convertToYUV,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToY()
{
    ThreadTwo = QtConcurrent::run(convertToYUV,img,'y');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToU()
{
    ThreadThree = QtConcurrent::run(convertToYUV,img,'u');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageToV()
{
    ThreadFor = QtConcurrent::run(convertToYUV,img,'v');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToYIQ()
{
    ThreadOne = QtConcurrent::run(convertToYIQ,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToI()
{
    ThreadThree = QtConcurrent::run(convertToYIQ,img,'i');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageToQ()
{
    ThreadFor = QtConcurrent::run(convertToYIQ,img,'q');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToCMY()
{
    ThreadOne = QtConcurrent::run(convertToCMY,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToC()
{
    ThreadTwo = QtConcurrent::run(convertToCMY,img,'c');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToM()
{
    ThreadThree = QtConcurrent::run(convertToCMY,img,'m');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageTocmY()
{
    ThreadFor = QtConcurrent::run(convertToCMY,img,'y');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToHSV()
{
    ThreadOne = QtConcurrent::run(convertToHSV,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToH()
{
    ThreadTwo = QtConcurrent::run(convertToHSV,img,'h');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToS()
{
    ThreadThree = QtConcurrent::run(convertToHSV,img,'s');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageTohsV()
{
    ThreadFor = QtConcurrent::run(convertToHSV,img,'v');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToHSL()
{
    ThreadOne = QtConcurrent::run(convertToHSL,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToL()
{
    ThreadFor = QtConcurrent::run(convertToHSL,img,'l');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToXYZ()
{
    ThreadOne = QtConcurrent::run(convertToXYZ,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToX()
{
    ThreadTwo = QtConcurrent::run(convertToXYZ,img,'x');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToxYz()
{
    ThreadThree = QtConcurrent::run(convertToXYZ,img,'y');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageToZ()
{
    ThreadFor = QtConcurrent::run(convertToXYZ,img,'z');
    ThreadFor.waitForFinished();
    return ThreadFor;
}

QFuture<QImage> ConvertSpaceColor::imageToOOO()
{
    ThreadOne = QtConcurrent::run(convertToOOO,img,'a');
    ThreadOne.waitForFinished();
    return ThreadOne;
}
QFuture<QImage> ConvertSpaceColor::imageToO1()
{
    ThreadTwo = QtConcurrent::run(convertToOOO,img,'x');
    ThreadTwo.waitForFinished();
    return ThreadTwo;
}
QFuture<QImage> ConvertSpaceColor::imageToO2()
{
    ThreadThree = QtConcurrent::run(convertToOOO,img,'y');
    ThreadThree.waitForFinished();
    return ThreadThree;
}
QFuture<QImage> ConvertSpaceColor::imageToO3()
{
    ThreadFor = QtConcurrent::run(convertToOOO,img,'z');
    ThreadFor.waitForFinished();
    return ThreadFor;
}
