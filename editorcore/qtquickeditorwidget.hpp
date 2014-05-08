#ifndef EDITORCORE_QTQUICKEDITORWIDGET_HPP
#define EDITORCORE_QTQUICKEDITORWIDGET_HPP

#include "editorprofile.hpp"

namespace editor {

class QtQuickEditorWidget: public EditorWidget {
	public:
		/**
		 * Constructor
		 * @param path path to the QML file for building this widget
		 * @param args the EditorWidgetParams needed for every EditorWidget
		 */
		QtQuickEditorWidget(QString path, EditorWidgetParams args);
};

}

#endif
