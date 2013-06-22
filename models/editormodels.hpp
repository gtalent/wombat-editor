//Generated Code
#ifndef EDITORMODELS_HPP
#define EDITORMODELS_HPP
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <jansson.h>
#include "modelmakerdefs.hpp"


using std::string;
using std::vector;
using std::map;

namespace editormodels {

class Bounds: public modelmaker::Model {

	public:

		Bounds();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int x;
		int y;
		int width;
		int height;
};

}


namespace editormodels {

class DockSettings: public modelmaker::Model {

	public:

		DockSettings();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		bool docked;
		Bounds undocked;
};

}


namespace editormodels {

class EditorSettings: public modelmaker::Model {

	public:

		EditorSettings();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, DockSettings > dockBounds;
};

}


namespace editormodels {

class SaveVariables: public modelmaker::Model {

	public:

		SaveVariables();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > vars;
};

}


#endif