#include "savevariableeditor.hpp"
#include "ui_savevariableeditor.h"

SaveVariableEditor::SaveVariableEditor(QWidget *parent, unknown *val): QDialog(parent), ui(new Ui::SaveVariableEditor) {
	ui->setupUi(this);
	ui->leValue->hide();
	ui->sbValue->hide();
	updateType(ui->cbType->currentText());
	updateValue(val);
}

SaveVariableEditor::~SaveVariableEditor() {
	delete ui;
}

void SaveVariableEditor::updateValue(unknown *v) {
	if (v->isBool()) {
		ui->cbValue->setCurrentText(v->toBool() ? "True" : "False");
	} else if (v->isString()) {
		ui->leValue->setText(QString(v->toString().c_str()));
	} else if (v->isInt()) {
		ui->sbValue->setValue(v->toInt());
	}
}

unknown* SaveVariableEditor::getValue() {
	unknown *v = new unknown();
	QString t = ui->cbType->currentText();
	if (t == "Bool")
		v->set(ui->cbValue->currentText() == "True");
	else if (t == "Number")
		v->set(ui->sbValue->value());
	else if (t == "String")
		v->set(ui->leValue->text().toStdString());
	return v;
}

std::pair<string, unknown*> SaveVariableEditor::getVar() {
	std::pair<string, unknown*> out;
	out.first = ui->leName->text().toStdString();
	out.second = getValue();
	return out;
}

void SaveVariableEditor::updateType(QString t) {
	if (t == "Bool") {
		ui->cbValue->show();
		ui->leValue->hide();
		ui->sbValue->hide();
	} else if (t == "String") {
		ui->cbValue->hide();
		ui->leValue->show();
		ui->sbValue->hide();
	} else if (t == "Number") {
		ui->cbValue->hide();
		ui->leValue->hide();
		ui->sbValue->show();
	}
}
