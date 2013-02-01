#include <QDir>
#include <QDataStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "newproject.hpp"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) : QDialog(parent), ui(new Ui::NewProject) {
	ui->setupUi(this);
    ui->lePath->setText(QDir::homePath());
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
	path += name;
	if (QDir(path + name).exists()) {
		QMessageBox b(this);
		b.setText("This path already exists.");
		b.exec();
		return;
	}
	this->strProjectDir = path;
	QDir().mkdir(path);
	QDir().mkdir(path + "/Animations");
	QDir().mkdir(path + "/Resources/Images");
	QDir().mkdir(path + "/Creatures/Types");
	QDir().mkdir(path + "/Creatures/Classes");
	QDir().mkdir(path + "/Creatures/Moves");
	QDir().mkdir(path + "/Items");
	QDir().mkdir(path + "/Misc");
	QDir().mkdir(path + "/People/Classes");
	QDir().mkdir(path + "/Instances/Creatures");
	QDir().mkdir(path + "/Instances/People");
	QDir().mkdir(path + "/Worlds/Sprites");
	QDir().mkdir(path + "/Worlds/TileClasses");
	QDir().mkdir(path + "/Worlds/Worlds");
	QDir().mkdir(path + "/Worlds/Zones");

	QFile f(path + "/Misc/SaveVariables.json");
	f.open(QIODevice::WriteOnly);
	QDataStream out(&f);
	out << "{}";
	f.close();
	this->close();
	this->parentWidget()->activateWindow();
}

QString NewProject::projectDir() {
	return this->strProjectDir;
}

void NewProject::browse() {
	QString p = QFileDialog::getExistingDirectory(this, tr("Select Project Directory..."), QDir::homePath());
	if (p != "")
		ui->lePath->setText(p);
}
