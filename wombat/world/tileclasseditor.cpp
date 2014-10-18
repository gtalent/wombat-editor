#include <QFormLayout>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <models/enums.hpp>
#include <models/paths.hpp>
#include "tileclasseditor.hpp"

namespace wombat {
namespace world {

using namespace editor;
using namespace models;
using namespace cyborgbear;

TileClassEditor::TileClassEditor(EditorWidgetParams args):
	EditorWidget(args), m_animDir(args.projectPath + Path_Animation) {
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

TileClassEditor::~TileClassEditor() {
	disconnect(m_chkLand, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWater, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWaterfall, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_chkWhirlpool, SIGNAL(toggled(bool)), this, SLOT(updateModel()));
	disconnect(m_lowerAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
	disconnect(m_upperAnim, SIGNAL(currentIndexChanged(int)), this, SLOT(updateModel()));
}

QLayout *TileClassEditor::buildGui() {
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

int TileClassEditor::saveFile() {
	auto json = m_model.toJson(Readable);
	auto ret = modelIoManager()->writeAbsolutePath(absolutePath(), json);
	notifyFileSave();
	return ret;
}

void TileClassEditor::loadView() {
	auto prefix = QString(Path_Animation).size();
	auto upper = m_model.UpperAnim.Animation;
	auto lower = m_model.LowerAnim.Animation;
	m_upperAnim->setCurrentText(upper.right(upper.size() - prefix));
	m_lowerAnim->setCurrentText(lower.right(lower.size() - prefix));
	switch (m_model.TerrainType) {
	case Land:
		m_chkLand->setChecked(true);
		break;
	case Water:
		m_chkWater->setChecked(true);
		break;
	case Waterfall:
		m_chkWaterfall->setChecked(true);
		break;
	case Whirlpool:
		m_chkWhirlpool->setChecked(true);
		break;
	}
}

void TileClassEditor::updateModel() {
	TileClass model;
	if (m_chkLand->isChecked()) {
		model.TerrainType = Land;
	} else if (m_chkWater->isChecked()) {
		model.TerrainType = Water;
	} else if (m_chkWaterfall->isChecked()) {
		model.TerrainType = Waterfall;
	} else if (m_chkWhirlpool->isChecked()) {
		model.TerrainType = Whirlpool;
	}

	if (m_lowerAnim->currentText() != "") {
		model.LowerAnim.Animation = Path_Animation + m_lowerAnim->currentText();
	} else {
		model.LowerAnim.Animation = "";
	}
	if (m_upperAnim->currentText() != "") {
		model.UpperAnim.Animation = Path_Animation + m_upperAnim->currentText();
	} else {
		model.UpperAnim.Animation = "";
	}

	if (m_model != model) { // only register change if there is a change
		notifyFileChange(new Command(this, m_model, model));
	}
}

void TileClassEditor::setModel(TileClass model) {
	m_model = model;
	loadView();
}

TileClassEditor::Command::Command(TileClassEditor *parent, TileClass before, TileClass after) {
	m_parent = parent;
	m_before = before;
	m_after = after;
}

void TileClassEditor::Command::undo() {
	m_parent->setModel(m_before);
}

void TileClassEditor::Command::redo() {
	m_parent->setModel(m_after);
}

}
}
