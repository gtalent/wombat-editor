#ifndef EDITORCORE_DOCKWINDOWPARAMS_HPP
#define EDITORCORE_DOCKWINDOWPARAMS_HPP

#include <QMainWindow>
#include "modeliomanager.hpp"

namespace editor {

struct DockWindowParams {
	class QMainWindow *parent = nullptr;
	const ModelIoManager &modelio;

	DockWindowParams(QMainWindow *parent, const ModelIoManager &modelio): modelio(modelio) {
		this->parent = parent;
	}
};

}

#endif
