#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <QWidget>
#include <QUndoStack>

#include "editortablistener.hpp"

class EditorTab: public QWidget {
	private:
		QVector<EditorTabListener*> m_listeners;
		QUndoStack *m_undoStack;

		int m_lastCommand;
		int m_lastSavedCommand;

		QString m_title;
		QString m_path;

	public:
		EditorTab(QWidget *win, QString path);
		~EditorTab();
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		bool currentStateSaved();
		QString title();
		void title(QString);
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
