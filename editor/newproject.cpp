#include <QDir>
#include <QTextStream>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <editorcore/misc.hpp>
#include "ui_newproject.h"
#include "newproject.hpp"

using namespace editor;

NewProject::NewProject(QWidget *parent, QVector<QString> defaultPaths): NewFileMenu(parent), ui(new Ui::NewProject) {
	ui->setupUi(this);
	ui->lePath->setText(QDir::homePath());
	m_defaultPaths = defaultPaths;

	setSizeGripEnabled(false);
	setFixedSize(550, 150);
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
	m_strProjectDir = path;
	QDir().mkpath(path);

	// create directories
	for (auto p : m_defaultPaths) {
		if (p.endsWith("/")) {
			QDir().mkpath(path + "/" + p);
		} else {
			QFile f(path + "/Misc/SaveVariables" + MODEL_FILE_EXTENSION);
			f.open(QIODevice::WriteOnly);
			QTextStream out(&f);
			if (p.endsWith(MODEL_FILE_EXTENSION)) {
				out << "{}\0";
			}
			f.close();
		}
	}

	QDialog::accept();
}

QString NewProject::path() {
	return m_strProjectDir;
}

void NewProject::browse() {
	QString p = QFileDialog::getExistingDirectory(this, tr("Select Project Directory..."), QDir::homePath());
	if (p != "")
		this->ui->lePath->setText(p);
}
