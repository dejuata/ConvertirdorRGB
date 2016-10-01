#-------------------------------------------------
#
# Project created by QtCreator 2016-09-04T09:03:49
#
#-------------------------------------------------

QT       += core gui widgets
QT       += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ConvertidorImage
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    settingsfilter.cpp \
    contrast.cpp

HEADERS  += mainwindow.h \
    process.h \
    settingsfilter.h \
    resources.h \
    filterminmedmax.h \
    globals.h \
    filter.h \
    contrast.h

FORMS    += mainwindow.ui \
    settingsfilter.ui \
    contrast.ui

RESOURCES += \
    resources.qrc
