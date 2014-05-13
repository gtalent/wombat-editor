#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "tileeditor.hpp"

namespace wombat {
namespace world {

using namespace editor;

TileEditor::TileEditor(EditorWidgetParams args): EditorWidget(args) {
	auto root = new QVBoxLayout(this);
	m_upperAnims = new QListView(this);
	m_lowerAnims = new QListView(this);

	auto layers = new QHBoxLayout();
	root->addLayout(layers);

	auto upperLayers = buildAnimLayersEditor("&Upper Animation Layers",
	m_upperAnims, &m_addUpper, &m_rmUpper);
	layers->addWidget(upperLayers);

	auto lowerLayers = buildAnimLayersEditor("&Lower Animation Layers",
	m_lowerAnims, &m_addLower, &m_rmLower);
	layers->addWidget(lowerLayers);

	auto terrain = new QVBoxLayout();
	root->addLayout(terrain);
}

TileEditor::~TileEditor() {
}

QGroupBox *TileEditor::buildAnimLayersEditor(QString title,
	QListView *listView, QPushButton **addBtn, QPushButton **rmBtn) {
	auto root = new QVBoxLayout();
	auto btnRow = new QHBoxLayout();
	*addBtn = new QPushButton("&Add");
	*rmBtn = new QPushButton("&Remove");
	auto group = new QGroupBox(title, this);
	group->setLayout(root);

	btnRow->addWidget(*addBtn);
	btnRow->addWidget(*rmBtn);
	btnRow->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum));
	root->addLayout(btnRow);
	root->addWidget(listView);

	return group;
}

int TileEditor::saveFile() {
	auto json = m_model.toJson(models::cyborgbear::Readable);
	auto ret = modelIoManager()->write(path(), json);
	notifyFileSave();
	return ret;
}

}
}
