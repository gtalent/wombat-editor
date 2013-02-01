#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T05:54:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WombatEditor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newmenu.cpp \
    newproject.cpp \
    savevariables.cpp

HEADERS  += mainwindow.hpp \
    newmenu.hpp \
    newproject.hpp \
    savevariables.hpp

FORMS    += mainwindow.ui \
    newmenu.ui \
    newproject.ui \
    savevariables.ui

RESOURCES += \
    rsrc.qrc
