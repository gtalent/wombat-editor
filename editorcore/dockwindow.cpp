#include "dockwindow.hpp"

namespace wombat {
namespace editor {

DockWindow::DockWindow(DockWindowParams args): QDockWidget(args.parent) {
	m_area = static_cast<Qt::DockWidgetArea>(0);
}
		
Qt::DockWidgetArea DockWindow::dockWidgetArea() {
	return m_area;
}

void DockWindow::dockWidgetArea(Qt::DockWidgetArea area) {
	m_area = area;
}

}
}
