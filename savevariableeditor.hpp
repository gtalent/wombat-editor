#ifndef SAVEVARIABLEEDITOR_HPP
#define SAVEVARIABLEEDITOR_HPP

#include <QString>
#include <QDialog>

#include "models/enginemodels.hpp"

namespace Ui {
class SaveVariableEditor;
}

using enginemodels::modelmaker::unknown;

class SaveVariableEditor: public QDialog {
	Q_OBJECT


	private:
		Ui::SaveVariableEditor *ui;

	public:
		explicit SaveVariableEditor(QWidget *parent, QString key = "", unknown *val = 0);
		~SaveVariableEditor();
		std::pair<QString, unknown*> getVar();

	public slots:
		void updateType(QString);
		void updateValue(unknown*);
		unknown* getValue();
};

#endif // SAVEVARIABLEEDITOR_HPP
