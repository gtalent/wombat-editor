//Generated Code



#include <fstream>
#include "editormodels.hpp"

using namespace editormodels;
using namespace editormodels::modelmaker;

bool Model::loadFile(string path) {
	std::ifstream in;
	in.open(modelmaker::toCString(path));
	std::string json;
	if (in.is_open()) {
		while (in.good()) {
			std::string s;
			in >> s;
			json += s;
		}
		in.close();
		load(modelmaker::toString(json));
		return true;
	}
	return false;
}

void Model::writeFile(string path) {
	std::ofstream out;
	out.open(modelmaker::toCString(path));
	std::string json = modelmaker::toStdString(write());
	out << json << "\n";
	out.close();
}

void Model::load(string json) {
	modelmaker::JsonValOut obj = modelmaker::read(modelmaker::toCString(json));
	loadJsonObj(obj);
	modelmaker::decref(obj);
}

string Model::write() {
	modelmaker::JsonValOut val = buildJsonObj();
	modelmaker::JsonObjOut obj = modelmaker::toObj(val);
	return modelmaker::write(obj);
}

unknown::unknown() {
#ifndef USING_QT
	m_obj = 0;
#endif
}

unknown::unknown(Model *v) {
#ifndef USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(bool v) {
#ifndef USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(int v) {
#ifndef USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(double v) {
#ifndef USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::unknown(string v) {
#ifndef USING_QT
	m_obj = 0;
#endif
	set(v);
}

unknown::~unknown() {
	modelmaker::decref(m_obj);
}

bool unknown::loadJsonObj(modelmaker::JsonVal obj) {
#ifdef USING_JANSSON
	m_obj = modelmaker::incref(obj);
#else
	m_obj = obj;
#endif
	return !modelmaker::isNull(obj);
}

modelmaker::JsonValOut unknown::buildJsonObj() {
#ifdef USING_JANSSON
	return modelmaker::incref(m_obj);
#else
	return m_obj;
#endif
}

bool unknown::loaded() {
	return !modelmaker::isNull(m_obj);
}

bool unknown::isBool() {
	return !modelmaker::isNull(m_obj) && modelmaker::isBool(m_obj);
}

bool unknown::isInt() {
	return !modelmaker::isNull(m_obj) && modelmaker::isInt(m_obj);
}

bool unknown::isDouble() {
	return !modelmaker::isNull(m_obj) && modelmaker::isDouble(m_obj);
}

bool unknown::isString() {
	return !modelmaker::isNull(m_obj) && modelmaker::isString(m_obj);
}

bool unknown::isObject() {
	return !modelmaker::isNull(m_obj) && modelmaker::isObj(m_obj);
}

bool unknown::toBool() {
	return modelmaker::toBool(m_obj);
}

int unknown::toInt() {
	return modelmaker::toInt(m_obj);
}

double unknown::toDouble() {
	return modelmaker::toDouble(m_obj);
}

string unknown::toString() {
	return modelmaker::toString(m_obj);
}

void unknown::set(Model *v) {
	modelmaker::JsonValOut obj = v->buildJsonObj();
	modelmaker::JsonVal old = m_obj;
	m_obj = obj;
	if (!modelmaker::isNull(old)) {
		modelmaker::decref(old);
	}
}

void unknown::set(bool v) {
	modelmaker::JsonValOut obj = modelmaker::toJsonVal(v);
	modelmaker::JsonVal old = m_obj;
	m_obj = obj;
	if (!modelmaker::isNull(old)) {
		modelmaker::decref(old);
	}
}

void unknown::set(int v) {
	modelmaker::JsonValOut obj = modelmaker::toJsonVal(v);
	modelmaker::JsonVal old = m_obj;
	m_obj = obj;
	if (!modelmaker::isNull(old)) {
		modelmaker::decref(old);
	}
}

void unknown::set(double v) {
	modelmaker::JsonValOut obj = modelmaker::toJsonVal(v);
	modelmaker::JsonVal old = m_obj;
	m_obj = obj;
	if (!modelmaker::isNull(old)) {
		modelmaker::decref(old);
	}
}

void unknown::set(string v) {
	modelmaker::JsonValOut obj = modelmaker::toJsonVal(v);
	modelmaker::JsonVal old = m_obj;
	m_obj = obj;
	if (!modelmaker::isNull(old)) {
		modelmaker::decref(old);
	}
}


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

bool Bounds::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "X");
		{
			if (modelmaker::isInt(obj0)) {
				this->x = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Y");
		{
			if (modelmaker::isInt(obj0)) {
				this->y = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Width");
		{
			if (modelmaker::isInt(obj0)) {
				this->width = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Height");
		{
			if (modelmaker::isInt(obj0)) {
				this->height = modelmaker::toInt(obj0);
			}
		}
	}
	return true;
}

bool DockSettings::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Docked");
		{
			if (modelmaker::isBool(obj0)) {
				this->docked = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Undocked");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->undocked.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool EditorSettings::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "DockBounds");
		if (!modelmaker::isNull(obj0) && modelmaker::isObj(obj0)) {
			modelmaker::JsonObjOut map0 = modelmaker::toObj(obj0);
			for (modelmaker::JsonObjIterator it1 = modelmaker::iterator(map0); !modelmaker::iteratorAtEnd(it1, map0); it1 = modelmaker::iteratorNext(map0,  it1)) {
				string i;
				modelmaker::JsonValOut obj1 = modelmaker::iteratorValue(it1);
				{
					std::string key = modelmaker::toStdString(modelmaker::iteratorKey(it1));
					std::string o;
					std::stringstream s;
					s << key;
					s >> o;
					i = o.c_str();
				}
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->dockBounds[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

modelmaker::JsonValOut Bounds::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->x);
		modelmaker::objSet(obj, "X", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->y);
		modelmaker::objSet(obj, "Y", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->width);
		modelmaker::objSet(obj, "Width", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->height);
		modelmaker::objSet(obj, "Height", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut DockSettings::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->docked);
		modelmaker::objSet(obj, "Docked", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->undocked.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Undocked", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut EditorSettings::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, DockSettings >::iterator n = this->dockBounds.begin(); n != this->dockBounds.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut obj0 = this->dockBounds[n->first].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "DockBounds", out1);
		modelmaker::decref(out1);
	}
	return obj;
}
