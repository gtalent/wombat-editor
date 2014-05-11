#include <QGroupBox>
#include <QPushButton>
#include <QListView>
#include "models/models.hpp"
#include "editorcore/editorwidget.hpp"

namespace wombat {
namespace world {

class TileEditor: public editor::EditorWidget {
	private:
		models::Tile m_model;
		QPushButton *m_addUpper, *m_rmUpper;
		QPushButton *m_addLower, *m_rmLower;
		QListView *m_upperAnims;
		QListView *m_lowerAnims;

	public:
		/**
		 * Constructor
		 * @param args standard EditorWidget arguments
		 */
		TileEditor(editor::EditorWidgetParams args);

		/**
		 * Destructor
		 */
		~TileEditor();

		int saveFile();

	private:
		QGroupBox *buildAnimLayersEditor(QString title, QListView *listView,
													QPushButton **add, QPushButton **rm);
};

}
}
