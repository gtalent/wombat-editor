#include <QDir>
#include "newproject.hpp"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) : QDialog(parent), ui(new Ui::NewProject) {
	ui->setupUi(this);
}

NewProject::~NewProject() {
	delete ui;
}

void NewProject::accept() {
	QString path = ui->lePath->text();
	QString name = ui->leName->text();
	if (path == "" || name == "") {
		return;
	}
	if (path.at(path.length() - 1) != '/') {
		path += '/';
	}
	QDir().mkdir(path + name);
	this->close();
	this->parentWidget()->activateWindow();
}
