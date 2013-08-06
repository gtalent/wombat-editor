//Generated Code
#ifndef ENGINEMODELS_HPP
#define ENGINEMODELS_HPP
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <jansson.h>
#include "modelmakerdefs.hpp"


using std::string;
using std::vector;
using std::map;

namespace enginemodels {

class CreatureType: public modelmaker::Model {

	public:

		CreatureType();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
		bool special;
		vector< string > strongAgainst;
		vector< string > weakAgainst;
};

}


namespace enginemodels {

class StatusEffect: public modelmaker::Model {

	public:

		StatusEffect();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int attackerEffect;
		int enemyEffect;
};

}


namespace enginemodels {

class Fraction: public modelmaker::Model {

	public:

		Fraction();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int current;
		int available;
};

}


namespace enginemodels {

class ModelFile: public modelmaker::Model {

	public:

		ModelFile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string type;
};

}


namespace enginemodels {

class Point: public modelmaker::Model {

	public:

		Point();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int x;
		int y;
};

}


namespace enginemodels {

class Size: public modelmaker::Model {

	public:

		Size();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int width;
		int height;
};

}


namespace enginemodels {

class Bounds: public modelmaker::Model {

	public:

		Bounds();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int x;
		int y;
		int width;
		int height;
};

}


namespace enginemodels {

class SaveVariables: public modelmaker::Model {

	public:

		SaveVariables();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > vars;
};

}


namespace enginemodels {

class SpriteSheet: public modelmaker::Model {

	public:

		SpriteSheet();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int tilesWide;
		int tilesHigh;
		int tileWidth;
		int tileHeight;
		string src;
		vector< Bounds > images;
};

}


namespace enginemodels {

class CreatureMove: public modelmaker::Model {

	public:

		CreatureMove();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
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

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int creatureMove;
		Fraction pP;
};

}


namespace enginemodels {

class Creature: public modelmaker::Model {

	public:

		Creature();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int iD;
		map< string, string > name;
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
		vector< CreatureMoveInstance > moves;
};

}


namespace enginemodels {

class User: public modelmaker::Model {

	public:

		User();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

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

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string accessorID;
		string path;
		Point location;
};

}


namespace enginemodels {

class Image: public modelmaker::Model {

	public:

		Image();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int imgId;
		Size defaultSize;
};

}


namespace enginemodels {

class ImageSrc: public modelmaker::Model {

	public:

		ImageSrc();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string srcFile;
		Bounds bounds;
};

}


namespace enginemodels {

class ImageMap: public modelmaker::Model {

	public:

		ImageMap();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< int, ImageSrc > images;
};

}


namespace enginemodels {

class Animation: public modelmaker::Model {

	public:

		Animation();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int interval;
		vector< Image > images;
};

}


namespace enginemodels {

class AnimLayer: public modelmaker::Model {

	public:

		AnimLayer();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		Point point;
		Animation animation;
};

}


namespace enginemodels {

class SaveFile: public modelmaker::Model {

	public:

		SaveFile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, modelmaker::unknown > vars;
		User user;
};

}


namespace enginemodels {

class CreatureClass: public modelmaker::Model {

	public:

		CreatureClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		map< string, string > name;
		string successor;
		string predecessor;
		vector< string > types;
		vector< string > canLearn;
		map< int, string > learnsAtLevel;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

class Sprite: public modelmaker::Model {

	public:

		Sprite();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< vector< AnimLayer > > animLayers;
		int spriteType;
		int personID;
		int speed;
		string name;
		string path;
		string scriptPath;
};

}


namespace enginemodels {

class TileClass: public modelmaker::Model {

	public:

		TileClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int terrainFlags;
		string import;
		vector< AnimLayer > lowerAnims;
		vector< AnimLayer > upperAnims;
};

}


namespace enginemodels {

class ZoneHeader: public modelmaker::Model {

	public:

		ZoneHeader();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		string path;
		Size size;
};

}


namespace enginemodels {

class PersonClass: public modelmaker::Model {

	public:

		PersonClass();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		int iD;
		map< string, string > name;
		vector< int > creatures;
		vector< Animation > overhead;
		Animation frontView;
		Animation backView;
};

}


namespace enginemodels {

class Person: public modelmaker::Model {

	public:

		Person();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		PersonClass personClass;
};

}


namespace enginemodels {

class Tile: public modelmaker::Model {

	public:

		Tile();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		TileClass tileClass;
		Sprite occupant;
};

}


namespace enginemodels {

class World: public modelmaker::Model {

	public:

		World();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< ZoneInstance > zones;
};

}


namespace enginemodels {

class Zone: public modelmaker::Model {

	public:

		Zone();

		bool load_json_t(json_t *obj);

		json_t* buildJsonObj();

		vector< vector< vector< Tile > > > tiles;
		vector< string > initScripts;
		Point location;
};

}


#endif