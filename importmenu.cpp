#include <QFileDialog>
#include <QStringList>

#include "importmenu.hpp"
#include "ui_importmenu.h"

ImportMenu::ImportMenu(QWidget *parent, QString projectDir): QDialog(parent), ui(new Ui::ImportMenu) {
	ui->setupUi(this);
	m_projectDir = projectDir;
}

ImportMenu::~ImportMenu() {
	delete ui;
}

void ImportMenu::run() {
	if (exec()) {
		QString import = ui->options->item(ui->options->currentRow())->text();
		if (import == "Images") {
			QStringList files = QFileDialog::getOpenFileNames(parentWidget(), "Choose images to import...", QDir::homePath());
			for (int i = 0; i < files.size(); i++) {
				QFile f(files[i]);
				QStringList l = files[i].split("/");
				f.copy(m_projectDir + "/Resources/Images/" + l[l.size() - 1]);
			}
		}
	}
}
