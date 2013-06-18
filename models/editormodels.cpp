//Generated Code

#include "editormodels.hpp"

using namespace editormodels;
using std::stringstream;

SaveVariables::SaveVariables() {
}

EditorSettings::EditorSettings() {
}

bool SaveVariables::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Vars");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				modelmaker::unknown val;
				this->vars.insert(make_pair(i, val));
				{
					this->vars[i].load_json_t(obj1);
				}
			}
		}
	}
	return true;
}

bool EditorSettings::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Settings");
		if (obj0 != NULL && json_typeof(obj0) == JSON_OBJECT) {
			const char *key;
			json_t *obj1;
			json_object_foreach(obj0, key, obj1) {
				string i;
				{
					std::stringstream s;
					s << key;
					s >> i;
				}
				modelmaker::unknown val;
				this->settings.insert(make_pair(i, val));
				{
					this->settings[i].load_json_t(obj1);
				}
			}
		}
	}
	return true;
}

json_t* SaveVariables::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, modelmaker::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = this->vars[n->first].buildJsonObj();
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Vars", out1);
		json_decref(out1);
	}
	return obj;
}

json_t* EditorSettings::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, modelmaker::unknown >::iterator n = this->settings.begin(); n != this->settings.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = this->settings[n->first].buildJsonObj();
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "Settings", out1);
		json_decref(out1);
	}
	return obj;
}
