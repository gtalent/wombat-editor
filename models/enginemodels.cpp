//Generated Code

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
	this->path = "";
}

ZoneHeader::ZoneHeader() {
	this->path = "";
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

TileClass::TileClass() {
	this->terrainFlags = 0;
	this->import = "";
}

PersonClass::PersonClass() {
	this->iD = 0;
}

Person::Person() {
}

World::World() {
}

Sprite::Sprite() {
	this->spriteType = 0;
	this->personID = 0;
	this->speed = 0;
	this->name = "";
	this->path = "";
	this->scriptPath = "";
}

Tile::Tile() {
}

Zone::Zone() {
}

bool CreatureType::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Name");
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
						if (json_object_get_type(obj1) == json_type_string) {
							this->name[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Special");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->special = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "StrongAgainst");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->strongAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->strongAgainst[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "WeakAgainst");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->weakAgainst.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->weakAgainst[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	return true;
}

bool StatusEffect::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "AttackerEffect");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->attackerEffect = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "EnemyEffect");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->enemyEffect = json_object_get_int(obj0);
				}
			}
		}
	}
	return true;
}

bool Fraction::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Current");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->current = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Available");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->available = json_object_get_int(obj0);
				}
			}
		}
	}
	return true;
}

bool ModelFile::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Type");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->type = json_object_get_string(obj0);
				}
			}
		}
	}
	return true;
}

bool Point::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "X");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->x = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Y");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->y = json_object_get_int(obj0);
				}
			}
		}
	}
	return true;
}

bool Size::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Width");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->width = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Height");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->height = json_object_get_int(obj0);
				}
			}
		}
	}
	return true;
}

bool CreatureMove::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Name");
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
						if (json_object_get_type(obj1) == json_type_string) {
							this->name[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Type");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->type = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Power");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->power = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "RequiresRegarge");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->requiresRegarge = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Script");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->script = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Burn");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->burn.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Freeze");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->freeze.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Paralyze");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->paralyze.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Poison");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->poison.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Sleep");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->sleep.load(obj0);
				}
			}
		}
	}
	return true;
}

bool CreatureMoveInstance::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "CreatureMove");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->creatureMove = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "PP");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->pP.load(obj0);
				}
			}
		}
	}
	return true;
}

bool Creature::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "ID");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->iD = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Name");
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
						if (json_object_get_type(obj1) == json_type_string) {
							this->name[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "CreatureClass");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->creatureClass = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Male");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->male = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Level");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->level = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Health");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->health.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Attack");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->attack = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "SpecAttack");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->specAttack = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Defense");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->defense = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "SpecDefense");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->specDefense = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Burned");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->burned = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Frozen");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->frozen = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Poisoned");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->poisoned = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Asleep");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_boolean) {
					this->asleep = json_object_get_boolean(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Moves");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->moves.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->moves[i].load(obj1);
						}
					}
				}
			}
		}
	}
	return true;
}

bool User::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "PersonID");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->personID = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "World");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->world = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Zone");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->zone = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "XAddress");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->xAddress = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "YAddress");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->yAddress = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Layer");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->layer = json_object_get_int(obj0);
				}
			}
		}
	}
	return true;
}

bool ZoneInstance::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "AccessorID");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->accessorID = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Path");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->path = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Location");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->location.load(obj0);
				}
			}
		}
	}
	return true;
}

bool Image::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Size");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->size.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Path");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->path = json_object_get_string(obj0);
				}
			}
		}
	}
	return true;
}

bool ZoneHeader::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Path");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->path = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Size");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->size.load(obj0);
				}
			}
		}
	}
	return true;
}

bool Animation::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Interval");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->interval = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Images");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->images.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->images[i].load(obj1);
						}
					}
				}
			}
		}
	}
	return true;
}

bool AnimLayer::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Point");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->point.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Animation");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->animation.load(obj0);
				}
			}
		}
	}
	return true;
}

bool SaveFile::load(json_object *in) {
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
	{
		json_object *obj0 = json_object_object_get(in, "User");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->user.load(obj0);
				}
			}
		}
	}
	return true;
}

bool CreatureClass::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Name");
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
						if (json_object_get_type(obj1) == json_type_string) {
							this->name[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Successor");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->successor = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Predecessor");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->predecessor = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Types");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->types.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->types[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "CanLearn");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->canLearn.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->canLearn[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "LearnsAtLevel");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_object) {
				json_object_object_foreach(obj0, key, obj1) {
					int i;
					{
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->learnsAtLevel[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "FrontView");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->frontView.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "BackView");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->backView.load(obj0);
				}
			}
		}
	}
	return true;
}

bool TileClass::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "TerrainFlags");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->terrainFlags = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Import");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->import = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "LowerAnims");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->lowerAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->lowerAnims[i].load(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "UpperAnims");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->upperAnims.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->upperAnims[i].load(obj1);
						}
					}
				}
			}
		}
	}
	return true;
}

bool PersonClass::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "ID");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->iD = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Name");
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
						if (json_object_get_type(obj1) == json_type_string) {
							this->name[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Creatures");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->creatures.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_int) {
							this->creatures[i] = json_object_get_int(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Overhead");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->overhead.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->overhead[i].load(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "FrontView");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->frontView.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "BackView");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->backView.load(obj0);
				}
			}
		}
	}
	return true;
}

bool Person::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "PersonClass");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->personClass.load(obj0);
				}
			}
		}
	}
	return true;
}

bool World::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Zones");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->zones.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_object) {
							this->zones[i].load(obj1);
						}
					}
				}
			}
		}
	}
	return true;
}

bool Sprite::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "AnimLayers");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->animLayers.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					if (obj1 != NULL && json_object_get_type(obj1) == json_type_array) {
						unsigned int size = json_object_array_length(obj1);
						this->animLayers[i].resize(size);
						for (unsigned int ii = 0; ii < size; ii++) {
							json_object *obj2 = json_object_array_get_idx(obj1, ii);
							{
								if (json_object_get_type(obj2) == json_type_object) {
									this->animLayers[i][ii].load(obj2);
								}
							}
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "SpriteType");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->spriteType = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "PersonID");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->personID = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Speed");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_int) {
					this->speed = json_object_get_int(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Name");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->name = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Path");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->path = json_object_get_string(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "ScriptPath");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_string) {
					this->scriptPath = json_object_get_string(obj0);
				}
			}
		}
	}
	return true;
}

bool Tile::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "TileClass");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->tileClass.load(obj0);
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Occupant");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->occupant.load(obj0);
				}
			}
		}
	}
	return true;
}

bool Zone::load(json_object *in) {
	{
		json_object *obj0 = json_object_object_get(in, "Tiles");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->tiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					if (obj1 != NULL && json_object_get_type(obj1) == json_type_array) {
						unsigned int size = json_object_array_length(obj1);
						this->tiles[i].resize(size);
						for (unsigned int ii = 0; ii < size; ii++) {
							json_object *obj2 = json_object_array_get_idx(obj1, ii);
							if (obj2 != NULL && json_object_get_type(obj2) == json_type_array) {
								unsigned int size = json_object_array_length(obj2);
								this->tiles[i][ii].resize(size);
								for (unsigned int iii = 0; iii < size; iii++) {
									json_object *obj3 = json_object_array_get_idx(obj2, iii);
									{
										if (json_object_get_type(obj3) == json_type_object) {
											this->tiles[i][ii][iii].load(obj3);
										}
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
		json_object *obj0 = json_object_object_get(in, "InitScripts");
		if (obj0 != NULL) {
			if (obj0 != NULL && json_object_get_type(obj0) == json_type_array) {
				unsigned int size = json_object_array_length(obj0);
				this->initScripts.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					json_object *obj1 = json_object_array_get_idx(obj0, i);
					{
						if (json_object_get_type(obj1) == json_type_string) {
							this->initScripts[i] = json_object_get_string(obj1);
						}
					}
				}
			}
		}
	}
	{
		json_object *obj0 = json_object_object_get(in, "Location");
		if (obj0 != NULL) {
			{
				if (json_object_get_type(obj0) == json_type_object) {
					this->location.load(obj0);
				}
			}
		}
	}
	return true;
}

json_object* CreatureType::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_object();
		for (map<string, string >::iterator n = this->name.begin(); n != this->name.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->name[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Name", out1);
	}
	{
		json_object *out0 = json_object_new_boolean(this->special);
		json_object_object_add(obj, "Special", out0);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->strongAgainst.size(); i++) {
			json_object *out0 = json_object_new_string(this->strongAgainst[i].c_str());
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "StrongAgainst", out1);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->weakAgainst.size(); i++) {
			json_object *out0 = json_object_new_string(this->weakAgainst[i].c_str());
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "WeakAgainst", out1);
	}
	return obj;
}

json_object* StatusEffect::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->attackerEffect);
		json_object_object_add(obj, "AttackerEffect", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->enemyEffect);
		json_object_object_add(obj, "EnemyEffect", out0);
	}
	return obj;
}

json_object* Fraction::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->current);
		json_object_object_add(obj, "Current", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->available);
		json_object_object_add(obj, "Available", out0);
	}
	return obj;
}

json_object* ModelFile::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_string(this->type.c_str());
		json_object_object_add(obj, "Type", out0);
	}
	return obj;
}

json_object* Point::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->x);
		json_object_object_add(obj, "X", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->y);
		json_object_object_add(obj, "Y", out0);
	}
	return obj;
}

json_object* Size::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->width);
		json_object_object_add(obj, "Width", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->height);
		json_object_object_add(obj, "Height", out0);
	}
	return obj;
}

json_object* CreatureMove::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_object();
		for (map<string, string >::iterator n = this->name.begin(); n != this->name.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->name[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Name", out1);
	}
	{
		json_object *out0 = json_object_new_string(this->type.c_str());
		json_object_object_add(obj, "Type", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->power);
		json_object_object_add(obj, "Power", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->requiresRegarge);
		json_object_object_add(obj, "RequiresRegarge", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->script.c_str());
		json_object_object_add(obj, "Script", out0);
	}
	{
		json_object *out0 = this->burn.buildJsonObj();
		json_object_object_add(obj, "Burn", out0);
	}
	{
		json_object *out0 = this->freeze.buildJsonObj();
		json_object_object_add(obj, "Freeze", out0);
	}
	{
		json_object *out0 = this->paralyze.buildJsonObj();
		json_object_object_add(obj, "Paralyze", out0);
	}
	{
		json_object *out0 = this->poison.buildJsonObj();
		json_object_object_add(obj, "Poison", out0);
	}
	{
		json_object *out0 = this->sleep.buildJsonObj();
		json_object_object_add(obj, "Sleep", out0);
	}
	return obj;
}

json_object* CreatureMoveInstance::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->creatureMove);
		json_object_object_add(obj, "CreatureMove", out0);
	}
	{
		json_object *out0 = this->pP.buildJsonObj();
		json_object_object_add(obj, "PP", out0);
	}
	return obj;
}

json_object* Creature::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->iD);
		json_object_object_add(obj, "ID", out0);
	}
	{
		json_object *out1 = json_object_new_object();
		for (map<string, string >::iterator n = this->name.begin(); n != this->name.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->name[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Name", out1);
	}
	{
		json_object *out0 = json_object_new_string(this->creatureClass.c_str());
		json_object_object_add(obj, "CreatureClass", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->male);
		json_object_object_add(obj, "Male", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->level);
		json_object_object_add(obj, "Level", out0);
	}
	{
		json_object *out0 = this->health.buildJsonObj();
		json_object_object_add(obj, "Health", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->attack);
		json_object_object_add(obj, "Attack", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->specAttack);
		json_object_object_add(obj, "SpecAttack", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->defense);
		json_object_object_add(obj, "Defense", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->specDefense);
		json_object_object_add(obj, "SpecDefense", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->burned);
		json_object_object_add(obj, "Burned", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->frozen);
		json_object_object_add(obj, "Frozen", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->poisoned);
		json_object_object_add(obj, "Poisoned", out0);
	}
	{
		json_object *out0 = json_object_new_boolean(this->asleep);
		json_object_object_add(obj, "Asleep", out0);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->moves.size(); i++) {
			json_object *out0 = this->moves[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Moves", out1);
	}
	return obj;
}

json_object* User::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->personID);
		json_object_object_add(obj, "PersonID", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->world.c_str());
		json_object_object_add(obj, "World", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->zone.c_str());
		json_object_object_add(obj, "Zone", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->xAddress);
		json_object_object_add(obj, "XAddress", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->yAddress);
		json_object_object_add(obj, "YAddress", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->layer);
		json_object_object_add(obj, "Layer", out0);
	}
	return obj;
}

json_object* ZoneInstance::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_string(this->accessorID.c_str());
		json_object_object_add(obj, "AccessorID", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->path.c_str());
		json_object_object_add(obj, "Path", out0);
	}
	{
		json_object *out0 = this->location.buildJsonObj();
		json_object_object_add(obj, "Location", out0);
	}
	return obj;
}

json_object* Image::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = this->size.buildJsonObj();
		json_object_object_add(obj, "Size", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->path.c_str());
		json_object_object_add(obj, "Path", out0);
	}
	return obj;
}

json_object* ZoneHeader::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_string(this->path.c_str());
		json_object_object_add(obj, "Path", out0);
	}
	{
		json_object *out0 = this->size.buildJsonObj();
		json_object_object_add(obj, "Size", out0);
	}
	return obj;
}

json_object* Animation::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->interval);
		json_object_object_add(obj, "Interval", out0);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->images.size(); i++) {
			json_object *out0 = this->images[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Images", out1);
	}
	return obj;
}

json_object* AnimLayer::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = this->point.buildJsonObj();
		json_object_object_add(obj, "Point", out0);
	}
	{
		json_object *out0 = this->animation.buildJsonObj();
		json_object_object_add(obj, "Animation", out0);
	}
	return obj;
}

json_object* SaveFile::buildJsonObj() {
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
	{
		json_object *out0 = this->user.buildJsonObj();
		json_object_object_add(obj, "User", out0);
	}
	return obj;
}

json_object* CreatureClass::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_object();
		for (map<string, string >::iterator n = this->name.begin(); n != this->name.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->name[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Name", out1);
	}
	{
		json_object *out0 = json_object_new_string(this->successor.c_str());
		json_object_object_add(obj, "Successor", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->predecessor.c_str());
		json_object_object_add(obj, "Predecessor", out0);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->types.size(); i++) {
			json_object *out0 = json_object_new_string(this->types[i].c_str());
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Types", out1);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->canLearn.size(); i++) {
			json_object *out0 = json_object_new_string(this->canLearn[i].c_str());
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "CanLearn", out1);
	}
	{
		json_object *out1 = json_object_new_object();
		for (map<int, string >::iterator n = this->learnsAtLevel.begin(); n != this->learnsAtLevel.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->learnsAtLevel[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "LearnsAtLevel", out1);
	}
	{
		json_object *out0 = this->frontView.buildJsonObj();
		json_object_object_add(obj, "FrontView", out0);
	}
	{
		json_object *out0 = this->backView.buildJsonObj();
		json_object_object_add(obj, "BackView", out0);
	}
	return obj;
}

json_object* TileClass::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->terrainFlags);
		json_object_object_add(obj, "TerrainFlags", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->import.c_str());
		json_object_object_add(obj, "Import", out0);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->lowerAnims.size(); i++) {
			json_object *out0 = this->lowerAnims[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "LowerAnims", out1);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->upperAnims.size(); i++) {
			json_object *out0 = this->upperAnims[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "UpperAnims", out1);
	}
	return obj;
}

json_object* PersonClass::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = json_object_new_int(this->iD);
		json_object_object_add(obj, "ID", out0);
	}
	{
		json_object *out1 = json_object_new_object();
		for (map<string, string >::iterator n = this->name.begin(); n != this->name.end(); n++) {
			std::stringstream s;
			string key;
			s << n->first;
			s >> key;
			json_object *out0 = json_object_new_string(this->name[n->first].c_str());
			json_object_object_add(out1, key.c_str(), out0);
		}
		json_object_object_add(obj, "Name", out1);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->creatures.size(); i++) {
			json_object *out0 = json_object_new_int(this->creatures[i]);
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Creatures", out1);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->overhead.size(); i++) {
			json_object *out0 = this->overhead[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Overhead", out1);
	}
	{
		json_object *out0 = this->frontView.buildJsonObj();
		json_object_object_add(obj, "FrontView", out0);
	}
	{
		json_object *out0 = this->backView.buildJsonObj();
		json_object_object_add(obj, "BackView", out0);
	}
	return obj;
}

json_object* Person::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = this->personClass.buildJsonObj();
		json_object_object_add(obj, "PersonClass", out0);
	}
	return obj;
}

json_object* World::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->zones.size(); i++) {
			json_object *out0 = this->zones[i].buildJsonObj();
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "Zones", out1);
	}
	return obj;
}

json_object* Sprite::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out2 = json_object_new_array();
		for (unsigned int i = 0; i < this->animLayers.size(); i++) {
			json_object *out1 = json_object_new_array();
			for (unsigned int ii = 0; ii < this->animLayers[i].size(); ii++) {
				json_object *out0 = this->animLayers[i][ii].buildJsonObj();
				json_object_array_add(out1, out0);
			}
			json_object_array_add(out2, out1);
		}
		json_object_object_add(obj, "AnimLayers", out2);
	}
	{
		json_object *out0 = json_object_new_int(this->spriteType);
		json_object_object_add(obj, "SpriteType", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->personID);
		json_object_object_add(obj, "PersonID", out0);
	}
	{
		json_object *out0 = json_object_new_int(this->speed);
		json_object_object_add(obj, "Speed", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->name.c_str());
		json_object_object_add(obj, "Name", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->path.c_str());
		json_object_object_add(obj, "Path", out0);
	}
	{
		json_object *out0 = json_object_new_string(this->scriptPath.c_str());
		json_object_object_add(obj, "ScriptPath", out0);
	}
	return obj;
}

json_object* Tile::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out0 = this->tileClass.buildJsonObj();
		json_object_object_add(obj, "TileClass", out0);
	}
	{
		json_object *out0 = this->occupant.buildJsonObj();
		json_object_object_add(obj, "Occupant", out0);
	}
	return obj;
}

json_object* Zone::buildJsonObj() {
	json_object *obj = json_object_new_object();
	{
		json_object *out3 = json_object_new_array();
		for (unsigned int i = 0; i < this->tiles.size(); i++) {
			json_object *out2 = json_object_new_array();
			for (unsigned int ii = 0; ii < this->tiles[i].size(); ii++) {
				json_object *out1 = json_object_new_array();
				for (unsigned int iii = 0; iii < this->tiles[i][ii].size(); iii++) {
					json_object *out0 = this->tiles[i][ii][iii].buildJsonObj();
					json_object_array_add(out1, out0);
				}
				json_object_array_add(out2, out1);
			}
			json_object_array_add(out3, out2);
		}
		json_object_object_add(obj, "Tiles", out3);
	}
	{
		json_object *out1 = json_object_new_array();
		for (unsigned int i = 0; i < this->initScripts.size(); i++) {
			json_object *out0 = json_object_new_string(this->initScripts[i].c_str());
			json_object_array_add(out1, out0);
		}
		json_object_object_add(obj, "InitScripts", out1);
	}
	{
		json_object *out0 = this->location.buildJsonObj();
		json_object_object_add(obj, "Location", out0);
	}
	return obj;
}
