#ifndef EDITORTABPARAMS_HPP
#define EDITORTABPARAMS_HPP

#include "modeliomanager.hpp"

namespace wombat {
namespace editor {

struct EditorTabParams {
	QString projectPath;
	QString filePath;
	QWidget *parent;
	ModelIoManager *models;
};

}
}

#endif
