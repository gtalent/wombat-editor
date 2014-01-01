#include "spritesheeteditor.hpp"
#include "newspritesheet.hpp"

#include "savevariables.hpp"

#include "editorcore/editorprofile.hpp"

namespace wombat {
namespace editor {

void setupWombatProfile(EditorProfile &p) {
	// setup sprite sheets
	p.addEditorTabMaker([](EditorTabParams args) -> EditorTab* {
		if (args.filePath.startsWith(args.projectPath + "Resources/SpriteSheets/")) {
			return new SpriteSheetEditor(args);
		}
		return 0;
	});
	p.addNewFileMenuMaker("Sprite Sheet", [](NewFileMenuParams args) -> NewFileMenu* {
		if (args.fileType == "Sprite Sheet") {
			return new NewSpriteSheet(args.projectPath, args.parent);
		}
		return 0;
	});
	p.addDefaultPath("Resources/SpriteSheets");

	// setup save variables
	p.addEditorTabMaker([](EditorTabParams args) {
		EditorTab *tab = 0;
		if (args.projectPath + "Misc/SaveVariables.json" == args.filePath) {
			//open save variables tab
			tab = new SaveVariables(args);
		}
		return tab;
	});
	p.addDefaultPath("Misc");
	p.addDefaultPath("Misc/SaveVariables.json");
}

}
}
