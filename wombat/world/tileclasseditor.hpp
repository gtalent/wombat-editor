#ifndef WOMBAT_WORLD_TILEEDITOR_HPP
#define WOMBAT_WORLD_TILEEDITOR_HPP

#include <QComboBox>
#include <QDir>
#include <QGroupBox>
#include <QPushButton>
#include <QRadioButton>
#include <models/models.hpp>
#include <editorcore/editorwidget.hpp>

namespace wombat {
namespace world {

class TileClassEditor: public editor::EditorWidget {
	Q_OBJECT

	private:
		// Commands
		class Command: public QUndoCommand {
			private:
				TileClassEditor *m_parent;
				models::TileClass m_before;
				models::TileClass m_after;

			public:
				Command(TileClassEditor *parent, models::TileClass before, models::TileClass after);

				void undo();

				void redo();
		};

	private:
		models::TileClass m_model;
		QDir m_animDir;
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
		TileClassEditor(editor::EditorWidgetParams args);

		/**
		 * Destructor
		 */
		~TileClassEditor();

		int saveFile();

	public slots:
		void updateModel();

	protected:
		void setModel(models::TileClass);

	private:
		QLayout *buildGui();

		void loadView();
};

}
}

#endif
