#include <string>
#include <sstream>

#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QComboBox>
#include <QMessageBox>

#include <editorcore/misc.hpp>
#include "savevariableeditor.hpp"
#include "savevariables.hpp"
#include "ui_savevariables.h"

using models::cyborgbear::unknown;
using namespace editor;
using namespace std;

namespace wombat {
namespace savevariables {

SaveVariables::SaveVariables(EditorWidgetParams args): EditorWidget(args), ui(new Ui::SaveVariables) {
	ui->setupUi(this);
	ui->tblVars->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tblVars->horizontalHeader()->setStretchLastSection(true);
	m_file.fromJson(modelIoManager()->readAbsolutePath(args.filePath));
	for (auto i = m_file.Vars.begin(); i != m_file.Vars.end(); i++) {
		tblInsertVar(ui->tblVars->rowCount(), i.key(), m_file.Vars[i.key()]);
	}
}

SaveVariables::~SaveVariables() {
	delete ui;
}

void SaveVariables::tblInsertVar(int row, QString name, unknown val) {
	string v = "N/A";
	QString type = "N/A";
	std::stringstream s;
	if (val.isBool()) {
		s << val.toBool();
		type = "Bool";
	} else if (val.isString()) {
		s << val.toString().toStdString();
		type = "String";
	} else if (val.isInt()) {
		s << val.toInt();
		type = "Number";
	}
	s >> v;

	ui->tblVars->insertRow(row);
	ui->tblVars->setItem(row, 0, new QTableWidgetItem(name));
	ui->tblVars->setItem(row, 1, new QTableWidgetItem(type));
	if (type == "Bool")
		ui->tblVars->setItem(row, 2, new QTableWidgetItem(QString(v.c_str()) == "0" ? "False" : "True"));
	else
		ui->tblVars->setItem(row, 2, new QTableWidgetItem(QString(v.c_str())));
}

void SaveVariables::addVar(QString name, unknown val) {
	tblInsertVar(ui->tblVars->rowCount(), name, val);
	m_file.Vars.remove(name);
	m_file.Vars.insert(name, unknown());
	m_file.Vars[name].set(&val);
}

void SaveVariables::removeVar(int row) {
	QString key = ui->tblVars->item(row, 0)->text();
	m_file.Vars.remove(key);
	ui->tblVars->removeRow(row);
	if (ui->tblVars->currentIndex().row() == -1) {
		ui->btnRemove->setEnabled(false);
		ui->btnEdit->setEnabled(false);
	}
}

void SaveVariables::addClicked() {
	models::cyborgbear::unknown unk;
	unk.set(true);
	SaveVariableEditor editor(this, "", unk);
	editor.setWindowTitle("Add Variable...");
	while (editor.exec()) {
		auto p = editor.getVar();
		bool exists = false;
		QString stdStrName = p.first;
		for (auto i = m_file.Vars.begin(); i != m_file.Vars.end(); ++i) {
			if (i.key() == stdStrName) {
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
	SaveVariableEditor editor(this, key, m_file.Vars[key]);
	editor.setWindowTitle("Edit Variable...");
	for (bool done = false; !done;) {
		if (editor.exec()) {
			auto nv = editor.getVar();

			//check to see if a variable by this name already exists
			bool exists = false;
			if (key != nv.first) { // if a variable by this name already exists
				// delete the old value from the list in case the name changed
				for (auto i = m_file.Vars.begin(); i != m_file.Vars.end(); ++i) {
					if (i.key() == nv.first) {
						exists = true;
						break;
					}
				}
			}
			
			if (!exists) {
				notifyFileChange(new EditVarCommand(this, key, nv.first, nv.second));
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

void SaveVariables::setVar(int row, QString name, unknown val) {
	QString type;
	std::stringstream s;
	if (val.isString()) {
		type = "String";
		s << val.toString().toStdString();
	} else if (val.isInt()) {
		type = "Number";
		s << val.toInt();
	} else if (val.isBool()) {
		type = "Bool";
		s << (val.toBool() ? "True" : "False");
	}
	string tmp;
	s >> tmp;
	QString valStr(tmp.c_str());

	ui->tblVars->setItem(row, 0, new QTableWidgetItem(name));
	ui->tblVars->setItem(row, 1, new QTableWidgetItem(type));
	ui->tblVars->setItem(row, 2, new QTableWidgetItem(valStr));
	m_file.Vars[name].set(&val);
}

void SaveVariables::removeClicked() {
	int row = ui->tblVars->currentItem()->row();
	QString key = ui->tblVars->item(row, 0)->text();
	notifyFileChange(new RemoveVarCommand(this, key, &m_file.Vars[key]));
}

void SaveVariables::tableClicked(QModelIndex) {
	ui->btnRemove->setEnabled(true);
	ui->btnEdit->setEnabled(true);
}

int SaveVariables::saveFile() {
	auto out = m_file.toJson(models::cyborgbear::Readable);
	auto ret = modelIoManager()->writeAbsolutePath(absolutePath(), out);
	notifyFileSave();
	return ret;
}
	
int SaveVariables::rowOfKey(QString key) {
	for (int i = 0; i < ui->tblVars->rowCount(); i++) {
		QString row = ui->tblVars->item(i, 0)->text();
		if (row == key) {
			return i;
		}
	}
	return -1;
}

SaveVariables::AddVarCommand::AddVarCommand(SaveVariables *parent, QString name, unknown unk) {
	m_parent = parent;
	m_varName = name;
	m_varVal = new unknown();
	m_varVal.set(&unk);
}

void SaveVariables::AddVarCommand::undo() {
	int row = m_parent->rowOfKey(m_varName);
	if (row != -1)
		m_parent->removeVar(row); 
}

void SaveVariables::AddVarCommand::redo() {
	m_parent->addVar(m_varName, m_varVal);
}

SaveVariables::RemoveVarCommand::RemoveVarCommand(SaveVariables *parent, QString name, unknown unk) {
	m_parent = parent;
	m_varName = name;
	m_varVal.set(&unk);
}

void SaveVariables::RemoveVarCommand::undo() {
	if (m_varTblRow != -1) {
		m_parent->tblInsertVar(m_varTblRow, m_varName, m_varVal);
		m_parent->m_file.Vars.remove(m_varName);
		m_parent->m_file.Vars.insert(m_varName, unknown());
		m_parent->m_file.Vars[m_varName].set(&m_varVal);
	}
}

void SaveVariables::RemoveVarCommand::redo() {
	m_varTblRow = m_parent->rowOfKey(m_varName);
	if (m_varTblRow != -1)
		m_parent->removeVar(m_varTblRow);
}

SaveVariables::EditVarCommand::EditVarCommand(SaveVariables *parent, QString name, QString newName, unknown unk) {
	m_parent = parent;
	m_varName = name;
	m_newVarName = newName;
	m_newVal.set(&unk);
	m_oldVal.set(&(m_parent->m_file.Vars[name]));
}

void SaveVariables::EditVarCommand::undo() {
	int row = m_parent->rowOfKey(m_newVarName);
	if (m_varName != m_newVarName) { // if a variable by this name already exists
		m_parent->m_file.Vars.remove(m_newVarName);
		m_parent->m_file.Vars[m_varName] = unknown();
	}
	m_parent->setVar(row, m_varName, m_oldVal);
}

void SaveVariables::EditVarCommand::redo() {
	int row = m_parent->rowOfKey(m_varName);
	if (m_varName != m_newVarName) { // if a variable by this name already exists
		m_parent->m_file.Vars.remove(m_varName);
		m_parent->m_file.Vars[m_newVarName] = unknown();
	}
	m_parent->setVar(row, m_newVarName, m_newVal);
}

}
}
