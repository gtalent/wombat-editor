#include <QFile>
#include <QImage>
#include "ui_newspritesheet.h"
#include "newspritesheet.hpp"
#include "models/editormodels.hpp"

using namespace wombat::editor;

namespace wombat {
namespace editor {

NewSpriteSheet::NewSpriteSheet(NewFileMenuParams args): NewFileMenu(args), ui(new Ui::NewSpriteSheet) {
	ui->setupUi(this);
	m_projectPath = args.projectPath;

	setSizeGripEnabled(false);
	setFixedSize(450, 175);
}

NewSpriteSheet::~NewSpriteSheet() {
	delete ui;
}

void NewSpriteSheet::accept() {
	m_path = m_projectPath + "Resources/SpriteSheets/" + ui->leName->text() + ".json";
	if (!QFile::exists(m_path)) {
		//setup JSON file
		models::SpriteSheet model;

		model.SrcFile = m_projectPath + "Resources/SpriteSheets/" + ui->leName->text() + ".png";

		QStringList ts = ui->cbTileSize->currentText().split("x");
		model.TileWidth = ts[0].toInt();
		model.TileHeight = ts[1].toInt();

		QStringList ss = ui->cbSheetSize->currentText().split("x");
		model.TilesWide = ss[0].toInt();
		model.TilesHigh = ss[1].toInt();

		model.writeJsonFile(m_path, models::cyborgbear::Readable);


		//setup image file
		QImage sprt(model.TilesWide * model.TileWidth, model.TilesHigh * model.TileHeight, QImage::Format_ARGB32);
		sprt.save(model.SrcFile);

		accept();
	}
}

QString NewSpriteSheet::path() {
	return m_path;
}

}
}
