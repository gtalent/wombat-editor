//Generated Code
#ifndef EDITORMODELS_HPP
#define EDITORMODELS_HPP
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <json/json.h>
#include "modelmakerdefs.hpp"


using std::string;
using std::vector;
using std::map;

namespace editormodels {

class SaveVariables: public modelmaker::Model {

	public:

		SaveVariables();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, modelmaker::unknown > vars;
};

}


namespace editormodels {

class EditorSettings: public modelmaker::Model {

	public:

		EditorSettings();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, modelmaker::unknown > settings;
};

}


#endif