#include <QDialogButtonBox>
#include <QDir>

#include "imageselectordialog.hpp"

namespace wombat {
namespace editor {

ImageSelectorDialog::ImageSelectorDialog(QWidget *parent, QString projectPath, QString title = "Image Selector"): QDialog(parent) {
	setWindowTitle(title);
	setBaseSize(600, 500);

	m_vbox = new QVBoxLayout();
	m_widget = new ImageSelectorWidget(this, projectPath);

	m_vbox->addWidget(m_widget);
	setLayout(m_vbox);

	m_mgr = 0;
}

ImageSelectorDialog::~ImageSelectorDialog() {
	delete m_vbox;
	delete m_widget;
}

}
}
