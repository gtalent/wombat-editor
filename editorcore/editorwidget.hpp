#ifndef EDITORCORE_EDITORWIDGET_HPP
#define EDITORCORE_EDITORWIDGET_HPP

#include <QWidget>
#include <QUndoStack>

#include "appcontext.hpp"
#include "modeliomanager.hpp"
#include "editorwidgetparams.hpp"

namespace editor {

class EditorWidget: public QWidget {
	Q_OBJECT
	friend class EditorProfile;
	private:
		const AppContext &m_context;
		ModelIoManager *m_models = nullptr;
		QUndoStack *m_undoStack = nullptr;
		int m_lastCommand = 0;
		int m_lastSavedCommand = 0;
		QString m_title;
		QString m_path;

	public:
		EditorWidget(EditorWidgetParams);
		~EditorWidget();
		bool currentStateSaved();
		QString title();
		void title(QString);
		void undo();
		void redo();
		bool canUndo();
		bool canRedo();
		const AppContext &context() const;
		QString absolutePath();
		virtual void closeWidget();
		virtual int saveFile() = 0;

	signals:
		void fileSaved();
		void fileChanged();

	protected:
		void modelIoManager(ModelIoManager*);
		ModelIoManager *modelIoManager();
		void notifyFileChange(QUndoCommand *c = 0);
		void notifyFileSave();
};

}

#endif
