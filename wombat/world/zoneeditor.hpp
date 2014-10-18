#ifndef WOMBAT_WORLD_ZONEEDITOR_HPP
#define WOMBAT_WORLD_ZONEEDITOR_HPP

#include <QGraphicsView>
#include <QMap>
#include <QObject>
#include <QPair>
#include <editorcore/editorwidget.hpp>
#include <models/models.hpp>
#include "worldutil.hpp"

namespace wombat {
namespace world {

class ZoneEditorTile: public QObject {
	Q_OBJECT
	protected:
		class ZoneEditor *m_parent = nullptr;
		QGraphicsPixmapItem *m_lower = nullptr;
		QGraphicsPixmapItem *m_upper = nullptr;
		QGraphicsPixmapItem *m_occupant = nullptr;

	public:
		ZoneEditorTile() = default;

		ZoneEditorTile(const ZoneEditorTile &o);

		void init(class ZoneEditor *parent);

		void set(models::Tile, int x, int y);

	private:
		QPixmap *firstImageOf(QString animPath);

		QGraphicsPixmapItem *addItem(QGraphicsPixmapItem *&gfxItem, QPixmap *img, int x, int y);
};

class ZoneEditor: public editor::EditorWidget {
	Q_OBJECT
	friend ZoneEditorTile;
	private:
		QString m_projectPath;
		QGraphicsView *m_graphicsView = nullptr;
		QGraphicsScene *m_scene = nullptr;
		QMap<QGraphicsItem*, models::Point> m_imgPtMap;
		// maps Animation paths to the first image of the Animation
		QMap<QString, QPixmap> m_imgs;
		QMap<QString, models::TileClass> m_tileClasses;
		QVector<QVector<QVector<ZoneEditorTile>>> m_tiles;
		models::Zone m_model;
		models::ZoneHeader m_header;
		WorldUtil m_worldUtil;
		const static int TileWidth;
		const static int TileHeight;

	public:
		/**
		 * Constructor
		 * @param args standard EditorWidget arguments
		 */
		ZoneEditor(editor::EditorWidgetParams args);

		int saveFile() override;

	private:
		void buildGui();

		void loadView();
};

}
}

#endif
