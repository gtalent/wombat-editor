#include "animationeditor.hpp"
#include "ui_animationeditor.h"

AnimationEditor::AnimationEditor(QWidget *parent, QString path): EditorTab(parent, path), ui(new Ui::AnimationEditor) {
	ui->setupUi(this);
}

AnimationEditor::~AnimationEditor() {
	delete ui;
}
