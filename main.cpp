#include <map>
#include "globs.hpp"
#include "mainwindow.hpp"
#include "models/enginemodels.hpp"
#include <QApplication>

using namespace std;
using namespace enginemodels;
using namespace modelmaker;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
	addDebugLogger(&w);
    w.show();
	w.openProject("C:/Users/gary/WombatProject1");

    return a.exec();
}
