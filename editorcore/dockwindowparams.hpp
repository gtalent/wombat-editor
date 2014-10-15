#ifndef EDITORCORE_DOCKWINDOWPARAMS_HPP
#define EDITORCORE_DOCKWINDOWPARAMS_HPP

#include <QMainWindow>
#include "modeliomanager.hpp"

namespace editor {

struct DockWindowParams {
	class QMainWindow *parent = nullptr;
	ModelIoManager *modelio;

	DockWindowParams(QMainWindow *parent, ModelIoManager *modelio) {
		this->parent = parent;
		this->modelio = modelio;
	}
};

}

#endif
