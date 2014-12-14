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

		ZoneEditorTile &operator=(const ZoneEditorTile &o);

		void init(class ZoneEditor *parent);

		void set(models::Tile, int x, int y);

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
		struct TileUpdate {
			models::Tile before;
			models::Tile after;
		};

		// Commands
		class UpdateTileCommand: public QUndoCommand {
			private:
				ZoneEditor *m_parent = nullptr;
				QMap<models::Point, TileUpdate> m_changeBuffer;

			public:
				UpdateTileCommand(ZoneEditor *parent, QMap<models::Point, TileUpdate> changeBuffer);

				void undo();

				void redo();
		};

		QString m_projectPath;
		QGraphicsView *m_graphicsView = nullptr;
		QGraphicsScene *m_scene = nullptr;
		QMap<QGraphicsItem*, models::Point> m_imgPtMap;
		// maps Animation paths to the first image of the Animation
		QMap<QString, QSharedPointer<QPixmap>> m_imgs;
		QMap<QString, models::TileClass> m_tileClasses;
		QVector<QVector<QVector<ZoneEditorTile>>> m_tiles;
		QMap<models::Point, TileUpdate> m_changeBuffer;
		QVector<QSharedPointer<ZoneEditorTile>> m_previewTiles;
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

	public slots:
		void refreshImageCache();

	protected:
		/**
		 * @param x x coordinate to register the click at within the Zone
		 * @param y y coordinate to register the click at within the Zone
		 */
		void click(int x, int y);

	private:
		void applyTile(int x, int y, models::Tile tile);

		/**
		 * Updates the Tile at the given location with the given TileClass.
		 * @param x x coordinate to regester the click at within the Zone
		 * @param y y coordinate to regester the click at within the Zone
		 * @param tc the TileClass to give the Tile at the given address
		 */
		void pushTileUpdate(int x, int y, models::TileClass tc);

		/**
		 * Pushes a change to the change buffer at the given address.
		 */
		void pushChange(int x, int y);

		/**
		 * Applies the changes in the change buffer, and then clears the change buffer.
		 */
		void applyChanges();

		void buildGui();

		void loadView();
};

}
}

#endif
