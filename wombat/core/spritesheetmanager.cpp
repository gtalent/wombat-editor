#include <editorcore/modeliomanager.hpp>
#include "spritesheetmanager.hpp"

namespace wombat {
namespace core {

SpriteSheetManager::SpriteSheetManager(models::SpriteSheet model, QString projectPath): m_src(projectPath + model.SrcFile) {
	m_model = model;
	m_projectPath = projectPath;
}

QImage SpriteSheetManager::getImage(models::SpriteSheetImage img) {
	int w = m_model.TileWidth;
	int h = m_model.TileHeight;
	auto bnds = img.SrcBounds;

	QImage sprt(w, h, QImage::Format_ARGB32);
	sprt.fill(0);

	for (int i = 0; i < w; i++) {
		for (int ii = 0; ii < h; ii++) {
			sprt.setPixel(i, ii, m_src.pixel(i + bnds.X, ii + bnds.Y));
		}
	}
	return sprt;
}

QPixmap SpriteSheetManager::getPixmap(models::SpriteSheetImage img) {
	return QPixmap::fromImage(getImage(img));
}

QImage SpriteSheetManager::getImage(models::Image img, QString projectPath) {
	models::SpriteSheet model;
	model.readJsonFile(projectPath + img.SpriteSheet);
	return SpriteSheetManager(model, projectPath).getImage(model.Images[img.ImgId]);
}

QPixmap SpriteSheetManager::getPixmap(models::Image img, QString projectPath) {
	models::SpriteSheet model;
	model.readJsonFile(projectPath + img.SpriteSheet);
	return SpriteSheetManager(model, projectPath).getPixmap(model.Images[img.ImgId]);
}

}
}
