#-------------------------------------------------
#
# Project created by QtCreator 2013-06-19T20:11:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QT += xmlpatterns

TARGET = pathfinder
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    xpathviewer.cpp \
    xmlsyntaxhighlighter.cpp

HEADERS  += mainwindow.h \
    xpathviewer.h \
    xmlsyntaxhighlighter.h

FORMS    += mainwindow.ui
