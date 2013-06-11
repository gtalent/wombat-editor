#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <map>

#include <QModelIndex>
#include <QMainWindow>

#include "filetab.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow: public QMainWindow {
	Q_OBJECT
	private:
		Ui::MainWindow *ui;
		FileTab *m_currentTab;
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
};

#endif // MAINWINDOW_HPP
