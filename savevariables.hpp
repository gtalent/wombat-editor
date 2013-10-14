#ifndef SAVEVARIABLES_H
#define SAVEVARIABLES_H

#include <QString>

#include <QWidget>
#include <QAbstractTableModel>
#include <QTableWidgetItem>
#include <QUndoCommand>

#include "editortab.hpp"
#include "models/enginemodels.hpp"

namespace Ui {
	class SaveVariables;
}

class SaveVariables: public EditorTab {
	Q_OBJECT

	private:

		//COMMANDS
		class AddVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				enginemodels::cyborgbear::unknown *m_varVal;
				SaveVariables *m_parent;

			public:
				AddVarCommand(SaveVariables *parent, QString name, enginemodels::cyborgbear::unknown *unk);
				void undo();
				void redo();
		};

		class RemoveVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				enginemodels::cyborgbear::unknown *m_varVal;
				int m_varTblRow;
				SaveVariables *m_parent;

			public:
				RemoveVarCommand(SaveVariables *parent, QString name, enginemodels::cyborgbear::unknown *unk);
				void undo();
				void redo();
		};

		class EditVarCommand: public QUndoCommand {
			private:
				QString m_varName;
				QString m_newVarName;
				enginemodels::cyborgbear::unknown m_newVal;
				enginemodels::cyborgbear::unknown m_oldVal;
				SaveVariables *m_parent;

			public:
				EditVarCommand(SaveVariables *parent, QString name, QString newName, enginemodels::cyborgbear::unknown *unk);
				void undo();
				void redo();
		};

	private:
		Ui::SaveVariables *ui;
		enginemodels::SaveVariables m_file;
	
	public:
		explicit SaveVariables(QWidget *parent, QString path);
		~SaveVariables();

	protected:
		void addVar(QString name, enginemodels::cyborgbear::unknown *val);
		void tblInsertVar(int row, QString name, enginemodels::cyborgbear::unknown *val);
		void setVar(int row, QString name, enginemodels::cyborgbear::unknown *val);
		void removeVar(int row);

	private:
		int rowOfKey(QString key);

	public slots:
		bool saveFile();

	protected slots:
		void addClicked();
		void editCurrentVar();
		void removeClicked();
		void tableClicked(QModelIndex);
};

#endif // SAVEVARIABLES_H
