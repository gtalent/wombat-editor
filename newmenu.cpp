#include "newmenu.hpp"
#include "ui_newmenu.h"

NewMenu::NewMenu(QWidget *parent, QString projectDir) :
	QDialog(parent), ui(new Ui::NewMenu) {
	ui->setupUi(this);
	ui->options->addItem("Project");
	if (projectDir != "") {
		ui->options->addItem("Animation");
	}
}

NewMenu::~NewMenu() {
    delete ui;
}

void NewMenu::accept() {
	strNewWhat = ui->options->currentItem()->text();
	close();
	this->parentWidget()->activateWindow();
}

QString NewMenu::newWhat() {
	return strNewWhat;
}
