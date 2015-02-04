#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T12:43:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMediaPlayer
TEMPLATE = app

DEFINES += _ARCH_ARM
DEFINES += _ARCH_x86

DEFINES += _SYS_LINUX
DEFINES += _SYS_WIN

DEFINES += _UI_WIDGET
DEFINES += _UI_QML



SOURCES += main.cpp\
        ui/QWidget/MainWindow.cpp

HEADERS  += ui/QWidget/MainWindow.h

FORMS    += ui/QWidget/MainWindow.ui
