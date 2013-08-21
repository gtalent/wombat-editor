//Generated Code



#include <fstream>
#include "enginemodels.hpp"

using namespace enginemodels;
using namespace enginemodels::modelmaker;

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


#include "enginemodels.hpp"

using namespace enginemodels;
using std::stringstream;

CreatureType::CreatureType() {
	this->special = 0;
}

StatusEffect::StatusEffect() {
	this->attackerEffect = 0;
	this->enemyEffect = 0;
}

Fraction::Fraction() {
	this->current = 0;
	this->available = 0;
}

ModelFile::ModelFile() {
	this->type = "";
}

Point::Point() {
	this->x = 0;
	this->y = 0;
}

Size::Size() {
	this->width = 0;
	this->height = 0;
}

Bounds::Bounds() {
	this->x = 0;
	this->y = 0;
	this->width = 0;
	this->height = 0;
}

SaveVariables::SaveVariables() {
}

SpriteSheet::SpriteSheet() {
	this->tilesWide = 0;
	this->tilesHigh = 0;
	this->tileWidth = 0;
	this->tileHeight = 0;
	this->src = "";
}

CreatureMove::CreatureMove() {
	this->type = "";
	this->power = 0;
	this->requiresRegarge = 0;
	this->script = "";
}

CreatureMoveInstance::CreatureMoveInstance() {
	this->creatureMove = 0;
}

Creature::Creature() {
	this->iD = 0;
	this->creatureClass = "";
	this->male = 0;
	this->level = 0;
	this->attack = 0;
	this->specAttack = 0;
	this->defense = 0;
	this->specDefense = 0;
	this->burned = 0;
	this->frozen = 0;
	this->poisoned = 0;
	this->asleep = 0;
}

User::User() {
	this->personID = 0;
	this->world = "";
	this->zone = "";
	this->xAddress = 0;
	this->yAddress = 0;
	this->layer = 0;
}

ZoneInstance::ZoneInstance() {
	this->accessorID = "";
	this->path = "";
}

Image::Image() {
	this->imgId = 0;
}

ImageSrc::ImageSrc() {
	this->srcFile = "";
}

ImageMap::ImageMap() {
}

Animation::Animation() {
	this->interval = 0;
}

AnimLayer::AnimLayer() {
}

SaveFile::SaveFile() {
}

CreatureClass::CreatureClass() {
	this->successor = "";
	this->predecessor = "";
}

Sprite::Sprite() {
	this->spriteType = 0;
	this->personID = 0;
	this->speed = 0;
	this->name = "";
	this->path = "";
	this->scriptPath = "";
}

TileClass::TileClass() {
	this->terrainFlags = 0;
	this->import = "";
}

ZoneHeader::ZoneHeader() {
	this->path = "";
}

PersonClass::PersonClass() {
	this->iD = 0;
}

Person::Person() {
}

Tile::Tile() {
}

World::World() {
}

Zone::Zone() {
}

bool CreatureType::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
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
					if (modelmaker::isString(obj1)) {
						this->name[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Special");
		{
			if (modelmaker::isBool(obj0)) {
				this->special = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "StrongAgainst");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->strongAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isString(obj1)) {
						this->strongAgainst[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "WeakAgainst");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->weakAgainst.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isString(obj1)) {
						this->weakAgainst[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool StatusEffect::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "AttackerEffect");
		{
			if (modelmaker::isInt(obj0)) {
				this->attackerEffect = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "EnemyEffect");
		{
			if (modelmaker::isInt(obj0)) {
				this->enemyEffect = modelmaker::toInt(obj0);
			}
		}
	}
	return true;
}

bool Fraction::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Current");
		{
			if (modelmaker::isInt(obj0)) {
				this->current = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Available");
		{
			if (modelmaker::isInt(obj0)) {
				this->available = modelmaker::toInt(obj0);
			}
		}
	}
	return true;
}

bool ModelFile::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Type");
		{
			if (modelmaker::isString(obj0)) {
				this->type = modelmaker::toString(obj0);
			}
		}
	}
	return true;
}

bool Point::loadJsonObj(modelmaker::JsonVal in) {
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
	return true;
}

bool Size::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
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

bool SaveVariables::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Vars");
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
					this->vars[i].loadJsonObj(obj1);
				}
			}
		}
	}
	return true;
}

bool SpriteSheet::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TilesWide");
		{
			if (modelmaker::isInt(obj0)) {
				this->tilesWide = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TilesHigh");
		{
			if (modelmaker::isInt(obj0)) {
				this->tilesHigh = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TileWidth");
		{
			if (modelmaker::isInt(obj0)) {
				this->tileWidth = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TileHeight");
		{
			if (modelmaker::isInt(obj0)) {
				this->tileHeight = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Src");
		{
			if (modelmaker::isString(obj0)) {
				this->src = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Images");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->images.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->images[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool CreatureMove::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
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
					if (modelmaker::isString(obj1)) {
						this->name[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Type");
		{
			if (modelmaker::isString(obj0)) {
				this->type = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Power");
		{
			if (modelmaker::isInt(obj0)) {
				this->power = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "RequiresRegarge");
		{
			if (modelmaker::isBool(obj0)) {
				this->requiresRegarge = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Script");
		{
			if (modelmaker::isString(obj0)) {
				this->script = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Burn");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->burn.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Freeze");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->freeze.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Paralyze");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->paralyze.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Poison");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->poison.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Sleep");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->sleep.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool CreatureMoveInstance::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "CreatureMove");
		{
			if (modelmaker::isInt(obj0)) {
				this->creatureMove = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "PP");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->pP.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Creature::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "ID");
		{
			if (modelmaker::isInt(obj0)) {
				this->iD = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
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
					if (modelmaker::isString(obj1)) {
						this->name[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "CreatureClass");
		{
			if (modelmaker::isString(obj0)) {
				this->creatureClass = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Male");
		{
			if (modelmaker::isBool(obj0)) {
				this->male = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Level");
		{
			if (modelmaker::isInt(obj0)) {
				this->level = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Health");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->health.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Attack");
		{
			if (modelmaker::isInt(obj0)) {
				this->attack = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "SpecAttack");
		{
			if (modelmaker::isInt(obj0)) {
				this->specAttack = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Defense");
		{
			if (modelmaker::isInt(obj0)) {
				this->defense = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "SpecDefense");
		{
			if (modelmaker::isInt(obj0)) {
				this->specDefense = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Burned");
		{
			if (modelmaker::isBool(obj0)) {
				this->burned = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Frozen");
		{
			if (modelmaker::isBool(obj0)) {
				this->frozen = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Poisoned");
		{
			if (modelmaker::isBool(obj0)) {
				this->poisoned = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Asleep");
		{
			if (modelmaker::isBool(obj0)) {
				this->asleep = modelmaker::toBool(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Moves");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->moves.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->moves[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool User::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "PersonID");
		{
			if (modelmaker::isInt(obj0)) {
				this->personID = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "World");
		{
			if (modelmaker::isString(obj0)) {
				this->world = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Zone");
		{
			if (modelmaker::isString(obj0)) {
				this->zone = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "XAddress");
		{
			if (modelmaker::isInt(obj0)) {
				this->xAddress = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "YAddress");
		{
			if (modelmaker::isInt(obj0)) {
				this->yAddress = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Layer");
		{
			if (modelmaker::isInt(obj0)) {
				this->layer = modelmaker::toInt(obj0);
			}
		}
	}
	return true;
}

bool ZoneInstance::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "AccessorID");
		{
			if (modelmaker::isString(obj0)) {
				this->accessorID = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Path");
		{
			if (modelmaker::isString(obj0)) {
				this->path = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Location");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->location.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Image::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "ImgId");
		{
			if (modelmaker::isInt(obj0)) {
				this->imgId = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "DefaultSize");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->defaultSize.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool ImageSrc::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "SrcFile");
		{
			if (modelmaker::isString(obj0)) {
				this->srcFile = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Bounds");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->bounds.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool ImageMap::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Images");
		if (!modelmaker::isNull(obj0) && modelmaker::isObj(obj0)) {
			modelmaker::JsonObjOut map0 = modelmaker::toObj(obj0);
			for (modelmaker::JsonObjIterator it1 = modelmaker::iterator(map0); !modelmaker::iteratorAtEnd(it1, map0); it1 = modelmaker::iteratorNext(map0,  it1)) {
				int i;
				modelmaker::JsonValOut obj1 = modelmaker::iteratorValue(it1);
				{
					std::string key = modelmaker::toStdString(modelmaker::iteratorKey(it1));
					std::stringstream s;
					s << key;
					s >> i;
				}
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->images[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool Animation::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Interval");
		{
			if (modelmaker::isInt(obj0)) {
				this->interval = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Images");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->images.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->images[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool AnimLayer::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Point");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->point.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Animation");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->animation.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool SaveFile::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Vars");
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
					this->vars[i].loadJsonObj(obj1);
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "User");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->user.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool CreatureClass::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
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
					if (modelmaker::isString(obj1)) {
						this->name[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Successor");
		{
			if (modelmaker::isString(obj0)) {
				this->successor = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Predecessor");
		{
			if (modelmaker::isString(obj0)) {
				this->predecessor = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Types");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->types.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isString(obj1)) {
						this->types[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "CanLearn");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->canLearn.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isString(obj1)) {
						this->canLearn[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "LearnsAtLevel");
		if (!modelmaker::isNull(obj0) && modelmaker::isObj(obj0)) {
			modelmaker::JsonObjOut map0 = modelmaker::toObj(obj0);
			for (modelmaker::JsonObjIterator it1 = modelmaker::iterator(map0); !modelmaker::iteratorAtEnd(it1, map0); it1 = modelmaker::iteratorNext(map0,  it1)) {
				int i;
				modelmaker::JsonValOut obj1 = modelmaker::iteratorValue(it1);
				{
					std::string key = modelmaker::toStdString(modelmaker::iteratorKey(it1));
					std::stringstream s;
					s << key;
					s >> i;
				}
				{
					if (modelmaker::isString(obj1)) {
						this->learnsAtLevel[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "FrontView");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->frontView.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "BackView");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->backView.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Sprite::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "AnimLayers");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->animLayers.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				if (!modelmaker::isNull(obj1) && modelmaker::isArray(obj1)) {
					modelmaker::JsonArrayOut array1 = modelmaker::toArray(obj1);
					unsigned int size = modelmaker::arraySize(array1);
					this->animLayers[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						modelmaker::JsonValOut obj2 = modelmaker::arrayRead(array1, ii);
						{
							modelmaker::JsonValOut finalObj = modelmaker::toObj(obj2);
							if (modelmaker::isObj(finalObj)) {
								this->animLayers[i][ii].loadJsonObj(obj2);
							}
						}
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "SpriteType");
		{
			if (modelmaker::isInt(obj0)) {
				this->spriteType = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "PersonID");
		{
			if (modelmaker::isInt(obj0)) {
				this->personID = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Speed");
		{
			if (modelmaker::isInt(obj0)) {
				this->speed = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
		{
			if (modelmaker::isString(obj0)) {
				this->name = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Path");
		{
			if (modelmaker::isString(obj0)) {
				this->path = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "ScriptPath");
		{
			if (modelmaker::isString(obj0)) {
				this->scriptPath = modelmaker::toString(obj0);
			}
		}
	}
	return true;
}

bool TileClass::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TerrainFlags");
		{
			if (modelmaker::isInt(obj0)) {
				this->terrainFlags = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Import");
		{
			if (modelmaker::isString(obj0)) {
				this->import = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "LowerAnims");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->lowerAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->lowerAnims[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "UpperAnims");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->upperAnims.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->upperAnims[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool ZoneHeader::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Path");
		{
			if (modelmaker::isString(obj0)) {
				this->path = modelmaker::toString(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Size");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->size.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool PersonClass::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "ID");
		{
			if (modelmaker::isInt(obj0)) {
				this->iD = modelmaker::toInt(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Name");
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
					if (modelmaker::isString(obj1)) {
						this->name[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Creatures");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->creatures.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isInt(obj1)) {
						this->creatures[i] = modelmaker::toInt(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Overhead");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->overhead.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->overhead[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "FrontView");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->frontView.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "BackView");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->backView.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Person::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "PersonClass");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->personClass.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool Tile::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "TileClass");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->tileClass.loadJsonObj(obj0);
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Occupant");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->occupant.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

bool World::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Zones");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->zones.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					modelmaker::JsonValOut finalObj = modelmaker::toObj(obj1);
					if (modelmaker::isObj(finalObj)) {
						this->zones[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return true;
}

bool Zone::loadJsonObj(modelmaker::JsonVal in) {
	modelmaker::JsonObjOut inObj = modelmaker::toObj(in);
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Tiles");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->tiles.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				if (!modelmaker::isNull(obj1) && modelmaker::isArray(obj1)) {
					modelmaker::JsonArrayOut array1 = modelmaker::toArray(obj1);
					unsigned int size = modelmaker::arraySize(array1);
					this->tiles[i].resize(size);
					for (unsigned int ii = 0; ii < size; ii++) {
						modelmaker::JsonValOut obj2 = modelmaker::arrayRead(array1, ii);
						if (!modelmaker::isNull(obj2) && modelmaker::isArray(obj2)) {
							modelmaker::JsonArrayOut array2 = modelmaker::toArray(obj2);
							unsigned int size = modelmaker::arraySize(array2);
							this->tiles[i][ii].resize(size);
							for (unsigned int iii = 0; iii < size; iii++) {
								modelmaker::JsonValOut obj3 = modelmaker::arrayRead(array2, iii);
								{
									modelmaker::JsonValOut finalObj = modelmaker::toObj(obj3);
									if (modelmaker::isObj(finalObj)) {
										this->tiles[i][ii][iii].loadJsonObj(obj3);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "InitScripts");
		if (!modelmaker::isNull(obj0) && modelmaker::isArray(obj0)) {
			modelmaker::JsonArrayOut array0 = modelmaker::toArray(obj0);
			unsigned int size = modelmaker::arraySize(array0);
			this->initScripts.resize(size);
			for (unsigned int i = 0; i < size; i++) {
				modelmaker::JsonValOut obj1 = modelmaker::arrayRead(array0, i);
				{
					if (modelmaker::isString(obj1)) {
						this->initScripts[i] = modelmaker::toString(obj1);
					}
				}
			}
		}
	}
	{
		modelmaker::JsonValOut obj0 = modelmaker::objRead(inObj, "Location");
		{
			modelmaker::JsonValOut finalObj = modelmaker::toObj(obj0);
			if (modelmaker::isObj(finalObj)) {
				this->location.loadJsonObj(obj0);
			}
		}
	}
	return true;
}

modelmaker::JsonValOut CreatureType::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Name", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->special);
		modelmaker::objSet(obj, "Special", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->strongAgainst.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->strongAgainst[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "StrongAgainst", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->weakAgainst.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->weakAgainst[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "WeakAgainst", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut StatusEffect::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->attackerEffect);
		modelmaker::objSet(obj, "AttackerEffect", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->enemyEffect);
		modelmaker::objSet(obj, "EnemyEffect", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Fraction::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->current);
		modelmaker::objSet(obj, "Current", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->available);
		modelmaker::objSet(obj, "Available", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut ModelFile::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->type);
		modelmaker::objSet(obj, "Type", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Point::buildJsonObj() {
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
	return obj;
}

modelmaker::JsonValOut Size::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
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

modelmaker::JsonValOut SaveVariables::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, modelmaker::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut obj0 = this->vars[n->first].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Vars", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut SpriteSheet::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->tilesWide);
		modelmaker::objSet(obj, "TilesWide", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->tilesHigh);
		modelmaker::objSet(obj, "TilesHigh", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->tileWidth);
		modelmaker::objSet(obj, "TileWidth", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->tileHeight);
		modelmaker::objSet(obj, "TileHeight", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->src);
		modelmaker::objSet(obj, "Src", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->images.size(); i++) {
			modelmaker::JsonValOut obj0 = this->images[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Images", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut CreatureMove::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Name", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->type);
		modelmaker::objSet(obj, "Type", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->power);
		modelmaker::objSet(obj, "Power", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->requiresRegarge);
		modelmaker::objSet(obj, "RequiresRegarge", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->script);
		modelmaker::objSet(obj, "Script", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->burn.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Burn", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->freeze.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Freeze", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->paralyze.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Paralyze", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->poison.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Poison", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->sleep.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Sleep", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut CreatureMoveInstance::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->creatureMove);
		modelmaker::objSet(obj, "CreatureMove", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->pP.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "PP", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Creature::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->iD);
		modelmaker::objSet(obj, "ID", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Name", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->creatureClass);
		modelmaker::objSet(obj, "CreatureClass", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->male);
		modelmaker::objSet(obj, "Male", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->level);
		modelmaker::objSet(obj, "Level", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->health.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Health", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->attack);
		modelmaker::objSet(obj, "Attack", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->specAttack);
		modelmaker::objSet(obj, "SpecAttack", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->defense);
		modelmaker::objSet(obj, "Defense", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->specDefense);
		modelmaker::objSet(obj, "SpecDefense", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->burned);
		modelmaker::objSet(obj, "Burned", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->frozen);
		modelmaker::objSet(obj, "Frozen", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->poisoned);
		modelmaker::objSet(obj, "Poisoned", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->asleep);
		modelmaker::objSet(obj, "Asleep", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->moves.size(); i++) {
			modelmaker::JsonValOut obj0 = this->moves[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Moves", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut User::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->personID);
		modelmaker::objSet(obj, "PersonID", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->world);
		modelmaker::objSet(obj, "World", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->zone);
		modelmaker::objSet(obj, "Zone", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->xAddress);
		modelmaker::objSet(obj, "XAddress", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->yAddress);
		modelmaker::objSet(obj, "YAddress", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->layer);
		modelmaker::objSet(obj, "Layer", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut ZoneInstance::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->accessorID);
		modelmaker::objSet(obj, "AccessorID", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->path);
		modelmaker::objSet(obj, "Path", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->location.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Location", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Image::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->imgId);
		modelmaker::objSet(obj, "ImgId", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->defaultSize.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "DefaultSize", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut ImageSrc::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->srcFile);
		modelmaker::objSet(obj, "SrcFile", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->bounds.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Bounds", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut ImageMap::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< int, ImageSrc >::iterator n = this->images.begin(); n != this->images.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut obj0 = this->images[n->first].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Images", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut Animation::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->interval);
		modelmaker::objSet(obj, "Interval", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->images.size(); i++) {
			modelmaker::JsonValOut obj0 = this->images[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Images", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut AnimLayer::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut obj0 = this->point.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Point", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->animation.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Animation", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut SaveFile::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, modelmaker::unknown >::iterator n = this->vars.begin(); n != this->vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut obj0 = this->vars[n->first].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Vars", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut obj0 = this->user.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "User", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut CreatureClass::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Name", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->successor);
		modelmaker::objSet(obj, "Successor", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->predecessor);
		modelmaker::objSet(obj, "Predecessor", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->types.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->types[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Types", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->canLearn.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->canLearn[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "CanLearn", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< int, string >::iterator n = this->learnsAtLevel.begin(); n != this->learnsAtLevel.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n->first;
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->learnsAtLevel[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "LearnsAtLevel", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut obj0 = this->frontView.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "FrontView", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->backView.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "BackView", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Sprite::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonArrayOut out2 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->animLayers.size(); i++) {
			modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
			for (unsigned int ii = 0; ii < this->animLayers[i].size(); ii++) {
				modelmaker::JsonValOut obj0 = this->animLayers[i][ii].buildJsonObj();
				modelmaker::JsonValOut out0 = obj0;
				modelmaker::arrayAdd(out1, out0);
				modelmaker::decref(out0);
			}
			modelmaker::arrayAdd(out2, out1);
			modelmaker::decref(out1);
		}
		modelmaker::objSet(obj, "AnimLayers", out2);
		modelmaker::decref(out2);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->spriteType);
		modelmaker::objSet(obj, "SpriteType", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->personID);
		modelmaker::objSet(obj, "PersonID", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->speed);
		modelmaker::objSet(obj, "Speed", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name);
		modelmaker::objSet(obj, "Name", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->path);
		modelmaker::objSet(obj, "Path", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->scriptPath);
		modelmaker::objSet(obj, "ScriptPath", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut TileClass::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->terrainFlags);
		modelmaker::objSet(obj, "TerrainFlags", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->import);
		modelmaker::objSet(obj, "Import", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->lowerAnims.size(); i++) {
			modelmaker::JsonValOut obj0 = this->lowerAnims[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "LowerAnims", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->upperAnims.size(); i++) {
			modelmaker::JsonValOut obj0 = this->upperAnims[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "UpperAnims", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut ZoneHeader::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->path);
		modelmaker::objSet(obj, "Path", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->size.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Size", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut PersonClass::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->iD);
		modelmaker::objSet(obj, "ID", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonObjOut out1 = modelmaker::newJsonObj();
		for (std::map< string, string >::iterator n = this->name.begin(); n != this->name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << modelmaker::toStdString(modelmaker::toString(n->first));
			s >> tmp;
			key = modelmaker::toString(tmp);
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->name[n->first]);
			modelmaker::objSet(out1, key, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Name", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->creatures.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->creatures[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Creatures", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->overhead.size(); i++) {
			modelmaker::JsonValOut obj0 = this->overhead[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Overhead", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut obj0 = this->frontView.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "FrontView", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->backView.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "BackView", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Person::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut obj0 = this->personClass.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "PersonClass", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut Tile::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonValOut obj0 = this->tileClass.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "TileClass", out0);
		modelmaker::decref(out0);
	}
	{
		modelmaker::JsonValOut obj0 = this->occupant.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Occupant", out0);
		modelmaker::decref(out0);
	}
	return obj;
}

modelmaker::JsonValOut World::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->zones.size(); i++) {
			modelmaker::JsonValOut obj0 = this->zones[i].buildJsonObj();
			modelmaker::JsonValOut out0 = obj0;
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "Zones", out1);
		modelmaker::decref(out1);
	}
	return obj;
}

modelmaker::JsonValOut Zone::buildJsonObj() {
	modelmaker::JsonObjOut obj = modelmaker::newJsonObj();
	{
		modelmaker::JsonArrayOut out3 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->tiles.size(); i++) {
			modelmaker::JsonArrayOut out2 = modelmaker::newJsonArray();
			for (unsigned int ii = 0; ii < this->tiles[i].size(); ii++) {
				modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
				for (unsigned int iii = 0; iii < this->tiles[i][ii].size(); iii++) {
					modelmaker::JsonValOut obj0 = this->tiles[i][ii][iii].buildJsonObj();
					modelmaker::JsonValOut out0 = obj0;
					modelmaker::arrayAdd(out1, out0);
					modelmaker::decref(out0);
				}
				modelmaker::arrayAdd(out2, out1);
				modelmaker::decref(out1);
			}
			modelmaker::arrayAdd(out3, out2);
			modelmaker::decref(out2);
		}
		modelmaker::objSet(obj, "Tiles", out3);
		modelmaker::decref(out3);
	}
	{
		modelmaker::JsonArrayOut out1 = modelmaker::newJsonArray();
		for (unsigned int i = 0; i < this->initScripts.size(); i++) {
			modelmaker::JsonValOut out0 = modelmaker::toJsonVal(this->initScripts[i]);
			modelmaker::arrayAdd(out1, out0);
			modelmaker::decref(out0);
		}
		modelmaker::objSet(obj, "InitScripts", out1);
		modelmaker::decref(out1);
	}
	{
		modelmaker::JsonValOut obj0 = this->location.buildJsonObj();
		modelmaker::JsonValOut out0 = obj0;
		modelmaker::objSet(obj, "Location", out0);
		modelmaker::decref(out0);
	}
	return obj;
}
