//Generated Code
#ifndef ENGINEMODELS_HPP
#define ENGINEMODELS_HPP
#include <string>
#include <sstream>

//Generated Code

#define USING_QT

#include <string>

#include <vector>
#include <map>

#ifdef USING_QT
#include <QString>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QMap>
#include <QVector>
#else
#include <string>
#include <jansson.h>
#endif

namespace enginemodels {

namespace modelmaker {

#ifdef USING_QT
typedef QJsonObject& JsonObj;
typedef QJsonValue&  JsonVal;
typedef QJsonArray&  JsonArray;

typedef QJsonObject  JsonObjOut;
typedef QJsonValue   JsonValOut;
typedef QJsonArray   JsonArrayOut;

typedef QJsonObject::iterator JsonObjIterator;
typedef QString               JsonObjIteratorKey;
typedef QJsonValueRef         JsonObjIteratorVal;

typedef QString string;

#else

typedef json_t* JsonObj;
typedef json_t* JsonVal;
typedef json_t* JsonArray;

typedef json_t* JsonObjOut;
typedef json_t* JsonValOut;
typedef json_t* JsonArrayOut;

typedef const char* JsonObjIterator;
typedef const char* JsonObjIteratorKey;
typedef json_t*     JsonObjIteratorVal;

typedef std::string string;
#endif

//string ops
std::string toStdString(string str);
const char* toCString(string str);


JsonObjOut read(const char *json);

int toInt(JsonVal);
double toDouble(JsonVal);
bool toBool(JsonVal);
string toString(JsonVal);
JsonArrayOut toArray(JsonVal);
JsonObjOut toObj(JsonVal);

JsonValOut toJsonVal(int);
JsonValOut toJsonVal(double);
JsonValOut toJsonVal(bool);
JsonValOut toJsonVal(string);
JsonValOut toJsonVal(JsonArray);
JsonValOut toJsonVal(JsonObj);


//value methods

bool isBool(JsonVal);
bool isInt(JsonVal);
bool isDouble(JsonVal);
bool isString(JsonVal);
bool isArray(JsonVal);
bool isObj(JsonVal);

JsonObj incref(JsonObj);
JsonVal incref(JsonVal);
JsonArray incref(JsonArray);

void decref(JsonObj);
void decref(JsonVal);
void decref(JsonArray);


JsonArrayOut newJsonArray();

void arrayAdd(JsonArray, JsonObj);
void arrayAdd(JsonArray, JsonVal);
void arrayAdd(JsonArray, JsonArray);

int arraySize(JsonArray);

JsonValOut arrayRead(JsonArray, int);


JsonObjOut newJsonObj();

void objSet(JsonObj, string, JsonObj);
void objSet(JsonObj, string, JsonVal);
void objSet(JsonObj, string, JsonArray);

JsonValOut objRead(JsonObj, string);


JsonObjIterator iterator(JsonObj);
JsonObjIterator iteratorNext(JsonObj, JsonObjIterator);
JsonObjIteratorKey iteratorKey(JsonObjIterator);
JsonObjIteratorVal iteratorValue(JsonObjIterator);
bool iteratorAtEnd(JsonObjIterator, JsonObj);



inline string toString(string str) {
	return str;
}


#ifdef USING_QT

//string conversions
inline std::string toStdString(string str) {
	return str.toStdString();
}

inline const char* toCString(std::string str) {
	return str.c_str();
}

inline const char* toCString(string str) {
	return toStdString(str).c_str();
}

inline string toString(std::string str) {
	return QString::fromStdString(str);
}


inline JsonObjOut read(const char *json) {
	return QJsonDocument::fromJson(QByteArray(json)).object();
}


//from JsonObjIteratorVal
inline int toInt(JsonObjIteratorVal v) {
	return (int) v.toDouble();
}

inline double toDouble(JsonObjIteratorVal v) {
	return v.toDouble();
}

inline bool toBool(JsonObjIteratorVal v) {
	return v.toBool();
}

inline string toString(JsonObjIteratorVal v) {
	return v.toString();
}

inline JsonArrayOut toArray(JsonObjIteratorVal v) {
	return v.toArray();
}

inline JsonObjOut toObj(JsonObjIteratorVal v) {
	return v.toObject();
}

//from JsonVal
inline int toInt(JsonVal v) {
	return (int) v.toDouble();
}

inline double toDouble(JsonVal v) {
	return v.toDouble();
}

inline bool toBool(JsonVal v) {
	return v.toBool();
}

inline string toString(JsonVal v) {
	return v.toString();
}

inline JsonArrayOut toArray(JsonVal v) {
	return v.toArray();
}

inline JsonObjOut toObj(JsonVal v) {
	return v.toObject();
}


inline JsonValOut toJsonVal(int v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(double v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(bool v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(string v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(JsonArray v) {
	return QJsonValue(v);
}

inline JsonValOut toJsonVal(JsonObj v) {
	return v;
}


inline bool isNull(JsonObjIteratorVal v) {
	return v.isNull();
}

inline bool isBool(JsonObjIteratorVal v) {
	return v.isBool();
}

inline bool isInt(JsonObjIteratorVal v) {
	return v.isDouble();
}

inline bool isDouble(JsonObjIteratorVal v) {
	return v.isDouble();
}

inline bool isString(JsonObjIteratorVal v) {
	return v.isString();
}

inline bool isArray(JsonObjIteratorVal v) {
	return v.isArray();
}

inline bool isObj(JsonObjIteratorVal v) {
	return v.isObject();
}

inline bool isBool(JsonVal v) {
	return v.isBool();
}

inline bool isInt(JsonVal v) {
	return v.isDouble();
}

inline bool isDouble(JsonVal v) {
	return v.isDouble();
}

inline bool isString(JsonVal v) {
	return v.isString();
}

inline bool isArray(JsonVal v) {
	return v.isArray();
}

inline bool isObj(JsonVal v) {
	return v.isObject();
}

inline bool isNull(JsonVal v) {
	return v.isNull();
}


inline JsonVal incref(JsonVal v) {
	return v;
}

inline void decref(JsonVal) {}

inline JsonObj incref(JsonObj v) {
	return v;
}

inline void decref(JsonObj) {}

inline JsonArray incref(JsonArray v) {
	return v;
}

inline void decref(JsonArray) {}


inline JsonArrayOut newJsonArray() {
	return QJsonArray();
}

inline void arrayAdd(JsonArray a, JsonArray v) {
	JsonValOut tmp = modelmaker::toJsonVal(v);
	a.append(tmp);
}

inline void arrayAdd(JsonArray a, JsonObj v) {
	JsonValOut tmp = modelmaker::toJsonVal(v);
	a.append(tmp);
}

inline void arrayAdd(JsonArray a, JsonVal v) {
	a.append(v);
}


inline JsonValOut arrayRead(JsonArray a, int i) {
	return a[i];
}

inline int arraySize(JsonArray a) {
	return a.size();
}


inline JsonObjOut newJsonObj() {
	return QJsonObject();
}

inline void objSet(JsonObj o, string k, JsonArray v) {
	JsonValOut tmp = modelmaker::toJsonVal(v);
	o.insert(k, tmp);
}

inline void objSet(JsonObj o, string k, JsonObj v) {
	JsonValOut tmp = modelmaker::toJsonVal(v);
	o.insert(k, tmp);
}

inline void objSet(JsonObj o, string k, JsonVal v) {
	o.insert(k, v);
}


inline JsonValOut objRead(JsonObj o, string k) {
	return o[k];
}

inline JsonObjIterator iterator(JsonObj o) {
	return o.begin();
}

inline JsonObjIterator iteratorNext(JsonObj, JsonObjIterator i) {
	return i + 1;
}

inline JsonObjIteratorKey iteratorKey(JsonObjIterator i) {
	return i.key();
}

inline bool iteratorAtEnd(JsonObjIterator i, JsonObj o) {
	return i == o.end();
}

inline JsonObjIteratorVal iteratorValue(JsonObjIterator i) {
	return i.value();
}

inline string write(JsonObj obj) {
	QJsonDocument doc(obj);
	return doc.toJson();
}

#else

inline std::string toStdString(string str) {
	return str;
}

inline const char* toCString(string str) {
	return str.c_str();
}


inline JsonObjOut read(const char *json) {
	return json_loads(json, 0, NULL);
}

inline string write(JsonObj obj) {
	char *tmp = json_dumps(obj, JSON_COMPACT);
	if (!tmp)
		return "{}";
	string out = tmp;
	free(tmp);
	modelmaker::decref(obj);
	return out;
}

//value methods

inline int toInt(JsonVal v) {
	return (int) json_integer_value(v);
}

inline double toDouble(JsonVal v) {
	return (double) json_real_value(v);
}

inline bool toBool(JsonVal v) {
	return json_is_true(v);
}

inline string toString(JsonVal v) {
	return json_string_value(v);
}

inline JsonArray toArray(JsonVal v) {
	return v;
}

inline JsonObj toObj(JsonVal v) {
	return v;
}


inline JsonVal toJsonVal(int v) {
	return json_integer(v);
}

inline JsonVal toJsonVal(double v) {
	return json_real(v);
}

inline JsonVal toJsonVal(bool v) {
	return json_boolean(v);
}

inline JsonVal toJsonVal(string v) {
	return json_string(v.c_str());
}

inline JsonVal toJsonVal(JsonArray v) {
	return v;
}


inline bool isNull(JsonVal v) {
	return !v;
}

inline bool isBool(JsonVal v) {
	return json_is_boolean(v);
}

inline bool isInt(JsonVal v) {
	return json_is_integer(v);
}

inline bool isDouble(JsonVal v) {
	return json_is_real(v);
}

inline bool isString(JsonVal v) {
	return json_is_string(v);
}

inline bool isArray(JsonVal v) {
	return json_is_array(v);
}

inline bool isObj(JsonVal v) {
	return json_is_object(v);
}

inline JsonVal incref(JsonVal v) {
	return json_incref(v);
}

inline void decref(JsonVal v) {
	json_decref(v);
}

//array methods

inline JsonArrayOut newJsonArray() {
	return json_array();
}

inline void arrayAdd(JsonArray a, JsonVal v) {
	json_array_append(a, v);
}

inline JsonVal arrayRead(JsonArray a, int i) {
	return json_array_get(a, i);
}

inline int arraySize(JsonArray a) {
	return json_array_size(a);
}

//object methods

inline JsonObjOut newJsonObj() {
	return json_object();
}

inline void objSet(JsonObj o, string k, JsonVal v) {
	json_object_set(o, k.c_str(), v);
}

inline JsonVal objRead(JsonObj o, string k) {
	return json_object_get(o, k.c_str());
}


inline JsonObjIterator iterator(JsonObj o) {
	return json_object_iter_key(json_object_iter(o));
}

inline JsonObjIterator iteratorNext(JsonObj o, JsonObjIterator i) {
	return json_object_iter_key(json_object_iter_next(o, json_object_key_to_iter(i)));
}

inline JsonObjIteratorKey iteratorKey(JsonObjIterator i) {
	return i;
}

inline JsonObjIteratorVal iteratorValue(JsonObjIterator i) {
	return json_object_iter_value(json_object_key_to_iter(i));
}

inline bool iteratorAtEnd(JsonObjIterator i, JsonObj) {
	return !i;
}

#endif

class unknown;

class Model {
	friend class unknown;
	public:
		bool loadFile(string path);
		void writeFile(string path);
		void load(string json);
		string write();
#ifdef USING_QT
		bool loadJsonObj(modelmaker::JsonObjIteratorVal &obj) { return loadJsonObj(obj); };
#endif
	protected:
		virtual modelmaker::JsonValOut buildJsonObj() = 0;
		virtual bool loadJsonObj(modelmaker::JsonVal obj) = 0;
};

class unknown: public Model {
	private:
		modelmaker::JsonValOut m_obj;
	public:
		unknown();
		unknown(Model *v);
		unknown(bool v);
		unknown(int v);
		unknown(double v);
		unknown(string v);
		virtual ~unknown();

		bool loaded();
		bool loadJsonObj(modelmaker::JsonVal obj);
		modelmaker::JsonValOut buildJsonObj();

		bool toBool();
		int toInt();
		double toDouble();
		string toString();
		
		bool isBool();
		bool isInt();
		bool isDouble();
		bool isString();
		bool isObject();

		void set(Model* v);
		void set(bool v);
		void set(int v);
		void set(double v);
		void set(string v);
};

};

};




namespace enginemodels {

using modelmaker::string;

class CreatureType: public modelmaker::Model {

	public:

		CreatureType();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< string, string > name;
		bool special;
		std::vector< string > strongAgainst;
		std::vector< string > weakAgainst;
};

}


namespace enginemodels {

using modelmaker::string;

class StatusEffect: public modelmaker::Model {

	public:

		StatusEffect();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int attackerEffect;
		int enemyEffect;
};

}


namespace enginemodels {

using modelmaker::string;

class Fraction: public modelmaker::Model {

	public:

		Fraction();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int current;
		int available;
};

}


namespace enginemodels {

using modelmaker::string;

class ModelFile: public modelmaker::Model {

	public:

		ModelFile();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		string type;
};

}


namespace enginemodels {

using modelmaker::string;

class Point: public modelmaker::Model {

	public:

		Point();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int x;
		int y;
};

}


namespace enginemodels {

using modelmaker::string;

class Size: public modelmaker::Model {

	public:

		Size();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int width;
		int height;
};

}


namespace enginemodels {

using modelmaker::string;

class Bounds: public modelmaker::Model {

	public:

		Bounds();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int x;
		int y;
		int width;
		int height;
};

}


namespace enginemodels {

using modelmaker::string;

class SaveVariables: public modelmaker::Model {

	public:

		SaveVariables();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< string, modelmaker::unknown > vars;
};

}


namespace enginemodels {

using modelmaker::string;

class SpriteSheet: public modelmaker::Model {

	public:

		SpriteSheet();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int tilesWide;
		int tilesHigh;
		int tileWidth;
		int tileHeight;
		string src;
		std::vector< Bounds > images;
};

}


namespace enginemodels {

using modelmaker::string;

class CreatureMove: public modelmaker::Model {

	public:

		CreatureMove();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< string, string > name;
		string type;
		int power;
		bool requiresRegarge;
		string script;
		StatusEffect burn;
		StatusEffect freeze;
		StatusEffect paralyze;
		StatusEffect poison;
		StatusEffect sleep;
};

}


namespace enginemodels {

using modelmaker::string;

class CreatureMoveInstance: public modelmaker::Model {

	public:

		CreatureMoveInstance();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int creatureMove;
		Fraction pP;
};

}


namespace enginemodels {

using modelmaker::string;

class Creature: public modelmaker::Model {

	public:

		Creature();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int iD;
		std::map< string, string > name;
		string creatureClass;
		bool male;
		int level;
		Fraction health;
		int attack;
		int specAttack;
		int defense;
		int specDefense;
		bool burned;
		bool frozen;
		bool poisoned;
		bool asleep;
		std::vector< CreatureMoveInstance > moves;
};

}


namespace enginemodels {

using modelmaker::string;

class User: public modelmaker::Model {

	public:

		User();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int personID;
		string world;
		string zone;
		int xAddress;
		int yAddress;
		int layer;
};

}


namespace enginemodels {

using modelmaker::string;

class ZoneInstance: public modelmaker::Model {

	public:

		ZoneInstance();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		string accessorID;
		string path;
		Point location;
};

}


namespace enginemodels {

using modelmaker::string;

class Image: public modelmaker::Model {

	public:

		Image();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int imgId;
		Size defaultSize;
};

}


namespace enginemodels {

using modelmaker::string;

class ImageSrc: public modelmaker::Model {

	public:

		ImageSrc();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		string srcFile;
		Bounds bounds;
};

}


namespace enginemodels {

using modelmaker::string;

class ImageMap: public modelmaker::Model {

	public:

		ImageMap();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< int, ImageSrc > images;
};

}


namespace enginemodels {

using modelmaker::string;

class Animation: public modelmaker::Model {

	public:

		Animation();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int interval;
		std::vector< Image > images;
};

}


namespace enginemodels {

using modelmaker::string;

class AnimLayer: public modelmaker::Model {

	public:

		AnimLayer();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		Point point;
		Animation animation;
};

}


namespace enginemodels {

using modelmaker::string;

class SaveFile: public modelmaker::Model {

	public:

		SaveFile();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< string, modelmaker::unknown > vars;
		User user;
};

}


namespace enginemodels {

using modelmaker::string;

class CreatureClass: public modelmaker::Model {

	public:

		CreatureClass();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::map< string, string > name;
		string successor;
		string predecessor;
		std::vector< string > types;
		std::vector< string > canLearn;
		std::map< int, string > learnsAtLevel;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

using modelmaker::string;

class Sprite: public modelmaker::Model {

	public:

		Sprite();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::vector< std::vector< AnimLayer > > animLayers;
		int spriteType;
		int personID;
		int speed;
		string name;
		string path;
		string scriptPath;
};

}


namespace enginemodels {

using modelmaker::string;

class TileClass: public modelmaker::Model {

	public:

		TileClass();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int terrainFlags;
		string import;
		std::vector< AnimLayer > lowerAnims;
		std::vector< AnimLayer > upperAnims;
};

}


namespace enginemodels {

using modelmaker::string;

class ZoneHeader: public modelmaker::Model {

	public:

		ZoneHeader();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		string path;
		Size size;
};

}


namespace enginemodels {

using modelmaker::string;

class PersonClass: public modelmaker::Model {

	public:

		PersonClass();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		int iD;
		std::map< string, string > name;
		std::vector< int > creatures;
		std::vector< Animation > overhead;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

using modelmaker::string;

class Person: public modelmaker::Model {

	public:

		Person();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		PersonClass personClass;
};

}


namespace enginemodels {

using modelmaker::string;

class Tile: public modelmaker::Model {

	public:

		Tile();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		TileClass tileClass;
		Sprite occupant;
};

}


namespace enginemodels {

using modelmaker::string;

class World: public modelmaker::Model {

	public:

		World();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::vector< ZoneInstance > zones;
};

}


namespace enginemodels {

using modelmaker::string;

class Zone: public modelmaker::Model {

	public:

		Zone();

		bool loadJsonObj(modelmaker::JsonVal obj);

		modelmaker::JsonValOut buildJsonObj();

		std::vector< std::vector< std::vector< Tile > > > tiles;
		std::vector< string > initScripts;
		Point location;
};

}


#endif