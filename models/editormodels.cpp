//Generated Code

#include "editormodels.hpp"

using namespace editormodels;
using std::stringstream;

SaveVariables::SaveVariables() {
}

EditorSettings::EditorSettings() {
}

bool SaveVariables::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Vars");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_object) {
				json_object_object_foreach(obj0, key, obj1) {
					string i;
					{
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						this->vars[i].load(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool EditorSettings::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Settings");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_object) {
				json_object_object_foreach(obj0, key, obj1) {
					string i;
					{
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						this->settings[i].load(obj1);
					}
				}
			}
		}
	}
	return true;
}

json_object* SaveVariables::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_object();
		for (map<string, modelmaker::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = this->vars[n->first].buildJsonObj();
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Vars", out1);
	}
	return obj;
}

json_object* EditorSettings::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_object();
		for (map<string, modelmaker::unknown >::iterator n = this->settings.begin(); n != this->settings.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = this->settings[n->first].buildJsonObj();
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Settings", out1);
	}
	return obj;
}
