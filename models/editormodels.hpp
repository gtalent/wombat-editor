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

class SaveVariables: public modelmaker::Model {

	public:

		SaveVariables();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > vars;
};

}


namespace editormodels {

class EditorSettings: public modelmaker::Model {

	public:

		EditorSettings();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > settings;
};

}


#endif