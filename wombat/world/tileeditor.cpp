#include <QDebug>
#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include "models/enums.hpp"
#include "tileeditor.hpp"

namespace wombat {
namespace world {

using namespace editor;

TileEditor::TileEditor(EditorWidgetParams args):
	EditorWidget(args), m_animDir(args.projectPath + "/Animation") {
	m_model.fromJson(modelIoManager()->readAbsolutePath(absolutePath()));

	buildGui();
	loadView();

	connect(m_chkLand, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	connect(m_chkWater, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	connect(m_chkWaterfall, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	connect(m_chkWhirlpool, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	connect(m_lowerAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
	connect(m_upperAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
}

TileEditor::~TileEditor() {
	disconnect(m_chkLand, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWater, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWaterfall, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWhirlpool, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_lowerAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
	disconnect(m_upperAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
}

QLayout *TileEditor::buildGui() {
	auto root = new QVBoxLayout(this);

	auto lytAnimLayers = new QFormLayout();
	auto grpAnimLayers = new QGroupBox("Animation Layers", this);
	m_lowerAnim = new QComboBox(this);
	m_upperAnim = new QComboBox(this);
	lytAnimLayers->addRow("&Lower Layer:", m_lowerAnim);
	lytAnimLayers->addRow("&Upper Layer:", m_upperAnim);
	grpAnimLayers->setLayout(lytAnimLayers);


	m_lowerAnim->addItem("");
	m_upperAnim->addItem("");
	auto files = m_animDir.entryList();
	for (int i = 2; i < files.size(); i++) {
		auto file = files[i];
		if (file.endsWith(".json")) {
			file = file.left(file.size() - 5);
		}
		m_upperAnim->addItem(file);
		m_lowerAnim->addItem(file);
	}


	auto lytTerrainType = new QVBoxLayout();
	auto grpTerrainType = new QGroupBox("Terrain Type", this);
	m_chkLand = new QRadioButton("L&and", this);
	m_chkWater = new QRadioButton("&Water", this);
	m_chkWaterfall = new QRadioButton("Wate&rfall", this);
	m_chkWhirlpool = new QRadioButton("Whirl&pool", this);
	lytTerrainType->addWidget(m_chkLand);
	lytTerrainType->addWidget(m_chkWater);
	lytTerrainType->addWidget(m_chkWaterfall);
	lytTerrainType->addWidget(m_chkWhirlpool);
	grpTerrainType->setLayout(lytTerrainType);

	root->addWidget(grpAnimLayers);
	root->addWidget(grpTerrainType);

	return root;
}

int TileEditor::saveFile() {
	auto json = m_model.toJson(models::cyborgbear::Readable);
	auto ret = modelIoManager()->writeAbsolutePath(absolutePath(), json);
	notifyFileSave();
	return ret;
}

void TileEditor::loadView() {
	auto prefix = QString("Animation/").size();
	auto upper = m_model.UpperAnim.Animation;
	auto lower = m_model.LowerAnim.Animation;
	m_upperAnim->setCurrentText(upper.right(upper.size() - prefix));
	m_lowerAnim->setCurrentText(lower.right(lower.size() - prefix));
	switch (m_model.TerrainType) {
	case models::Land:
		m_chkLand->setChecked(true);
		break;
	case models::Water:
		m_chkWater->setChecked(true);
		break;
	case models::Waterfall:
		m_chkWaterfall->setChecked(true);
		break;
	case models::Whirlpool:
		m_chkWhirlpool->setChecked(true);
		break;
	}
}

void TileEditor::updateModel() {
	models::TileClass model;
	if (m_chkLand->isChecked()) {
		model.TerrainType = models::Land;
	} else if (m_chkWater->isChecked()) {
		model.TerrainType = models::Water;
	} else if (m_chkWaterfall->isChecked()) {
		model.TerrainType = models::Waterfall;
	} else if (m_chkWhirlpool->isChecked()) {
		model.TerrainType = models::Whirlpool;
	}

	if (m_lowerAnim->currentText() != "") {
		model.LowerAnim.Animation = "Animation/" + m_lowerAnim->currentText();
	} else {
		model.LowerAnim.Animation = "";
	}
	if (m_upperAnim->currentText() != "") {
		model.UpperAnim.Animation = "Animation/" + m_upperAnim->currentText();
	} else {
		model.UpperAnim.Animation = "";
	}

	if (m_model != model) { // only register change if there is a change
		notifyFileChange(new Command(this, m_model, model));
	}
}

void TileEditor::setModel(models::TileClass model) {
	m_model = model;
	loadView();
}

TileEditor::Command::Command(TileEditor *parent, models::TileClass before, models::TileClass after) {
	m_parent = parent;
	m_before = before;
	m_after = after;
}

void TileEditor::Command::undo() {
	m_parent->setModel(m_before);
}

void TileEditor::Command::redo() {
	m_parent->setModel(m_after);
}

}
}
