#include <editorcore/genericnewfilemenu.hpp>
#include <editorcore/editorprofile.hpp>
#include <editorcore/misc.hpp>
#include "tileclassexplorer.hpp"
#include "tileclasseditor.hpp"
#include "zoneeditor.hpp"
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
			return new TileClassEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Tile Class", [](NewFileMenuParams args) -> NewFileMenu* {
		return new editor::GenericNewFileMenu<models::TileClass>(args, "New Tile Class", "World/TileClass");
	});
	p.addDefaultPath("World/TileClass/");

	// TileClass Explorer
	p.addDockMaker<TileClassExplorer>();

	// Zone
	p.addNewFileMenuMaker("Zone", [](NewFileMenuParams args) -> NewFileMenu* {
		return new editor::GenericNewFileMenu<models::Zone>(args, "New Zone", "World/Zone");
	});
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + "World/ZoneHeader/")) {
			return new ZoneEditor(args);
		}
		return nullptr;
	});
	p.addDefaultPath("World/Zone/");
	p.addDefaultPath("World/ZoneHeader/");
}

}
}
