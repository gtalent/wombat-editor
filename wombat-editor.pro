QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += \
	models/models.cpp \
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
	editor/newmenu.cpp \
	editor/newproject.cpp \
	editor/mainwindow.cpp \
	editor/main.cpp

HEADERS += \
	models/models.hpp \
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
	editor/newmenu.hpp \
	editor/newproject.hpp \
	editor/mainwindow.hpp

FORMS += \
	wombatcore/newspritesheet.ui \
	wombatcore/newanimation.ui \
	wombatcore/animationeditor.ui \
	wombatcore/spritesheeteditor.ui \
	wombatcore/imageselectorwidget.ui \
	savevariables/savevariableeditor.ui \
	savevariables/savevariables.ui \
	editor/mainwindow.ui \
	editor/newmenu.ui \
	editor/newproject.ui

RESOURCES += \
	editor/rsrc.qrc

CONFIG += c++11
