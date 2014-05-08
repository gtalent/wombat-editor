#ifndef WOMBATCORE_NEWSPRITESHEET_HPP
#define WOMBATCORE_NEWSPRITESHEET_HPP

#include "editorcore/newfilemenu.hpp"

namespace Ui {
class NewSpriteSheet;
}

namespace wombat {
namespace core {

class NewSpriteSheet: public editor::NewFileMenu {
	Q_OBJECT
		
	private:
		Ui::NewSpriteSheet *ui;
		QString m_projectPath;
		QString m_path;

	public:
		explicit NewSpriteSheet(editor::NewFileMenuParams);
		~NewSpriteSheet();

		/**
		 * @brief Gets path of created file.
		 * @return path of created file
		 */
		QString path();

	public slots:
		void accept();
};

}
}

#endif // NEWSPRITESHEET_HPP
