#ifndef EDITORCORE_QTQUICKSIGNALER_HPP
#define EDITORCORE_QTQUICKSIGNALER_HPP

#include <QObject>

namespace editor {

class QtQuickSignaler: public QObject {
	Q_OBJECT
	signals:
		/**
		 * Sends save signal to the QtQuick apps.
		 */
		void saveFile();
};

}

#endif
