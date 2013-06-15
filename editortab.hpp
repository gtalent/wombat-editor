#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <vector>

#include "editortablistener.hpp"

class EditorTab {
	private:
		std::vector<EditorTabListener*> m_listeners;
		bool m_hasUnsavedChanges;

	public:
		EditorTab();
		void updateListeners();
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		virtual bool saveFile() = 0;

	protected:
		void notifyFileChange();
		void notifyFileSave();
};

#endif
