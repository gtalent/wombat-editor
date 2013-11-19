#ifndef SAVEVARIABLEEDITOR_HPP
#define SAVEVARIABLEEDITOR_HPP

#include <QString>
#include <QDialog>

#include "models/models.hpp"

namespace Ui {
class SaveVariableEditor;
}

using models::cyborgbear::unknown;

class SaveVariableEditor: public QDialog {
	Q_OBJECT


	private:
		Ui::SaveVariableEditor *ui;

	public:
		explicit SaveVariableEditor(QWidget *parent, QString key, unknown val);
		~SaveVariableEditor();
		std::pair<QString, unknown> getVar();

	public slots:
		void updateType(QString);
		void updateValue(unknown);
		unknown getValue();
};

#endif // SAVEVARIABLEEDITOR_HPP
