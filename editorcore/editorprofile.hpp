#ifndef EDITORMANAGER_HPP
#define EDITORMANAGER_HPP

#include <functional>
#include <QVector>
#include <QMap>
#include <QDockWidget>
#include "models/editormodels.hpp"
#include "modeliomanager.hpp"
#include "dockwindow.hpp"
#include "editorwidget.hpp"
#include "newfilemenu.hpp"

namespace wombat {
namespace editor {

typedef std::function<EditorWidget*(EditorWidgetParams)> EditorWidgetMaker;

typedef std::function<NewFileMenu*(NewFileMenuParams)> NewFileMenuMaker;

typedef std::function<DockWindow*(DockWindowParams)> DockMaker;

class EditorProfile {
	private:
		QMap<QString, NewFileMenuMaker> m_newFileMenuMakers;

		QVector<EditorWidgetMaker> m_editorWidgetMakers;

		QVector<QString> m_fileTypes;

		QVector<QString> m_defaultPaths;

		QVector<DockMaker> m_dockMakers;

		ModelIoManager m_models;

		QMap<QString, QString> m_vars;

	public:
		NewFileMenu *newFileMenu(NewFileMenuParams);

		EditorWidget *editorWidget(EditorWidgetParams);

		QVector<QString> defaultPaths();

		QVector<QString> fileTypes();

		void addNewFileMenuMaker(QString, NewFileMenuMaker);

		void addEditorWidgetMaker(EditorWidgetMaker);

		void addDefaultPath(QString);

		void var(QString key, QString val);

		QString var(QString key);
};

}
}

#endif
