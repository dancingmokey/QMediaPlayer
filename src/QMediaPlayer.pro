#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T12:43:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QMediaPlayer
TEMPLATE = app

#DEFINES += _ARCH_ARM
DEFINES += _ARCH_x86

DEFINES += _OS_LINUX
#DEFINES += _OS_WIN

DEFINES += _UI_WIDGET
#DEFINES += _UI_QML

DEFINES += __STDC_CONSTANT_MACROS



SOURCES += main.cpp\
        ui/QWidget/MainWindow.cpp \
    TestPlay.cpp

HEADERS  += ui/QWidget/MainWindow.h \
    include/TestPlay.h

FORMS    += ui/QWidget/MainWindow.ui

RESOURCES += \
    ui/QWidget/UIResource.qrc


INCLUDEPATH += /usr/local/ffmpeg/include

LIBS += -L/usr/local/ffmpeg/lib
LIBS += -lavformat -lavcodec -lavutil
LIBS += -L/usr/local/ffmpeg/lib64

