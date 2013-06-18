#include <sstream>

#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QComboBox>
#include <QMessageBox>

#include "savevariableeditor.hpp"
#include "savevariables.hpp"
#include "ui_savevariables.h"

using modelmaker::unknown;

SaveVariables::SaveVariables(QString path, QWidget *parent): QWidget(parent), EditorTab(parent), ui(new Ui::SaveVariables) {
	ui->setupUi(this);
	ui->tblVars->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_path = path;
	m_file.loadFile(path.toStdString());
	for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); i++) {
		//clone the mapped var because addVar re-sets the value in the map, and that causes wierdness
		unknown unk(&m_file.vars[i->first]);
		addVar(i->first, &unk);
	}
}

SaveVariables::~SaveVariables() {
	delete ui;
}

void SaveVariables::insertVar(int row, string name, unknown *val) {
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

	ui->tblVars->insertRow(row);
	ui->tblVars->setItem(row, 0, new QTableWidgetItem(QString(name.c_str())));
	ui->tblVars->setItem(row, 1, new QTableWidgetItem(type));
	if (type == "Bool")
		ui->tblVars->setItem(row, 2, new QTableWidgetItem(QString(v.c_str()) == "0" ? "False" : "True"));
	else
		ui->tblVars->setItem(row, 2, new QTableWidgetItem(QString(v.c_str())));
	m_file.vars.erase(name);
	m_file.vars.insert(make_pair(name, unknown()));
	m_file.vars[name].set(val);
}

void SaveVariables::addVar(string name, unknown *val) {
	insertVar(ui->tblVars->rowCount(), name, val);
}

void SaveVariables::removeVar(int row) {
	string key = ui->tblVars->item(row, 0)->text().toStdString();
	m_file.vars.erase(key);
	ui->tblVars->removeRow(row);
	if (ui->tblVars->currentIndex().row() == -1) {
		ui->btnRemove->setEnabled(false);
		ui->btnEdit->setEnabled(false);
	}
}

void SaveVariables::addClicked() {
	SaveVariableEditor editor(this);
	editor.setWindowTitle("Add Variable...");
	while (editor.exec()) {
		std::pair<string, unknown*> p = editor.getVar();
		bool exists = false;
		string stdStrName = p.first;
		for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); ++i) {
			if (i->first == stdStrName) {
				exists = true;
			}
		}

		if (!exists) {
			notifyFileChange(new AddVarCommand(this, p.first, p.second));
			break;
		} else {
			QMessageBox alert;
			alert.setText("A variable by this name already exists.");
			alert.exec();
		}
	}
}

void SaveVariables::editCurrentVar() {
	int row = ui->tblVars->currentItem()->row();
	QString key = ui->tblVars->item(row, 0)->text();
	SaveVariableEditor editor(this, key, &m_file.vars[key.toStdString()]);
	editor.setWindowTitle("Edit Variable...");
	for (bool done = false; !done;) {
		if (editor.exec()) {
			std::pair<string, unknown*> nv = editor.getVar();

			//check to see if a variable by this name already exists
			bool exists = false;
			if (key.toStdString() != nv.first) { // if a variable by this name already exists
				// delete the old value from the list in case the name changed
				m_file.vars.erase(key.toStdString());
				for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); ++i) {
					if (i->first == nv.first) {
						exists = true;
						break;
					}
				}
			}
			
			if (!exists) {
				setVar(row, nv.first, nv.second);
				notifyFileChange();
				done = true;
			} else {
				QMessageBox alert;
				alert.setText("A variable by this name already exists.");
				alert.exec();
			}
		} else {
			done = true;
		}
	}
}

void SaveVariables::setVar(int row, string name, unknown *val) {
	QString type;
	std::stringstream s;
	if (val->isString()) {
		type = "String";
		s << val->toString();
	} else if (val->isInt()) {
		type = "Number";
		s << val->toInt();
	} else if (val->isBool()) {
		type = "Bool";
		s << (val->toBool() ? "True" : "False");
	}
	string tmp;
	s >> tmp;
	QString valStr(tmp.c_str());
	
	ui->tblVars->setItem(row, 0, new QTableWidgetItem(QString(name.c_str())));
	ui->tblVars->setItem(row, 1, new QTableWidgetItem(type));
	ui->tblVars->setItem(row, 2, new QTableWidgetItem(valStr));
	m_file.vars[name].set(val);
}

void SaveVariables::removeClicked() {
	int row = ui->tblVars->currentItem()->row();
	string key = ui->tblVars->item(row, 0)->text().toStdString();
	notifyFileChange(new RemoveVarCommand(this, key, &m_file.vars[key]));
}

void SaveVariables::tableClicked(QModelIndex) {
	ui->btnRemove->setEnabled(true);
	ui->btnEdit->setEnabled(true);
}

bool SaveVariables::saveFile() {
	m_file.writeFile(m_path.toStdString());
	notifyFileSave();
	return false;
}
	
int SaveVariables::rowOfKey(string key) {
	for (int i = 0; i < ui->tblVars->rowCount(); i++) {
		string row = ui->tblVars->item(i, 0)->text().toStdString();
		if (row == key) {
			return i;
		}
	}
	return -1;
}

SaveVariables::AddVarCommand::AddVarCommand(SaveVariables *parent, string name, modelmaker::unknown *unk) {
	m_parent = parent;
	m_varName = name;
	m_varVal = new unknown();
	m_varVal->set(unk);
}

void SaveVariables::AddVarCommand::undo() {
	int row = m_parent->rowOfKey(m_varName);
	if (row != -1)
		m_parent->removeVar(row); 
}

void SaveVariables::AddVarCommand::redo() {
	m_parent->addVar(m_varName, m_varVal);
}

SaveVariables::RemoveVarCommand::RemoveVarCommand(SaveVariables *parent, string name, modelmaker::unknown *unk) {
	m_parent = parent;
	m_varName = name;
	m_varVal = new unknown();
	m_varVal->set(unk);
}

void SaveVariables::RemoveVarCommand::undo() {
	if (m_varTblRow != -1)
		m_parent->insertVar(m_varTblRow, m_varName, m_varVal);
}

void SaveVariables::RemoveVarCommand::redo() {
	m_varTblRow = m_parent->rowOfKey(m_varName);
	if (m_varTblRow != -1)
		m_parent->removeVar(m_varTblRow);
}
