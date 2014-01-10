#ifndef IMAGESELECTORDIALOG_HPP
#define IMAGESELECTORDIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QBoxLayout>
#include <QString>

#include "spritesheetmanager.hpp"
#include "imageselectorwidget.hpp"

namespace wombat {
namespace editor {

class ImageSelectorDialog: public QDialog {
	Q_OBJECT

	private:
		QDialogButtonBox *m_btnBox;
		QVBoxLayout *m_vbox;
		ImageSelectorWidget *m_widget;

	public:
		ImageSelectorDialog(QWidget *parent, ModelIoManager *modelIo, QString projectPath, QString path);
		~ImageSelectorDialog();

	private slots:
		void okPressed();
};

}
}

#endif // IMAGESELECTOR_HPP
