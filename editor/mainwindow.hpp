#ifndef EDITOR_MAINWINDOW_HPP
#define EDITOR_MAINWINDOW_HPP

#include <QModelIndex>
#include <QMainWindow>
#include <QPoint>
#include <QString>

#include <editorcore/misc.hpp>
#include <editorcore/editorwidget.hpp>
#include <editorcore/editorprofile.hpp>
#include <editorcore/modeliomanager.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow, public editor::DebugLogger {
	Q_OBJECT
	public:
		static const QString AppTitle;
		Ui::MainWindow *ui;

	private:
		QString m_projectPath;
		QMap<QString, editor::EditorWidget*> m_openTabs;
		editor::EditorProfile *m_profile;
		editor::ModelIoManager m_models;
		QVector<QDockWidget*> m_dockWidgets;

	public:
		explicit MainWindow(editor::EditorProfile *profile = 0, QWidget *parent = 0);
		~MainWindow();

		void openProject(QString);
		virtual void logDebug(QString msg);

	private:
		void setupDockWidgets();
		editor::EditorWidget *currentTab();
		int readSettings(QString path);
		int writeSettings(QString path);

	public slots:
		void newMenu();
		void openProject();
		void openFile(QModelIndex);
		void openFile(QString);
		void saveFile();
		void undo();
		void redo();
		void changeTab();
		void closeTab(int index);
		void closeTab(editor::EditorWidget *tab);
		void filePaneContextMenu(const QPoint &p);

		void fileSaved();
		void fileChanged();
};

#endif // MAINWINDOW_HPP
