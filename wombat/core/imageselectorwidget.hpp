#ifndef WOMBATCORE_IMAGESELECTORWIDGET_HPP
#define WOMBATCORE_IMAGESELECTORWIDGET_HPP

#include <QWidget>
#include <QGraphicsScene>
#include <QString>
#include <models/models.hpp>
#include <editorcore/modeliomanager.hpp>

namespace Ui {
class ImageSelectorWidget;
}

namespace wombat {
namespace core {

using namespace editor;

class ImageSelectorWidget: public QWidget {
	Q_OBJECT

	private:
		Ui::ImageSelectorWidget *ui = nullptr;
		QString m_projectPath;
		QGraphicsScene *m_scene = nullptr;
		ModelIoManager *m_modelIo = nullptr;
		QString m_currentModelPath;
		models::SpriteSheet m_model;
		QMap<QString, int> m_ptToImg;

	public:
		ImageSelectorWidget(QWidget *parent, QString projectPath, ModelIoManager *modelIo);
		~ImageSelectorWidget();

		int openSpriteSheet(QString path);

		models::Image selectedImage();

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
