#ifndef WOMBATCORE_IMAGESELECTORDIALOG_HPP
#define WOMBATCORE_IMAGESELECTORDIALOG_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QBoxLayout>
#include <QString>

#include "spritesheetmanager.hpp"
#include "imageselectorwidget.hpp"

namespace wombat {
namespace core {

class ImageSelectorDialog: public QDialog {
	Q_OBJECT

	private:
		QDialogButtonBox *m_btnBox;
		QVBoxLayout *m_vbox;
		ImageSelectorWidget *m_widget;

	public:
		ImageSelectorDialog(QWidget *parent, ModelIoManager *modelIo, QString projectPath, QString path);
		~ImageSelectorDialog();

		models::Image selectedImage();

	private slots:
		void okPressed();
};

}
}

#endif // IMAGESELECTOR_HPP
