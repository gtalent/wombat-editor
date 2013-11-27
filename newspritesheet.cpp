#include <QFile>
#include <QImage>
#include "newspritesheet.hpp"
#include "models/editormodels.hpp"
#include "ui_newspritesheet.h"

NewSpriteSheet::NewSpriteSheet(QString projectPath, QWidget *parent): QDialog(parent), ui(new Ui::NewSpriteSheet) {
	ui->setupUi(this);
	m_projectPath = projectPath;
}

NewSpriteSheet::~NewSpriteSheet() {
	delete ui;
}

void NewSpriteSheet::accept() {
	if (!QFile::exists(ui->leName->text() + ".json")) {
		//setup JSON file
		models::SpriteSheet model;
		m_path = m_projectPath + "Resources/SpriteSheets/" + ui->leName->text() + ".json";

		model.srcFile = m_projectPath + "Resources/SpriteSheets/" + ui->leName->text() + ".png";

		QStringList ts = ui->cbTileSize->currentText().split("x");
		model.tileWidth = ts[0].toInt();
		model.tileHeight = ts[1].toInt();

		QStringList ss = ui->cbSheetSize->currentText().split("x");
		model.tilesWide = ss[0].toInt();
		model.tilesHigh = ss[1].toInt();

		model.writeJsonFile(m_path, models::cyborgbear::Readable);


		//setup image file
		QImage sprt(model.tilesWide * model.tileWidth, model.tilesHigh * model.tileHeight, QImage::Format_ARGB32);
		sprt.save(model.srcFile);

		this->close();
		this->parentWidget()->activateWindow();
	}
}

QString NewSpriteSheet::path() {
	return m_path;
}
