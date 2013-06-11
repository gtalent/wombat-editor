#ifndef SAVEVARIABLEEDITOR_HPP
#define SAVEVARIABLEEDITOR_HPP

#include <QDialog>

#include "models/modelmakerdefs.hpp"

using modelmaker::unknown;

namespace Ui {
class SaveVariableEditor;
}

class SaveVariableEditor: public QDialog {
	Q_OBJECT

	private:
		Ui::SaveVariableEditor *ui;

	public:
		explicit SaveVariableEditor(QWidget *parent, unknown *val);
		~SaveVariableEditor();
		std::pair<string, unknown*> getVar();

	public slots:
		void updateType(QString);
		void updateValue(unknown*);
		unknown* getValue();
};

#endif // SAVEVARIABLEEDITOR_HPP
