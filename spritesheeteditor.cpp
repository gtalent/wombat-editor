#include <iostream>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QAbstractItemModel>
#include <QGraphicsPixmapItem>
#include <QPainter>

#include "globs.hpp"
#include "spritesheeteditor.hpp"
#include "ui_spritesheeteditor.h"

using std::string;
using models::Bounds;

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
	ui->canvas->setAlignment(Qt::AlignLeft | Qt::AlignTop);	
	ui->canvas->setScene(m_scene);
	ui->canvas->setStyleSheet("background-color: transparent");
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));
	draw();
}

SpriteSheetEditor::~SpriteSheetEditor() {
	delete ui;
	delete m_scene;
}

bool SpriteSheetEditor::saveFile() {
	notifyFileSave();
	m_model.writeJsonFile(m_path, models::cyborgbear::Readable);

	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;

	QImage imgOut(width, height, QImage::Format_ARGB32);

	for (auto i = m_model.images.begin(); i != m_model.images.end(); ++i) {
		QImage src = m_imgs[i->first]->img.toImage();
		for (int x = 0; x < i->second.srcBounds.width; x++)
			for (int y = 0; y < i->second.srcBounds.height; y++)
				imgOut.setPixel(i->second.srcBounds.x + x, i->second.srcBounds.y + y, src.pixel(x, y));
	}

	imgOut.save(m_model.srcFile);

	return true;
}

QPixmap SpriteSheetEditor::buildImage(QImage *src, Bounds bnds) {
	int w = m_model.tileWidth;
	int h = m_model.tileHeight;
	QImage sprt(w, h, QImage::Format_ARGB32);
	sprt.fill(0);

	for (int i = 0; i < w; i++) {
		for (int ii = 0; ii < h; ii++) {
			sprt.setPixel(i, ii, src->pixel(i + bnds.x, ii + bnds.y));
		}
	}
	return QPixmap::fromImage(sprt);
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

int SpriteSheetEditor::addImages() {
	QStringList files = QFileDialog::getOpenFileNames(parentWidget(), "Choose images to import...", QDir::homePath());
	for (int n = 0; n < files.size(); n++) {
		QImage src(files[n]);
		for (int i = 0; i < files.size(); i += m_model.tileHeight) {
			for (int ii = 0; ii < files.size(); ii += m_model.tileWidth) {
				int imgId = newImageId();
				models::SpriteSheetImage imgModel;
				imgModel.srcBounds.x = m_model.sheetIdx.x * m_model.tileWidth;
				imgModel.srcBounds.y = m_model.sheetIdx.y * m_model.tileHeight;
				imgModel.srcBounds.width = m_model.tileWidth;
				imgModel.srcBounds.height = m_model.tileHeight;
				m_model.images[imgId] = imgModel;

				Image *img = new Image();
				img->x = imgModel.srcBounds.x;
				img->y = imgModel.srcBounds.y;
				img->imgId = imgId;

				models::Bounds srcBnds;
				srcBnds.x = ii;
				srcBnds.y = i;
				srcBnds.width = m_model.tileWidth;
				srcBnds.height = m_model.tileHeight;
				img->img = buildImage(&src, srcBnds);

				m_model.sheetIdx.x++;
				if (m_model.tilesHigh <= m_model.sheetIdx.y) {
					m_model.sheetIdx.x = 0;
					m_model.sheetIdx.y++;
					if (m_model.tilesHigh <= m_model.sheetIdx.y) {
						delete img;
						return 1;
					}
				}
				m_imgs[imgId] = img;
			}
		}
	}
	draw();
	notifyFileChange();
	return 0;
}

int SpriteSheetEditor::load(QString path) {
	m_model.loadJsonFile(path);
	QImage src(m_model.srcFile);
	if (!src.isNull()) {
		for (auto i = m_model.images.begin(); i != m_model.images.end(); ++i) {
			Image *img = new Image();
			img->x = i->second.srcBounds.x;
			img->y = i->second.srcBounds.y;
			img->img = buildImage(&src, i->second.srcBounds);
			m_imgs[i->first] = img;
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
		m_scene->addPixmap(i.value()->img)->setPos(i.value()->x, i.value()->y);
	}

	ui->canvas->centerOn(0, 0);
	ui->canvas->show();
}
