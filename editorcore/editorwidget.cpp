#include "editorwidget.hpp"

namespace editor {

EditorWidget::EditorWidget(EditorWidgetParams args):
QWidget(args.parent), m_context(args.context), m_models(args.models) {
	m_undoStack = new QUndoStack(args.parent);
	m_lastCommand = m_lastSavedCommand = 0;
	m_path = args.filePath;
}

EditorWidget::~EditorWidget() {
	delete m_undoStack;
}

bool EditorWidget::currentStateSaved() {
	return m_lastSavedCommand == m_lastCommand;
}

QString EditorWidget::title() {
	return m_title;
}

void EditorWidget::title(QString title) {
	m_title = title;
}

void EditorWidget::notifyFileChange(QUndoCommand *uc) {
	if (uc) {
		m_undoStack->push(uc);
		m_lastCommand = m_undoStack->index();
	}
	emit fileChanged();
}

const ModelIoManager &EditorWidget::modelIoManager() {
	return m_models;
}

void EditorWidget::notifyFileSave() {
	emit fileSaved();
	m_lastSavedCommand = m_lastCommand;
}

void EditorWidget::undo() {
	if (m_undoStack->canUndo()) {
		m_undoStack->undo();
		m_lastCommand = m_undoStack->index();

		if (currentStateSaved()) {
			notifyFileSave();
		} else {
			notifyFileChange();
		}
	}
}

void EditorWidget::redo() {
	if (m_undoStack->canRedo()) {
		m_undoStack->redo();
		m_lastCommand = m_undoStack->index();

		if (currentStateSaved()) {
			notifyFileSave();
		} else {
			notifyFileChange();
		}
	}
}

bool EditorWidget::canUndo() {
	return m_undoStack->canUndo();
}

bool EditorWidget::canRedo() {
	return m_undoStack->canRedo();
}

const AppContext &EditorWidget::context() const {
	return m_context;
}

QString EditorWidget::absolutePath() {
	return m_path;
}

void EditorWidget::closeWidget() {
}

}
