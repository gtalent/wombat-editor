#include "savevariableeditor.hpp"
#include "ui_savevariableeditor.h"

namespace wombat {
namespace savevariables {

SaveVariableEditor::SaveVariableEditor(QWidget *parent, QString key, unknown val): QDialog(parent), ui(new Ui::SaveVariableEditor) {
	ui->setupUi(this);
	ui->leName->setText(key);
	updateValue(val);
	setSizeGripEnabled(false);
	setFixedSize(400, 170);
}

SaveVariableEditor::~SaveVariableEditor() {
	delete ui;
}

void SaveVariableEditor::updateValue(unknown v) {
	if (v.isBool()) {
		ui->cbValue->setCurrentText(v.toBool() ? "True" : "False");
		updateType("Bool");
	} else if (v.isString()) {
		ui->leValue->setText(v.toString());
		updateType("String");
	} else if (v.isInt()) {
		ui->sbValue->setValue(v.toInt());
		updateType("Number");
	}
}

unknown SaveVariableEditor::getValue() {
	unknown v;
	QString t = ui->cbType->currentText();
	if (t == "Bool") {
		v.set(ui->cbValue->currentText() == "True");
	} else if (t == "Number") {
		v.set(ui->sbValue->value());
	} else if (t == "String") {
		v.set(ui->leValue->text());
	}
	return v;
}

QPair<QString, unknown> SaveVariableEditor::getVar() {
	QPair<QString, unknown> out(ui->leName->text(), getValue());
	return out;
}

void SaveVariableEditor::updateType(QString t) {
	if (t == "Bool") {
		ui->cbValue->show();
		ui->leValue->hide();
		ui->sbValue->hide();
		ui->lblValue->setBuddy(ui->cbValue);
		ui->cbType->setCurrentText("Bool");
	} else if (t == "String") {
		ui->cbValue->hide();
		ui->leValue->show();
		ui->sbValue->hide();
		ui->lblValue->setBuddy(ui->leValue);
		ui->cbType->setCurrentText("String");
	} else if (t == "Number") {
		ui->cbValue->hide();
		ui->leValue->hide();
		ui->sbValue->show();
		ui->lblValue->setBuddy(ui->sbValue);
		ui->cbType->setCurrentText("Number");
	}
}

}
}
