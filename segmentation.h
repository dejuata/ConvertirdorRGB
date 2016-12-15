#ifndef SEGMENTATION_H
#define SEGMENTATION_H

#include <QImage>
#include <QColor>
#include <math.h>
// debe recibir una imagen a escala de grises
QImage segmentationThreshold(QImage image, int t)
{
    QImage result = image;
    QRgb threshold = qRgb(t,t,t);

    for(int i = 0; i < image.width(); i++)
    {
        for(int j = 0; j < image.height(); j++)
        {
            if(image.pixel(i,j) < threshold)
            {
                result.setPixel(i,j,qRgb(0,0,0));
            }
            else if(image.pixel(i,j) >= threshold)
            {
                result.setPixel(i,j,qRgb(255,255,255));
            }
        }
    }
    return result;
}

QImage segmentationKMeans(QImage image, int iteration)
{
    QImage result = image;

    int clusterOne[3] = {0,0,0};
    int clusterTwo[3] = {128,128,128};
    int clusterThree[3] = {255,255,255};

    double distance[3];

    int r,g,b;
    for(int x = 0; x < iteration; x++)
    {
        for(int i = 0; i < image.width(); i++)
        {
            for(int j = 0; j < image.height(); j++)
            {
                r = QColor(image.pixel(i,j)).red();
                g = QColor(image.pixel(i,j)).green();
                b = QColor(image.pixel(i,j)).blue();

                distance[0] = sqrt(pow(clusterOne[0] - r, 2) + pow(clusterOne[1] - g, 2) + pow(clusterOne[2] - b, 2));
                distance[1] = sqrt(pow(clusterTwo[0] - r, 2) + pow(clusterTwo[1] - g, 2) + pow(clusterTwo[2] - b, 2));
                distance[2] = sqrt(pow(clusterThree[0] - r, 2) + pow(clusterThree[1] - g, 2) + pow(clusterThree[2] - b, 2));

                // Ordeno de menor a mayor creando un vector para usar el
                // metodo sort
                vector<double> distancia (distance, distance+3);
                sort (distancia.begin(), distancia.begin()+3);

                // De acuerdo a la distancia minima seteo la imagen con el
                // color negro, gris o blanco
                if(distancia[0] == distance[0])
                {
                    result.setPixel(i,j,qRgb(clusterOne[0],clusterOne[1],clusterOne[2]));
                }
                if(distancia[0] == distance[1])
                {
                    result.setPixel(i,j,qRgb(clusterTwo[0],clusterTwo[1],clusterTwo[2]));
                }
                if(distancia[0] == distance[2])
                {
                    result.setPixel(i,j,qRgb(clusterThree[0],clusterThree[1],clusterThree[2]));
                }
            }
        }
    }


    return result;

}

#endif // SEGMENTATION_H
