#include <QDir>

#include "imageselectordialog.hpp"

namespace wombat {
namespace editor {

ImageSelectorDialog::ImageSelectorDialog(QWidget *parent, ModelIoManager *modelIo, QString projectPath, QString title = "Image Selector"): QDialog(parent) {
	setWindowTitle(title);
	setMinimumSize(600, 400);
	adjustSize();

	m_vbox = new QVBoxLayout(this);
	m_btnBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
	m_widget = new ImageSelectorWidget(this, projectPath, modelIo);

	m_vbox->addWidget(m_widget);
	m_vbox->addWidget(m_btnBox);
	setLayout(m_vbox);

	connect(m_btnBox, SIGNAL(accepted()), this, SLOT(okPressed()));
	connect(m_btnBox, SIGNAL(rejected()), this, SLOT(reject()));
}

ImageSelectorDialog::~ImageSelectorDialog() {
	disconnect(m_btnBox, SIGNAL(accepted()), this, SLOT(okPressed()));
	disconnect(m_btnBox, SIGNAL(rejected()), this, SLOT(reject()));

	delete m_vbox;
	delete m_btnBox;
	delete m_widget;
}

void ImageSelectorDialog::okPressed() {
	accept();
}

}
}
