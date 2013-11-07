#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <map>

#include <QFileSystemModel>
#include <QModelIndex>
#include <QMainWindow>
#include <QPoint>
#include <QString>

#include "globs.hpp"
#include "editortab.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow, public EditorTabListener, public wombat::editor::DebugLogger {
	Q_OBJECT
	public:
		Ui::MainWindow *ui;
	private:
		QString m_projectPath;
		QMap<QString, EditorTab*> m_openTabs;
		QFileSystemModel *m_fsModel;

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void openProject(QString);
		virtual void logDebug(QString msg);

	private:
		EditorTab *currentTab();

	public slots:
		void newMenu();
		void openProject();
		void openFile(QModelIndex);
		void openFile(QString);
		void import();
		void saveFile();
		void undo();
		void redo();
		void changeTab();
		void closeTab(int index);
		void closeTab(EditorTab *tab);
		void filePaneContextMenu(const QPoint &p);

		void fileSaved();
		void fileChanged();

};

#endif // MAINWINDOW_HPP
