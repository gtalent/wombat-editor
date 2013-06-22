#include "imagegallery.hpp"
#include "ui_imagegallery.h"

ImageGallery::ImageGallery(QWidget *parent): QDialog(parent), ui(new Ui::ImageGallery) {
	ui->setupUi(this);
}

ImageGallery::~ImageGallery() {
	delete ui;
}
