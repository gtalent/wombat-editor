#include "animationeditor.hpp"
#include "ui_animationeditor.h"

namespace wombat {
namespace editor {

AnimationEditor::AnimationEditor(EditorTabParams args): EditorTab(args), ui(new Ui::AnimationEditor) {
	ui->setupUi(this);
}

AnimationEditor::~AnimationEditor() {
	delete ui;
}

}
}
