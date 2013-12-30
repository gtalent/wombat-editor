#ifndef EDITORTABLISTENER_HPP
#define EDITORTABLISTENER_HPP

/**
 * Used to allow the MainWindow to track when editors are change and save files.
 */
class EditorTabListener {
	public:
        virtual void fileSaved() {}
        virtual void fileChanged() {}
};

#endif
