#ifndef EDITORCORE_QTQUICKEDITORWIDGET_HPP
#define EDITORCORE_QTQUICKEDITORWIDGET_HPP

#include <QGridLayout>
#include "qtquicksignaler.hpp"
#include "editorprofile.hpp"

namespace editor {

class QtQuickEditorWidget: public EditorWidget {
	private:
		QGridLayout *m_layout;
		QtQuickSignaler m_signaler;

	public:
		/**
		 * Constructor
		 * @param path path to the QML file for building this widget
		 * @param args the EditorWidgetParams needed for vevery EditorWidget
		 */
		QtQuickEditorWidget(QString path, EditorWidgetParams args);

	signals:
		/**
		 * Does nothing. This only exists to emit a signal for the QML code.
		 * @return always returns 0
		 */
		int saveFile();
};

}

#endif
