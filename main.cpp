#include "editorcore/misc.hpp"
#include "mainwindow.hpp"
#include "models/editormodels.hpp"
#include <QApplication>

using namespace wombat::editor;

int main(int argc, char *argv[]) {
	QApplication::setApplicationName("Wombat Editor");
	QApplication a(argc, argv);
	MainWindow w;
	addDebugLogger(&w);
	w.show();

	return a.exec();
}
