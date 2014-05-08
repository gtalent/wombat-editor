#include "editorcore/misc.hpp"
#include "imageselectordialog.hpp"
#include "spritesheetmanager.hpp"
#include "animationeditor.hpp"
#include "ui_animationeditor.h"

namespace wombat {
namespace core {

AnimationEditor::AnimationEditor(EditorWidgetParams args): EditorWidget(args), ui(new Ui::AnimationEditor) {
	ui->setupUi(this);

	m_model.fromJson(modelIoManager()->read(args.filePath));

	m_projectPath = args.projectPath;
	m_modelView = new ImageTableModel(m_model, m_pixMaps, m_projectPath);
	ui->lstAnims->setModel(m_modelView);
	ui->lstAnims->verticalHeader()->setVisible(true);
	ui->lstAnims->resizeColumnsToContents();

	connect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));
	connect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(rmBtnClick()));
	connect(ui->lstAnims, SIGNAL(clicked(QModelIndex)), this, SLOT(tableClicked()));
}

AnimationEditor::~AnimationEditor() {
	disconnect(ui->lstAnims, SIGNAL(clicked(QModelIndex)), this, SLOT(tableClicked()));
	disconnect(ui->btnRemove, SIGNAL(clicked()), this, SLOT(rmBtnClick()));
	disconnect(ui->btnAdd, SIGNAL(clicked()), this, SLOT(addBtnClick()));

	delete m_modelView;
	delete ui;
}

int AnimationEditor::saveFile() {
	auto ret = modelIoManager()->write(path(), m_model.toJson(models::cyborgbear::Readable));
	notifyFileSave();
	return ret;
}

void AnimationEditor::addBtnClick() {
	ImageSelectorDialog imgSel(this, modelIoManager(), m_projectPath, "Add Image...");
	if (imgSel.exec() == QDialog::Accepted) {
		auto img = imgSel.selectedImage();
		auto model = m_model;
		models::AnimationSlide slide;
		slide.Image = img;
		slide.Interval = 1000;
		model.Images.push_back(slide);

		notifyFileChange(new Command(this, m_model, model));
	}
}

void AnimationEditor::rmBtnClick() {
	auto model = m_model;
	int row = ui->lstAnims->selectionModel()->currentIndex().row();
	model.Images.remove(row);
	notifyFileChange(new Command(this, m_model, model));
	ui->btnRemove->setEnabled(false);
}

void AnimationEditor::tableClicked() {
	ui->btnRemove->setEnabled(true);
}

void AnimationEditor::updateModel(models::Animation model) {
	// update the actual model
	m_model = model;

	// refresh the model view
	ImageTableModel dummy(m_model, m_pixMaps, m_projectPath);
	ui->lstAnims->setModel(&dummy);
	ui->lstAnims->setModel(m_modelView);

	ui->btnRemove->setEnabled(ui->lstAnims->selectionModel()->hasSelection());
}

AnimationEditor::ImageTableModel::ImageTableModel(models::Animation &model, QMap<QString, QPixmap> &pixMaps, QString &projectPath): QAbstractTableModel(0), m_model(model), m_pixMaps(pixMaps), m_projectPath(projectPath) {
}

QVariant AnimationEditor::ImageTableModel::data(const QModelIndex &index, int role) const {
	if (role == Qt::DecorationRole || role == Qt::DisplayRole) {
		int r = index.row();
		int c = index.column();
		auto slide = m_model.Images[r];

		switch (c) {
		case 0:
		{
			auto img = slide.Image;
			if (!m_pixMaps.contains(slide.Image.toJson())) {
				m_pixMaps[img.toJson()] = SpriteSheetManager::getPixmap(img, m_projectPath);
			}
			return m_pixMaps[slide.Image.toJson()];
		}
		case 1:
		{
			auto spriteSheet = m_projectPath + slide.Image.SpriteSheet;
			logDebug(spriteSheet);
			spriteSheet = spriteSheet.mid(spriteSheet.lastIndexOf('/') + 1);
			spriteSheet = spriteSheet.mid(0, spriteSheet.size() - 5);
			return spriteSheet;
		}
		case 2:
			return slide.Interval;
		}
	}
	return QVariant();
}

int AnimationEditor::ImageTableModel::rowCount(const QModelIndex&) const {
	return m_model.Images.size();
}

int AnimationEditor::ImageTableModel::columnCount(const QModelIndex&) const {
	return 3;
}

QVariant AnimationEditor::ImageTableModel::headerData(int index, Qt::Orientation ori, int role) const {
	if (role == Qt::DisplayRole) {
		if (ori == Qt::Horizontal) {
			switch (index) {
			case 0:
				return "Image";
			case 1:
				return "Sprite Sheet";
			case 2:
				return "Duration (Milliseconds)";
			}
		} else {
			return index + 1;
		}
	}
	return QVariant();
}

AnimationEditor::Command::Command(AnimationEditor *parent, models::Animation before, models::Animation after) {
	m_parent = parent;
	m_before = before;
	m_after = after;
}

void AnimationEditor::Command::undo() {
	m_parent->updateModel(m_before);
}

void AnimationEditor::Command::redo() {
	m_parent->updateModel(m_after);
}

}
}
