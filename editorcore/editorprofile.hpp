#ifndef EDITORMANAGER_HPP
#define EDITORMANAGER_HPP

#include <functional>
#include <QVector>
#include <QMap>
#include "modeliomanager.hpp"
#include "editortab.hpp"
#include "newfilemenu.hpp"

namespace wombat {
namespace editor {

typedef std::function<EditorTab*(EditorTabParams)> EditorTabMaker;

typedef std::function<NewFileMenu*(NewFileMenuParams)> NewFileMenuMaker;

class EditorProfile {
	private:
		QMap<QString, NewFileMenuMaker> m_newFileMenuMakers;

		QVector<EditorTabMaker> m_editorTabMakers;

		QVector<QString> m_fileTypes;

		QVector<QString> m_defaultPaths;

		ModelIoManager m_models;

	public:
		NewFileMenu *newFileMenu(NewFileMenuParams);

		EditorTab *editorTab(EditorTabParams);

		QVector<QString> defaultPaths();

		QVector<QString> fileTypes();

		void addNewFileMenuMaker(QString, NewFileMenuMaker);

		void addEditorTabMaker(EditorTabMaker);

		void addDefaultPath(QString);
};

}
}

#endif
