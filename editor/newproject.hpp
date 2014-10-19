#ifndef EDITOR_NEWPROJECT_HPP
#define EDITOR_NEWPROJECT_HPP

#include <QVector>
#include <editorcore/newfilemenu.hpp>

namespace Ui {
class NewProject;
}

class NewProject: public editor::NewFileMenu {
	Q_OBJECT
		
	private:
		Ui::NewProject *ui = nullptr;
		QString m_strProjectDir;
		QVector<QString> m_defaultPaths;

	public:
		explicit NewProject(QWidget *parent, QVector<QString> defaultPaths);
		~NewProject();

		QString path();
		
	public slots:
		void accept();
		void browse();
};

#endif // NEWPrOJECT_HPP
