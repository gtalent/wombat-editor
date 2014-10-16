QT += core gui widgets qml quick

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = WombatStudio
TEMPLATE = app

SOURCES += \
	models/models.cpp \
	models/paths.cpp \
	editorcontrols/dockwidget.cpp\
	editorcore/dockwindow.cpp \
	editorcore/editorprofile.cpp \
	editorcore/editorwidget.cpp \
	editorcore/genericnewfilemenu.cpp \
	editorcore/newfilemenu.cpp \
	editorcore/misc.cpp \
	editorcore/modeliomanager.cpp \
	editorcore/qtquickeditorwidget.cpp \
	editorcore/qtquicksignaler.cpp \
	wombat/core/newspritesheet.cpp \
	wombat/core/animationeditor.cpp \
	wombat/core/spritesheeteditor.cpp \
	wombat/core/spritesheetmanager.cpp \
	wombat/core/imageselectorwidget.cpp \
	wombat/core/imageselectordialog.cpp \
	wombat/core/wombatprofile.cpp \
	wombat/savevariables/savevariables.cpp \
	wombat/savevariables/savevariableeditor.cpp \
	wombat/savevariables/savevariablesprofile.cpp \
	wombat/world/tileclasseditor.cpp \
	wombat/world/tileclassexplorer.cpp \
	wombat/world/worldprofile.cpp \
	wombat/world/worldutil.cpp \
	wombat/world/zoneeditor.cpp \
	editor/newmenu.cpp \
	editor/newproject.cpp \
	editor/mainwindow.cpp \
	editor/main.cpp

HEADERS += \
	models/enums.hpp \
	models/models.hpp \
	models/paths.hpp \
	editorcontrols/dockwidget.hpp\
	editorcore/dockwindow.hpp \
	editorcore/dockwindowparams.hpp \
	editorcore/editorprofile.hpp \
	editorcore/editorwidget.hpp \
	editorcore/editorwidgetparams.hpp \
	editorcore/genericnewfilemenu.hpp \
	editorcore/newfilemenuparams.hpp \
	editorcore/newfilemenu.hpp \
	editorcore/misc.hpp \
	editorcore/modeliomanager.hpp \
	editorcore/qtquickeditorwidget.hpp \
	editorcore/qtquicksignaler.hpp \
	wombat/core/newspritesheet.hpp \
	wombat/core/animationeditor.hpp \
	wombat/core/spritesheeteditor.hpp \
	wombat/core/spritesheetmanager.hpp \
	wombat/core/imageselectorwidget.hpp \
	wombat/core/imageselectordialog.hpp \
	wombat/core/wombatprofile.hpp \
	wombat/savevariables/savevariableeditor.hpp \
	wombat/savevariables/savevariables.hpp \
	wombat/savevariables/savevariablesprofile.hpp \
	wombat/world/tileclasseditor.hpp \
	wombat/world/tileclassexplorer.hpp \
	wombat/world/worldprofile.hpp \
	wombat/world/worldutil.hpp \
	wombat/world/zoneeditor.hpp \
	editor/newmenu.hpp \
	editor/newproject.hpp \
	editor/mainwindow.hpp

FORMS += \
	wombat/core/newspritesheet.ui \
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
