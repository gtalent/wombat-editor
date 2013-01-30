#include "newmenu.hpp"
#include "ui_newmenu.h"
#include "newproject.hpp"

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
	QString txt = ui->options->currentItem()->text();
	if (txt == "Project") {
		NewProject menu(this);
		menu.exec();
	}
	this->close();
	this->parentWidget()->activateWindow();
}
