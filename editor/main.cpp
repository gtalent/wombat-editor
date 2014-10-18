#include <editorcore/misc.hpp>
#include <wombat/core/wombatprofile.hpp>
#include <wombat/savevariables/savevariablesprofile.hpp>
#include <wombat/world/worldprofile.hpp>
#include <models/editormodels.hpp>
#include <QApplication>
#include "mainwindow.hpp"

using namespace wombat;
using namespace editor;

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	app.setApplicationName(MainWindow::AppTitle);

	editor::EditorProfile profile;
	core::setupEditorProfile(profile);
	savevariables::setupEditorProfile(profile);
	world::setupEditorProfile(profile);

	MainWindow w(&profile);
	addDebugLogger(&w);
	w.show();

	return app.exec();
}
