#-------------------------------------------------
#
# Project created by QtCreator 2013-06-19T20:11:32
#
#-------------------------------------------------

QT       += core gui

QT += widgets

QT += xmlpatterns

TARGET = pathfinder
TEMPLATE = app

LIBS += -stdlib=libc++

QMAKE_CXXFLAGS += -stdlib=libc++
QMAKE_CXXFLAGS += -std=c++11
QMAKE_CXXFLAGS += -mmacosx-version-min=10.7
QMAKE_LFLAGS += -mmacosx-version-min=10.7


QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.7 #2


SOURCES += main.cpp\
        mainwindow.cpp \
    xpathviewer.cpp \
    xmlsyntaxhighlighter.cpp

HEADERS  += mainwindow.h \
    xpathviewer.h \
    xmlsyntaxhighlighter.h

FORMS    += mainwindow.ui
