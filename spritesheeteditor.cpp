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
using enginemodels::Bounds;

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
	m_model.loadFile(path);
	m_imgs = new Image**[m_model.tilesWide];
	for (int i = 0; i < m_model.tilesWide; i++) {
		m_imgs[i] = new Image*[m_model.tilesHigh];
		for (int ii = 0; ii < m_model.tilesWide; ii++) {
			m_imgs[i][ii] = 0;
		}
	}
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;
	m_scene = new QGraphicsScene(0, 0, width, height, this);
	ui->canvas->setScene(m_scene);
}

SpriteSheetEditor::~SpriteSheetEditor() {
	delete ui;
	for (int i = 0; i < m_model.tilesWide; i++) {
		delete m_imgs[i];
	}
	delete m_imgs;
	delete m_scene;
}

bool SpriteSheetEditor::saveFile() {
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
		for (int i = 0; i < files.size(); i += m_model.tileWidth) {
			for (int ii = 0; ii < files.size(); ii += m_model.tileHeight) {
				Image *img = new Image();
				img->srcBnds.x = i;
				img->srcBnds.y = ii;
				img->srcBnds.width = m_model.tileWidth;
				img->srcBnds.height = m_model.tileHeight;
				img->img = buildImage(&src, img->srcBnds);
				m_imgs[m_sheetIdx.x][m_sheetIdx.y] = img;
				m_sheetIdx.y++;
				if (m_model.tilesHigh <= m_sheetIdx.y) {
					m_sheetIdx.y = 0;
					m_sheetIdx.x++;
					if (m_model.tilesWide <= m_sheetIdx.x) {
						delete img;
						return 1;
					}
				}
			}
		}
	}
	draw();
	return 0;
}

void SpriteSheetEditor::draw() {
	ui->canvas->setParent(this);
	int width = m_model.tilesWide * m_model.tileWidth;
	int height = m_model.tilesHigh * m_model.tileHeight;
	m_scene->clear();
	m_scene->setSceneRect(0, 0, width, height);
	printf("width: %d\n", width);
	for (int x = 0; x < m_model.tilesWide; x++) {
		for (int y = 0; y < m_model.tilesHigh; y++) {
			if (m_imgs[x][y]) {
				m_scene->addPixmap(m_imgs[x][y]->img)->setPos(0, 0);
			}
		}
	}
	ui->canvas->translate((width / 2), -(height / 2));
	ui->canvas->show();
}
