#include <sstream>

#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QComboBox>
#include <QMessageBox>

#include "savevariableeditor.hpp"
#include "savevariables.hpp"
#include "ui_savevariables.h"

using modelmaker::unknown;
using namespace std;

SaveVariables::SaveVariables(QWidget *parent, string path): EditorTab(parent, path), ui(new Ui::SaveVariables) {
	ui->setupUi(this);
	ui->tblVars->setEditTriggers(QAbstractItemView::NoEditTriggers);
	m_file.loadFile(path);
	for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); i++) {
		//clone the mapped var because addVar re-sets the value in the map, and that causes wierdness
		tblInsertVar(ui->tblVars->rowCount(), i->first, &m_file.vars[i->first]);
	}
}

SaveVariables::~SaveVariables() {
	delete ui;
}

void SaveVariables::tblInsertVar(int row, string name, unknown *val) {
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
}

void SaveVariables::addVar(string name, unknown *val) {
	tblInsertVar(ui->tblVars->rowCount(), name, val);
	m_file.vars.erase(name);
	m_file.vars.insert(make_pair(name, unknown()));
	m_file.vars[name].set(val);
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
				for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); ++i) {
					if (i->first == nv.first) {
						exists = true;
						break;
					}
				}
			}
			
			if (!exists) {
				notifyFileChange(new EditVarCommand(this, key.toStdString(), nv.first, nv.second));
				delete nv.second;
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
	m_file.writeFile(m_path);
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
	if (m_varTblRow != -1) {
		m_parent->tblInsertVar(m_varTblRow, m_varName, m_varVal);
		m_parent->m_file.vars.erase(m_varName);
		m_parent->m_file.vars.insert(make_pair(m_varName, unknown()));
		m_parent->m_file.vars[m_varName].set(m_varVal);
	}
}

void SaveVariables::RemoveVarCommand::redo() {
	m_varTblRow = m_parent->rowOfKey(m_varName);
	if (m_varTblRow != -1)
		m_parent->removeVar(m_varTblRow);
}

SaveVariables::EditVarCommand::EditVarCommand(SaveVariables *parent, string name, string newName, modelmaker::unknown *unk) {
	m_parent = parent;
	m_varName = name;
	m_newVarName = newName;
	m_newVal.set(unk);
	m_oldVal.set(&(m_parent->m_file.vars[name]));
}

void SaveVariables::EditVarCommand::undo() {
	int row = m_parent->rowOfKey(m_newVarName);
	if (m_varName != m_newVarName) { // if a variable by this name already exists
		m_parent->m_file.vars.erase(m_newVarName);
		m_parent->m_file.vars[m_varName] = unknown();
	}
	m_parent->setVar(row, m_varName, &m_oldVal);
}

void SaveVariables::EditVarCommand::redo() {
	int row = m_parent->rowOfKey(m_varName);
	if (m_varName != m_newVarName) { // if a variable by this name already exists
		m_parent->m_file.vars.erase(m_varName);
		m_parent->m_file.vars[m_newVarName] = unknown();
	}
	m_parent->setVar(row, m_newVarName, &m_newVal);
}
