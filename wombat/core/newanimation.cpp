#include <QFile>
#include "ui_newanimation.h"
#include "models/editormodels.hpp"
#include "newanimation.hpp"
#include "editorcore/misc.hpp"

namespace wombat {
namespace core {

using namespace editor;

NewAnimation::NewAnimation(NewFileMenuParams args): NewFileMenu(args), ui(new Ui::NewAnimation) {
	ui->setupUi(this);
	m_projectPath = args.projectPath;

	setSizeGripEnabled(false);
	setFixedSize(450, 110);
}

NewAnimation::~NewAnimation() {
	delete ui;
}

QString NewAnimation::path() {
	return m_path;
}

void NewAnimation::accept() {
	auto path = m_projectPath + "Animations/" + ui->leName->text() + ".json";
	if (!QFile::exists(path)) {
		models::Animation model;
		model.writeJsonFile(path);
		m_path = path;
		QDialog::accept();
	}
}

}
}
