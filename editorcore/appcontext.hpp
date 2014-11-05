#ifndef EDITORCORE_APPCONTEXT_HPP
#define EDITORCORE_APPCONTEXT_HPP

#include <QMap>
#include "commonobject.hpp"
#include "dockwindow.hpp"

namespace editor {

class AppContext {
	private:
		QMap<QString, CommonObject*> m_dockWindows;

	public:
		AppContext();

		~AppContext();

		CommonObject &commonObject(QString id) const;

		const QMap<QString, CommonObject*> &commonObjects();

		void addCommonObject(CommonObject *dw);
};

}

#endif
