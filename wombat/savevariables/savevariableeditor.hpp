#ifndef SAVEVARIABLES_SAVEVARIABLEEDITOR_HPP
#define SAVEVARIABLES_SAVEVARIABLEEDITOR_HPP

#include <QString>
#include <QDialog>

#include <models/models.hpp>

namespace Ui {
class SaveVariableEditor;
}

namespace wombat {
namespace savevariables {

using models::cyborgbear::unknown;

class SaveVariableEditor: public QDialog {
	Q_OBJECT

	private:
		Ui::SaveVariableEditor *ui = nullptr;

	public:
		explicit SaveVariableEditor(QWidget *parent, QString key, unknown val);
		~SaveVariableEditor();
		QPair<QString, unknown> getVar();

	public slots:
		void updateType(QString);
		void updateValue(unknown);
		unknown getValue();
};

}
}

#endif // SAVEVARIABLEEDITOR_HPP
