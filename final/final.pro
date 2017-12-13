#-------------------------------------------------
#
# Project created by QtCreator 2017-12-04T15:06:28
#
#-------------------------------------------------

QT       += core gui
QT       += widgets
QT += bluetooth
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = final
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    moving.cpp \
    trisol.c \
    kfsol.c \
    mainmenu.cpp \
    mapsettings.cpp

HEADERS  += mainwindow.h \
    moving.h \
    shm.h \
    trisol.h \
    kfsol.h \
    mainmenu.h \
    mapsettings.h

FORMS    += mainwindow.ui \
    moving.ui \
    mainmenu.ui \
    mapsettings.ui

RESOURCES += \
    MyResources.qrc
