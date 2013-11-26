#include "editortab.hpp"

EditorTab::EditorTab(QWidget *parent, QString path): QWidget(parent) {
	m_undoStack = new QUndoStack(parent);
	m_lastCommand = m_lastSavedCommand = 0;
	m_path = path;
}

EditorTab::~EditorTab() {
	delete m_undoStack;
}

void EditorTab::addListener(EditorTabListener *l) {
	m_listeners.push_back(l);
}

void EditorTab::removeListener(EditorTabListener *l) {
	for (int i = 0; i < m_listeners.size(); i++) {
		if (m_listeners[i] == l) {
			m_listeners.erase(m_listeners.begin() + i);
			break;
		}
	}
}

bool EditorTab::currentStateSaved() {
	return m_lastSavedCommand == m_lastCommand;
}

void EditorTab::notifyFileChange(QUndoCommand *uc) {
	if (uc) {
		m_undoStack->push(uc);
		m_lastCommand = m_undoStack->index();
	}
	for (int i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileChanged();
	}
}

void EditorTab::notifyFileSave() {
	for (int i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileSaved();
	}
	m_lastSavedCommand = m_lastCommand;
}

void EditorTab::undo() {
	if (m_undoStack->canUndo()) {
		m_undoStack->undo();
		m_lastCommand = m_undoStack->index();

		if (currentStateSaved())
			notifyFileSave();
		else
			notifyFileChange();
	}
}

void EditorTab::redo() {
	if (m_undoStack->canRedo()) {
		m_undoStack->redo();
		m_lastCommand = m_undoStack->index();

		if (currentStateSaved())
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

QString EditorTab::path() {
	return m_path;
}

void EditorTab::closeTab() {
}
