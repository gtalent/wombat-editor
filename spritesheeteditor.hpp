#ifndef SPRITESHEETEDITOR_HPP
#define SPRITESHEETEDITOR_HPP

#include <QString>
#include <QVector>
#include <QGraphicsScene>

#include "models/models.hpp"

#include "editortab.hpp"

namespace Ui {
class SpriteSheetEditor;
}

class SpriteSheetEditor: public EditorTab {
	Q_OBJECT

	private:

		class Image {
			public:
				QPixmap img;
				models::Bounds srcBnds;
				int imgId;
				// The location of the image on the sprite sheet
				int x, y;
		};

		Ui::SpriteSheetEditor *ui;
		QString m_projectDir;
		models::SpriteSheet m_model;
		QGraphicsScene *m_scene;
		models::Point m_sheetIdx;
		QVector<Image *> m_imgs;

	public:
		explicit SpriteSheetEditor(QWidget *parent, QString projectDir, QString path);
		~SpriteSheetEditor();
		QPixmap buildImage(QImage*, models::Bounds);
		virtual bool saveFile();
		
	public slots:
		int addImages();

	private:
		void draw();
};

#endif // SPRITESHEETEDITOR_HPP
