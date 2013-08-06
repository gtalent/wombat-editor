#include <QDir>

#include "imageselector.hpp"
#include "ui_imageselector.h"

#include <iostream>

ImageSelector::ImageSelector(QWidget *parent, QString): QDialog(parent), ui(new Ui::ImageSelector) {
	ui->setupUi(this);
	//QFileSystemModel *model = new QFileSystemModel();
	//ui->fileList->setModel(model);
	//ui->fileList->setHeaderHidden(true);
	//for (int i = 1; i < 4; i++) {
	//	ui->fileList->hideColumn(i);
	//}
	//QStringList l;
	//l << "*.bmp" << "*.png" << "*.jpg";
	//model->setNameFilters(l);
	//model->setNameFilterDisables(false);
}

ImageSelector::~ImageSelector() {
	delete ui;
}
