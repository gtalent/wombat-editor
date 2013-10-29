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
		QImage &src = m_imgs[i->first].img;
		for (int x = 0; x < i->second.srcBounds.width; x++)
			for (int y = 0; y < i->second.srcBounds.height; y++)
				imgOut.setPixel(i->second.srcBounds.x + x, i->second.srcBounds.y + y, src.pixel(x, y));
	}

	imgOut.save(m_model.srcFile, "png", 100);

	return true;
}

QImage SpriteSheetEditor::buildImage(QImage *src, Bounds bnds) {
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
	auto after = m_model;
	QStringList files = QFileDialog::getOpenFileNames(parentWidget(), "Choose images to import...", QDir::homePath());
	QVector<Image> imgs;
	for (int n = 0; n < files.size(); n++) {
		QImage src(files[n]);
		for (int i = 0; i < files.size(); i += after.tileHeight) {
			for (int ii = 0; ii < files.size(); ii += after.tileWidth) {
				int imgId = newImageId();
				models::SpriteSheetImage imgModel;
				imgModel.srcBounds.x = after.sheetIdx.x * after.tileWidth;
				imgModel.srcBounds.y = after.sheetIdx.y * after.tileHeight;
				imgModel.srcBounds.width = after.tileWidth;
				imgModel.srcBounds.height = after.tileHeight;
				after.images[imgId] = imgModel;

				Image img;
				img.x = imgModel.srcBounds.x;
				img.y = imgModel.srcBounds.y;
				img.imgId = imgId;

				models::Bounds srcBnds;
				srcBnds.x = ii;
				srcBnds.y = i;
				srcBnds.width = after.tileWidth;
				srcBnds.height = after.tileHeight;
				img.img = buildImage(&src, srcBnds);
				img.pxMap = QPixmap::fromImage(img.img);

				after.sheetIdx.x++;
				if (after.tilesWide <= after.sheetIdx.x) {
					after.sheetIdx.x = 0;
					after.sheetIdx.y++;
					if (after.tilesHigh <= after.sheetIdx.y) {
						return 1;
					}
				}
				m_imgs[imgId] = img;
				imgs.push_back(img);
			}
		}
	}
	notifyFileChange(new AddImageCommand(this, imgs, before, after));
	return 0;
}

int SpriteSheetEditor::load(QString path) {
	if (!m_model.loadJsonFile(path))
		return 1;

	QImage src(m_model.srcFile);
	if (!src.isNull()) {
		for (auto i = m_model.images.begin(); i != m_model.images.end(); ++i) {
			Image img;
			img.x = i->second.srcBounds.x;
			img.y = i->second.srcBounds.y;
			img.img = buildImage(&src, i->second.srcBounds);
			img.pxMap = QPixmap::fromImage(img.img);
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
		m_scene->addPixmap(i.value().pxMap)->setPos(i.value().x, i.value().y);
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
