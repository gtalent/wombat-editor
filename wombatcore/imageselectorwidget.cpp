#include <QDir>

#include "imageselectorwidget.hpp"
#include "ui_imageselectorwidget.h"

ImageSelectorWidget::ImageSelectorWidget(QWidget *parent, QString): QWidget(parent), ui(new Ui::ImageSelectorWidget) {
	ui->setupUi(this);
}

ImageSelectorWidget::~ImageSelectorWidget() {
	delete ui;
}
