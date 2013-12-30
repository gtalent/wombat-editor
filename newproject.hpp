#ifndef NEWPROJECT_HPP
#define NEWPROJECT_HPP

#include "editorcore/newfilemenu.hpp"

namespace Ui {
	class NewProject;
}

class NewProject: public wombat::editor::NewFileMenu {
	Q_OBJECT
		
	private:
		Ui::NewProject *ui;
		QString strProjectDir;

	public:
		explicit NewProject(QWidget *parent = 0);
		~NewProject();

		QString path();
		
	public slots:
		void accept();
		void browse();
};

#endif // NEWPrOJECT_HPP
