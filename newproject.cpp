#include <QDir>
#include <QTextStream>
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
	QDir().mkpath(path);
	QDir().mkpath(path + "/Animations");
	QDir().mkpath(path + "/Resources/Images");
	QDir().mkpath(path + "/Creatures/Types");
	QDir().mkpath(path + "/Creatures/Classes");
	QDir().mkpath(path + "/Creatures/Moves");
	QDir().mkpath(path + "/Items");
	QDir().mkpath(path + "/Misc");
	QDir().mkpath(path + "/People/Classes");
	QDir().mkpath(path + "/Instances/Creatures");
	QDir().mkpath(path + "/Instances/People");
	QDir().mkpath(path + "/Worlds/Sprites");
	QDir().mkpath(path + "/Worlds/TileClasses");
	QDir().mkpath(path + "/Worlds/Worlds");
	QDir().mkpath(path + "/Worlds/Zones");

	QFile f(path + "/Misc/SaveVariables.json");
	f.open(QIODevice::WriteOnly);
    QTextStream out(&f);
    out << "{}\n";
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
