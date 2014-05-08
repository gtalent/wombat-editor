#ifndef SAVEVARIABLES_H
#define SAVEVARIABLES_H

#include <QString>

#include <QWidget>
#include <QAbstractTableModel>
#include <QTableWidgetItem>
#include <QUndoCommand>

#include "editorcore/editorwidget.hpp"
#include "models/editormodels.hpp"

namespace Ui {
	class SaveVariables;
}

namespace wombat {
namespace savevariables {

class SaveVariables: public editor::EditorWidget {
	Q_OBJECT

	private:

		//COMMANDS
		class AddVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				models::cyborgbear::unknown m_varVal;
				SaveVariables *m_parent;

			public:
				AddVarCommand(SaveVariables *parent, QString name, models::cyborgbear::unknown unk);
				void undo();
				void redo();
		};

		class RemoveVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				models::cyborgbear::unknown m_varVal;
				int m_varTblRow;
				SaveVariables *m_parent;

			public:
				RemoveVarCommand(SaveVariables *parent, QString name, models::cyborgbear::unknown unk);
				void undo();
				void redo();
		};

		class EditVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				QString m_newVarName;
				models::cyborgbear::unknown m_newVal;
				models::cyborgbear::unknown m_oldVal;
				SaveVariables *m_parent;

			public:
				EditVarCommand(SaveVariables *parent, QString name, QString newName, models::cyborgbear::unknown unk);
				void undo();
				void redo();
		};

	private:
		Ui::SaveVariables *ui;
		models::SaveVariables m_file;
	
	public:
		explicit SaveVariables(editor::EditorWidgetParams);
		~SaveVariables();

	protected:
		void addVar(QString name, models::cyborgbear::unknown val);
		void tblInsertVar(int row, QString name, models::cyborgbear::unknown val);
		void setVar(int row, QString name, models::cyborgbear::unknown val);
		void removeVar(int row);

	private:
		int rowOfKey(QString key);

	public slots:
		int saveFile();

	protected slots:
		void addClicked();
		void editCurrentVar();
		void removeClicked();
		void tableClicked(QModelIndex);
};

}
}

#endif // SAVEVARIABLES_H
