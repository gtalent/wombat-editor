#ifndef EDITORWIDGETLISTENER_HPP
#define EDITORWIDGETLISTENER_HPP

namespace editor {

/**
 * Used to allow the MainWindow to track when editors are change and save files.
 */
class EditorWidgetListener {
	public:
        virtual void fileSaved() {}
        virtual void fileChanged() {}
};

}

#endif
