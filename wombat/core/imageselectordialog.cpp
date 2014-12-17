#include "imageselectordialog.hpp"

namespace wombat {
namespace core {

ImageSelectorDialog::ImageSelectorDialog(QWidget *parent, const ModelIoManager &modelIo, QString projectPath, QString title = "Image Selector"): QDialog(parent) {
	setWindowTitle(title);
	setMinimumSize(600, 400);
	setMaximumSize(600, 400);
	setSizeGripEnabled(false);
	adjustSize();

	m_vbox = new QVBoxLayout(this);
	m_btnBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal, this);
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

models::Image ImageSelectorDialog::selectedImage() {
	return m_widget->selectedImage();
}

void ImageSelectorDialog::okPressed() {
	auto sel = m_widget->selectedImage();
	if (sel.ImgId != -1) {
		accept();
	}
}

}
}
