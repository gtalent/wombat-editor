#include "editorprofile.hpp"

namespace wombat {
namespace editor {

NewFileMenu *EditorProfile::newFileMenu(QString fileType, QWidget *parent) {
	if (m_newFileMenuMakers.contains(fileType)) {
		return m_newFileMenuMakers[fileType](fileType, parent);
	}
	return 0;
}

EditorTab *EditorProfile::editorTab(QString path) {
	for (auto f : m_editorTabMakers) {
		auto retval = f(path);
		if (retval) {
			return retval;
		}
	}
	return 0;
}

void EditorProfile::addNewFileMenuMaker(QString fileType, std::function<NewFileMenu*(QString, QWidget*)> mkr) {
	m_newFileMenuMakers[fileType] = mkr;
}

void EditorProfile::addEditorTabMaker(std::function<EditorTab*(QString)> mkr) {
	m_editorTabMakers.push_back(mkr);
}

void EditorProfile::addDefaultPath(QString path) {
	for (auto p : m_defaultPaths) {
		if (path == p) {
			break;
		}
	}
	m_defaultPaths.push_back(path);
}

}
}
