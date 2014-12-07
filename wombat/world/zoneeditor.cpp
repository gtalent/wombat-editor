#include <QDebug>
#include <QScrollBar>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QMouseEvent>
#include <wombat/core/spritesheetmanager.hpp>
#include "tileclassexplorer.hpp"
#include "zoneeditor.hpp"

namespace wombat {
namespace world {

using namespace core;
using namespace editor;

const int ZoneEditor::TileWidth = 32;
const int ZoneEditor::TileHeight = 32;

// TileClas
ZoneEditor::UpdateTileCommand::UpdateTileCommand
(ZoneEditor *parent, models::Point address, models::Tile before, models::Tile after) {
	m_parent = parent;
	m_address = address;
	m_before = before;
	m_after = after;
}

void ZoneEditor::UpdateTileCommand::undo() {
	m_parent->updateTile(m_address.X, m_address.Y, m_before);
}

void ZoneEditor::UpdateTileCommand::redo() {
	m_parent->updateTile(m_address.X, m_address.Y, m_after);
}

// ZoneEditorTile

ZoneEditorTile::ZoneEditorTile(const ZoneEditorTile &o) {
	m_parent = o.m_parent;
	m_lower = o.m_lower;
	m_upper = o.m_upper;
	m_occupant = o.m_occupant;
}

ZoneEditorTile::~ZoneEditorTile() {
	rmItem(m_lower.data());
	rmItem(m_upper.data());
}

void ZoneEditorTile::init(ZoneEditor *parent) {
	m_parent = parent;
}

void ZoneEditorTile::set(models::Tile tile, int x, int y) {
	set(tile.TileClass, x, y);
}

void ZoneEditorTile::set(models::TileClass tc, int x, int y) {
	auto &key = tc.Import;
	auto &classes = m_parent->m_tileClasses;
	if (key != "") {
		if (!classes.contains(key)) {
			auto &modelio = *m_parent->modelIoManager();
			auto path = m_parent->m_projectPath + "/" + key;
			auto json = modelio.readAbsolutePath(path);
			classes[key].fromJson(json);
		}
	}

	auto &c = classes[key];
	auto lowerPm = firstImageOf(c.LowerAnim.Animation);
	auto upperPm = firstImageOf(c.UpperAnim.Animation);

	m_lower = QSharedPointer<QGraphicsPixmapItem>(addItem(m_lower.data(), lowerPm, x, y));
	m_upper = QSharedPointer<QGraphicsPixmapItem>(addItem(m_upper.data(), upperPm, x, y));
}

QPixmap *ZoneEditorTile::firstImageOf(QString animPath) {
	QPixmap *retval = nullptr;
	if (animPath != "") {
		auto &imgs = m_parent->m_imgs;
		if (!imgs.contains(animPath)) {
			models::Animation model;
			auto &modelio = *m_parent->modelIoManager();
			auto path = m_parent->m_projectPath + "/" + animPath;
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

QGraphicsPixmapItem *ZoneEditorTile::addItem(QGraphicsPixmapItem *gfxItem,
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

void ZoneEditorTile::rmItem(QGraphicsPixmapItem *gfxItem) {
	if (gfxItem) {
		m_parent->m_scene->removeItem(gfxItem);
	}
}


// ZoneEditorGraphicsView

class ZoneEditorGraphicsView: public QGraphicsView {
	private:
		ZoneEditor *m_parent = nullptr;

	public:
		ZoneEditorGraphicsView(ZoneEditor *parent);

		void mouseMoveEvent(QMouseEvent *event);

		void mousePressEvent(QMouseEvent *event);
};

ZoneEditorGraphicsView::ZoneEditorGraphicsView(ZoneEditor *parent):
QGraphicsView(parent) {
	m_parent = parent;
}

void ZoneEditorGraphicsView::mouseMoveEvent(QMouseEvent*) {
}

void ZoneEditorGraphicsView::mousePressEvent(QMouseEvent *event) {
	auto pos = mapToScene(event->pos());
	if (m_parent) {
		m_parent->click(pos.x(), pos.y());
	}
}


// ZoneEditor

ZoneEditor::ZoneEditor(EditorWidgetParams args):
EditorWidget(args), m_worldUtil(args.models) {
	m_projectPath = args.projectPath;
	m_header.fromJson(modelIoManager()->readAbsolutePath(absolutePath()));
	m_model.fromJson(modelIoManager()->read(m_header.Zone));

	buildGui();
	loadView();
}

int ZoneEditor::saveFile() {
	auto json = m_header.toJson(models::cyborgbear::Readable);
	auto ret = modelIoManager()->writeAbsolutePath(absolutePath(), json);

	json = m_model.toJson(models::cyborgbear::Readable);
	ret |= modelIoManager()->write(m_header.Zone, json);

	notifyFileSave();
	return ret;
}

void ZoneEditor::click(int x, int y) {
	auto co = &context().commonObject(TileClassExplorer::DockId);
	auto te = dynamic_cast<TileClassExplorer*>(co);
	x /= TileWidth;
	y /= TileHeight;
	models::Point addr;
	addr.X = x;
	addr.Y = y;
	if (te) {
		models::TileClass tc;
		tc.Import = te->selectedTile();
		if (tc.Import != "") {
			auto &old = m_model.Tiles[0][y][x];
			auto updated = old;
			updated.TileClass = tc;

			notifyFileChange(new UpdateTileCommand(this, addr, old, updated));
		}
	}
}

void ZoneEditor::updateTileClass(int x, int y, models::TileClass tc) {
	// TODO: bounds checking
	auto &tile = m_model.Tiles[0][y][x];
	tile.TileClass = tc;
	m_tiles[0][y][x].set(tile, x * TileWidth, y * TileHeight);
}

void ZoneEditor::updateTile(int x, int y, models::Tile tile) {
	// TODO: bounds checking
	m_model.Tiles[0][y][x] = tile;
	m_tiles[0][y][x].set(tile, x * TileWidth, y * TileHeight);
}

void ZoneEditor::buildGui() {
	auto layout = new QVBoxLayout(this);
	m_graphicsView = new ZoneEditorGraphicsView(this);

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

}
}