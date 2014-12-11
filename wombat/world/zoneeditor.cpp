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
(ZoneEditor *parent, QMap<models::Point, ZoneEditor::TileUpdate> changeBuffer) { 
	m_parent = parent;
	m_changeBuffer = changeBuffer;
}

void ZoneEditor::UpdateTileCommand::undo() {
	for (auto c = m_changeBuffer.begin(); c != m_changeBuffer.end(); c++) {
		auto &addr = c.key();
		m_parent->applyTile(addr.X, addr.Y, m_changeBuffer[addr].before);
	}
}

void ZoneEditor::UpdateTileCommand::redo() {
	for (auto c = m_changeBuffer.begin(); c != m_changeBuffer.end(); c++) {
		auto &addr = c.key();
		m_parent->applyTile(addr.X, addr.Y, m_changeBuffer[addr].after);
	}
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

ZoneEditorTile &ZoneEditorTile::operator=(const ZoneEditorTile &o) {
	m_parent = o.m_parent;
	m_lower = o.m_lower;
	m_upper = o.m_upper;
	m_occupant = o.m_occupant;
	return *this;
}

void ZoneEditorTile::init(ZoneEditor *parent) {
	m_parent = parent;
}

void ZoneEditorTile::set(models::Tile tile, int x, int y) {
	auto tc = tile.TileClass;
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

		void mouseReleaseEvent(QMouseEvent *event);
};

ZoneEditorGraphicsView::ZoneEditorGraphicsView(ZoneEditor *parent):
QGraphicsView(parent) {
	m_parent = parent;
}

void ZoneEditorGraphicsView::mouseMoveEvent(QMouseEvent *event) {
	auto pos = mapToScene(event->pos());
	if (m_parent) {
		m_parent->pushChange(pos.x(), pos.y());
	}
}

void ZoneEditorGraphicsView::mousePressEvent(QMouseEvent *event) {
	auto pos = mapToScene(event->pos());
	if (m_parent) {
		m_parent->pushChange(pos.x(), pos.y());
	}
}

void ZoneEditorGraphicsView::mouseReleaseEvent(QMouseEvent*) {
	if (m_parent) {
		m_parent->applyChanges();
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

	// get current cursor address
	models::Point addr;
	addr.X = x / TileWidth;
	addr.Y = y / TileHeight;

	if (te) {
		models::TileClass tc;
		tc.Import = te->selectedTile();
		if (tc.Import != "") {
			auto &old = m_model.Tiles[0][addr.Y][addr.X];
			auto updated = old;
			updated.TileClass = tc;

			if (old != updated) {
				notifyFileChange(new UpdateTileCommand(this, m_changeBuffer));
			}
		}
	}
}

void ZoneEditor::applyTile(int x, int y, models::Tile tile) {
	m_model.Tiles[0][y][x] = tile;
	m_tiles[0][y][x].set(tile, x * TileWidth, y * TileHeight);
}

void ZoneEditor::pushTileUpdate(int x, int y, models::TileClass tc) {
	models::Point addr;
	addr.X = x / TileWidth;
	addr.Y = y / TileHeight;

	const auto &current = m_model.Tiles[0][addr.Y][addr.X];
	if (current.TileClass != tc) {
		m_changeBuffer[addr].before = current;
		auto &after = m_changeBuffer[addr].after = current;
		after.TileClass = tc;

		QSharedPointer<ZoneEditorTile> zet(new ZoneEditorTile());
		zet->init(this);
		zet->set(after, addr.X * TileWidth, addr.Y * TileHeight);
		m_previewTiles.push_back(zet);
	}
}

void ZoneEditor::pushChange(int x, int y) {
	auto co = &context().commonObject(TileClassExplorer::DockId);
	auto te = dynamic_cast<TileClassExplorer*>(co);

	if (te) {
		models::TileClass tc;
		tc.Import = te->selectedTile();
		if (tc.Import != "") {
			auto addrX = x / TileWidth;
			auto addrY = y / TileHeight;

			if (m_model.Tiles.size() > 0) {
				if (m_model.Tiles[0].size() > addrY && addrY >= 0) {
					if (m_model.Tiles[0][addrY].size() > addrX && addrX >= 0) {

						pushTileUpdate(x, y, tc);

					}
				}
			}

		}
	}
}

void ZoneEditor::applyChanges() {
	if (m_changeBuffer.size()) {
		notifyFileChange(new UpdateTileCommand(this, m_changeBuffer));
		m_changeBuffer.clear();
		m_previewTiles.clear();
	}
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
