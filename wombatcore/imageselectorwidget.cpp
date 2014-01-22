#include <QDir>
#include <QGraphicsPixmapItem>

#include "editorcore/misc.hpp"
#include "editorcore/modeliomanager.hpp"
#include "spritesheetmanager.hpp"
#include "imageselectorwidget.hpp"
#include "ui_imageselectorwidget.h"

namespace wombat {
namespace editor {

ImageSelectorWidget::ImageSelectorWidget(QWidget *parent, QString projectPath, ModelIoManager *modelIo): QWidget(parent), ui(new Ui::ImageSelectorWidget) {
	ui->setupUi(this);
	m_scene = new QGraphicsScene(this);
	m_scene->setBackgroundBrush(QColor(0, 0, 0, 0));

	ui->canvas->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	ui->canvas->setScene(m_scene);

	m_projectPath = projectPath;
	m_modelIo = modelIo;

	populateSheetSelect();

	connect(ui->cbSpriteSheet, SIGNAL(currentTextChanged(QString)), this, SLOT(changeSpriteSheet(QString)));

	auto anims = QDir(m_projectPath + "Resources/SpriteSheets").entryInfoList();
	for (auto s : anims) {
		if (s.isFile() and s.fileName().endsWith(".json")) {
			changeSpriteSheet(s.fileName());
			break;
		}
	}
}

ImageSelectorWidget::~ImageSelectorWidget() {
	disconnect(ui->cbSpriteSheet, SIGNAL(currentTextChanged(QString)), this, SLOT(changeSpriteSheet(QString)));

	delete m_scene;
	delete ui;
}

int ImageSelectorWidget::openSpriteSheet(QString path) {
	models::SpriteSheet model;
	model.fromJson(m_modelIo->read(m_projectPath + path));

	m_ptToImg.clear();
	m_currentModelPath = path;

	SpriteSheetManager sheet(model, m_projectPath);

	m_scene->clear();

	int x = 0;
	int y = 0;
	for (auto img = model.Images.begin(); img != model.Images.end(); ++img) {
		if (x == model.TileWidth * model.TilesWide) {
			x = 0;
			y++;
		}
		m_scene->addPixmap(sheet.getPixmap(img.value()))->setPos(x, y);
		m_ptToImg[pointKey(x, y)] = img.key();
		x += model.TileWidth;
	}

	auto items = m_scene->items();
	for (auto i : items) {
		i->setFlags(i->flags() | QGraphicsItem::ItemIsSelectable);
	}

	ui->canvas->centerOn(0, 0);
	ui->canvas->show();

	m_model = model;

	return 0;
}

models::Image ImageSelectorWidget::selectedImage() {
	auto items = m_scene->selectedItems();
	models::Image out;
	out.ImgId = -1;
	for (auto i : items) {
		if (i->isSelected()) {
			out.SpriteSheet = m_currentModelPath;
			out.ImgId = pointImgId(i->x(), i->y());
			out.DefaultSize.Width = m_model.TileWidth;
			out.DefaultSize.Height = m_model.TileHeight;
			break;
		}
	}
	return out;
}

void ImageSelectorWidget::populateSheetSelect() {
	auto anims = QDir(m_projectPath + "Resources/SpriteSheets").entryInfoList();
	for (auto s : anims) {
		if (s.isFile() and s.fileName().endsWith(".json")) {
			ui->cbSpriteSheet->addItem(s.fileName());
		}
	}
}

QString ImageSelectorWidget::pointKey(int x, int y) {
	return QString("(%1, %2)").arg(x).arg(y);
} 
int ImageSelectorWidget::pointImgId(int x, int y) {
	return m_ptToImg[pointKey(x, y)];
}

void ImageSelectorWidget::changeSpriteSheet(QString file) {
	openSpriteSheet("Resources/SpriteSheets/" + file);
}

}
}
