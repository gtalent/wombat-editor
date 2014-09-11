#include <QSizePolicy>
#include <QHBoxLayout>
#include <QFile>
#include <QLabel>
#include "misc.hpp"
#include "genericnewfilemenu.hpp"

namespace editor {

BaseGenericNewFileMenu::BaseGenericNewFileMenu(NewFileMenuParams args, QString title, QString classPath): NewFileMenu(args) {
	setWindowTitle(title);
	m_projectPath = args.projectPath;
	m_classPath = classPath;

	auto label = new QLabel(this);
	label->setText("&Name:");

	m_leName = new QLineEdit(this);
	label->setBuddy(m_leName);

	setSizeGripEnabled(false);
	setFixedSize(450, 110);

	auto root = new QVBoxLayout(this);
	auto layout = new QHBoxLayout();
	m_btns = new QDialogButtonBox(this);
	m_btns->setStandardButtons(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
	layout->addWidget(label);
	layout->addWidget(m_leName);
	root->addLayout(layout);
	root->addWidget(m_btns);

	connect(m_btns, SIGNAL(accepted()), this, SLOT(accept()));
	connect(m_btns, SIGNAL(rejected()), this, SLOT(close()));
}

BaseGenericNewFileMenu::~BaseGenericNewFileMenu() {
	disconnect(m_btns, SIGNAL(accepted()), this, SLOT(accept()));
	disconnect(m_btns, SIGNAL(rejected()), this, SLOT(close()));
}

QString BaseGenericNewFileMenu::path() {
	return m_path;
}

void BaseGenericNewFileMenu::accept() {
	auto path = m_projectPath + "/" + m_classPath + "/" + m_leName->text() + ".json";
	if (!QFile::exists(path)) {
		defaultModel().writeJsonFile(path);
		m_path = path;
		QDialog::accept();
	} else {
		// TODO: error message
	}
}

}
