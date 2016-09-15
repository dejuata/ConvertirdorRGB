#ifndef RESOURCES_H
#define RESOURCES_H

#include <QStringList>

QStringList cleanMatriz(QString text){

    QStringList list = text.split("\r\n");
    QStringList cleanList;

    for(int i = 0; i < list.length(); i++)
    {
        cleanList.append(list[i].split(' '));
    }

    return cleanList;
}

#endif // RESOURCES_H
