#include <editorcore/genericnewfilemenu.hpp>
#include "spritesheeteditor.hpp"
#include "animationeditor.hpp"
#include "newspritesheet.hpp"

#include "editorcore/editorprofile.hpp"

namespace wombat {
namespace core {

using namespace editor;

void setupEditorProfile(EditorProfile &p) {
	// setup animations
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "Animation/")) {
			return new AnimationEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Animation", [](NewFileMenuParams args) -> NewFileMenu* {
		return new GenericNewFileMenu<models::Animation>(args, "New Animation", "Animation");
	});
	p.addDefaultPath("Animation/");


	// setup sprite sheets
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "Resources/SpriteSheets/")) {
			return new SpriteSheetEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Sprite Sheet", [](NewFileMenuParams args) -> NewFileMenu* {
		return new NewSpriteSheet(args);
	});
	p.addDefaultPath("Resources/");
	p.addDefaultPath("Resources/SpriteSheets/");
}

}
}
