#ifndef EDITORCORE_GENERICNEWFILEMENU_HPP
#define EDITORCORE_GENERICNEWFILEMENU_HPP

#include <functional>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFile>
#include <QLineEdit>
#include <QMessageBox>
#include <models/editormodels.hpp>
#include <editorcore/newfilemenu.hpp>
#include "misc.hpp"

namespace editor {

// BaseGenericNewFileMenu needs to exist because a template class cannot be a
//  Q_OBJECT

class BaseGenericNewFileMenu: public NewFileMenu {
	Q_OBJECT

	protected:
		QString m_projectPath;
		QString m_path, m_classPath;
		QString m_appTitle;
		QLineEdit *m_leName = nullptr;
		QDialogButtonBox *m_btns = nullptr;

	public:
		BaseGenericNewFileMenu(NewFileMenuParams args, QString title,
			QString classPath);
		~BaseGenericNewFileMenu();

		QString path();

		/**
		 * @return 0 if success
		 */
		virtual int initFile(QString name) = 0;

	public slots:
		void accept();
};

template<typename Model>
class GenericNewFileMenu: public BaseGenericNewFileMenu {
	public:
		GenericNewFileMenu(NewFileMenuParams args, QString title, QString classPath):
			BaseGenericNewFileMenu(args, title, classPath) {
		}

		int initFile(QString name) {
			auto path = m_projectPath + "/" + m_classPath + "/" + name + MODEL_FILE_EXTENSION;
			int retval = 1;
			if (!QFile::exists(path)) {
				m_path = path;
				Model().writeJsonFile(m_path, models::cyborgbear::Readable);
				retval = 0;
			} else {
				QMessageBox::critical(this, m_appTitle, "A file with this name already exists.");
			}
			return retval;
		}
};

}

#endif
