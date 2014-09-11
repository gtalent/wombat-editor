#include <editorcore/genericnewfilemenu.hpp>
#include <editorcore/misc.hpp>
#include "tileeditor.hpp"
#include "worldprofile.hpp"

namespace wombat {
namespace world {

using namespace editor;

void setupEditorProfile(EditorProfile &p) {
	// General
	p.addDefaultPath("World/");

	// Tile Editor
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "World/TileClass/")) {
			return new TileEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Tile Class", [](NewFileMenuParams args) -> NewFileMenu* {
		return new editor::GenericNewFileMenu<models::TileClass>(args, "New Tile Class...", "World/TileClass");
	});
	p.addDefaultPath("World/TileClass/");
}

}
}
