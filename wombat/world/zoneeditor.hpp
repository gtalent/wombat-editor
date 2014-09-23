#ifndef WOMBAT_WORLD_ZONEEDITOR_HPP
#define WOMBAT_WORLD_ZONEEDITOR_HPP

#include <QGraphicsView>
#include <QMap>
#include <QPair>
#include <editorcore/editorwidget.hpp>
#include <models/models.hpp>

namespace wombat {
namespace world {

class ZoneEditor: public editor::EditorWidget {
	Q_OBJECT
	private:
		QGraphicsView *m_graphicsView = nullptr;
		QGraphicsScene *m_scene = nullptr;
		QMap<QGraphicsItem*, models::Point> m_imgPtMap;
		models::Zone m_model;
		models::ZoneHeader m_header;
		const static int TileWidth, TileHeight;

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

		void addTile(models::Tile tile);
};

}
}

#endif
