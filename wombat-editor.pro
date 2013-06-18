#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T05:54:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WombatEditor
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    newmenu.cpp \
    newproject.cpp \
    savevariables.cpp \
    importmenu.cpp \
    editortab.cpp \
    models/modelmakerdefs.cpp \
    models/enginemodels.cpp \
    models/editormodels.cpp \
    savevariableeditor.cpp

HEADERS  += mainwindow.hpp \
    newmenu.hpp \
    newproject.hpp \
    savevariables.hpp \
    importmenu.hpp \
    editortab.hpp \
    editortablistener.hpp \
    models/modelmakerdefs.hpp \
    models/enginemodels.hpp \
    models/editormodels.hpp \
    savevariableeditor.hpp

FORMS    += mainwindow.ui \
    newmenu.ui \
    newproject.ui \
    savevariables.ui \
    importmenu.ui \
    savevariableeditor.ui

RESOURCES += \
    rsrc.qrc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += jansson
