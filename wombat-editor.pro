#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T05:54:13
#
#-------------------------------------------------

QT       += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app


SOURCES += main.cpp \
    mainwindow.cpp \
    newmenu.cpp \
    newproject.cpp \
    savevariables.cpp \
    importmenu.cpp \
    editortab.cpp \
    models/enginemodels.cpp \
    models/editormodels.cpp \
    savevariableeditor.cpp \
    animationeditor.cpp \
    imageselector.cpp \
    spritesheeteditor.cpp \
    newspritesheet.cpp

HEADERS  += mainwindow.hpp \
    globs.hpp \
    newmenu.hpp \
    newproject.hpp \
    savevariables.hpp \
    importmenu.hpp \
    editortab.hpp \
    editortablistener.hpp \
    models/enginemodels.hpp \
    models/editormodels.hpp \
    savevariableeditor.hpp \
    animationeditor.hpp \
    imageselector.hpp \
    spritesheeteditor.hpp \
    newspritesheet.hpp

FORMS    += mainwindow.ui \
    newmenu.ui \
    newproject.ui \
    savevariables.ui \
    importmenu.ui \
    savevariableeditor.ui \
    animationeditor.ui \
    imageselector.ui \
    spritesheeteditor.ui \
    newspritesheet.ui

RESOURCES += \
    rsrc.qrc

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += jansson

OTHER_FILES +=
