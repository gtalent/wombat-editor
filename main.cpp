#include <map>
#include "globs.hpp"
#include "mainwindow.hpp"
#include "models/models.hpp"
#include <QApplication>

using namespace std;
using namespace models;
using namespace cyborgbear;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	addDebugLogger(&w);
    w.show();
	w.openProject("/home/gary/WombatProject1");

    return a.exec();
}
