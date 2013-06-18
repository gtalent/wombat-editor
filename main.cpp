#include <iostream>
#include <map>
#include "mainwindow.hpp"
#include "models/editormodels.hpp"
#include <QApplication>

using namespace std;
using namespace modelmaker;
using namespace editormodels;

int main(int argc, char *argv[]) {
	editormodels::SaveVariables m_file;
	m_file.loadFile("/home/gary/WombatProject1/Misc/SaveVariables.json");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
