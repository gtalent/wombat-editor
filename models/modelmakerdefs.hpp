//Generated Code

#ifndef MODELMAKERDEFS_HPP
#define MODELMAKERDEFS_HPP

#include <string>
#include <json/json.h>

using std::string;

namespace modelmaker {

class unknown;

class Model {
	friend unknown;
	public:
		bool loadFile(string path);
		void writeFile(string path);
		void load(string json);
		string write();
	protected:
		virtual json_object* buildJsonObj() = 0;
		virtual bool load(json_object *obj) = 0;
};

class unknown: public Model {
	private:
		json_object *m_obj;
	public:
		unknown();
		~unknown();

		bool loaded();
		bool load(json_object *obj);
		json_object* buildJsonObj();

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

#endif
