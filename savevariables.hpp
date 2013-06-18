#ifndef SAVEVARIABLES_H
#define SAVEVARIABLES_H

#include <string>
#include <QWidget>
#include <QAbstractTableModel>
#include <QTableWidgetItem>
#include <QUndoCommand>

#include "editortab.hpp"
#include "models/editormodels.hpp"

namespace Ui {
	class SaveVariables;
}

class SaveVariables: public QWidget, public EditorTab {
	Q_OBJECT

	private:

		//COMMANDS
		class AddVarCommand: public QUndoCommand {
			private:
				string m_varName;
				modelmaker::unknown *m_varVal;
				SaveVariables *m_parent;

			public:
				AddVarCommand(SaveVariables *parent, string name, modelmaker::unknown *unk);
				void undo();
				void redo();
		};

		class RemoveVarCommand: public QUndoCommand {
			private:
				string m_varName;
				modelmaker::unknown *m_varVal;
				int m_varTblRow;
				SaveVariables *m_parent;

			public:
				RemoveVarCommand(SaveVariables *parent, string name, modelmaker::unknown *unk);
				void undo();
				void redo();
		};

		class EditVarCommand: public QUndoCommand {
			private:
				string m_varName;
				modelmaker::unknown *m_varVal;
				int m_varTblRow;
				SaveVariables *m_parent;

			public:
				EditVarCommand(SaveVariables *parent, string name, modelmaker::unknown *unk);
				void undo();
				void redo();
		};

	private:
		Ui::SaveVariables *ui;
		QString m_path;
		editormodels::SaveVariables m_file;
	
	public:
		explicit SaveVariables(QString path, QWidget *parent = 0);
		~SaveVariables();

	protected:
		void addVar(string name, modelmaker::unknown *val);
		void insertVar(int row, string name, modelmaker::unknown *val);
		void setVar(int row, string name, modelmaker::unknown *val);

	private:
		int rowOfKey(string key);

	public slots:
		bool saveFile();

	protected slots:
		void removeVar(int row);
		void addClicked();
		void editCurrentVar();
		void removeClicked();
		void tableClicked(QModelIndex);
};

#endif // SAVEVARIABLES_H
