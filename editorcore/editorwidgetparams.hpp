#ifndef EDITORCORE_EDITORTABPARAMS_HPP
#define EDITORCORE_EDITORTABPARAMS_HPP

#include "modeliomanager.hpp"

namespace editor {

struct EditorWidgetParams {
	QString projectPath;
	QString filePath;
	QWidget *parent;
	ModelIoManager *models;
};

}

#endif
