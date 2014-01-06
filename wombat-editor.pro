QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += \
	models/editormodels.cpp \
	editorcore/editorprofile.cpp \
	editorcore/editortab.cpp \
	editorcore/newfilemenu.cpp \
	editorcore/misc.cpp \
	editorcore/modeliomanager.cpp \
	wombatcore/newspritesheet.cpp \
	wombatcore/newanimation.cpp \
	wombatcore/animationeditor.cpp \
	wombatcore/savevariables.cpp \
	wombatcore/savevariableeditor.cpp \
	wombatcore/spritesheeteditor.cpp \
	wombatcore/spritesheetmanager.cpp \
	wombatcore/imageselectorwidget.cpp \
	wombatcore/imageselectordialog.cpp \
	wombatcore/wombatprofile.cpp \
	newmenu.cpp \
	newproject.cpp \
	mainwindow.cpp \
	main.cpp

HEADERS += \
	models/editormodels.hpp \
	editorcore/editorprofile.hpp \
	editorcore/editortablistener.hpp \
	editorcore/editortab.hpp \
	editorcore/editortabparams.hpp \
	editorcore/newfilemenuparams.hpp \
	editorcore/newfilemenu.hpp \
	editorcore/misc.hpp \
	editorcore/modeliomanager.hpp \
	wombatcore/newspritesheet.hpp \
	wombatcore/newanimation.hpp \
	wombatcore/animationeditor.hpp \
	wombatcore/spritesheeteditor.hpp \
	wombatcore/savevariableeditor.hpp \
	wombatcore/spritesheetmanager.hpp \
	wombatcore/savevariables.hpp \
	wombatcore/imageselectorwidget.hpp \
	wombatcore/imageselectordialog.hpp \
	wombatcore/wombatprofile.hpp \
	newmenu.hpp \
	newproject.hpp \
	mainwindow.hpp

FORMS += \
	mainwindow.ui \
	newmenu.ui \
	newproject.ui \
	wombatcore/newspritesheet.ui \
	wombatcore/newanimation.ui \
	wombatcore/animationeditor.ui \
	wombatcore/savevariableeditor.ui \
	wombatcore/spritesheeteditor.ui \
	wombatcore/imageselectorwidget.ui \
	wombatcore/imageselectordialog.ui \
	wombatcore/savevariables.ui

RESOURCES += \
	rsrc.qrc

CONFIG += c++11
