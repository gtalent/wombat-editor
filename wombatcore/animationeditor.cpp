#include "imageselectordialog.hpp"
#include "animationeditor.hpp"
#include "ui_animationeditor.h"

namespace wombat {
namespace editor {

using namespace wombat::editor;

AnimationEditor::AnimationEditor(EditorWidgetParams args): EditorWidget(args), ui(new Ui::AnimationEditor) {
	ui->setupUi(this);
	connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));
	m_projectPath = args.projectPath;
}

AnimationEditor::~AnimationEditor() {
	disconnect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));
	delete ui;
}

bool AnimationEditor::saveFile() {
	return 0;
}

void AnimationEditor::addBtnClick() {
	ImageSelectorDialog imgSel(this, m_projectPath, "Add Image...");
	imgSel.exec();
}

}
}
