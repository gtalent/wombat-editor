QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += \
	models/editormodels.cpp \
	editorcore/dockwindow.cpp \
	editorcore/editorprofile.cpp \
	editorcore/editorwidget.cpp \
	editorcore/newfilemenu.cpp \
	editorcore/misc.cpp \
	editorcore/modeliomanager.cpp \
	wombatcore/newspritesheet.cpp \
	wombatcore/newanimation.cpp \
	wombatcore/animationeditor.cpp \
	wombatcore/spritesheeteditor.cpp \
	wombatcore/spritesheetmanager.cpp \
	wombatcore/imageselectorwidget.cpp \
	wombatcore/imageselectordialog.cpp \
	wombatcore/wombatprofile.cpp \
	savevariables/savevariables.cpp \
	savevariables/savevariableeditor.cpp \
	savevariables/profile.cpp \
	newmenu.cpp \
	newproject.cpp \
	mainwindow.cpp \
	main.cpp

HEADERS += \
	models/editormodels.hpp \
	editorcore/dockwindow.hpp \
	editorcore/dockwindowparams.hpp \
	editorcore/editorprofile.hpp \
	editorcore/editorwidgetlistener.hpp \
	editorcore/editorwidget.hpp \
	editorcore/editorwidgetparams.hpp \
	editorcore/newfilemenuparams.hpp \
	editorcore/newfilemenu.hpp \
	editorcore/misc.hpp \
	editorcore/modeliomanager.hpp \
	wombatcore/newspritesheet.hpp \
	wombatcore/newanimation.hpp \
	wombatcore/animationeditor.hpp \
	wombatcore/spritesheeteditor.hpp \
	wombatcore/spritesheetmanager.hpp \
	wombatcore/imageselectorwidget.hpp \
	wombatcore/imageselectordialog.hpp \
	wombatcore/wombatprofile.hpp \
	savevariables/savevariableeditor.hpp \
	savevariables/savevariables.hpp \
	savevariables/profile.hpp \
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
	wombatcore/spritesheeteditor.ui \
	wombatcore/imageselectorwidget.ui \
	savevariables/savevariableeditor.ui \
	savevariables/savevariables.ui

RESOURCES += \
	rsrc.qrc

CONFIG += c++11
