#ifndef NEWFILEMENU_HPP
#define NEWFILEMENU_HPP

#include <QDialog>
#include <QString>

namespace wombat {
namespace editor {

class NewFileMenu: public QDialog {
	public:
		NewFileMenu();
		NewFileMenu(QWidget *parent);
		virtual QString path() = 0;
};

}
}

#endif
