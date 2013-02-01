#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
		Q_OBJECT
	private:
		Ui::MainWindow *ui;
		QString projectDir;

	public:
		explicit MainWindow(QWidget *parent = 0);
		~MainWindow();

	private:
		void setProjectDir(QString);

	public slots:
		void newMenu();
		void openProject();
};

#endif // MAINWINDOW_HPP
