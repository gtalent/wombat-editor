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
		QDialogButtonBox *m_btnBox = nullptr;
		QVBoxLayout *m_vbox = nullptr;
		ImageSelectorWidget *m_widget = nullptr;

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
