#include <map>

#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>

#include "mainwindow.hpp"
#include "editortab.hpp"
#include "newmenu.hpp"
#include "savevariables.hpp"
#include "importmenu.hpp"
#include "newproject.hpp"
#include "ui_mainwindow.h"

using std::make_pair;

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	m_currentTab = 0;
}

MainWindow::~MainWindow() {
	if (ui->fileList->model())
		delete ui->fileList->model();
	delete ui;
}

void MainWindow::newMenu() {
	NewMenu menu(this, "");
	if (!menu.exec()) {
		QString nw = menu.newWhat();
		if (nw == "Project") {
			NewProject np(this);
			if (!np.exec()) {
				QString p = np.projectDir();
				if (p != "") {
					openProject(p);
				}
			}
		}
	}
}

void MainWindow::openProject() {
	QString p = QFileDialog::getExistingDirectory(this, tr("Open Project Directory..."), QDir::homePath());
	if (p != "") {
		openProject(p);
	}
}

void MainWindow::openProject(QString path) {
	if (!path.endsWith("/"))
		path += "/";
	m_projectDir = path;
	setWindowTitle("Wombat Editor - " + path.mid(0, path.length() - 1));

	if (ui->fileList->model())
		delete ui->fileList->model();

	QFileSystemModel *model = new QFileSystemModel();
	ui->fileList->setModel(model);
	ui->fileList->setHeaderHidden(true);
	for (int i = 1; i < 4; i++) {
		ui->fileList->hideColumn(i);
	}
	QStringList l;
	l << "*.json" << "*.bmp" << "*.png" << "*.jpg";
	model->setNameFilters(l);
	model->setNameFilterDisables(false);
	ui->fileList->setRootIndex(model->setRootPath(path));
	ui->actionImport->setEnabled(true);
}

void MainWindow::openFile(QModelIndex index) {
	QString path = ((QFileSystemModel*) ui->fileList->model())->fileInfo(index).canonicalFilePath();
	EditorTab *tab;
	if (m_projectDir + "Misc/SaveVariables.json" == path) {
		//open save variables tab
		if (!m_openTabs[path.toStdString()]) {
			tab = new SaveVariables(ui->tabWidget, path.toStdString());
			tab->addListener(this);
			ui->tabWidget->addTab(tab, "SaveVariables.json");
			m_openTabs[path.toStdString()] = tab;
			m_currentTab = tab;
		}
	}
}

void MainWindow::import() {
	ImportMenu menu(this);
	if (menu.exec()) {
		QString iw = menu.importWhat();

		if (iw == "Image") {
		}
	}
}

void MainWindow::undo() {
	if (m_currentTab) {
		m_currentTab->undo();
		ui->actionUndo->setEnabled(m_currentTab->canUndo());
		ui->actionRedo->setEnabled(m_currentTab->canRedo());
	}
}

void MainWindow::redo() {
	if (m_currentTab) {
		m_currentTab->redo();
		ui->actionUndo->setEnabled(m_currentTab->canUndo());
		ui->actionRedo->setEnabled(m_currentTab->canRedo());
	}
}

void MainWindow::closeTab(int index) {
	EditorTab *t = (EditorTab*) ui->tabWidget->widget(index);
	ui->actionUndo->setEnabled(false);
	ui->actionRedo->setEnabled(false);
	t->close();
	m_openTabs[t->path()] = 0;
	m_openTabs.erase(m_openTabs.find(t->path()));
	delete t;
}

void MainWindow::saveFile() {
	EditorTab *t = m_currentTab;
	if (t)
		t->saveFile();
}

void MainWindow::fileSaved() {
	ui->actionSave->setEnabled(false);
}

void MainWindow::fileChanged() {
	ui->actionSave->setEnabled(true);
	ui->actionUndo->setEnabled(m_currentTab->canUndo());
	ui->actionRedo->setEnabled(m_currentTab->canRedo());
}
