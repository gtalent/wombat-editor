#ifndef EDITORWIDGET_HPP
#define EDITORWIDGET_HPP

#include <QWidget>
#include <QUndoStack>

#include "modeliomanager.hpp"
#include "editorwidgetlistener.hpp"
#include "editorwidgetparams.hpp"

namespace editor {

class EditorProfile;

class EditorWidget: public QWidget {
	friend EditorProfile;
	private:
		ModelIoManager *m_models;

		QVector<EditorWidgetListener*> m_listeners;
		QUndoStack *m_undoStack;

		int m_lastCommand;
		int m_lastSavedCommand;

		QString m_title;
		QString m_path;

	public:
		EditorWidget(EditorWidgetParams);
		~EditorWidget();
		void addListener(EditorWidgetListener *l);
		void removeListener(EditorWidgetListener *l);
		bool currentStateSaved();
		QString title();
		void title(QString);
		void undo();
		void redo();
		bool canUndo();
		bool canRedo();
		QString path();
		virtual void closeWidget();
		virtual int saveFile() = 0;

	protected:
		void modelIoManager(ModelIoManager*);
		ModelIoManager *modelIoManager();
		void notifyFileChange(QUndoCommand *c = 0);
		void notifyFileSave();
};

}

#endif
