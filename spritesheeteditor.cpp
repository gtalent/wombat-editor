#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QAbstractItemModel>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include "editorcore/misc.hpp"
#include "spritesheeteditor.hpp"
#include "ui_spritesheeteditor.h"

using std::string;

class AnimationTreeModel: public QAbstractItemModel {
	Q_OBJECT
	public:
 		QVariant data(const QModelIndex&, int) const;
 		Qt::ItemFlags flags(const QModelIndex&) const;
 		QVariant headerData(int, Qt::Orientation, int role = Qt::DisplayRole) const;
};

SpriteSheetEditor::SpriteSheetEditor(QWidget *parent, QString projectDir, QString path): EditorTab(parent, path), ui(new Ui::SpriteSheetEditor) {
	ui->setupUi(this);
	m_projectDir = projectDir;
	load(path);
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;
	m_scene = new QGraphicsScene(0, 0, width, height, this);
	connect(m_scene, SIGNAL(selectionChanged()), this, SLOT(sceneSelection()));
	ui->canvas->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	ui->canvas->setScene(m_scene);
	ui->canvas->setStyleSheet("background-color: transparent");
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));
	draw();
}

SpriteSheetEditor::~SpriteSheetEditor() {
	disconnect(m_scene, SIGNAL(selectionChanged()), this, SLOT(sceneSelection()));
	delete ui;
	delete m_scene;
}

bool SpriteSheetEditor::saveFile() {
	notifyFileSave();
	m_model.writeJsonFile(path(), models::cyborgbear::Readable);

	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;

	QImage imgOut(width, height, QImage::Format_ARGB32);

	for (auto i = m_model.images.begin(); i != m_model.images.end(); ++i) {
		QImage &src = m_imgs[i.key()].img;
		for (int x = 0; x < i.value().srcBounds.width; x++) {
			for (int y = 0; y < i.value().srcBounds.height; y++) {
				imgOut.setPixel(i.value().srcBounds.x + x, i.value().srcBounds.y + y, src.pixel(x, y));
			}
		}
	}

	return imgOut.save(m_model.srcFile, "png", 100);
}

QImage SpriteSheetEditor::buildImage(QImage *src, models::Bounds bnds) {
	int w = m_model.tileWidth;
	int h = m_model.tileHeight;
	QImage sprt(w, h, QImage::Format_ARGB32);
	sprt.fill(0);

	for (int i = 0; i < w; i++) {
		for (int ii = 0; ii < h; ii++) {
			sprt.setPixel(i, ii, src->pixel(i + bnds.x, ii + bnds.y));
		}
	}
	return sprt;
}

int SpriteSheetEditor::newImageId() {
	int retval;
	if (m_model.recycledImageIds.empty()) {
		retval = m_model.imageIdIterator++;
	} else {
		retval = m_model.recycledImageIds.back();
		m_model.recycledImageIds.pop_back();
	}
	return retval;
}

void SpriteSheetEditor::recycleImageId(int imgId) {
	m_model.recycledImageIds.push_back(imgId);
}

int SpriteSheetEditor::addImages() {
	auto before = m_model;
	QStringList files = QFileDialog::getOpenFileNames(parentWidget(), "Choose images to import...", QDir::homePath());
	if (files.size()) {
		QVector<Image> imgs;
		for (int n = 0; n < files.size(); n++) {
			QImage src(files[n]);
			for (int i = 0; i < files.size(); i += m_model.tileHeight) {
				for (int ii = 0; ii < files.size(); ii += m_model.tileWidth) {
					int imgId = newImageId();
					if (imgId >= m_model.tilesHigh * m_model.tilesWide) {
						return 1;
					}

					models::SpriteSheetImage imgModel;
					models::Point pt = indexPoint(imgId);
					imgModel.srcBounds.x = pt.x * m_model.tileWidth;
					imgModel.srcBounds.y = pt.y * m_model.tileHeight;
					imgModel.srcBounds.width = m_model.tileWidth;
					imgModel.srcBounds.height = m_model.tileHeight;
					m_model.images[imgId] = imgModel;

					Image img;
					img.x = imgModel.srcBounds.x;
					img.y = imgModel.srcBounds.y;
					img.imgId = imgId;

					models::Bounds srcBnds;
					srcBnds.x = ii;
					srcBnds.y = i;
					srcBnds.width = m_model.tileWidth;
					srcBnds.height = m_model.tileHeight;
					img.img = buildImage(&src, srcBnds);
					img.pxMap = QPixmap::fromImage(img.img);

					m_imgs[imgId] = img;
					imgs.push_back(img);
				}
			}
		}
		notifyFileChange(new AddImageCommand(this, imgs, before, m_model));
	}
	return 0;
}

models::Point SpriteSheetEditor::indexPoint(int i) {
	models::Point p;
	p.x = i % m_model.tilesWide;
	p.y = i / m_model.tilesWide;
	return p;
}

int SpriteSheetEditor::load(QString path) {
    if (m_model.readJsonFile(path))
		return 1;

	QImage src(m_model.srcFile);
	if (!src.isNull()) {
		for (auto i = m_model.images.begin(); i != m_model.images.end(); ++i) {
			Image img;
			img.x = i.value().srcBounds.x;
			img.y = i.value().srcBounds.y;
			img.img = buildImage(&src, i.value().srcBounds);
			img.pxMap = QPixmap::fromImage(img.img);
			img.imgId = i.key();
			m_imgs[i.key()] = img;
		}
	}
	return 0;
}

void SpriteSheetEditor::sceneSelection() {
	ui->btnRemove->setEnabled(false);
	// if a selected item is found, enable the Remove button
	auto items = m_scene->selectedItems();
	for (auto i : items) {
		if (i->isSelected()) {
			ui->btnRemove->setEnabled(true);
		}
	}
}

int SpriteSheetEditor::removeImage() {
	auto items = m_scene->selectedItems();
	for (auto i : items) {
		if (i->isSelected()) {
			int x = i->x();
			int y = i->y();
			for (auto img = m_imgs.begin(); img != m_imgs.end(); ++img) {
				if (img.value().x == x && img.value().y == y) {
					QVector<Image> imgs;
					imgs.push_back(img.value());
					auto before = m_model;
					m_model.images.remove(img.key());
					recycleImageId(img.key());
					notifyFileChange(new RemoveImageCommand(this, imgs, before, m_model));
					break;
				}
			}
			break;
		}
	}
	return 0;
}

void SpriteSheetEditor::draw() {
	ui->canvas->setParent(this);
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;

	m_scene->clear();
	m_scene->setSceneRect(0, 0, width, height);
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));

	for (auto i = m_imgs.begin(); i != m_imgs.end(); ++i) {
		m_scene->addPixmap(i.value().pxMap)->setPos(i.value().x, i.value().y);
	}

	auto items = m_scene->items();
	for (auto i : items) {
		i->setFlags(i->flags() | QGraphicsItem::ItemIsSelectable);
	}

	ui->canvas->centerOn(0, 0);
	ui->canvas->show();
}

SpriteSheetEditor::AddImageCommand::AddImageCommand(SpriteSheetEditor *parent, QVector<SpriteSheetEditor::Image> imgs, models::SpriteSheet before, models::SpriteSheet after) {
	m_parent = parent;
	m_newImages = imgs;
	m_before = before;
	m_after = after;
}

void SpriteSheetEditor::AddImageCommand::redo() {
	for (auto img : m_newImages) {
		m_parent->m_imgs[img.imgId] = img;
	}
	m_parent->m_model = m_after;
	m_parent->draw();
}

void SpriteSheetEditor::AddImageCommand::undo() {
	for (auto img : m_newImages) {
		m_parent->m_imgs.remove(img.imgId);
	}
	m_parent->m_model = m_before;
	m_parent->draw();
}

SpriteSheetEditor::RemoveImageCommand::RemoveImageCommand(SpriteSheetEditor *parent, QVector<SpriteSheetEditor::Image> imgs, models::SpriteSheet before, models::SpriteSheet after) {
	m_parent = parent;
	m_newImages = imgs;
	m_before = before;
	m_after = after;
}

SpriteSheetEditor::RemoveImageCommand::~RemoveImageCommand() {
}

void SpriteSheetEditor::RemoveImageCommand::redo() {
	for (auto img : m_newImages) {
		m_parent->m_imgs.remove(img.imgId);
	}
	m_parent->m_model = m_after;
	m_parent->draw();
}

void SpriteSheetEditor::RemoveImageCommand::undo() {
	for (auto img : m_newImages) {
		m_parent->m_imgs[img.imgId] = img;
	}
	m_parent->m_model = m_before;
	m_parent->draw();
}
