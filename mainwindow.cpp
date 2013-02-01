#include <QDir>
#include <QFileDialog>

#include "mainwindow.hpp"
#include "newmenu.hpp"
#include "newproject.hpp"
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
	QString nw = menu.newWhat();

	if (nw == "Project") {
		NewProject np(this);
		np.exec();
		setProjectDir(np.projectDir());
	}
}

void MainWindow::openProject() {
	setProjectDir(QFileDialog::getExistingDirectory(this, tr("Open Project Directory..."), QDir::homePath()));
}

void MainWindow::setProjectDir(QString path) {
	projectDir = path;
	setWindowTitle("Wombat Editor - " + path);
}
