#include "editorcore/misc.hpp"
#include "wombatcore/wombatprofile.hpp"
#include "savevariables/profile.hpp"
#include "mainwindow.hpp"
#include "models/editormodels.hpp"
#include <QApplication>

using namespace wombat::editor;

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	a.setApplicationName("Wombat Editor");

	wombat::editor::EditorProfile profile;
	wombat::core::setupEditorProfile(profile);
	wombat::savevariables::setupEditorProfile(profile);

	MainWindow w(&profile);
	addDebugLogger(&w);
	w.show();

	return a.exec();
}
