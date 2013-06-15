#ifndef EDITORTAB_HPP
#define EDITORTAB_HPP

#include <vector>

#include "editortablistener.hpp"

class EditorTab {
	private:
		std::vector<EditorTabListener*> m_listeners;

	public:
		void addListener(EditorTabListener *l);
		void removeListener(EditorTabListener *l);
		virtual bool saveFile() = 0;

	protected:
		void notifyFileChange();
};

#endif
