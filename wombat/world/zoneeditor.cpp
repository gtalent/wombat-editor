#include <QVBoxLayout>
#include "zoneeditor.hpp"

namespace wombat {
namespace world {

using editor::EditorWidget;
using editor::EditorWidgetParams;

const int ZoneEditor::TileWidth = 32;
const int ZoneEditor::TileHeight = 32;

ZoneEditor::ZoneEditor(EditorWidgetParams args): EditorWidget(args) {
	m_header.fromJson(modelIoManager()->read(path()));
	m_model.fromJson(m_header.Zone);
	buildGui();
	loadView();
}

void ZoneEditor::buildGui() {
	auto layout = new QVBoxLayout(this);
	m_graphicsView = new QGraphicsView(this);

	int width = m_header.TilesWide * TileWidth;
	int height = m_header.TilesHigh * TileHeight;
	m_scene = new QGraphicsScene(0, 0, width, height, this);

	m_graphicsView->setBackgroundBrush(QColor(0, 0, 0, 175));
	m_graphicsView->setAutoFillBackground(true);
	m_graphicsView->setScene(m_scene);
	layout->addWidget(m_graphicsView);
}

void ZoneEditor::loadView() {
	for (auto tiles : m_model.Tiles) {
		for (auto tiles : tiles) {
			for (auto tile : tiles) {
				addTile(tile);
			}
		}
	}
}

int ZoneEditor::saveFile() {
	return 1;
}

void ZoneEditor::addTile(models::Tile) {
}

}
}
