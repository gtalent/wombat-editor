#ifndef SPRITESHEETEDITOR_HPP
#define SPRITESHEETEDITOR_HPP

#include <string>

#include <QString>
#include <QVector>
#include <QGraphicsScene>

#include "models/editormodels.hpp"
#include "models/enginemodels.hpp"

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
				enginemodels::Bounds srcBnds;
		};

		Ui::SpriteSheetEditor *ui;
		QString m_projectDir;
		enginemodels::SpriteSheet m_model;
		QGraphicsScene *m_scene;
		enginemodels::Point m_sheetIdx;
		Image ***m_imgs;

	public:
		explicit SpriteSheetEditor(QWidget *parent, QString projectDir, QString path);
		~SpriteSheetEditor();
		QPixmap buildImage(QImage*, enginemodels::Bounds);
		virtual bool saveFile();
		
	public slots:
		int addImages();

	private:
		void draw();
};

#endif // SPRITESHEETEDITOR_HPP
