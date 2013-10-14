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

class MainWindow: public QMainWindow, public EditorTabListener, public DebugLogger {
	Q_OBJECT
	public:
		Ui::MainWindow *ui;
	private:
		EditorTab *m_currentTab;
		QString m_projectPath;
		std::map<QString, EditorTab*> m_openTabs;
		QFileSystemModel *m_fsModel;

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void openProject(QString);
		virtual void logDebug(QString msg);

	public slots:
		void newMenu();
		void openProject();
		void openFile(QModelIndex);
		void import();
		void saveFile();
		void undo();
		void redo();
		void closeTab(int index);
		void filePaneContextMenu(const QPoint &p);

		void fileSaved();
		void fileChanged();
};

#endif // MAINWINDOW_HPP
