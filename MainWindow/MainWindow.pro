#-------------------------------------------------
#
# Project created by QtCreator 2017-04-15T16:58:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MainWindow
TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

SOURCES +=\
    main.cpp \
    tablemodel.cpp \
    checkboxdelegate.cpp \
    TBMainWindow.cpp \
    TBDownloadPage.cpp

HEADERS  += \
    tablemodel.h \
    checkboxdelegate.h \
    TBMainWindow.h \
    TBDownloadPage.h


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../bin/ -lBaseUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../bin/ -lBaseUI
else:unix: LIBS += -L$$PWD/../bin/ -lBaseUI

INCLUDEPATH += $$PWD/../BaseUI
DEPENDPATH += $$PWD/../BaseUI
