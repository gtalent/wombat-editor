#include "importmenu.hpp"
#include "ui_importmenu.h"

ImportMenu::ImportMenu(QWidget *parent): QDialog(parent), ui(new Ui::ImportMenu) {
	ui->setupUi(this);
}

ImportMenu::~ImportMenu() {
	delete ui;
}

QString ImportMenu::importWhat() {
	return strImportWhat;
}
