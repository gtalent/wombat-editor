#include <editorcore/genericnewfilemenu.hpp>
#include <editorcore/editorprofile.hpp>
#include <editorcore/misc.hpp>
#include <models/paths.hpp>
#include "tileclassexplorer.hpp"
#include "tileclasseditor.hpp"
#include "zoneeditor.hpp"
#include "worldprofile.hpp"

namespace wombat {
namespace world {

using namespace editor;
using models::Path_TileClass;
using models::Path_Zone;
using models::Path_ZoneHeader;

void setupEditorProfile(EditorProfile &p) {
	// General
	p.addDefaultPath("World/");

	// Tile Editor
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + Path_TileClass)) {
			return new TileClassEditor(args);
		}
		return nullptr;
	});
	p.addNewFileMenuMaker("Tile Class", [](NewFileMenuParams args) {
		return new editor::GenericNewFileMenu<models::TileClass>(args, "New Tile Class", Path_TileClass);
	});
	p.addDefaultPath(Path_TileClass);

	// TileClass Explorer
	p.addDockMaker<TileClassExplorer>();

	// Zone
	p.addNewFileMenuMaker("Zone", [](NewFileMenuParams args) {
		return new editor::GenericNewFileMenu<models::Zone>(args, "New Zone", Path_Zone);
	});
	p.addEditorWidgetMaker([](EditorWidgetParams args) -> EditorWidget* {
		if (args.filePath.startsWith(args.projectPath + Path_ZoneHeader)) {
			return new ZoneEditor(args);
		}
		return nullptr;
	});
	p.addDefaultPath(Path_Zone);
	p.addDefaultPath(Path_ZoneHeader);
}

}
}
