//Generated Code

#include "editormodels.hpp"

using namespace editormodels;
using std::stringstream;

Bounds::Bounds() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

DockSettings::DockSettings() {
	this->docked = 0;
}

EditorSettings::EditorSettings() {
}

bool Bounds::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "X");
		{
			if (json_is_integer(obj0)) {
				this->x = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Y");
		{
			if (json_is_integer(obj0)) {
				this->y = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Width");
		{
			if (json_is_integer(obj0)) {
				this->width = (int) json_integer_value(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Height");
		{
			if (json_is_integer(obj0)) {
				this->height = (int) json_integer_value(obj0);
			}
		}
	}
	return true;
}

bool DockSettings::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "Docked");
		{
			if (json_is_boolean(obj0)) {
				this->docked = json_is_true(obj0);
			}
		}
	}
	{
		json_t *obj0 = json_object_get(in, "Undocked");
		{
			if (json_is_object(obj0)) {
				this->undocked.load_json_t(obj0);
			}
		}
	}
	return true;
}

bool EditorSettings::load_json_t(json_t *in) {
	{
		json_t *obj0 = json_object_get(in, "DockBounds");
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
				DockSettings val;
				this->dockBounds.insert(std::make_pair(i, val));
				{
					if (json_is_object(obj1)) {
						this->dockBounds[i].load_json_t(obj1);
					}
				}
			}
		}
	}
	return true;
}

json_t* Bounds::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_integer(this->x);
		json_object_set(obj, "X", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->y);
		json_object_set(obj, "Y", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->width);
		json_object_set(obj, "Width", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = json_integer(this->height);
		json_object_set(obj, "Height", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* DockSettings::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out0 = json_boolean(this->docked);
		json_object_set(obj, "Docked", out0);
		json_decref(out0);
	}
	{
		json_t *out0 = this->undocked.buildJsonObj();
		json_object_set(obj, "Undocked", out0);
		json_decref(out0);
	}
	return obj;
}

json_t* EditorSettings::buildJsonObj() {
	json_t *obj = json_object();
	{
		json_t *out1 = json_object();
		for (map< string, DockSettings >::iterator n = this->dockBounds.begin(); n != this->dockBounds.end(); ++n) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_t *out0 = this->dockBounds[n->first].buildJsonObj();
			json_object_set(out1, key.c_str(), out0);
			json_decref(out0);
		}
		json_object_set(obj, "DockBounds", out1);
		json_decref(out1);
	}
	return obj;
}
