#include <QDir>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QMenu>
#include <QString>

#include "editorcore/misc.hpp"
#include "editorcore/editorwidget.hpp"
#include "newmenu.hpp"
#include "newproject.hpp"
#include "ui_mainwindow.h"
#include "mainwindow.hpp"

using namespace editor;

const QString MainWindow::AppTitle = "Wombat Studio";

MainWindow::MainWindow(EditorProfile *profile, QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	// for some reason this can't be done QtDesigner
	connect(ui->fileList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(filePaneContextMenu(QPoint)));

	ui->dockDebug->setVisible(false);

	m_profile = profile;

	readSettings("editor_settings.json");
	setupDockWidgets();
}

MainWindow::~MainWindow() {
	writeSettings("editor_settings.json");

	if (ui->fileList->model())
		delete ui->fileList->model();
	delete ui;
}

int MainWindow::readSettings(QString path) {
	int retval = 0;

	models::EditorSettings settings;
	retval = settings.readJsonFile(path);

	if (settings.OpenProject != "") {
		openProject(settings.OpenProject);
	}

	for (auto i : settings.OpenFiles) {
		openFile(i);
	}
	ui->tabWidget->setCurrentIndex(settings.OpenTab);

	return retval;
}

int MainWindow::writeSettings(QString path) {
	models::EditorSettings settings;

	settings.OpenProject = m_projectPath;
	for (int i = 0; i < ui->tabWidget->count(); i++) {
		auto t = dynamic_cast<EditorWidget*>(ui->tabWidget->widget(i));
		if (t) {
			settings.OpenFiles.push_back(t->absolutePath());
		}
	}
	settings.OpenTab = ui->tabWidget->currentIndex();

	settings.writeJsonFile(path, models::cyborgbear::Readable);

	return 0;
}

void MainWindow::newMenu() {
	NewMenu menu(this, m_projectPath, m_profile->fileTypes());
	if (menu.exec() == QDialog::Accepted) {
		QString nw = menu.newWhat();
		if (nw == "Project") {
			NewProject np(this, m_profile->defaultPaths());
			if (np.exec() == QDialog::Accepted) {
				QString p = np.path();
				if (p != "") {
					openProject(p);
				}
			}
		} else {
			editor::NewFileMenuParams args;
			args.projectPath = m_projectPath;
			args.fileType = nw;
			args.appTitle = AppTitle;
			args.parent = this;
			auto nm = m_profile->newFileMenu(args);
			if (nm && nm->exec() == QDialog::Accepted) {
				openFile(nm->path());
			}
			delete nm;
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
	logDebug("Opening project: " + path);
	if (!path.endsWith("/"))
		path += "/";
	m_projectPath = path;
	m_models.setProjectPath(path);
	setWindowTitle(path.mid(0, path.length() - 1) + " - " + AppTitle);

	if (ui->fileList->model())
		delete ui->fileList->model();

	QFileSystemModel *model = new QFileSystemModel();
	ui->fileList->setModel(model);
	ui->fileList->setHeaderHidden(true);
	for (int i = 1; i < 4; i++) {
		ui->fileList->hideColumn(i);
	}
	QStringList l;
	l << "*.json";
	model->setNameFilters(l);
	model->setNameFilterDisables(false);
	ui->fileList->setRootIndex(model->setRootPath(path));
}

void MainWindow::openFile(QModelIndex index) {
	QString path = ((QFileSystemModel*) ui->fileList->model())->fileInfo(index).absoluteFilePath();
	openFile(path);
}

void MainWindow::openFile(QString path) {
	logDebug("Opening file: " + path);
	auto tab = m_openTabs[path];
	if (!tab) {
		QString tabName = "";
		QStringList list = path.split("/");
		tabName = list[list.size() - 1];

		// setup tab
		EditorWidgetParams args;
		args.projectPath = m_projectPath;
		args.filePath = path;
		args.parent = ui->tabWidget;
		args.models = &m_models;
		tab = m_profile->editorWidget(args);

		if (tab) {
			connect(tab, &EditorWidget::fileChanged, this, &MainWindow::fileChanged);
			connect(tab, &EditorWidget::fileSaved, this, &MainWindow::fileSaved);
			tab->title(tabName);
			m_openTabs[path] = tab;
			ui->tabWidget->addTab(tab, tab->title());

			ui->tabWidget->setCurrentWidget(tab);
		}
	} else {
		ui->tabWidget->setCurrentWidget(tab);
	}
}

void MainWindow::undo() {
	auto tab = currentTab();
	if (tab) {
		tab->undo();
		ui->actionUndo->setEnabled(tab->canUndo());
		ui->actionRedo->setEnabled(tab->canRedo());
	}
}

void MainWindow::redo() {
	auto tab = currentTab();
	if (tab) {
		tab->redo();
		ui->actionUndo->setEnabled(tab->canUndo());
		ui->actionRedo->setEnabled(tab->canRedo());
	}
}

void MainWindow::closeTab(EditorWidget *tab) {
	if (tab) {
		ui->actionUndo->setEnabled(false);
		ui->actionRedo->setEnabled(false);
		tab->close();
		m_openTabs[tab->absolutePath()] = 0;
		m_openTabs.erase(m_openTabs.find(tab->absolutePath()));
		disconnect(tab, &EditorWidget::fileChanged, this, &MainWindow::fileChanged);
		disconnect(tab, &EditorWidget::fileSaved, this, &MainWindow::fileSaved);
		delete tab;
	}
}

void MainWindow::closeTab(int index) {
	closeTab(dynamic_cast<EditorWidget*>(ui->tabWidget->widget(index)));
}

void MainWindow::filePaneContextMenu(const QPoint &itemPt) {
	QModelIndex index = ui->fileList->currentIndex();
	QPoint p = ui->fileList->mapToGlobal(itemPt);
	QMenu m;

	QString path = ((QFileSystemModel*) ui->fileList->model())->fileInfo(index).absoluteFilePath();
	if (QFileInfo(path).isDir()) {
		path += "/";
	}
	QString projectDir = m_projectPath;

	if (path != "") {
		bool fileDeletable = true;
		auto defaultPaths = m_profile->defaultPaths();
		for (auto p : defaultPaths) {
			if (m_projectPath + p == path) {
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
			closeTab(m_openTabs[path]);
		}
	}
}

void MainWindow::setupDockWidgets() {
	const auto args = DockWindowParams(this, &m_models);
	auto makers = m_profile->dockMakers();
	for (auto maker : makers) {
		auto dock = maker(args);
		addDockWidget(dock->dockWidgetArea(), dock);
	}
}

void MainWindow::logDebug(QString msg) {
	ui->listDebugLog->addItem(msg);
	ui->listDebugLog->scrollToBottom();
}

EditorWidget *MainWindow::currentTab() {
	return dynamic_cast<EditorWidget*>(ui->tabWidget->currentWidget());
}

void MainWindow::saveFile() {
	auto tab = currentTab();
	if (tab) {
		tab->saveFile();
	}
}

void MainWindow::fileSaved() {
	ui->actionSave->setEnabled(false);
	auto tab = currentTab();
	auto tabIdx = ui->tabWidget->indexOf(tab);
	ui->tabWidget->setTabText(tabIdx, tab->title());
}

void MainWindow::fileChanged() {
	auto tab = currentTab();
	if (tab) {
		ui->actionSave->setEnabled(true);
		ui->actionUndo->setEnabled(tab->canUndo());
		ui->actionRedo->setEnabled(tab->canRedo());

		auto tabIdx = ui->tabWidget->indexOf(tab);
		ui->tabWidget->setTabText(tabIdx, "* " + tab->title());
	}
}

void MainWindow::changeTab() {
	EditorWidget *tab = currentTab();
	if (tab) {
		ui->actionSave->setEnabled(!tab->currentStateSaved());
		ui->actionUndo->setEnabled(tab->canUndo());
		ui->actionRedo->setEnabled(tab->canRedo());
	}
}
