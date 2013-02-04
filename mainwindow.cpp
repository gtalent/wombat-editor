#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>

#include "mainwindow.hpp"
#include "newmenu.hpp"
#include "newproject.hpp"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);

}

MainWindow::~MainWindow() {
	if (ui->fileList->model())
		delete ui->fileList->model();
	delete ui;
}

void MainWindow::newMenu() {
	NewMenu menu(this, "");
	menu.exec();
	QString nw = menu.newWhat();

	if (nw == "Project") {
		NewProject np(this);
		np.exec();
		openProject(np.projectDir());
	}
}

void MainWindow::openProject() {
	openProject(QFileDialog::getExistingDirectory(this, tr("Open Project Directory..."), QDir::homePath()));
}

void MainWindow::openProject(QString path) {
	projectDir = path;
	setWindowTitle("Wombat Editor - " + path);

	if (ui->fileList->model())
		delete ui->fileList->model();

	QFileSystemModel *model = new QFileSystemModel();
	ui->fileList->setModel(model);
	ui->fileList->setHeaderHidden(true);
	for (int i = 1; i < 4; i++) {
		ui->fileList->hideColumn(i);
	}
	QStringList l;
	l << "*.json" << "*.bmp" << "*.png" << "*.jpg";
	model->setNameFilters(l);
	model->setNameFilterDisables(false);
	ui->fileList->setRootIndex(model->setRootPath(path));
}
