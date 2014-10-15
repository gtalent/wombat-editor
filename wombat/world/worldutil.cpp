#include <editorcore/modeliomanager.hpp>
#include <wombat/core/spritesheetmanager.hpp>
#include "worldutil.hpp"

namespace wombat {
namespace world {

using core::SpriteSheetManager;

WorldUtil::WorldUtil(editor::ModelIoManager *modelio, QMap<QString, QPixmap> *imgs) {
	m_modelio = modelio;
	if (imgs == nullptr) {
		m_externalImgs = false;
		imgs = new QMap<QString, QPixmap>();
	} else {
		m_externalImgs = true;
	}
	m_imgs = imgs;
}

WorldUtil::~WorldUtil() {
	if (!m_externalImgs && m_imgs) {
		delete m_imgs;
	}
}

QPixmap WorldUtil::firstImage(models::Animation anim) {
	auto projectPath = m_modelio->getProjectPath();
	
	if (anim.Import != "") {
		anim.fromJson(m_modelio->readAbsolutePath(projectPath + "/" + anim.Import + ".json"));
	}

	if (anim.Images.size()) {
		auto img = anim.Images[0].Image;
		if (m_imgs) {
			// look for the image in the image cache
			auto &imgs = *m_imgs;
			auto key = img.toJson();
			if (!imgs.contains(key)) {
				imgs[key] = SpriteSheetManager::getPixmap(img, projectPath);
			}
			return imgs[key];
		} else {
			return SpriteSheetManager::getPixmap(img, projectPath);
		}
	}

	return QPixmap();
}

QPixmap WorldUtil::firstImage(QString animPath) {
	animPath = m_modelio->getProjectPath() + "/" + animPath + ".json";
	auto json = m_modelio->readAbsolutePath(animPath);
	models::Animation anim;
	anim.fromJson(json);
	return firstImage(anim);
}

}
}
