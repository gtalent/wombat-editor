#ifndef EDITORCORE_GENERICNEWFILEMENU_HPP
#define EDITORCORE_GENERICNEWFILEMENU_HPP

#include <QDialog>
#include <QDialogButtonBox>
#include <QLineEdit>
#include <models/editormodels.hpp>
#include <editorcore/newfilemenu.hpp>

namespace editor {

// BaseGenericNewFileMenu needs to exist because a template class cannot be a
//  Q_OBJECT

class BaseGenericNewFileMenu: public NewFileMenu {
	Q_OBJECT

	private:
		QString m_projectPath;
		QString m_path, m_classPath;
		QString m_appTitle;
		QLineEdit *m_leName = nullptr;
		QDialogButtonBox *m_btns = nullptr;

	public:
		BaseGenericNewFileMenu(NewFileMenuParams args, QString title, QString classPath);
		~BaseGenericNewFileMenu();

		QString path();

		virtual models::cyborgbear::Model &defaultModel() = 0;

	public slots:
		void accept();
};

template<typename Model>
class GenericNewFileMenu: public BaseGenericNewFileMenu {
	public:
		GenericNewFileMenu(NewFileMenuParams args, QString title, QString classPath): 
			BaseGenericNewFileMenu(args, title, classPath) {
		}

		models::cyborgbear::Model &defaultModel() {
			static Model m;
			return m;
		}
};

}

#endif
