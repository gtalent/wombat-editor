#include "editorprofile.hpp"

namespace wombat {
namespace editor {

NewFileMenu *EditorProfile::newFileMenu(NewFileMenuParams args) {
	if (m_newFileMenuMakers.contains(args.fileType)) {
		return m_newFileMenuMakers[args.fileType](args);
	}
	return 0;
}

EditorTab *EditorProfile::editorTab(EditorTabParams args) {
	for (auto f : m_editorTabMakers) {
		auto retval = f(args);
		if (retval) {
			return retval;
		}
	}
	return 0;
}

QVector<QString> EditorProfile::defaultPaths() {
	return m_defaultPaths;
}

void EditorProfile::addNewFileMenuMaker(QString fileType, NewFileMenuMaker mkr) {
	bool addToFileTypes = true;
	for (auto t : m_fileTypes) {
		if (t == fileType) {
			addToFileTypes = false;
		}
	}

	if (addToFileTypes) {
		m_fileTypes.push_back(fileType);
	}
	m_newFileMenuMakers[fileType] = mkr;
}

void EditorProfile::addEditorTabMaker(EditorTabMaker mkr) {
	m_editorTabMakers.push_back(mkr);
}

void EditorProfile::addDefaultPath(QString path) {
	for (auto p : m_defaultPaths) {
		if (path == p) {
			return;
		}
	}
	m_defaultPaths.push_back(path);
}

}
}
