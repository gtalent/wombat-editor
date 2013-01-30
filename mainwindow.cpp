#include "mainwindow.hpp"
#include "newmenu.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::newMenu() {
	NewMenu menu(this, "");
	menu.exec();
}

void MainWindow::openProject() {

}
