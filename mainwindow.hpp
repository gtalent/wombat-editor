#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <map>

#include <QFileSystemModel>
#include <QModelIndex>
#include <QMainWindow>
#include <QPoint>

#include "editortab.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow, public EditorTabListener {
	Q_OBJECT
	private:
		Ui::MainWindow *ui;
		EditorTab *m_currentTab;
		QString m_projectDir;
		std::map<std::string, EditorTab*> m_openTabs;
		QFileSystemModel *m_fsModel;

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

		void openProject(QString);

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
