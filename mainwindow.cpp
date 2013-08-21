#include <iostream>
#include <map>

#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QMenu>
#include <QString>

#include "globs.hpp"
#include "mainwindow.hpp"
#include "editortab.hpp"
#include "newmenu.hpp"
#include "savevariables.hpp"
#include "spritesheeteditor.hpp"
#include "importmenu.hpp"
#include "newproject.hpp"
#include "newspritesheet.hpp"
#include "ui_mainwindow.h"

using std::make_pair;

QString defaultPaths[] = {
	"Animations",
	"Creatures",
	"Creatures/Classes",
	"Creatures/Moves",
	"Creatures/Types",
	"Instances",
	"Instances/Creatures",
	"Instances/People",
	"Items",
	"Misc",
	"Misc/SaveVariables.json",
	"People",
	"People/Classes",
	"Resources",
	"Resources/SpriteSheets",
	"Worlds",
	"Worlds/Sprites",
	"Worlds/TileClasses",
	"Worlds/Worlds",
	"Worlds/Zones"
};

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	// for some reason this can't be done QtDesigner
	connect(ui->fileList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(filePaneContextMenu(QPoint)));

	ui->actionAnimationEditor->setEnabled(false);
	ui->dockAnimationEditor->setVisible(false);
	mainWin = ui;
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
		} else if (nw == "Sprite Sheet") {
			NewSpriteSheet np(m_projectPath, this);
			if (!np.exec()) {
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
	m_projectPath = path;
	setWindowTitle("Wombat Editor - " + path.mid(0, path.length() - 1));

	if (ui->fileList->model())
		delete ui->fileList->model();

	QFileSystemModel *model = new QFileSystemModel();
	m_fsModel = model;
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
	EditorTab *tab = 0;
	if (!m_openTabs[path]) {
		QString tabName = "";
		if (m_projectPath + "Misc/SaveVariables.json" == path) {
			//open save variables tab
			tab = new SaveVariables(ui->tabWidget, path);
		} else if (path.startsWith(m_projectPath + "Resources/SpriteSheets/")) {
			tab = new SpriteSheetEditor(ui->tabWidget, m_projectPath, path);
		}

		QStringList list = path.split("/");
		tabName = list[list.size() - 1];

		if (tab) {
			tab->addListener(this);
			m_openTabs[path] = tab;
			ui->tabWidget->addTab(tab, tabName);
			ui->tabWidget->setCurrentWidget(tab);
			m_currentTab = tab;
		}
	}
}

void MainWindow::import() {
	ImportMenu(this, m_projectPath).run();
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
	m_currentTab = (EditorTab*) ui->tabWidget->currentWidget();
}

void MainWindow::filePaneContextMenu(const QPoint &itemPt) {
	QModelIndex index = ui->fileList->currentIndex();
	QPoint p = ui->fileList->mapToGlobal(itemPt);
	QMenu m;

	QString path = ((QFileSystemModel*) ui->fileList->model())->fileInfo(index).canonicalFilePath();
	QString projectDir = m_projectPath;

	if (path != "") {
		bool fileDeletable = true;
		unsigned long size = sizeof(defaultPaths) / sizeof(QString);
		for (unsigned long i = 0; i < size; i++) {
			if (path == projectDir + defaultPaths[i]) {
				fileDeletable = false;
				break;
			}
		}
		if (fileDeletable) {
			m.addAction("&Delete");
			QAction *qaction = m.exec(p);

			if (qaction) {
				QString action = qaction->text();
				if (action == "&Delete") {
					QFile::remove(path);
				}
			}
		}
	}
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
