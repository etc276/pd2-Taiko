#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T16:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = prject
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

RESOURCES += \
    play.qrc \
    reference/start.qrc \
    start.qrc \
    black.qrc \
    white.qrc \
    red.qrc \
    key_d.qrc \
    key_j.qrc

DISTFILES += \
    reference/PLAY.jpg \
    reference/START.jpg
