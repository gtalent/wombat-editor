#include "newmenu.hpp"
#include "ui_newmenu.h"

NewMenu::NewMenu(QWidget *parent, QString projectDir) :
	QDialog(parent), ui(new Ui::NewMenu) {
    this->ui->setupUi(this);
    this->ui->options->addItem("Project");
	if (projectDir != "") {
        this->ui->options->addItem("Animation");
	}
}

NewMenu::~NewMenu() {
    delete this->ui;
}

void NewMenu::accept() {
    this->strNewWhat = this->ui->options->currentItem()->text();
    this->close();
	this->parentWidget()->activateWindow();
}

QString NewMenu::newWhat() {
    return this->strNewWhat;
}
