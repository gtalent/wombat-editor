#include <QQuickView>
#include <QFile>
#include "qtquickeditorwidget.hpp"
#include "misc.hpp"
#include "editorprofile.hpp"
#include <QDebug>

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
			return retval;
		}
	}
	return 0;
}

const QVector<QString> &EditorProfile::defaultPaths() {
	return m_defaultPaths;
}

const QVector<QString> &EditorProfile::fileTypes() {
	return m_fileTypes;
}

const QVector<DockMaker> &EditorProfile::dockMakers() {
	return m_dockMakers;
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

void EditorProfile::loadQtQuickProfile(models::EditorProfile prof) {
	addEditorWidgetMaker([prof](EditorWidgetParams args) -> EditorWidget* {
		for (auto pref : prof.PathStartsWith) {
			if (args.filePath.startsWith(args.projectPath + pref)) {
				return new QtQuickEditorWidget(prof.Editor, args);
			}
		}
		return 0;
	});
	addNewFileMenuMaker(prof.FileType, [](NewFileMenuParams) -> NewFileMenu* {
		return 0;
	});
	for (auto p : prof.DefaultPaths) {
		addDefaultPath(p);
	}
}

void EditorProfile::loadQtQuickModule(QString path) {
	using namespace models::cyborgbear;

	QFile file(path);
	if (file.open(QFile::ReadOnly | QFile::Text)) {
		QTextStream in(&file);
		models::EditorModule model;

		auto err = model.fromJson(in.readAll());
		if (err & Error_GenericParsingError) {
			qDebug() << "Error loading QtQuickProfile:" << path;
		} else if (err & Error_TypeMismatch) {
			qDebug() << "Error (Type Mismatch) loading QtQuickProfile:" << path;
		} else {
			for (auto prof : model.Profiles) {
				loadQtQuickProfile(prof);
			}
		}
	} else {
		qDebug() << "Could not load file: " << path;
	}
}

void EditorProfile::addDockMaker(DockMaker dm) {
	m_dockMakers.push_back(dm);
}

}
