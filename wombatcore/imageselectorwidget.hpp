#ifndef IMAGESELECTORWIDGET_HPP
#define IMAGESELECTORWIDGET_HPP

#include <QWidget>
#include <QString>

namespace Ui {
class ImageSelectorWidget;
}

namespace wombat {
namespace editor {

class ImageSelectorWidget: public QWidget {
	Q_OBJECT

	private:
		QString m_projectPath;

	public:
		ImageSelectorWidget(QWidget *parent, QString projectPath);
		~ImageSelectorWidget();

	private:
		Ui::ImageSelectorWidget *ui;
};

}
}

#endif // IMAGESELECTOR_HPP
