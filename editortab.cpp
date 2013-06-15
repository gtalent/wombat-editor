
#include "editortab.hpp"

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

void EditorTab::notifyFileChange() {
	for (unsigned i = 0; i < m_listeners.size(); i++) {
		m_listeners[i]->fileChanged();
	}
}
