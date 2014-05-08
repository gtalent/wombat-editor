#ifndef EDITORCONTROLS_DOCKWIDGET_HPP
#define EDITORCONTROLS_DOCKWIDGET_HPP

#include <QDockWidget>

namespace editor {
namespace controls {

class DockWidget: public QDockWidget {
	Q_OBJECT
	public:
		DockWidget();
};

}
}

#endif
