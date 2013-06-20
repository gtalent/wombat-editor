#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <string>
#include <vector>

#include <QWidget>
#include <QUndoStack>

#include "editortablistener.hpp"

class EditorTab: public QWidget {
	private:
		std::vector<EditorTabListener*> m_listeners;
		bool m_hasUnsavedChanges;
		QUndoStack *m_undoStack;

		const QUndoCommand *m_lastCommand;
		const QUndoCommand *m_lastSavedCommand;

	protected:
		std::string m_path;

	public:
		EditorTab(QWidget *win, std::string path);
		~EditorTab();
		void updateListeners();
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		void undo();
		void redo();
		bool canUndo();
		bool canRedo();
		std::string path();
		virtual void closeTab();
		virtual bool saveFile() = 0;

	protected:
		void notifyFileChange(QUndoCommand *c = 0);
		void notifyFileSave();
	protected slots:
};

#endif
