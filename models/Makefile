generate: editormodels.hpp enginemodels.hpp

clean:
	rm -f enginemodels.cpp enginemodels.hpp editormodels.cpp\
		editormodels.hpp modelmakerdefs.cpp modelmakerdefs.hpp

editormodels.hpp: editormodels.mod
	modelmaker -i editormodels.mod -o editormodels -n editormodels
enginemodels.hpp: enginemodels.mod
	modelmaker -i enginemodels.mod -o enginemodels -n enginemodels
