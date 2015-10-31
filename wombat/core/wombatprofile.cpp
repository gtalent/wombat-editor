#include <editorcore/genericnewfilemenu.hpp>
#include <editorcore/genericnewfilemenu.hpp>
#include <models/models.hpp>
#include <models/paths.hpp>
#include "spritesheeteditor.hpp"
#include "animationeditor.hpp"
#include "newspritesheet.hpp"
#include "wombatprofile.hpp"

namespace wombat {
namespace core {

using namespace editor;
using models::Path_Animation;
using models::Path_SpriteSheet;

void setupEditorProfile(EditorProfile &profile) {
	// setup animations
	profile.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + models::Path_Animation)) {
			return new AnimationEditor(args);
		}
		return nullptr;
	});
	profile.addNewFileMenuMaker("Animation", [](NewFileMenuParams args) {
		return new GenericNewFileMenu<models::Animation>(args, "New Animation", "Animation");
	});
	profile.addDefaultPath(Path_Animation);

	// setup sprite sheets
	profile.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + Path_SpriteSheet)) {
			return new SpriteSheetEditor(args);
		}
		return nullptr;
	});
	profile.addNewFileMenuMaker("Sprite Sheet", [](NewFileMenuParams args) {
		return new NewSpriteSheet(args);
	});
	profile.addDefaultPath(Path_SpriteSheet);
}

}
}
