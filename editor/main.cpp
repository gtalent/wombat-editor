#include "editorcore/misc.hpp"
#include "wombat/core/wombatprofile.hpp"
#include "wombat/savevariables/profile.hpp"
//#include "wombat/world/profile.hpp"
#include "mainwindow.hpp"
#include "models/editormodels.hpp"
#include <QApplication>

using namespace wombat;
using namespace editor;

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	a.setApplicationName("Wombat Editor");

	editor::EditorProfile profile;
	core::setupEditorProfile(profile);
	savevariables::setupEditorProfile(profile);

	MainWindow w(&profile);
	addDebugLogger(&w);
	w.show();

	return a.exec();
}
