#ifndef DOCKWINDOW_HPP
#define DOCKWINDOW_HPP

#include <QDockWidget>
#include "dockwindowparams.hpp"

namespace wombat {
namespace editor {

class DockWindow: public QDockWidget {
	private:
		Qt::DockWidgetArea m_area;

	public:
		DockWindow(DockWindowParams);

		Qt::DockWidgetArea dockWidgetArea();

		void dockWidgetArea(Qt::DockWidgetArea);
};

}
}

#endif
