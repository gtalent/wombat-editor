#include "appcontext.hpp"

namespace editor {

AppContext::AppContext() {
}

AppContext::~AppContext() {
}

CommonObject &AppContext::commonObject(QString id) const {
	return *m_dockWindows[id];
}

const QMap<QString, CommonObject*> &AppContext::commonObjects() {
	return m_dockWindows;
}

void AppContext::addCommonObject(CommonObject *dw) {
	if (dw && dw->objectId() != "") {
		m_dockWindows[dw->objectId()] = dw;
	}
}

}
