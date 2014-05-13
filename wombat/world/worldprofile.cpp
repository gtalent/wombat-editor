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
		if (args.filePath.startsWith(args.projectPath + "World/Tiles/")) {
			return new TileEditor(args);
		}
		return 0;
	});
	p.addDefaultPath("World/Tiles/");
}

}
}
