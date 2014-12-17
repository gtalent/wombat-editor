#ifndef EDITORCORE_EDITORTABPARAMS_HPP
#define EDITORCORE_EDITORTABPARAMS_HPP

#include "appcontext.hpp"
#include "modeliomanager.hpp"

namespace editor {

struct EditorWidgetParams {
	QString projectPath;
	QString filePath;
	QWidget *parent = nullptr;
	const ModelIoManager &models;
	const AppContext &context;

	EditorWidgetParams(QString projectPath, QString filePath,
	                   QWidget *parent, const ModelIoManager &models,
							 const AppContext &context);
};

}

#endif
