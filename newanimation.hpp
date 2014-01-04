#ifndef NEWANIMATION_H
#define NEWANIMATION_H

#include <QDialog>
#include "editorcore/newfilemenu.hpp"

namespace Ui {
class NewAnimation;
}

namespace wombat {
namespace editor {

class NewAnimation: public NewFileMenu {
	Q_OBJECT

	private:
		Ui::NewAnimation *ui;
		QString m_projectPath;

	public:
		explicit NewAnimation(NewFileMenuParams);
		~NewAnimation();
		QString path();
		void accept();
};

}
}

#endif // NEWANIMATION_H
