#ifndef EDITORMANAGER_HPP
#define EDITORMANAGER_HPP

#include <functional>
#include <QVector>
#include <QMap>
#include "editortab.hpp"
#include "newfilemenu.hpp"

namespace wombat {
namespace editor {

class EditorProfile {
	private:
		QMap<QString, std::function<NewFileMenu*(QString, QWidget*)>> m_newFileMenuMakers;

		QVector<std::function<EditorTab*(QString)>> m_editorTabMakers;

		QVector<QString> m_defaultPaths;

	public:
		NewFileMenu *newFileMenu(QString fileType, QWidget *parent);

		EditorTab *editorTab(QString path);

		void addNewFileMenuMaker(QString, std::function<NewFileMenu*(QString, QWidget*)>);

		void addEditorTabMaker(std::function<EditorTab*(QString)>);

		void addDefaultPath(QString);
};

}
}

#endif
