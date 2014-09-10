//Generated Code

#include <fstream>
#include "models.hpp"

using namespace models;
using namespace models::cyborgbear;

string models::cyborgbear::version = "1.1.1";

int Model::readJsonFile(string path) {
	try {
		std::ifstream in;
		in.open(cyborgbear::toStdString(path).c_str());
		if (in.is_open()) {
			std::string json((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
			in.close();
			return fromJson(cyborgbear::toString(json));
		}
	} catch (...) {
	}
	return cyborgbear::Error_CouldNotAccessFile;
}

void Model::writeJsonFile(string path, cyborgbear::JsonSerializationSettings sttngs) {
	std::ofstream out;
	out.open(cyborgbear::toStdString(path).c_str());
	std::string json = cyborgbear::toStdString(toJson(sttngs));
	out << json << "\0";
	out.close();
}

int Model::fromJson(string json) {
	cyborgbear::JsonValOut obj = cyborgbear::read(json);
	cyborgbear::Error retval = loadJsonObj(obj);
	cyborgbear::decref(obj);
	return retval;
}

string Model::toJson(cyborgbear::JsonSerializationSettings sttngs) {
	cyborgbear::JsonValOut val = buildJsonObj();
	cyborgbear::JsonObjOut obj = cyborgbear::toObj(val);
	return cyborgbear::write(obj, sttngs);
}

unknown::unknown() {
}

unknown::unknown(Model *v) {
	set(v);
}

unknown::unknown(bool v) {
	set(v);
}

unknown::unknown(int v) {
	set(v);
}

unknown::unknown(double v) {
	set(v);
}

unknown::unknown(string v) {
	set(v);
}

unknown::~unknown() {
}

cyborgbear::Error unknown::loadJsonObj(cyborgbear::JsonVal obj) {
	cyborgbear::JsonObjOut wrapper = cyborgbear::newJsonObj();
	cyborgbear::objSet(wrapper, "Value", obj);
	m_data = cyborgbear::write(wrapper, cyborgbear::Compact);
	if (cyborgbear::isBool(obj)) {
		m_type = cyborgbear::Bool;
	} else if (cyborgbear::isInt(obj)) {
		m_type = cyborgbear::Integer;
	} else if (cyborgbear::isDouble(obj)) {
		m_type = cyborgbear::Double;
	} else if (cyborgbear::isString(obj)) {
		m_type = cyborgbear::String;
	} else if (cyborgbear::isObj(obj)) {
		m_type = cyborgbear::Object;
	}

	if (cyborgbear::isNull(obj)) {
		return cyborgbear::Error_GenericParsingError;
	} else {
		return cyborgbear::Error_Ok;
	}
}

cyborgbear::JsonValOut unknown::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::read(m_data);
#ifdef CYBORGBEAR_USING_QT
	cyborgbear::JsonValOut val = cyborgbear::objRead(obj, "Value");
#else
	cyborgbear::JsonValOut val = cyborgbear::incref(cyborgbear::objRead(obj, "Value"));
#endif
	cyborgbear::decref(obj);
	return val;
}

bool unknown::loaded() {
	return m_data != "";
}

bool unknown::isBool() {
	return m_type == cyborgbear::Bool;
}

bool unknown::isInt() {
	return m_type == cyborgbear::Integer;
}

bool unknown::isDouble() {
	return m_type == cyborgbear::Double;
}

bool unknown::isString() {
	return m_type == cyborgbear::String;
}

bool unknown::isObject() {
	return m_type == cyborgbear::Object;
}

bool unknown::toBool() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toBool(out);
}

int unknown::toInt() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toInt(out);
}

double unknown::toDouble() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toDouble(out);
}

string unknown::toString() {
	cyborgbear::JsonValOut out = buildJsonObj();
	return cyborgbear::toString(out);
}

void unknown::set(Model *v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = v->buildJsonObj();
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Object;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);

	unknown *unk = dynamic_cast<unknown*>(v);
	if (unk)
		m_type = unk->m_type;
}

void unknown::set(bool v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Bool;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(int v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Integer;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(double v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::Double;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

void unknown::set(string v) {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	cyborgbear::JsonValOut val = cyborgbear::toJsonVal(v);
	cyborgbear::objSet(obj, "Value", val);
	m_type = cyborgbear::String;
	m_data = cyborgbear::write(obj, cyborgbear::Compact);
	cyborgbear::decref(obj);
}

bool unknown::operator==(const unknown &o) const {
	return m_type == o.m_type && m_data == o.m_data;
}

bool unknown::operator!=(const unknown &o) const {
	return m_type != o.m_type || m_data != o.m_data;
}

#ifdef CYBORGBEAR_BOOST_ENABLED

void unknown::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string unknown::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}
	string str;
	while (out.good())
		str += out.get();
	return str;
}
#endif


#include "string.h"
#include "models.hpp"

using namespace models;
using std::stringstream;

Point::Point() {
	this->X = 0;
	this->Y = 0;
}

Size::Size() {
	this->Width = 0;
	this->Height = 0;
}

Bounds::Bounds() {
	this->X = 0;
	this->Y = 0;
	this->Width = 0;
	this->Height = 0;
}

SaveVariables::SaveVariables() {
}

SpriteSheetImage::SpriteSheetImage() {
}

SpriteSheet::SpriteSheet() {
	this->TilesWide = 0;
	this->TilesHigh = 0;
	this->TileWidth = 0;
	this->TileHeight = 0;
	this->SrcFile = "";
	this->ImageIdIterator = 0;
}

Image::Image() {
	this->SpriteSheet = "";
	this->ImgId = 0;
}

Sprite::Sprite() {
	this->Id = "";
	this->SpriteClass = "";
	this->Motion = 0;
	this->Facing = 0;
	this->SpriteType = 0;
	this->Data = "";
}

AnimationSlide::AnimationSlide() {
	this->Interval = 0;
}

AnimLayer::AnimLayer() {
	this->Animation = "";
}

EditorProfile::EditorProfile() {
	this->FileType = "";
	this->Editor = "";
	this->NewFileMenu = "";
}

EditorDockSettings::EditorDockSettings() {
	this->Docked = 0;
	this->Visible = 0;
}

ZoneInstance::ZoneInstance() {
	this->AccessorID = "";
	this->ZoneHeader = "";
}

SpriteClass::SpriteClass() {
	this->SpriteType = 0;
	this->Attributes = "";
}

Animation::Animation() {
	this->Import = "";
}

World::World() {
}

EditorModule::EditorModule() {
}

EditorSettings::EditorSettings() {
	this->OpenProject = "";
	this->OpenTab = 0;
}

ZoneHeader::ZoneHeader() {
	this->Zone = "";
	this->TilesWide = 0;
	this->TilesHigh = 0;
	this->Layers = 0;
}

PersonClass::PersonClass() {
	this->Import = "";
}

Person::Person() {
}

TileClass::TileClass() {
	this->Import = "";
	this->TerrainType = 0;
}

Tile::Tile() {
}

Zone::Zone() {
}

cyborgbear::Error Point::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->X = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Size::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Bounds::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "X");
		{
			if (cyborgbear::isInt(obj0)) {
				this->X = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Y");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Y = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Width");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Width = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Height");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Height = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SaveVariables::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Vars");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						retval |= this->Vars[i].loadJsonObj(obj1);
					}
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheetImage::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcBounds");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->SrcBounds.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteSheet::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesWide");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesWide = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesHigh");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesHigh = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileWidth");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TileWidth = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileHeight");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TileHeight = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SrcFile");
		{
			if (cyborgbear::isString(obj0)) {
				this->SrcFile = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					int i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::stringstream s;
						s << key;
						s >> i;
					}
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImageIdIterator");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ImageIdIterator = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "RecycledImageIds");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->RecycledImageIds.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isInt(obj1)) {
							this->RecycledImageIds[i] = cyborgbear::toInt(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error Image::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteSheet");
		{
			if (cyborgbear::isString(obj0)) {
				this->SpriteSheet = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ImgId");
		{
			if (cyborgbear::isInt(obj0)) {
				this->ImgId = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DefaultSize");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->DefaultSize.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Sprite::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Id");
		{
			if (cyborgbear::isString(obj0)) {
				this->Id = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteClass");
		{
			if (cyborgbear::isString(obj0)) {
				this->SpriteClass = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Motion");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Motion = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Facing");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Facing = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->SpriteType = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Data");
		{
			if (cyborgbear::isString(obj0)) {
				this->Data = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimationSlide::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Interval");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Interval = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Image");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Image.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error AnimLayer::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Point");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Point.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Animation");
		{
			if (cyborgbear::isString(obj0)) {
				this->Animation = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error EditorProfile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FileType");
		{
			if (cyborgbear::isString(obj0)) {
				this->FileType = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PathStartsWith");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->PathStartsWith.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->PathStartsWith[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DefaultPaths");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->DefaultPaths.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->DefaultPaths[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Editor");
		{
			if (cyborgbear::isString(obj0)) {
				this->Editor = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "NewFileMenu");
		{
			if (cyborgbear::isString(obj0)) {
				this->NewFileMenu = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error EditorDockSettings::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Docked");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Docked = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Visible");
		{
			if (cyborgbear::isBool(obj0)) {
				this->Visible = cyborgbear::toBool(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Undocked");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Undocked.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneInstance::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AccessorID");
		{
			if (cyborgbear::isString(obj0)) {
				this->AccessorID = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "ZoneHeader");
		{
			if (cyborgbear::isString(obj0)) {
				this->ZoneHeader = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Address");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Address.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error SpriteClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "AnimLayers");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->AnimLayers.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->AnimLayers[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								{
									cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj2);
									if (cyborgbear::isObj(finalObj)) {
										retval |= this->AnimLayers[i][ii].loadJsonObj(obj2);
									} else {
										if (cyborgbear::isNull(obj2)) {
											retval |= cyborgbear::Error_MissingField;
										} else {
											retval |= cyborgbear::Error_TypeMismatch;
										}
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "SpriteType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->SpriteType = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Attributes");
		{
			if (cyborgbear::isString(obj0)) {
				this->Attributes = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Animation::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->Import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Images");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Images.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Images[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error World::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zones");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Zones.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Zones[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error EditorModule::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Profiles");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Profiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->Profiles[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error EditorSettings::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "DockBounds");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj1);
						if (cyborgbear::isObj(finalObj)) {
							retval |= this->DockBounds[i].loadJsonObj(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "OpenProject");
		{
			if (cyborgbear::isString(obj0)) {
				this->OpenProject = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "OpenFiles");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->OpenFiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->OpenFiles[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "OpenTab");
		{
			if (cyborgbear::isInt(obj0)) {
				this->OpenTab = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error ZoneHeader::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Zone");
		{
			if (cyborgbear::isString(obj0)) {
				this->Zone = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesWide");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesWide = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TilesHigh");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TilesHigh = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Layers");
		{
			if (cyborgbear::isInt(obj0)) {
				this->Layers = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error PersonClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->Import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Title");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Title[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Overhead");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Overhead.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->Overhead[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								{
									cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj2);
									if (cyborgbear::isObj(finalObj)) {
										retval |= this->Overhead[i][ii].loadJsonObj(obj2);
									} else {
										if (cyborgbear::isNull(obj2)) {
											retval |= cyborgbear::Error_MissingField;
										} else {
											retval |= cyborgbear::Error_TypeMismatch;
										}
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "FrontView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->FrontView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "BackView");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->BackView.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Person::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "PersonClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->PersonClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Name");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isObj(obj0)) {
				cyborgbear::JsonObjOut map0 = cyborgbear::toObj(obj0);
				for (cyborgbear::JsonObjIterator it1 = cyborgbear::jsonObjIterator(map0); !cyborgbear::iteratorAtEnd(it1, map0); it1 = cyborgbear::jsonObjIteratorNext(map0,  it1)) {
					string i;
					cyborgbear::JsonValOut obj1 = cyborgbear::iteratorValue(it1);
					{
						std::string key = cyborgbear::toStdString(cyborgbear::jsonObjIteratorKey(it1));
						std::string o;
						std::stringstream s;
						s << key;
						s >> o;
						i = o.c_str();
					}
					{
						if (cyborgbear::isString(obj1)) {
							this->Name[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Creatures");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Creatures.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					{
						if (cyborgbear::isString(obj1)) {
							this->Creatures[i] = cyborgbear::toString(obj1);
						} else {
							if (cyborgbear::isNull(obj1)) {
								retval |= cyborgbear::Error_MissingField;
							} else {
								retval |= cyborgbear::Error_TypeMismatch;
							}
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::Error TileClass::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Import");
		{
			if (cyborgbear::isString(obj0)) {
				this->Import = cyborgbear::toString(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TerrainType");
		{
			if (cyborgbear::isInt(obj0)) {
				this->TerrainType = cyborgbear::toInt(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "LowerAnim");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->LowerAnim.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "UpperAnim");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->UpperAnim.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Tile::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "TileClass");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->TileClass.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Occupant");
		{
			cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj0);
			if (cyborgbear::isObj(finalObj)) {
				retval |= this->Occupant.loadJsonObj(obj0);
			} else {
				if (cyborgbear::isNull(obj0)) {
					retval |= cyborgbear::Error_MissingField;
				} else {
					retval |= cyborgbear::Error_TypeMismatch;
				}
			}
		}
	}
	return retval;
}

cyborgbear::Error Zone::loadJsonObj(cyborgbear::JsonVal in) {
	cyborgbear::Error retval = cyborgbear::Error_Ok;
	cyborgbear::JsonObjOut inObj = cyborgbear::toObj(in);

	{
		cyborgbear::JsonValOut obj0 = cyborgbear::objRead(inObj, "Tiles");
		if (!cyborgbear::isNull(obj0)) {
			if (cyborgbear::isArray(obj0)) {
				cyborgbear::JsonArrayOut array0 = cyborgbear::toArray(obj0);
				unsigned int size = cyborgbear::arraySize(array0);
				this->Tiles.resize(size);
				for (unsigned int i = 0; i < size; i++) {
					cyborgbear::JsonValOut obj1 = cyborgbear::arrayRead(array0, i);
					if (!cyborgbear::isNull(obj1)) {
						if (cyborgbear::isArray(obj1)) {
							cyborgbear::JsonArrayOut array1 = cyborgbear::toArray(obj1);
							unsigned int size = cyborgbear::arraySize(array1);
							this->Tiles[i].resize(size);
							for (unsigned int ii = 0; ii < size; ii++) {
								cyborgbear::JsonValOut obj2 = cyborgbear::arrayRead(array1, ii);
								if (!cyborgbear::isNull(obj2)) {
									if (cyborgbear::isArray(obj2)) {
										cyborgbear::JsonArrayOut array2 = cyborgbear::toArray(obj2);
										unsigned int size = cyborgbear::arraySize(array2);
										this->Tiles[i][ii].resize(size);
										for (unsigned int iii = 0; iii < size; iii++) {
											cyborgbear::JsonValOut obj3 = cyborgbear::arrayRead(array2, iii);
											{
												cyborgbear::JsonValOut finalObj = cyborgbear::toObj(obj3);
												if (cyborgbear::isObj(finalObj)) {
													retval |= this->Tiles[i][ii][iii].loadJsonObj(obj3);
												} else {
													if (cyborgbear::isNull(obj3)) {
														retval |= cyborgbear::Error_MissingField;
													} else {
														retval |= cyborgbear::Error_TypeMismatch;
													}
												}
											}
										}
									} else {
										retval |= cyborgbear::Error_TypeMismatch;
									}
								}
							}
						} else {
							retval |= cyborgbear::Error_TypeMismatch;
						}
					}
				}
			} else {
				retval |= cyborgbear::Error_TypeMismatch;
			}
		}
	}
	return retval;
}

cyborgbear::JsonValOut Point::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->X);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Size::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Bounds::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->X);
		cyborgbear::objSet(obj, "X", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Y);
		cyborgbear::objSet(obj, "Y", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Width);
		cyborgbear::objSet(obj, "Width", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Height);
		cyborgbear::objSet(obj, "Height", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SaveVariables::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (QMap< string, cyborgbear::unknown >::iterator n = this->Vars.begin(); n != this->Vars.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n.key()));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->Vars[n.key()].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Vars", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheetImage::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->SrcBounds.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "SrcBounds", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteSheet::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesWide);
		cyborgbear::objSet(obj, "TilesWide", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesHigh);
		cyborgbear::objSet(obj, "TilesHigh", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TileWidth);
		cyborgbear::objSet(obj, "TileWidth", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TileHeight);
		cyborgbear::objSet(obj, "TileHeight", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SrcFile);
		cyborgbear::objSet(obj, "SrcFile", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (QMap< int, models::SpriteSheetImage >::iterator n = this->Images.begin(); n != this->Images.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << n.key();
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->Images[n.key()].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ImageIdIterator);
		cyborgbear::objSet(obj, "ImageIdIterator", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->RecycledImageIds.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->RecycledImageIds[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "RecycledImageIds", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut Image::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteSheet);
		cyborgbear::objSet(obj, "SpriteSheet", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ImgId);
		cyborgbear::objSet(obj, "ImgId", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->DefaultSize.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "DefaultSize", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Sprite::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Id);
		cyborgbear::objSet(obj, "Id", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteClass);
		cyborgbear::objSet(obj, "SpriteClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Motion);
		cyborgbear::objSet(obj, "Motion", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Facing);
		cyborgbear::objSet(obj, "Facing", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteType);
		cyborgbear::objSet(obj, "SpriteType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Data);
		cyborgbear::objSet(obj, "Data", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut AnimationSlide::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Interval);
		cyborgbear::objSet(obj, "Interval", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Image.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Image", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut AnimLayer::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->Point.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Point", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Animation);
		cyborgbear::objSet(obj, "Animation", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut EditorProfile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->FileType);
		cyborgbear::objSet(obj, "FileType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->PathStartsWith.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->PathStartsWith[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "PathStartsWith", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->DefaultPaths.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->DefaultPaths[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "DefaultPaths", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Editor);
		cyborgbear::objSet(obj, "Editor", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->NewFileMenu);
		cyborgbear::objSet(obj, "NewFileMenu", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut EditorDockSettings::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Docked);
		cyborgbear::objSet(obj, "Docked", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Visible);
		cyborgbear::objSet(obj, "Visible", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Undocked.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Undocked", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneInstance::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->AccessorID);
		cyborgbear::objSet(obj, "AccessorID", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->ZoneHeader);
		cyborgbear::objSet(obj, "ZoneHeader", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Address.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Address", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut SpriteClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->AnimLayers.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->AnimLayers[i].size(); ii++) {
				cyborgbear::JsonValOut obj0 = this->AnimLayers[i][ii].buildJsonObj();
				cyborgbear::JsonValOut out0 = obj0;
				cyborgbear::arrayAdd(out1, out0);
				cyborgbear::decref(out0);
			}
			cyborgbear::arrayAdd(out2, out1);
			cyborgbear::decref(out1);
		}
		cyborgbear::objSet(obj, "AnimLayers", out2);
		cyborgbear::decref(out2);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->SpriteType);
		cyborgbear::objSet(obj, "SpriteType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Attributes);
		cyborgbear::objSet(obj, "Attributes", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Animation::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Images.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Images[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Images", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut World::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Zones.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Zones[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Zones", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut EditorModule::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Profiles.size(); i++) {
			cyborgbear::JsonValOut obj0 = this->Profiles[i].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Profiles", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut EditorSettings::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (QMap< string, models::EditorDockSettings >::iterator n = this->DockBounds.begin(); n != this->DockBounds.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n.key()));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut obj0 = this->DockBounds[n.key()].buildJsonObj();
			cyborgbear::JsonValOut out0 = obj0;
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "DockBounds", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->OpenProject);
		cyborgbear::objSet(obj, "OpenProject", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->OpenFiles.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->OpenFiles[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "OpenFiles", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->OpenTab);
		cyborgbear::objSet(obj, "OpenTab", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut ZoneHeader::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Zone);
		cyborgbear::objSet(obj, "Zone", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesWide);
		cyborgbear::objSet(obj, "TilesWide", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TilesHigh);
		cyborgbear::objSet(obj, "TilesHigh", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Layers);
		cyborgbear::objSet(obj, "Layers", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut PersonClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (QMap< string, string >::iterator n = this->Title.begin(); n != this->Title.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n.key()));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Title[n.key()]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Title", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Overhead.size(); i++) {
			cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->Overhead[i].size(); ii++) {
				cyborgbear::JsonValOut obj0 = this->Overhead[i][ii].buildJsonObj();
				cyborgbear::JsonValOut out0 = obj0;
				cyborgbear::arrayAdd(out1, out0);
				cyborgbear::decref(out0);
			}
			cyborgbear::arrayAdd(out2, out1);
			cyborgbear::decref(out1);
		}
		cyborgbear::objSet(obj, "Overhead", out2);
		cyborgbear::decref(out2);
	}
	{
		cyborgbear::JsonValOut obj0 = this->FrontView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "FrontView", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->BackView.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "BackView", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Person::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->PersonClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "PersonClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonObjOut out1 = cyborgbear::newJsonObj();
		for (QMap< string, string >::iterator n = this->Name.begin(); n != this->Name.end(); ++n) {
			std::stringstream s;
			string key;
			std::string tmp;
			s << cyborgbear::toStdString(cyborgbear::toString(n.key()));
			s >> tmp;
			key = cyborgbear::toString(tmp);
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Name[n.key()]);
			cyborgbear::objSet(out1, key, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Name", out1);
		cyborgbear::decref(out1);
	}
	{
		cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Creatures.size(); i++) {
			cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Creatures[i]);
			cyborgbear::arrayAdd(out1, out0);
			cyborgbear::decref(out0);
		}
		cyborgbear::objSet(obj, "Creatures", out1);
		cyborgbear::decref(out1);
	}
	return obj;
}

cyborgbear::JsonValOut TileClass::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->Import);
		cyborgbear::objSet(obj, "Import", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut out0 = cyborgbear::toJsonVal(this->TerrainType);
		cyborgbear::objSet(obj, "TerrainType", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->LowerAnim.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "LowerAnim", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->UpperAnim.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "UpperAnim", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Tile::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonValOut obj0 = this->TileClass.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "TileClass", out0);
		cyborgbear::decref(out0);
	}
	{
		cyborgbear::JsonValOut obj0 = this->Occupant.buildJsonObj();
		cyborgbear::JsonValOut out0 = obj0;
		cyborgbear::objSet(obj, "Occupant", out0);
		cyborgbear::decref(out0);
	}
	return obj;
}

cyborgbear::JsonValOut Zone::buildJsonObj() {
	cyborgbear::JsonObjOut obj = cyborgbear::newJsonObj();
	{
		cyborgbear::JsonArrayOut out3 = cyborgbear::newJsonArray();
		for (cyborgbear::VectorIterator i = 0; i < this->Tiles.size(); i++) {
			cyborgbear::JsonArrayOut out2 = cyborgbear::newJsonArray();
			for (cyborgbear::VectorIterator ii = 0; ii < this->Tiles[i].size(); ii++) {
				cyborgbear::JsonArrayOut out1 = cyborgbear::newJsonArray();
				for (cyborgbear::VectorIterator iii = 0; iii < this->Tiles[i][ii].size(); iii++) {
					cyborgbear::JsonValOut obj0 = this->Tiles[i][ii][iii].buildJsonObj();
					cyborgbear::JsonValOut out0 = obj0;
					cyborgbear::arrayAdd(out1, out0);
					cyborgbear::decref(out0);
				}
				cyborgbear::arrayAdd(out2, out1);
				cyborgbear::decref(out1);
			}
			cyborgbear::arrayAdd(out3, out2);
			cyborgbear::decref(out2);
		}
		cyborgbear::objSet(obj, "Tiles", out3);
		cyborgbear::decref(out3);
	}
	return obj;
}
bool Point::operator==(const Point &o) const {
	if (X != o.X) return false;
	if (Y != o.Y) return false;

	return true;
}

bool Size::operator==(const Size &o) const {
	if (Width != o.Width) return false;
	if (Height != o.Height) return false;

	return true;
}

bool Bounds::operator==(const Bounds &o) const {
	if (X != o.X) return false;
	if (Y != o.Y) return false;
	if (Width != o.Width) return false;
	if (Height != o.Height) return false;

	return true;
}

bool SaveVariables::operator==(const SaveVariables &o) const {
	if (Vars != o.Vars) return false;

	return true;
}

bool SpriteSheetImage::operator==(const SpriteSheetImage &o) const {
	if (SrcBounds != o.SrcBounds) return false;

	return true;
}

bool SpriteSheet::operator==(const SpriteSheet &o) const {
	if (TilesWide != o.TilesWide) return false;
	if (TilesHigh != o.TilesHigh) return false;
	if (TileWidth != o.TileWidth) return false;
	if (TileHeight != o.TileHeight) return false;
	if (SrcFile != o.SrcFile) return false;
	if (Images != o.Images) return false;
	if (ImageIdIterator != o.ImageIdIterator) return false;
	if (RecycledImageIds != o.RecycledImageIds) return false;

	return true;
}

bool Image::operator==(const Image &o) const {
	if (SpriteSheet != o.SpriteSheet) return false;
	if (ImgId != o.ImgId) return false;
	if (DefaultSize != o.DefaultSize) return false;

	return true;
}

bool Sprite::operator==(const Sprite &o) const {
	if (Id != o.Id) return false;
	if (SpriteClass != o.SpriteClass) return false;
	if (Motion != o.Motion) return false;
	if (Facing != o.Facing) return false;
	if (SpriteType != o.SpriteType) return false;
	if (Data != o.Data) return false;

	return true;
}

bool AnimationSlide::operator==(const AnimationSlide &o) const {
	if (Interval != o.Interval) return false;
	if (Image != o.Image) return false;

	return true;
}

bool AnimLayer::operator==(const AnimLayer &o) const {
	if (Point != o.Point) return false;
	if (Animation != o.Animation) return false;

	return true;
}

bool EditorProfile::operator==(const EditorProfile &o) const {
	if (FileType != o.FileType) return false;
	if (PathStartsWith != o.PathStartsWith) return false;
	if (DefaultPaths != o.DefaultPaths) return false;
	if (Editor != o.Editor) return false;
	if (NewFileMenu != o.NewFileMenu) return false;

	return true;
}

bool EditorDockSettings::operator==(const EditorDockSettings &o) const {
	if (Docked != o.Docked) return false;
	if (Visible != o.Visible) return false;
	if (Undocked != o.Undocked) return false;

	return true;
}

bool ZoneInstance::operator==(const ZoneInstance &o) const {
	if (AccessorID != o.AccessorID) return false;
	if (ZoneHeader != o.ZoneHeader) return false;
	if (Address != o.Address) return false;

	return true;
}

bool SpriteClass::operator==(const SpriteClass &o) const {
	if (AnimLayers != o.AnimLayers) return false;
	if (SpriteType != o.SpriteType) return false;
	if (Attributes != o.Attributes) return false;

	return true;
}

bool Animation::operator==(const Animation &o) const {
	if (Import != o.Import) return false;
	if (Images != o.Images) return false;

	return true;
}

bool World::operator==(const World &o) const {
	if (Zones != o.Zones) return false;

	return true;
}

bool EditorModule::operator==(const EditorModule &o) const {
	if (Profiles != o.Profiles) return false;

	return true;
}

bool EditorSettings::operator==(const EditorSettings &o) const {
	if (DockBounds != o.DockBounds) return false;
	if (OpenProject != o.OpenProject) return false;
	if (OpenFiles != o.OpenFiles) return false;
	if (OpenTab != o.OpenTab) return false;

	return true;
}

bool ZoneHeader::operator==(const ZoneHeader &o) const {
	if (Zone != o.Zone) return false;
	if (TilesWide != o.TilesWide) return false;
	if (TilesHigh != o.TilesHigh) return false;
	if (Layers != o.Layers) return false;

	return true;
}

bool PersonClass::operator==(const PersonClass &o) const {
	if (Import != o.Import) return false;
	if (Title != o.Title) return false;
	if (Overhead != o.Overhead) return false;
	if (FrontView != o.FrontView) return false;
	if (BackView != o.BackView) return false;

	return true;
}

bool Person::operator==(const Person &o) const {
	if (PersonClass != o.PersonClass) return false;
	if (Name != o.Name) return false;
	if (Creatures != o.Creatures) return false;

	return true;
}

bool TileClass::operator==(const TileClass &o) const {
	if (Import != o.Import) return false;
	if (TerrainType != o.TerrainType) return false;
	if (LowerAnim != o.LowerAnim) return false;
	if (UpperAnim != o.UpperAnim) return false;

	return true;
}

bool Tile::operator==(const Tile &o) const {
	if (TileClass != o.TileClass) return false;
	if (Occupant != o.Occupant) return false;

	return true;
}

bool Zone::operator==(const Zone &o) const {
	if (Tiles != o.Tiles) return false;

	return true;
}

bool Point::operator!=(const Point &o) const {
	if (X != o.X) return true;
	if (Y != o.Y) return true;

	return false;
}

bool Size::operator!=(const Size &o) const {
	if (Width != o.Width) return true;
	if (Height != o.Height) return true;

	return false;
}

bool Bounds::operator!=(const Bounds &o) const {
	if (X != o.X) return true;
	if (Y != o.Y) return true;
	if (Width != o.Width) return true;
	if (Height != o.Height) return true;

	return false;
}

bool SaveVariables::operator!=(const SaveVariables &o) const {
	if (Vars != o.Vars) return true;

	return false;
}

bool SpriteSheetImage::operator!=(const SpriteSheetImage &o) const {
	if (SrcBounds != o.SrcBounds) return true;

	return false;
}

bool SpriteSheet::operator!=(const SpriteSheet &o) const {
	if (TilesWide != o.TilesWide) return true;
	if (TilesHigh != o.TilesHigh) return true;
	if (TileWidth != o.TileWidth) return true;
	if (TileHeight != o.TileHeight) return true;
	if (SrcFile != o.SrcFile) return true;
	if (Images != o.Images) return true;
	if (ImageIdIterator != o.ImageIdIterator) return true;
	if (RecycledImageIds != o.RecycledImageIds) return true;

	return false;
}

bool Image::operator!=(const Image &o) const {
	if (SpriteSheet != o.SpriteSheet) return true;
	if (ImgId != o.ImgId) return true;
	if (DefaultSize != o.DefaultSize) return true;

	return false;
}

bool Sprite::operator!=(const Sprite &o) const {
	if (Id != o.Id) return true;
	if (SpriteClass != o.SpriteClass) return true;
	if (Motion != o.Motion) return true;
	if (Facing != o.Facing) return true;
	if (SpriteType != o.SpriteType) return true;
	if (Data != o.Data) return true;

	return false;
}

bool AnimationSlide::operator!=(const AnimationSlide &o) const {
	if (Interval != o.Interval) return true;
	if (Image != o.Image) return true;

	return false;
}

bool AnimLayer::operator!=(const AnimLayer &o) const {
	if (Point != o.Point) return true;
	if (Animation != o.Animation) return true;

	return false;
}

bool EditorProfile::operator!=(const EditorProfile &o) const {
	if (FileType != o.FileType) return true;
	if (PathStartsWith != o.PathStartsWith) return true;
	if (DefaultPaths != o.DefaultPaths) return true;
	if (Editor != o.Editor) return true;
	if (NewFileMenu != o.NewFileMenu) return true;

	return false;
}

bool EditorDockSettings::operator!=(const EditorDockSettings &o) const {
	if (Docked != o.Docked) return true;
	if (Visible != o.Visible) return true;
	if (Undocked != o.Undocked) return true;

	return false;
}

bool ZoneInstance::operator!=(const ZoneInstance &o) const {
	if (AccessorID != o.AccessorID) return true;
	if (ZoneHeader != o.ZoneHeader) return true;
	if (Address != o.Address) return true;

	return false;
}

bool SpriteClass::operator!=(const SpriteClass &o) const {
	if (AnimLayers != o.AnimLayers) return true;
	if (SpriteType != o.SpriteType) return true;
	if (Attributes != o.Attributes) return true;

	return false;
}

bool Animation::operator!=(const Animation &o) const {
	if (Import != o.Import) return true;
	if (Images != o.Images) return true;

	return false;
}

bool World::operator!=(const World &o) const {
	if (Zones != o.Zones) return true;

	return false;
}

bool EditorModule::operator!=(const EditorModule &o) const {
	if (Profiles != o.Profiles) return true;

	return false;
}

bool EditorSettings::operator!=(const EditorSettings &o) const {
	if (DockBounds != o.DockBounds) return true;
	if (OpenProject != o.OpenProject) return true;
	if (OpenFiles != o.OpenFiles) return true;
	if (OpenTab != o.OpenTab) return true;

	return false;
}

bool ZoneHeader::operator!=(const ZoneHeader &o) const {
	if (Zone != o.Zone) return true;
	if (TilesWide != o.TilesWide) return true;
	if (TilesHigh != o.TilesHigh) return true;
	if (Layers != o.Layers) return true;

	return false;
}

bool PersonClass::operator!=(const PersonClass &o) const {
	if (Import != o.Import) return true;
	if (Title != o.Title) return true;
	if (Overhead != o.Overhead) return true;
	if (FrontView != o.FrontView) return true;
	if (BackView != o.BackView) return true;

	return false;
}

bool Person::operator!=(const Person &o) const {
	if (PersonClass != o.PersonClass) return true;
	if (Name != o.Name) return true;
	if (Creatures != o.Creatures) return true;

	return false;
}

bool TileClass::operator!=(const TileClass &o) const {
	if (Import != o.Import) return true;
	if (TerrainType != o.TerrainType) return true;
	if (LowerAnim != o.LowerAnim) return true;
	if (UpperAnim != o.UpperAnim) return true;

	return false;
}

bool Tile::operator!=(const Tile &o) const {
	if (TileClass != o.TileClass) return true;
	if (Occupant != o.Occupant) return true;

	return false;
}

bool Zone::operator!=(const Zone &o) const {
	if (Tiles != o.Tiles) return true;

	return false;
}


namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Point::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Point::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Size::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Size::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Bounds::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Bounds::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SaveVariables::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SaveVariables::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheetImage::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheetImage::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteSheet::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteSheet::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Image::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Image::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Sprite::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Sprite::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimationSlide::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimationSlide::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void AnimLayer::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string AnimLayer::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void EditorProfile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string EditorProfile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void EditorDockSettings::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string EditorDockSettings::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneInstance::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneInstance::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void SpriteClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string SpriteClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Animation::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Animation::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void World::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string World::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void EditorModule::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string EditorModule::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void EditorSettings::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string EditorSettings::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void ZoneHeader::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string ZoneHeader::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void PersonClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string PersonClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Person::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Person::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void TileClass::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string TileClass::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Tile::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Tile::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}

namespace models {

#ifdef CYBORGBEAR_BOOST_ENABLED
void Zone::fromBoostBinary(string dat) {
	std::stringstream in(dat);
	boost::archive::binary_iarchive ia(in);
	ia >> *this;
}

string Zone::toBoostBinary() {
	std::stringstream out;
	{
		boost::archive::binary_oarchive oa(out);
		oa << *this;
	}

	string str;
	while (out.good())
		str += out.get();

	return str;
}
#endif
}
