#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T05:54:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wombat-editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newmenu.cpp \
    newproject.cpp

HEADERS  += mainwindow.hpp \
    newmenu.hpp \
    newproject.hpp

FORMS    += mainwindow.ui \
    newmenu.ui \
    newproject.ui

RESOURCES += \
    rsrc.qrc
