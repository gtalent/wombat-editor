#include "dockwindow.hpp"

namespace editor {

DockWindow::DockWindow(DockWindowParams args): QDockWidget(args.parent) {
	m_area = static_cast<Qt::DockWidgetArea>(1);
	setFeatures(QDockWidget::AllDockWidgetFeatures);
}
		
Qt::DockWidgetArea DockWindow::dockWidgetArea() {
	return m_area;
}

void DockWindow::dockWidgetArea(Qt::DockWidgetArea area) {
	m_area = area;
}

}
