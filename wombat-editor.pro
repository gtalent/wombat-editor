QT += core gui widgets

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
	models/editormodels.cpp \
	savevariableeditor.cpp \
	animationeditor.cpp \
	imageselector.cpp \
	spritesheeteditor.cpp \
	newspritesheet.cpp \
	wombatcanvas.cpp \
	globs.cpp

HEADERS += mainwindow.hpp \
	newmenu.hpp \
	newproject.hpp \
	savevariables.hpp \
	importmenu.hpp \
	editortab.hpp \
	editortablistener.hpp \
	models/editormodels.hpp \
	savevariableeditor.hpp \
	animationeditor.hpp \
	imageselector.hpp \
	spritesheeteditor.hpp \
	newspritesheet.hpp \
	wombatcanvas.cpp \
	globs.hpp

FORMS   += mainwindow.ui \
	newmenu.ui \
	newproject.ui \
	importmenu.ui \
	savevariableeditor.ui \
	animationeditor.ui \
	imageselector.ui \
	spritesheeteditor.ui \
	newspritesheet.ui \
	savevariables.ui

RESOURCES += \
    rsrc.qrc

QMAKE_CXXFLAGS = -std=c++11

