#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <map>

#include <QModelIndex>
#include <QMainWindow>

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
		std::map<QString, QWidget*> m_openTabs;

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		void openProject(QString);

	public slots:
		void newMenu();
		void openProject();
		void openFile(QModelIndex);
		void import();
		void saveFile();

		void fileSaved();
		void fileChanged();
};

#endif // MAINWINDOW_HPP
