#include "newmenu.hpp"
#include "ui_newmenu.h"

NewMenu::NewMenu(QWidget *parent, QString projectDir, QVector<QString> itemTypes): QDialog(parent), ui(new Ui::NewMenu) {
	this->ui->setupUi(this);
	this->ui->options->addItem("Project");
	if (projectDir != "") {
		for (auto t : itemTypes) {
			this->ui->options->addItem(t);
		}
	}

	setSizeGripEnabled(false);
	setFixedSize(400, 275);
}

NewMenu::~NewMenu() {
	delete this->ui;
}

void NewMenu::accept() {
	this->strNewWhat = this->ui->options->currentItem()->text();
	QDialog::accept();
}

QString NewMenu::newWhat() {
	return this->strNewWhat;
}
