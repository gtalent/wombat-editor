//Generated Code

#include <fstream>
#include "editormodels.hpp"

using namespace editormodels;
using namespace editormodels::cyborgbear;

bool Model::loadJsonFile(string path) {
	std::ifstream in;
	in.open(cyborgbear::toCString(path));
	std::string json;
	if (in.is_open()) {
		while (in.good()) {
			std::string s;
			in >> s;
			json += s;
		}
		in.close();
		fromJson(cyborgbear::toString(json));
		return true;
	}
	return false;
}

void Model::writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgbear::toCString(path));
	std::string json = cyborgbear::toStdString(toJson(sttngs));
	out << json << "\n";
	out.close();
}

void Model::fromJson(string json) {
	cyborgbear::JsonValOut obj = cyborgbear::read(cyborgbear::toCString(json));
	loadJsonObj(obj);
	cyborgbear::decref(obj);
}

string Model::toJson(cyborgbear::JsonSerializationSettings sttngs) {
	cyborgbear::JsonValOut val = buildJsonObj();
	cyborgbear::JsonObjOut obj = cyborgbear::toObj(val);
	return cyborgbear::write(obj, sttngs);
}

unknown::unknown() {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
}

unknown::unknown(Model *v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(bool v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(int v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(double v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(string v) {
#ifndef CYBORGBEAR_USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::~unknown() {
	cyborgbear::decref(m_obj);
}

bool unknown::loadJsonObj(cyborgbear::JsonVal obj) {
#ifdef CYBORGBEAR_USING_JANSSON
	m_obj = cyborgbear::incref(obj);
#else
	m_obj = obj;
#endif
	return !cyborgbear::isNull(obj);
}

cyborgbear::JsonValOut unknown::buildJsonObj() {
#ifdef CYBORGBEAR_USING_JANSSON
	return cyborgbear::incref(m_obj);
#else
	return m_obj;
#endif
}

bool unknown::loaded() {
	return !cyborgbear::isNull(m_obj);
}

bool unknown::isBool() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isBool(m_obj);
}

bool unknown::isInt() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isInt(m_obj);
}

bool unknown::isDouble() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isDouble(m_obj);
}

bool unknown::isString() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isString(m_obj);
}

bool unknown::isObject() {
	return !cyborgbear::isNull(m_obj) && cyborgbear::isObj(m_obj);
}

bool unknown::toBool() {
	return cyborgbear::toBool(m_obj);
}

int unknown::toInt() {
	return cyborgbear::toInt(m_obj);
}

double unknown::toDouble() {
	return cyborgbear::toDouble(m_obj);
}

string unknown::toString() {
	return cyborgbear::toString(m_obj);
}

void unknown::set(Model *v) {
	cyborgbear::JsonValOut obj = v->buildJsonObj();
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(bool v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(int v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(double v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}

void unknown::set(string v) {
	cyborgbear::JsonValOut obj = cyborgbear::toJsonVal(v);
	cyborgbear::JsonVal old = m_obj;
	m_obj = obj;
	if (!cyborgbear::isNull(old)) {
		cyborgbear::decref(old);
	}
}


#include "string.h"
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

bool Bounds::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->x = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->y = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->width = cyborgbear::toInt(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->height = cyborgbear::toInt(obj0);
			}
		}
	}
	return true;
}

bool DockSettings::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Docked");
		{
			if (cyborgbear::isBool(obj0)) {
				this->docked = cyborgbear::toBool(obj0);
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Undocked");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				this->undocked.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool EditorSettings::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DockBounds");
		if (!cyborgbear::isNull(obj0) && cyborgbear::isObj(obj0)) {
			cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
			for (cyborgbear::JsonObjIterator it1 = cyborgbear::iterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::iteratorNext(map0,  it1)) {
				string i;
				cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
				{
					std::string key = cyborgbear::toStdString(cyborgbear::iteratorKey(it1));
					std::string o;
					std::stringstream s;
					s << key;
					s >> o;
					i = o.c_str();
				}
				{
					cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
					if (cyborgbear::isObj(finalObj)) {
						this->dockBounds[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

cyborgbear::JsonValOut Bounds::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->x);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut DockSettings::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->docked);
		cyborgbear::objSet(obj, "Docked", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->undocked.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Undocked", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut EditorSettings::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (std::map< string, DockSettings >::iterator n = this->dockBounds.begin(); n != this->dockBounds.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n->first));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->dockBounds[n->first].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "DockBounds", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}
