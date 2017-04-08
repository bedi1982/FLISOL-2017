#-------------------------------------------------
#
# Project created by QtCreator 2017-04-03T17:54:24
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Teste
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        database.cpp

HEADERS  += mainwindow.h \
        database.h

FORMS    += mainwindow.ui \
    dialog.ui
