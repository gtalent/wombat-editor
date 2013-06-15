#include <sstream>

#include <QTableWidgetItem>
#include <QModelIndexList>
#include <QComboBox>
#include <QMessageBox>

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

	ui->tblVars->setRowCount(ui->tblVars->rowCount() + 1);
	ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 0, new QTableWidgetItem(name));
	ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 1, new QTableWidgetItem(type));
	if (type == "Bool")
		ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 2, new QTableWidgetItem(QString(v.c_str()) == "0" ? "False" : "True"));
	else
		ui->tblVars->setItem(ui->tblVars->rowCount() - 1, 2, new QTableWidgetItem(QString(v.c_str())));
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
		m_file.vars[stdStrName].set(p.second);

		if (!exists) {
			addVar(QString(p.first.c_str()), p.second);
			notifyFileChange();
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
	for (bool done = false; !done;) {
		if (editor.exec()) {
			std::pair<string, unknown*> nv = editor.getVar();

			//check to see if a variable by this name already exists
			bool exists = false;
			if (key.toStdString() != nv.first) { // if a variable by this name already exists
				for (map<string, unknown>::iterator i = m_file.vars.begin(); i != m_file.vars.end(); ++i) {
					if (i->first == nv.first) {
						exists = true;
						break;
					}
				}
			}
			
			if (!exists) {
				// delete the old value from the list in case the name changed
				m_file.vars.erase(key.toStdString());
				QString type;
				std::stringstream s;
				if (nv.second->isString()) {
					type = "String";
					s << nv.second->toString();
				} else if (nv.second->isInt()) {
					type = "Number";
					s << nv.second->toInt();
				} else if (nv.second->isBool()) {
					type = "Bool";
					s << (nv.second->toBool() ? "True" : "False");
				}
				string tmp;
				s >> tmp;
				QString val(tmp.c_str());

				ui->tblVars->setItem(row, 0, new QTableWidgetItem(QString(nv.first.c_str())));
				ui->tblVars->setItem(row, 1, new QTableWidgetItem(type));
				ui->tblVars->setItem(row, 2, new QTableWidgetItem(val));
				m_file.vars[nv.first].set(nv.second);
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

void SaveVariables::removeClicked() {
	int row = ui->tblVars->currentItem()->row();
	string key = ui->tblVars->item(row, 0)->text().toStdString();
	m_file.vars.erase(key);
	ui->tblVars->removeRow(row);
	if (ui->tblVars->currentIndex().row() == -1) {
		ui->btnRemove->setEnabled(false);
		ui->btnEdit->setEnabled(false);
		notifyFileChange();
	}
}

void SaveVariables::tableClicked(QModelIndex) {
	ui->btnRemove->setEnabled(true);
	ui->btnEdit->setEnabled(true);
}

bool SaveVariables::saveFile() {
	m_file.writeFile(m_path.toStdString());
	notifyFileChange();
	return false;
}
