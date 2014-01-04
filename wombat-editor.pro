QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += \
	editorcore/editorprofile.cpp \
	editorcore/editortab.cpp \
	editorcore/newfilemenu.cpp \
	editorcore/misc.cpp \
	editorcore/modeliomanager.cpp \
	models/editormodels.cpp \
	wombatprofile.cpp \
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
	wombatcanvas.cpp \
	newanimation.cpp

HEADERS += \
	editorcore/editorprofile.hpp \
	editorcore/editortablistener.hpp \
	editorcore/editortab.hpp \
	editorcore/editortabparams.hpp \
	editorcore/newfilemenuparams.hpp \
	editorcore/newfilemenu.hpp \
	editorcore/misc.hpp \
	editorcore/modeliomanager.hpp \
	models/editormodels.hpp \
	wombatprofile.hpp \
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
	wombatcanvas.hpp \
	newanimation.hpp

FORMS += \
	mainwindow.ui \
	newmenu.ui \
	newproject.ui \
	importmenu.ui \
	savevariableeditor.ui \
	animationeditor.ui \
	imageselector.ui \
	spritesheeteditor.ui \
	newspritesheet.ui \
	savevariables.ui \
	newanimation.ui

RESOURCES += \
	rsrc.qrc

CONFIG += c++11
