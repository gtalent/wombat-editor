//Generated Code

#include <fstream>
#include "modelmakerdefs.hpp"

using namespace modelmaker;

bool Model::loadFile(string path) {
	std::ifstream in;
	in.open(path.c_str());
	string json;
	if (in.is_open()) {
		while (in.good()) {
			string s;
			in >> s;
			json += s;
		}
		in.close();
		load(json);
		return true;
	}
	return false;
}

void Model::writeFile(string path) {
	std::ofstream out;
	out.open(path.c_str());
	string json = write();
	out << json << "\n";
	out.close();
}

void Model::load(string json) {
	json_object *obj = json_tokener_parse(json.c_str());
	load(obj);
	json_object_put(obj);
}

string Model::write() {
	json_object *obj = buildJsonObj();
	string out = json_object_to_json_string(obj);
	json_object_put(obj);
	return out;
}

unknown::unknown() {
	m_obj = 0;
}

unknown::~unknown() {
	json_object_put(m_obj);
}

bool unknown::load(json_object *obj) {
	//clone the input object because it will get deleted with its parent
	m_obj = json_tokener_parse(json_object_to_json_string(obj));
	return true;
}

json_object* unknown::buildJsonObj() {
	return json_tokener_parse(json_object_to_json_string(m_obj));
}

bool unknown::loaded() {
	return m_obj;
}

bool unknown::isBool() {
	return m_obj && json_object_get_type(m_obj) == json_type_boolean;
}

bool unknown::isInt() {
	return m_obj && json_object_get_type(m_obj) == json_type_int;
}

bool unknown::isDouble() {
	return m_obj && json_object_get_type(m_obj) == json_type_double;
}

bool unknown::isString() {
	return m_obj && json_object_get_type(m_obj) == json_type_string;
}

bool unknown::isObject() {
	return m_obj && json_object_get_type(m_obj) == json_type_object;
}

bool unknown::toBool() {
	return json_object_get_boolean(m_obj);
}

int unknown::toInt() {
	return json_object_get_int(m_obj);
}

double unknown::toDouble() {
	return json_object_get_double(m_obj);
}

string unknown::toString() {
	return json_object_get_string(m_obj);
}

void unknown::set(Model *v) {
	json_object *obj = v->buildJsonObj();
	json_object *old = m_obj;
	m_obj = obj;
	if (old)
		json_object_put(old);
}

void unknown::set(bool v) {
	json_object *obj = json_object_new_boolean(v);
	json_object *old = m_obj;
	m_obj = obj;
	if (old)
		json_object_put(old);
}

void unknown::set(int v) {
	json_object *obj = json_object_new_int(v);
	json_object *old = m_obj;
	m_obj = obj;
	if (old)
		json_object_put(old);
}

void unknown::set(double v) {
	json_object *obj = json_object_new_double(v);
	json_object *old = m_obj;
	m_obj = obj;
	if (old)
		json_object_put(old);
}

void unknown::set(string v) {
	json_object *obj = json_object_new_string(v.c_str());
	json_object *old = m_obj;
	m_obj = obj;
	if (old)
		json_object_put(old);
}
