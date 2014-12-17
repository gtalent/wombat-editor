#include "editorwidgetparams.hpp"

namespace editor {

EditorWidgetParams::EditorWidgetParams(QString projectPath, QString filePath,
	                                    QWidget *parent, const ModelIoManager &models,
							                  const AppContext &context): models(models),  context(context) {
	this->projectPath = projectPath;
	this->filePath = filePath;
	this->parent = parent;
}

}
