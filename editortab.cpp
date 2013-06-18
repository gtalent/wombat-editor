#include "editortab.hpp"

using namespace std;

EditorTab::EditorTab(QWidget *win) {
	m_hasUnsavedChanges = false;
	m_undoStack = new QUndoStack(win);
	m_lastCommand = m_lastSavedCommand = (QUndoCommand*) this;
}

EditorTab::~EditorTab() {
	delete m_undoStack;
}

void EditorTab::addListener(EditorTabListener *l) {
	m_listeners.push_back(l);
}

void EditorTab::removeListener(EditorTabListener *l) {
	for (unsigned i = 0; i < m_listeners.size(); i++) {
		if (m_listeners[i] == l) {
			m_listeners.erase(m_listeners.begin() + i);
			break;
		}
	}
}

void EditorTab::updateListeners() {
	if (m_hasUnsavedChanges) {
		notifyFileChange();
	} else {
		notifyFileSave();
	}
}

void EditorTab::notifyFileChange(QUndoCommand *uc) {
	for (unsigned i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileChanged();
	}
	if (uc)
		m_undoStack->push(uc);
	m_lastCommand = m_undoStack->command(m_undoStack->index());
}

void EditorTab::notifyFileSave() {
	for (unsigned i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileSaved();
	}
	m_lastSavedCommand = m_lastCommand;
}

void EditorTab::undo() {
	if (m_undoStack->canUndo()) {
		m_undoStack->undo();
		if (m_undoStack->canUndo()) {
			m_lastCommand = m_undoStack->command(m_undoStack->index() - 1);
		} else {
			//this is being used to signify the bottom of the stack
			m_lastCommand = (QUndoCommand*) this;
		}

		if (m_lastSavedCommand == m_lastCommand)
			notifyFileSave();
		else
			notifyFileChange();
	}
}

void EditorTab::redo() {
	if (m_undoStack->canRedo()) {
		m_undoStack->redo();
		m_lastCommand = m_undoStack->command(m_undoStack->index() - 1);

		if (m_lastSavedCommand == m_lastCommand)
			notifyFileSave();
		else
			notifyFileChange();
	}
}

bool EditorTab::canUndo() {
	return m_undoStack->canUndo();
}

bool EditorTab::canRedo() {
	return m_undoStack->canRedo();
}
