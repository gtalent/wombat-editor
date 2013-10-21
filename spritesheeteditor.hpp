#ifndef SPRITESHEETEDITOR_HPP
#define SPRITESHEETEDITOR_HPP

#include <QString>
#include <QMap>
#include <QGraphicsScene>

#include "models/models.hpp"

#include "editortab.hpp"

namespace Ui {
class SpriteSheetEditor;
}

class SpriteSheetEditor: public EditorTab {
	Q_OBJECT

	private:

		//COMMANDS
		class AddImageCommand: public QUndoCommand {
			public:
				AddImageCommand();
				void undo();
				void redo();
		};

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
		QMap<int, Image *> m_imgs;

	public:
		explicit SpriteSheetEditor(QWidget *parent, QString projectDir, QString path);
		~SpriteSheetEditor();
		QPixmap buildImage(QImage*, models::Bounds);
		virtual bool saveFile();
		
	public slots:
		int addImages();

	private:
		int load(QString path);
		void draw();
		int newImageId();
};

#endif // SPRITESHEETEDITOR_HPP
