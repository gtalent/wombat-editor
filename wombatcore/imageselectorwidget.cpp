#include <QDir>

#include "imageselectorwidget.hpp"
#include "ui_imageselectorwidget.h"

namespace wombat {
namespace editor {

ImageSelectorWidget::ImageSelectorWidget(QWidget *parent, QString projectPath): QWidget(parent), ui(new Ui::ImageSelectorWidget) {
	ui->setupUi(this);
	m_projectPath = projectPath;
}

ImageSelectorWidget::~ImageSelectorWidget() {
	delete ui;
}

}
}
