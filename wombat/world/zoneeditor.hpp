#ifndef WOMBAT_WORLD_ZONEEDITOR_HPP
#define WOMBAT_WORLD_ZONEEDITOR_HPP

#include <QGraphicsView>
#include <QMap>
#include <QObject>
#include <QPair>
#include <QSharedPointer>
#include <editorcore/editorwidget.hpp>
#include <models/models.hpp>
#include "worldutil.hpp"

namespace wombat {
namespace world {

class ZoneEditorTile: public QObject {
	Q_OBJECT
	protected:
		class ZoneEditor *m_parent = nullptr;
		QSharedPointer<QGraphicsPixmapItem> m_lower;
		QSharedPointer<QGraphicsPixmapItem> m_upper;
		QSharedPointer<QGraphicsPixmapItem> m_occupant;

	public:
		ZoneEditorTile() = default;

		ZoneEditorTile(const ZoneEditorTile &o);

		~ZoneEditorTile();

		void init(class ZoneEditor *parent);

		void set(models::Tile, int x, int y);

		void set(models::TileClass, int x, int y);

	private:
		QPixmap *firstImageOf(QString animPath);

		QGraphicsPixmapItem *addItem(QGraphicsPixmapItem *gfxItem, QPixmap *img, int x, int y);

		void rmItem(QGraphicsPixmapItem *gfxItem);
};

class ZoneEditor: public editor::EditorWidget {
	Q_OBJECT
	friend class ZoneEditorTile;
	friend class ZoneEditorGraphicsView;
	private:
		// Commands
		class UpdateTileCommand: public QUndoCommand {
			private:
				ZoneEditor *m_parent = nullptr;
				models::Point m_address;
				models::Tile m_before;
				models::Tile m_after;

			public:
				UpdateTileCommand(ZoneEditor *parent, models::Point address, models::Tile before, models::Tile after);

				void undo();

				void redo();
		};

		QString m_projectPath;
		QGraphicsView *m_graphicsView = nullptr;
		QGraphicsScene *m_scene = nullptr;
		QMap<QGraphicsItem*, models::Point> m_imgPtMap;
		// maps Animation paths to the first image of the Animation
		QMap<QString, QPixmap> m_imgs;
		QMap<QString, models::TileClass> m_tileClasses;
		QVector<QVector<QVector<ZoneEditorTile>>> m_tiles;
		ZoneEditorTile m_cursorTile;
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

	protected:
		/**
		 * @param x x coordinate to register the click at within the Zone
		 * @param y y coordinate to register the click at within the Zone
		 */
		void click(int x, int y);

	private:
		/**
		 * Updates the tile at the given location with the TileClass
		 * currently selected in the TileClass Explorer.
		 * @param x x coordinate to regester the click at within the Zone
		 * @param y y coordinate to regester the click at within the Zone
		 */
		void updateTileClass(int x, int y, models::TileClass);

		void updateTile(int x, int y, models::Tile tc);

		void buildGui();

		void loadView();
};

}
}

#endif
