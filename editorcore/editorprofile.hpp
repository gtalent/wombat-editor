#ifndef EDITORCORE_EDITORMANAGER_HPP
#define EDITORCORE_EDITORMANAGER_HPP

#include <functional>
#include <QVector>
#include <QMap>
#include <QDockWidget>
#include <models/editormodels.hpp>
#include "modeliomanager.hpp"
#include "dockwindow.hpp"
#include "editorwidget.hpp"
#include "newfilemenu.hpp"

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
		QMap<QString, QString> m_vars;

	public:
		EditorProfile() = default;

		NewFileMenu *newFileMenu(NewFileMenuParams);

		EditorWidget *editorWidget(EditorWidgetParams);

		const QVector<QString> &defaultPaths();

		const QVector<QString> &fileTypes();

		const QVector<DockMaker> &dockMakers();

		void addNewFileMenuMaker(QString, NewFileMenuMaker);

		void addEditorWidgetMaker(EditorWidgetMaker);

		/**
		 * Adds a function that the MainWindow will use to make a DockWidget.
		 */
		void addDockMaker(DockMaker);

		/**
		 * Adds a function that the MainWindow will use to make a DockWidget
		 * of type T. T should have a constructor that takes a DockWindowParams.
		 */
		template<typename T>
		void addDockMaker() {
			addDockMaker([](DockWindowParams args) -> DockWindow* {
				return new T(args);
			});
		}

		void addDefaultPath(QString);

		void var(QString key, QString val);

		QString var(QString key);

		/**
		 * Loads EditorProfile information for a QtQuick module.
		 * @param the path to the desired
		 */
		void loadQtQuickModule(QString path);

		void loadQtQuickProfile(models::EditorProfile);

	private:
		EditorProfile(const EditorProfile&);
		const EditorProfile &operator=(const EditorProfile&);
};

}

#endif
