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

void setupEditorProfile(editor::EditorProfile &p) {
	// setup animations
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + models::Path_Animation)) {
			return new AnimationEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Animation", [](NewFileMenuParams args) {
		return new GenericNewFileMenu<models::Animation>(args, "New Animation", "Animation");
	});
	p.addDefaultPath(Path_Animation);


	// setup sprite sheets
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + Path_SpriteSheet)) {
			return new SpriteSheetEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Sprite Sheet", [](NewFileMenuParams args) {
		return new NewSpriteSheet(args);
	});
	p.addDefaultPath(Path_SpriteSheet);
}

}
}
