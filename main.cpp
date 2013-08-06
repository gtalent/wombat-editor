#include <map>
#include "mainwindow.hpp"
#include "models/enginemodels.hpp"
#include <QApplication>

using namespace std;
using namespace modelmaker;
using namespace enginemodels;

int main(int argc, char *argv[]) {
	enginemodels::SaveVariables m_file;
	m_file.loadFile("/home/gary/WombatProject1/Misc/SaveVariables.json");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
	w.openProject("/home/gary/WombatProject1");
    
    return a.exec();
}
