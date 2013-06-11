#include <iostream>
#include <sstream>

#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QComboBox>

#include "savevariableeditor.hpp"
#include "savevariables.hpp"
#include "ui_savevariables.h"

using namespace std;

SaveVariables::SaveVariables(QString path, QWidget *parent): QWidget(parent), ui(new Ui::SaveVariables) {
	ui->setupUi(this);
	ui->tblVars->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_path = path;
	m_file.loadFile(path.toStdString());
	for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); i++) {
		addVar(QString(i->first.c_str()), &m_file.vars[i->first]);
	}
}

SaveVariables::~SaveVariables() {
	delete ui;
}

void SaveVariables::addVar(QString name, unknown *val) {
	string v = "N/A";
	QString type = "N/A";
	std::stringstream s;
	if (val->isBool()) {
		s << val->toBool();
		type = "Bool";
	} else if (val->isString()) {
		s << val->toString();
		type = "String";
	} else if (val->isInt()) {
		s << val->toInt();
		type = "Number";
	}
	s >> v;
	addVar(name, type, QString(v.c_str()));
}

void SaveVariables::addVar(QString name, QString type, QString val) {
	ui->tblVars->setRowCount(ui->tblVars->rowCount() + 1);
	ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 0, new QTableWidgetItem(name));
	ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 1, new QTableWidgetItem(type));
	ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 2, new QTableWidgetItem(val));
}

void SaveVariables::addClicked() {
	unknown u;
	u.set(false);
	SaveVariableEditor editor(this, &u);
	editor.setWindowTitle("Add Variable...");
	if (editor.exec()) {
		std::pair<string, unknown*> p = editor.getVar();
		m_file.vars[p.first] = *p.second;
		addVar(QString(p.first.c_str()), p.second);
	}
}

void SaveVariables::editCurrentVar() {
	int row = ui->tblVars->currentItem()->row();
	string key = ui->tblVars->item(row, 0)->text().toStdString();
	SaveVariableEditor editor(this, &m_file.vars[key]);
	m_file.vars.erase(key);
	editor.exec();
	std::pair<string, unknown*> p = editor.getVar();
	m_file.vars[p.first].set(p.second);
}

void SaveVariables::removeClicked() {
	int row = ui->tblVars->currentItem()->row();
	string key = ui->tblVars->item(row, 0)->text().toStdString();
	cout << "row: " << row << endl;
	cout << "key: " << key << endl;
	m_file.vars.erase(key);
	ui->tblVars->removeRow(row);
	if (ui->tblVars->currentIndex().row() == -1) {
		ui->btnRemove->setEnabled(false);
		ui->btnEdit->setEnabled(false);
	}
}

void SaveVariables::tableClicked(QModelIndex) {
	ui->btnRemove->setEnabled(true);
	ui->btnEdit->setEnabled(true);
}

bool SaveVariables::saveFile() {
	m_file.writeFile(m_path.toStdString());
	return false;
}
