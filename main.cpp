#include <map>
#include "mainwindow.hpp"
#include "models/enginemodels.hpp"
#include <QApplication>

using namespace std;
using namespace enginemodels;
using namespace cyborgbear;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	w.openProject("/home/gary/WombatProject1");
    
    return a.exec();
}
