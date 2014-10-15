#ifndef WOMBAT_WORLD_WORLDUTIL_HPP
#define WOMBAT_WORLD_WORLDUTIL_HPP

#include <models/models.hpp>
#include <QPixmap>

namespace wombat {
namespace world {

class WorldUtil {
	private:
		editor::ModelIoManager *m_modelio = nullptr;
		QMap<QString, QPixmap> *m_imgs = nullptr;
		bool m_externalImgs = true;

	public:
		/**
		 * Constructor
		 * @param modelio the ModelIoManager for the current project
		 */
		WorldUtil(editor::ModelIoManager *modelio, QMap<QString, QPixmap> *imgs = nullptr);

		/**
		 * Destructor
		 */
		~WorldUtil();

		QPixmap firstImage(models::Animation anim);

		QPixmap firstImage(QString animPath);

	private:
		WorldUtil(const WorldUtil&);
		const WorldUtil &operator=(const WorldUtil&);
};

}
}

#endif
