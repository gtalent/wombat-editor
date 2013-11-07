#include "globs.hpp"
#include "mainwindow.hpp"
#include "models/models.hpp"
#include <QApplication>

using namespace wombat::editor;

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	MainWindow w;
	addDebugLogger(&w);
	w.show();

	return a.exec();
}
