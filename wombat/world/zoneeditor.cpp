#include <QScrollBar>
#include <QVBoxLayout>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <wombat/core/spritesheetmanager.hpp>
#include "zoneeditor.hpp"

namespace wombat {
namespace world {

using namespace core;
using namespace editor;

const int ZoneEditor::TileWidth = 32;
const int ZoneEditor::TileHeight = 32;

ZoneEditor::ZoneEditor(EditorWidgetParams args):
EditorWidget(args), m_worldUtil(args.models) {
	m_projectPath = args.projectPath;
	m_header.fromJson(modelIoManager()->readAbsolutePath(absolutePath()));
	m_model.fromJson(modelIoManager()->readAbsolutePath(m_projectPath + "/" + m_header.Zone + ".json"));

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
	m_tiles.resize(m_header.Layers);
	for (auto &layer : m_tiles) {
		layer.resize(m_header.TilesHigh);
		for (auto &row : layer) {
			row.resize(m_header.TilesWide);
			for (auto &tile : row) {
				tile.init(this);
			}
		}
	}

	for (auto layer = 0; layer < m_model.Tiles.size(); layer++) {
		auto &rows = m_model.Tiles[layer];
		for (auto y = 0; y < rows.size(); y++) {
			auto &tiles = rows[y];
			for (auto x = 0; x < tiles.size(); x++) {
				auto &tile = tiles[x];
				m_tiles[layer][y][x].set(tile, x * TileWidth, y * TileHeight);
			}
		}
	}
}

int ZoneEditor::saveFile() {
	return 1;
}

void ZoneEditor::Tile::init(ZoneEditor *parent) {
	m_parent = parent;
}

void ZoneEditor::Tile::set(models::Tile tile, int x, int y) {
	auto &key = tile.TileClass.Import;
	auto &classes = m_parent->m_tileClasses;
	if (key != "") {
		if (!classes.contains(key)) {
			auto &modelio = *m_parent->modelIoManager();
			auto path = m_parent->m_projectPath + "/" + key + ".json";
			auto json = modelio.readAbsolutePath(path);
			classes[key].fromJson(json);
		}
	}

	auto &c = classes[key];
	auto lower = firstImageOf(c.LowerAnim.Animation);
	auto upper = firstImageOf(c.UpperAnim.Animation);

	addItem(m_lower, lower, x, y);
	addItem(m_upper, upper, x, y);
}

QPixmap *ZoneEditor::Tile::firstImageOf(QString animPath) {
	QPixmap *retval = nullptr;
	if (animPath != "") {
		auto &imgs = m_parent->m_imgs;
		if (!imgs.contains(animPath)) {
			models::Animation model;
			auto &modelio = *m_parent->modelIoManager();
			auto path = m_parent->m_projectPath + "/" + animPath + ".json";
			auto json = modelio.readAbsolutePath(path);
			model.fromJson(json);
			if (model.Images.size()) {
				auto img = model.Images[0].Image;
				imgs[animPath] = SpriteSheetManager::getPixmap(img, m_parent->m_projectPath);
			}
		}
		retval = &imgs[animPath];
	}
	return retval;
}

QGraphicsPixmapItem *ZoneEditor::Tile::addItem(QGraphicsPixmapItem *&gfxItem,
                                               QPixmap *img, int x, int y) {
	auto &scene = *m_parent->m_scene;
	if (gfxItem) {
		scene.removeItem(gfxItem);
		gfxItem = nullptr;
	}
	if (img) {
		gfxItem = scene.addPixmap(*img);
		gfxItem->setPos(x, y);
	}
	return gfxItem;
}

}
}
