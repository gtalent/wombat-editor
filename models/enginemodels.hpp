//Generated Code
#ifndef ENGINEMODELS_HPP
#define ENGINEMODELS_HPP
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <json/json.h>
#include "modelmakerdefs.hpp"


using std::string;
using std::vector;
using std::map;

namespace enginemodels {

class CreatureType: public modelmaker::Model {

	public:

		CreatureType();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, string > name;
		bool special;
		vector<string > strongAgainst;
		vector<string > weakAgainst;
};

}


namespace enginemodels {

class StatusEffect: public modelmaker::Model {

	public:

		StatusEffect();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int attackerEffect;
		int enemyEffect;
};

}


namespace enginemodels {

class Fraction: public modelmaker::Model {

	public:

		Fraction();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int current;
		int available;
};

}


namespace enginemodels {

class ModelFile: public modelmaker::Model {

	public:

		ModelFile();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		string type;
};

}


namespace enginemodels {

class Point: public modelmaker::Model {

	public:

		Point();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int x;
		int y;
};

}


namespace enginemodels {

class Size: public modelmaker::Model {

	public:

		Size();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int width;
		int height;
};

}


namespace enginemodels {

class CreatureMove: public modelmaker::Model {

	public:

		CreatureMove();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, string > name;
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

class CreatureMoveInstance: public modelmaker::Model {

	public:

		CreatureMoveInstance();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int creatureMove;
		Fraction pP;
};

}


namespace enginemodels {

class Creature: public modelmaker::Model {

	public:

		Creature();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int iD;
		map<string, string > name;
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
		vector<CreatureMoveInstance > moves;
};

}


namespace enginemodels {

class User: public modelmaker::Model {

	public:

		User();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int personID;
		string world;
		string zone;
		int xAddress;
		int yAddress;
		int layer;
};

}


namespace enginemodels {

class ZoneInstance: public modelmaker::Model {

	public:

		ZoneInstance();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		string accessorID;
		string path;
		Point location;
};

}


namespace enginemodels {

class Image: public modelmaker::Model {

	public:

		Image();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		Size size;
		string path;
};

}


namespace enginemodels {

class ZoneHeader: public modelmaker::Model {

	public:

		ZoneHeader();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		string path;
		Size size;
};

}


namespace enginemodels {

class Animation: public modelmaker::Model {

	public:

		Animation();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int interval;
		vector<Image > images;
};

}


namespace enginemodels {

class AnimLayer: public modelmaker::Model {

	public:

		AnimLayer();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		Point point;
		Animation animation;
};

}


namespace enginemodels {

class SaveFile: public modelmaker::Model {

	public:

		SaveFile();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, modelmaker::unknown > vars;
		User user;
};

}


namespace enginemodels {

class CreatureClass: public modelmaker::Model {

	public:

		CreatureClass();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		map<string, string > name;
		string successor;
		string predecessor;
		vector<string > types;
		vector<string > canLearn;
		map<int, string > learnsAtLevel;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

class TileClass: public modelmaker::Model {

	public:

		TileClass();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int terrainFlags;
		string import;
		vector<AnimLayer > lowerAnims;
		vector<AnimLayer > upperAnims;
};

}


namespace enginemodels {

class PersonClass: public modelmaker::Model {

	public:

		PersonClass();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		int iD;
		map<string, string > name;
		vector<int > creatures;
		vector<Animation > overhead;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

class Person: public modelmaker::Model {

	public:

		Person();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		PersonClass personClass;
};

}


namespace enginemodels {

class World: public modelmaker::Model {

	public:

		World();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		vector<ZoneInstance > zones;
};

}


namespace enginemodels {

class Sprite: public modelmaker::Model {

	public:

		Sprite();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		vector<vector<AnimLayer > > animLayers;
		int spriteType;
		int personID;
		int speed;
		string name;
		string path;
		string scriptPath;
};

}


namespace enginemodels {

class Tile: public modelmaker::Model {

	public:

		Tile();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		TileClass tileClass;
		Sprite occupant;
};

}


namespace enginemodels {

class Zone: public modelmaker::Model {

	public:

		Zone();

		void load(string text);

		bool load(json_object *obj);

		json_object* buildJsonObj();

		vector<vector<vector<Tile > > > tiles;
		vector<string > initScripts;
		Point location;
};

}


#endif