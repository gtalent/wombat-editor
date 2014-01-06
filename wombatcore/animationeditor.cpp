#include "imageselectordialog.hpp"
#include "animationeditor.hpp"
#include "ui_animationeditor.h"

namespace wombat {
namespace editor {

using namespace wombat::editor;

AnimationEditor::AnimationEditor(EditorTabParams args): EditorTab(args), ui(new Ui::AnimationEditor) {
	ui->setupUi(this);
	connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));
}

AnimationEditor::~AnimationEditor() {
	disconnect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));
	delete ui;
}

bool AnimationEditor::saveFile() {
	return 0;
}

void AnimationEditor::addBtnClick() {
	ImageSelectorDialog imgSel(this, "Add Image...");
	imgSel.exec();
}

}
}
