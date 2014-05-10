QT += core gui widgets qml quick

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatEditor
TEMPLATE = app

SOURCES += \
	models/models.cpp \
	editorcontrols/dockwidget.cpp\
	editorcore/dockwindow.cpp \
	editorcore/editorprofile.cpp \
	editorcore/editorwidget.cpp \
	editorcore/newfilemenu.cpp \
	editorcore/misc.cpp \
	editorcore/modeliomanager.cpp \
	editorcore/qtquickeditorwidget.cpp \
	editorcore/qtquicksignaler.cpp \
	wombat/core/newspritesheet.cpp \
	wombat/core/newanimation.cpp \
	wombat/core/animationeditor.cpp \
	wombat/core/spritesheeteditor.cpp \
	wombat/core/spritesheetmanager.cpp \
	wombat/core/imageselectorwidget.cpp \
	wombat/core/imageselectordialog.cpp \
	wombat/core/wombatprofile.cpp \
	wombat/savevariables/savevariables.cpp \
	wombat/savevariables/savevariableeditor.cpp \
	wombat/savevariables/profile.cpp \
	wombat/world/tileeditor.cpp \
	wombat/world/worldprofile.cpp \
	editor/newmenu.cpp \
	editor/newproject.cpp \
	editor/mainwindow.cpp \
	editor/main.cpp

HEADERS += \
	models/models.hpp \
	editorcontrols/dockwidget.hpp\
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
	editorcore/qtquickeditorwidget.hpp \
	editorcore/qtquicksignaler.hpp \
	wombat/core/newspritesheet.hpp \
	wombat/core/newanimation.hpp \
	wombat/core/animationeditor.hpp \
	wombat/core/spritesheeteditor.hpp \
	wombat/core/spritesheetmanager.hpp \
	wombat/core/imageselectorwidget.hpp \
	wombat/core/imageselectordialog.hpp \
	wombat/core/wombatprofile.hpp \
	wombat/savevariables/savevariableeditor.hpp \
	wombat/savevariables/savevariables.hpp \
	wombat/savevariables/profile.hpp \
	wombat/world/tileeditor.hpp \
	wombat/world/worldprofile.hpp \
	editor/newmenu.hpp \
	editor/newproject.hpp \
	editor/mainwindow.hpp

FORMS += \
	wombat/core/newspritesheet.ui \
	wombat/core/newanimation.ui \
	wombat/core/animationeditor.ui \
	wombat/core/spritesheeteditor.ui \
	wombat/core/imageselectorwidget.ui \
	wombat/savevariables/savevariableeditor.ui \
	wombat/savevariables/savevariables.ui \
	editor/mainwindow.ui \
	editor/newmenu.ui \
	editor/newproject.ui

RESOURCES += \
	editor/rsrc.qrc

CONFIG += c++11
