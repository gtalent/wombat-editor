#ifndef EDITORMANAGER_HPP
#define EDITORMANAGER_HPP

#include <functional>
#include <QVector>
#include <QMap>
#include "editortab.hpp"
#include "newfilemenu.hpp"

namespace wombat {
namespace editor {

struct EditorTabParams {
	QString projectPath;
	QString filePath;
	QWidget *parent;
};

struct NewFileMenuParams {
	QString projectPath;
	QString fileType;
	QWidget *parent;
};

typedef std::function<EditorTab*(EditorTabParams)> EditorTabMaker;

typedef std::function<NewFileMenu*(NewFileMenuParams)> NewFileMenuMaker;

class EditorProfile {
	private:
		QMap<QString, NewFileMenuMaker> m_newFileMenuMakers;

		QVector<EditorTabMaker> m_editorTabMakers;

		QVector<QString> m_defaultPaths;

	public:
		NewFileMenu *newFileMenu(NewFileMenuParams);

		EditorTab *editorTab(EditorTabParams);

		void addNewFileMenuMaker(QString, NewFileMenuMaker);

		void addEditorTabMaker(EditorTabMaker);

		void addDefaultPath(QString);
};

}
}

#endif
