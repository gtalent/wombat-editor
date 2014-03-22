#include "spritesheeteditor.hpp"
#include "animationeditor.hpp"
#include "newspritesheet.hpp"
#include "newanimation.hpp"

#include "editorcore/editorprofile.hpp"

namespace wombat {
namespace editor {

using namespace wombat::editor;

void setupWombatProfile(EditorProfile &p) {
	// setup animations
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "Animations/")) {
			return new AnimationEditor(args);
		}
		return 0;
	});
	p.addNewFileMenuMaker("Animation", [](NewFileMenuParams args) -> NewFileMenu* {
		if (args.fileType == "Animation") {
			return new NewAnimation(args);
		}
		return 0;
	});
	p.addDefaultPath("Animations/");


	// setup sprite sheets
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "Resources/SpriteSheets/")) {
			return new SpriteSheetEditor(args);
		}
		return 0;
	});
	p.addNewFileMenuMaker("Sprite Sheet", [](NewFileMenuParams args) -> NewFileMenu* {
		if (args.fileType == "Sprite Sheet") {
			return new NewSpriteSheet(args);
		}
		return 0;
	});
	p.addDefaultPath("Resources/");
	p.addDefaultPath("Resources/SpriteSheets/");
}

}
}
