#ifndef PROCESS_H
#define PROCESS_H

#include <QImage>
#include <QString>
#include <QDebug>

int r,g,b;

QImage convertToRGB(QImage image, char channel='a')
{
    QRgb value;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

            // Format RGB
            if (channel == 'a')
            {
                //return image;
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
    int y,u,v;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            // get pixels
            r = QColor(image.pixel(i,j)).red();
            g = QColor(image.pixel(i,j)).green();
            b = QColor(image.pixel(i,j)).blue();

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



/*QImage convertToChannels(QImage image, int format, char channel)
{
    QRgb value;

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
           // save pixels
           r = QColor(image.pixel(i,j)).red();
           g = QColor(image.pixel(i,j)).green();
           b = QColor(image.pixel(i,j)).blue();

           // Format YUV
           y = (0.299 * r) + (0.587 * g) + (0.114 * b );
           u = 0.439 * (b - y);
           v = 0.877 * (r - y);

           // Format CMY
          // c = 255 - r;
          // m = 255 - g;
           ya = 255 - b;

           // Choose channels

           // Channels RGB



           // Channels YUV

           // channel Y
           if (format == 1 && channel == 'y')
           {
               value = qRgb(y,y,y);
               image.setPixelColor(i,j,value);
           }
           // channel U
           if (format == 1 && channel == 'u')
           {
               value = qRgb(u,u,u);
               image.setPixelColor(i,j,value);
           }
           // channel V
           if (format == 1 && channel == 'v')
           {
               value = qRgb(v,v,v);
               image.setPixelColor(i,j,value);
           }

           // Channels CMY

           // channel C
           if (format == 2 && channel == 'c')
           {
               value = qRgb(c,c,c);
               image.setPixelColor(i,j,value);
           }
           // channel M
           if (format == 2 && channel == 'm')
           {
               value = qRgb(m,m,m);
               image.setPixelColor(i,j,value);
           }
           // channel Y
           if (format == 1 && channel == 'y')
           {
               value = qRgb(ya,ya,ya);
               image.setPixelColor(i,j,value);

           }

        }
    }

   return image;
}*/



#endif // PROCESS_H
