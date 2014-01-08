#ifndef IMAGESELECTORDIALOG_HPP
#define IMAGESELECTORDIALOG_HPP

#include <QDialog>
#include <QBoxLayout>
#include <QString>

#include "spritesheetmanager.hpp"
#include "imageselectorwidget.hpp"

namespace wombat {
namespace editor {

class ImageSelectorDialog: public QDialog {
	Q_OBJECT

	private:
		QVBoxLayout *m_vbox;
		ImageSelectorWidget *m_widget;
		SpriteSheetManager *m_mgr;

	public:
		ImageSelectorDialog(QWidget *parent, QString projectPath, QString path);
		~ImageSelectorDialog();
};

}
}

#endif // IMAGESELECTOR_HPP
