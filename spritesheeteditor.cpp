#include "stdio.h"
#include <iostream>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QAbstractItemModel>
#include <QGraphicsPixmapItem>
#include <QPainter>

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
	m_model.loadJsonFile(path);
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;
	m_scene = new QGraphicsScene(0, 0, width, height, this);
	ui->canvas->setAlignment(Qt::AlignLeft | Qt::AlignTop);	
	ui->canvas->setScene(m_scene);
	ui->canvas->setStyleSheet("background-color: transparent");
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));
}

SpriteSheetEditor::~SpriteSheetEditor() {
	delete ui;
	delete m_scene;
}

bool SpriteSheetEditor::saveFile() {
	notifyFileSave();
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

int SpriteSheetEditor::addImages() {
	QStringList files = QFileDialog::getOpenFileNames(parentWidget(), "Choose images to import...", QDir::homePath());
	for (int n = 0; n < files.size(); n++) {
		QImage src(files[n]);
		for (int i = 0; i < files.size(); i += m_model.tileHeight) {
			for (int ii = 0; ii < files.size(); ii += m_model.tileWidth) {
				Image *img = new Image();
				img->x = m_sheetIdx.x * m_model.tileWidth;
				img->y = m_sheetIdx.y * m_model.tileHeight;
				img->srcBnds.x = ii;
				img->srcBnds.y = i;
				img->srcBnds.width = m_model.tileWidth;
				img->srcBnds.height = m_model.tileHeight;
				models::SpriteSheetImage imgModel;
				imgModel.bounds = img->srcBnds;
				img->img = buildImage(&src, img->srcBnds);
				m_sheetIdx.x++;
				if (m_model.tilesHigh <= m_sheetIdx.y) {
					m_sheetIdx.x = 0;
					m_sheetIdx.y++;
					if (m_model.tilesHigh <= m_sheetIdx.y) {
						delete img;
						return 1;
					}
				}
				m_imgs.push_back(img);
			}
		}
	}
	draw();
	notifyFileChange();
	return 0;
}

void SpriteSheetEditor::draw() {
	ui->canvas->setParent(this);
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;

	m_scene->clear();
	m_scene->setSceneRect(0, 0, width, height);
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));

	for (int i = 0; i < m_imgs.size(); i++) {
		m_scene->addPixmap(m_imgs[i]->img)->setPos(m_imgs[i]->x, m_imgs[i]->y);
	}

	ui->canvas->centerOn(0, 0);
	ui->canvas->show();
}
