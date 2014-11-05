#ifndef EDITORCORE_EDITORTABPARAMS_HPP
#define EDITORCORE_EDITORTABPARAMS_HPP

#include "appcontext.hpp"
#include "modeliomanager.hpp"

namespace editor {

struct EditorWidgetParams {
	QString projectPath;
	QString filePath;
	QWidget *parent = nullptr;
	ModelIoManager *models = nullptr;
	const AppContext &context;

	EditorWidgetParams(QString projectPath, QString filePath,
	                   QWidget *parent, ModelIoManager *models,
							 const AppContext &context);
};

}

#endif
