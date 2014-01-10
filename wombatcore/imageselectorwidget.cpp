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
	model.fromJson(m_modelIo->read(path));
	m_ptToImg.clear();

	SpriteSheetManager sheet(model);

	m_scene->clear();

	int x = 0;
	int y = 0;
	for (auto img = model.images.begin(); img != model.images.end(); ++img) {
		if (x == model.tileWidth * model.tilesWide) {
			x = 0;
			y++;
		}
		m_scene->addPixmap(sheet.getPixmap(img.value()))->setPos(x, y);
		m_ptToImg[pointKey(x, y)] = img.key();
		x += model.tileWidth;
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

int ImageSelectorWidget::selectedWidget() {
	auto items = m_scene->selectedItems();
	for (auto i : items) {
		if (i->isSelected()) {
			return pointImgId(i->x(), i->y());
		}
	}
	return -1;
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
	openSpriteSheet(m_projectPath + "Resources/SpriteSheets/" + file);
}

}
}
