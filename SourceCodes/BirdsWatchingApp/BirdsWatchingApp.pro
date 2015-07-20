#-------------------------------------------------
#
# Project created by QtCreator 2015-07-17T17:29:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BirdsWatchingApp
TEMPLATE = app


SOURCES += main.cpp\
    hmi/mainwindow.cpp \
    service/qserviceobject.cpp \
    hmi/qchoosebird.cpp

HEADERS  += \
    hmi/mainwindow.h \
    service/qserviceobject.h \
    dummy_data.h \
    hmi/qchoosebird.h

FORMS    += hmi/ui/mainwindow.ui \
    hmi/ui/dlg_choosebird.ui
