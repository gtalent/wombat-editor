#ifndef SPRITESHEETEDITOR_HPP
#define SPRITESHEETEDITOR_HPP

#include <QString>
#include <QMap>
#include <QGraphicsScene>

#include "models/editormodels.hpp"
#include "editorcore/editorwidget.hpp"
#include "editorcore/editorwidgetparams.hpp"

namespace Ui {
class SpriteSheetEditor;
}

namespace wombat {
namespace core {

class SpriteSheetEditor: public editor::EditorWidget {
	Q_OBJECT

	private:

		class Image {
			public:
				QPixmap pxMap;
				QImage img;
				models::Bounds srcBnds;
				int imgId;
				// The location of the image on the sprite sheet
				int x, y;
		};

		//COMMANDS
		class AddImageCommand: public QUndoCommand {
			private:
				QVector<Image> m_newImages;
				SpriteSheetEditor *m_parent;
				models::SpriteSheet m_before;
				models::SpriteSheet m_after;
			public:
				AddImageCommand(SpriteSheetEditor *parent, QVector<Image> imgs,
									 models::SpriteSheet before, models::SpriteSheet after);
				void undo();
				void redo();
		};

		class RemoveImageCommand: public QUndoCommand {
			private:
				QVector<Image> m_newImages;
				SpriteSheetEditor *m_parent;
				models::SpriteSheet m_before;
				models::SpriteSheet m_after;
			public:
				RemoveImageCommand(SpriteSheetEditor *parent, QVector<Image> imgs,
										 models::SpriteSheet before, models::SpriteSheet after);
				virtual ~RemoveImageCommand();
				void undo();
				void redo();
		};

		Ui::SpriteSheetEditor *ui;
		models::SpriteSheet m_model;
		models::Point m_sheetIdx;
		QString m_projectPath;
		QGraphicsScene *m_scene;
		QMap<int, Image> m_imgs;

	public:
		explicit SpriteSheetEditor(editor::EditorWidgetParams);
		~SpriteSheetEditor();
		QImage buildImage(QImage*, models::Bounds);
		virtual int saveFile();
		
	private slots:
		int addImages();
		int removeImage();
		void sceneSelection();

	private:
		/**
		 * Returns point associated with the given index.
		 */
		models::Point indexPoint(int i);
		int load(QString path);
		void draw();
		int newImageId();
		void recycleImageId(int imgId);
};

}
}

#endif // SPRITESHEETEDITOR_HPP
