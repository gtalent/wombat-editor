#include <QComboBox>
#include <QDir>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include "models/models.hpp"
#include "editorcore/editorwidget.hpp"

namespace wombat {
namespace world {

class TileEditor: public editor::EditorWidget {
	Q_OBJECT

	private:
		//COMMANDS
		class Command: public QUndoCommand {
			private:
				TileEditor *m_parent;
				models::Tile m_before;
				models::Tile m_after;

			public:
				Command(TileEditor *parent, models::Tile before, models::Tile after);

				void undo();

				void redo();
		};

	private:
		models::Tile m_model;
		QDir m_projectDir;
		QComboBox *m_upperAnim;
		QComboBox *m_lowerAnim;
		QRadioButton *m_chkLand;
		QRadioButton *m_chkWater;
		QRadioButton *m_chkWaterfall;
		QRadioButton *m_chkWhirlpool;

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

	public slots:
		void updateModel();

	protected:
		void setModel(models::Tile);

	private:
		QLayout *buildGui();

		void loadView();
};

}
}
