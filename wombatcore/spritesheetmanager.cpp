#include "editorcore/modeliomanager.hpp"
#include "spritesheetmanager.hpp"

namespace wombat {
namespace editor {

SpriteSheetManager::SpriteSheetManager(models::SpriteSheet model): src(model.srcFile) {
	m_model = model;
}

QImage SpriteSheetManager::getImage(models::SpriteSheetImage img) {
	int w = m_model.tileWidth;
	int h = m_model.tileHeight;
	auto bnds = img.srcBounds;

	QImage sprt(w, h, QImage::Format_ARGB32);
	sprt.fill(0);

	for (int i = 0; i < w; i++) {
		for (int ii = 0; ii < h; ii++) {
			sprt.setPixel(i, ii, src.pixel(i + bnds.x, ii + bnds.y));
		}
	}
	return sprt;
}

QPixmap SpriteSheetManager::getPixmap(models::SpriteSheetImage img) {
	return QPixmap::fromImage(getImage(img));
}

}
}
