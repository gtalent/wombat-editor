#include "editortab.hpp"

EditorTab::EditorTab(QWidget *parent, std::string path): QWidget(parent) {
	m_hasUnsavedChanges = false;
	m_undoStack = new QUndoStack(parent);
	m_lastCommand = m_lastSavedCommand = (QUndoCommand*) this;
	m_path = path;
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
	if (uc) {
		m_undoStack->push(uc);
		m_lastCommand = m_undoStack->command(m_undoStack->index());
	}
	for (unsigned i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileChanged();
	}
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
			m_lastCommand = m_undoStack->command(m_undoStack->index());
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
		m_lastCommand = m_undoStack->command(m_undoStack->index());

		if (m_lastSavedCommand == m_lastCommand)
			notifyFileSave();
		else
			notifyFileChange();
	}
}

bool EditorTab::canUndo() {
	return (void*) m_lastCommand != (void*) this;
}

bool EditorTab::canRedo() {
	return (void*) m_lastCommand != (void*) 0;
}

std::string EditorTab::path() {
	return m_path;
}

void EditorTab::closeTab() {
}
