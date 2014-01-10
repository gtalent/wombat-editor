#ifndef IMAGESELECTORWIDGET_HPP
#define IMAGESELECTORWIDGET_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QString>
#include "models/editormodels.hpp"
#include "editorcore/modeliomanager.hpp"

namespace Ui {
class ImageSelectorWidget;
}

namespace wombat {
namespace editor {

class ImageSelectorWidget: public QWidget {
	Q_OBJECT

	private:
		Ui::ImageSelectorWidget *ui;
		QString m_projectPath;
		QGraphicsScene *m_scene;
		ModelIoManager *m_modelIo;
		models::SpriteSheet m_model;
		QMap<QString, int> m_ptToImg;

	public:
		ImageSelectorWidget(QWidget *parent, QString projectPath, ModelIoManager *modelIo);
		~ImageSelectorWidget();

		int openSpriteSheet(QString path);

		int selectedWidget();

	private:
		void populateSheetSelect();
		
		QString pointKey(int x, int y);

		int pointImgId(int x, int y);

	private slots:
		void changeSpriteSheet(QString);
};

}
}

#endif // IMAGESELECTOR_HPP
