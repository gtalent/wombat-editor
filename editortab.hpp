#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <QWidget>
#include <QUndoStack>

#include "editortablistener.hpp"

class EditorTab: public QWidget {
	private:
		QVector<EditorTabListener*> m_listeners;
		QUndoStack *m_undoStack;
		bool m_hasUnsavedChanges;

		int m_lastCommand;
		int m_lastSavedCommand;

	protected:
		QString m_path;

	public:
		EditorTab(QWidget *win, QString path);
		~EditorTab();
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		bool currentStateSaved();
		void undo();
		void redo();
		bool canUndo();
		bool canRedo();
		QString path();
		virtual void closeTab();
		virtual bool saveFile() = 0;

	protected:
		void notifyFileChange(QUndoCommand *c = 0);
		void notifyFileSave();
};

#endif
