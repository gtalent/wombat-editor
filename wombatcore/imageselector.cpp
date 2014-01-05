#include <QDir>

#include "imageselector.hpp"
#include "ui_imageselector.h"

#include <iostream>

ImageSelector::ImageSelector(QWidget *parent, QString): QDialog(parent), ui(new Ui::ImageSelector) {
	ui->setupUi(this);
}

ImageSelector::~ImageSelector() {
	delete ui;
}
