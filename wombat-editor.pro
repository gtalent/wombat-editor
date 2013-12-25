QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += editorcore/editormanager.cpp \
	editorcore/editortab.cpp \
	editorcore/misc.cpp \
	models/editormodels.cpp \
	main.cpp \
	mainwindow.cpp \
	newmenu.cpp \
	newproject.cpp \
	savevariables.cpp \
	importmenu.cpp \
	savevariableeditor.cpp \
	animationeditor.cpp \
	imageselector.cpp \
	spritesheeteditor.cpp \
	newspritesheet.cpp \
	wombatcanvas.cpp

HEADERS += editorcore/editormanager.hpp \
	editorcore/editortablistener.hpp \
	editorcore/editortab.hpp \
	editorcore/misc.hpp \
	models/editormodels.hpp \
	mainwindow.hpp \
	newmenu.hpp \
	newproject.hpp \
	savevariables.hpp \
	importmenu.hpp \
	savevariableeditor.hpp \
	animationeditor.hpp \
	imageselector.hpp \
	spritesheeteditor.hpp \
	newspritesheet.hpp \
	wombatcanvas.hpp

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

QMAKE_CXXFLAGS = -std=c++11 -stdlib=libc++
CONFIG += c++11
