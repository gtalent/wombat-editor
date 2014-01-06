#ifndef SPRITESHEETMANAGER_HPP
#define SPRITESHEETMANAGER_HPP

#include <QPixmap>
#include "models/editormodels.hpp"

namespace wombat {
namespace editor {

class SpriteSheetManager {
	private:
		models::SpriteSheet m_model;
		QImage src;
	public:
		SpriteSheetManager(models::SpriteSheet);
		QImage getImage(models::SpriteSheetImage);
		QPixmap getPixmap(models::SpriteSheetImage);
};

}
}

#endif
