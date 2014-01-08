#include "editorprofile.hpp"

namespace wombat {
namespace editor {

NewFileMenu *EditorProfile::newFileMenu(NewFileMenuParams args) {
	if (m_newFileMenuMakers.contains(args.fileType)) {
		return m_newFileMenuMakers[args.fileType](args);
	}
	return 0;
}

EditorWidget *EditorProfile::editorWidget(EditorWidgetParams args) {
	for (auto f : m_editorWidgetMakers) {
		auto retval = f(args);
		if (retval) {
			retval->modelIoManager(&m_models);
			return retval;
		}
	}
	return 0;
}

QVector<QString> EditorProfile::defaultPaths() {
	return m_defaultPaths;
}

QVector<QString> EditorProfile::fileTypes() {
	return m_fileTypes;
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

void EditorProfile::addEditorWidgetMaker(EditorWidgetMaker mkr) {
	m_editorWidgetMakers.push_back(mkr);
}

void EditorProfile::addDefaultPath(QString path) {
	for (auto p : m_defaultPaths) {
		if (path == p) {
			return;
		}
	}
	m_defaultPaths.push_back(path);
}

void EditorProfile::var(QString key, QString val) {
	m_vars[key] = val;
}

QString EditorProfile::var(QString key) {
	return m_vars[key];
}

}
}
