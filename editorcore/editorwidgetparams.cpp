#include "editorwidgetparams.hpp"

namespace editor {

EditorWidgetParams::EditorWidgetParams(QString projectPath, QString filePath,
	                                    QWidget *parent, ModelIoManager *models,
							                  const AppContext &context): context(context) {
	this->projectPath = projectPath;
	this->filePath = filePath;
	this->parent = parent;
	this->models = models;
}

}
