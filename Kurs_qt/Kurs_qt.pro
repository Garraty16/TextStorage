#-------------------------------------------------
#
# Project created by QtCreator 2017-05-22T15:45:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kurs_qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    storageservice.cpp \
    comline.cpp

HEADERS  += mainwindow.h \
    storageservice.h \
    comline.h

FORMS    += mainwindow.ui
