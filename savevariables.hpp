#ifndef SAVEVARIABLES_H
#define SAVEVARIABLES_H

#include <string>
#include <QWidget>
#include <QAbstractTableModel>
#include <QTableWidgetItem>

#include "filetab.hpp"
#include "models/editormodels.hpp"

namespace Ui {
	class SaveVariables;
}

class SaveVariables: public QWidget, public FileTab {
	Q_OBJECT
	class Var: public QAbstractTableModel {
	};
	
	private:
		Ui::SaveVariables *ui;
		QString m_path;
		editormodels::SaveVariables m_file;
	
	public:
		explicit SaveVariables(QString path, QWidget *parent = 0);
		~SaveVariables();
	
	public slots:
		bool saveFile();

	protected slots:
		void addVar(QString name, QString type, QString val);
		void addVar(QString name, modelmaker::unknown *val);
		void addClicked();
		void editCurrentVar();
		void removeClicked();
		void tableClicked(QModelIndex);
};

#endif // SAVEVARIABLES_H
