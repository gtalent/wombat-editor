#include "savevariables.hpp"

#include "editorcore/editorprofile.hpp"

namespace wombat {
namespace savevariables {

using namespace wombat::editor;

void setupEditorProfile(EditorProfile &p) {
	// setup save variables
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.projectPath + "Misc/SaveVariables.json" == args.filePath) {
			//open save variables tab
			return new SaveVariables(args);
		}
		return 0;
	});
	p.addDefaultPath("Misc/");
	p.addDefaultPath("Misc/SaveVariables.json");
}

}
}
