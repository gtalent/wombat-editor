#ifndef WOMBATCORE_SPRITESHEETMANAGER_HPP
#define WOMBATCORE_SPRITESHEETMANAGER_HPP

#include <QPixmap>
#include <models/models.hpp>

namespace wombat {
namespace core {

class SpriteSheetManager {
	private:
		models::SpriteSheet m_model;
		QString m_projectPath;
		QImage m_src;

	public:
		SpriteSheetManager(models::SpriteSheet, QString projectPath);
		QImage getImage(models::SpriteSheetImage);
		QPixmap getPixmap(models::SpriteSheetImage);

		static QImage getImage(models::Image, QString projectPath);
		static QPixmap getPixmap(models::Image, QString projectPath);
};

}
}

#endif
