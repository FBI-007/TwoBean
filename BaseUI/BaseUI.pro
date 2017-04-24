#-------------------------------------------------
#
# Project created by QtCreator 2017-04-10T16:23:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BaseUI
TEMPLATE = lib

DEFINES += BASEUI_LIBRARY

ED_PATH = $$PWD/../bin/
DESTDIR = $${ED_PATH}

SOURCES += \
    framelesshelper.cpp \
    widgetdata.cpp \
    cursorposcalculator.cpp \
    MBTitleBar.cpp \
    MBWindow.cpp \
    MBSearchBar.cpp \
    messagebox.cpp \
    MBMessageBox.cpp

HEADERS  += \
    widgetdata.h \
    cursorposcalculator.h \
    const.h \
    baseui_global.h \
    MBTitleBar.h \
    MBWindow.h \
    MBSearchBar.h \
    messagebox.h \
    MBMessageBox.h

DISTFILES +=

RESOURCES += \
    titleicon.qrc


