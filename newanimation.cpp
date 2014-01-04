#include "ui_newanimation.h"

#include "models/editormodels.hpp"
#include "newanimation.hpp"

namespace wombat {
namespace editor {

NewAnimation::NewAnimation(NewFileMenuParams args): NewFileMenu(args), ui(new Ui::NewAnimation) {
	ui->setupUi(this);
	m_projectPath = args.projectPath;
}

NewAnimation::~NewAnimation() {
	delete ui;
}

QString NewAnimation::path() {
	return ui->leName->text();;
}

void NewAnimation::accept() {
	models::Animation model;
	model.writeJsonFile(m_projectPath + "/Animations/" + path() + ".json");
}

}
}
