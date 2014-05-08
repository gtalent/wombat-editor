#ifndef WOMBATCORE_NEWANIMATION_H
#define WOMBATCORE_NEWANIMATION_H

#include <QDialog>
#include "editorcore/newfilemenu.hpp"

namespace Ui {
class NewAnimation;
}

namespace wombat {
namespace core {

using namespace editor;

class NewAnimation: public NewFileMenu {
	Q_OBJECT

	private:
		Ui::NewAnimation *ui;
		QString m_projectPath;
		QString m_path;

	public:
		NewAnimation(NewFileMenuParams);
		~NewAnimation();
		QString path();

	public slots:
		void accept();
};

}
}

#endif // NEWANIMATION_H
