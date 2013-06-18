#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <vector>

#include <QWidget>
#include <QUndoStack>

#include "editortablistener.hpp"

class EditorTab {
	private:
		std::vector<EditorTabListener*> m_listeners;
		bool m_hasUnsavedChanges;
		QUndoStack *m_undoStack;

		const QUndoCommand *m_lastCommand;
		const QUndoCommand *m_lastSavedCommand;

	public:
		EditorTab(QWidget *win);
		~EditorTab();
		void updateListeners();
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		void undo();
		void redo();
		bool canUndo();
		bool canRedo();
		virtual bool saveFile() = 0;

	protected:
		void notifyFileChange(QUndoCommand *c = 0);
		void notifyFileSave();
};

#endif
