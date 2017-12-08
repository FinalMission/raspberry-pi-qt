#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T15:06:28
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    moving.cpp

HEADERS  += mainwindow.h \
    moving.h

FORMS    += mainwindow.ui \
    moving.ui

RESOURCES += \
    MyResources.qrc
