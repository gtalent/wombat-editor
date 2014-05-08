#ifndef EDITORCORE_NEWFILEMENU_HPP
#define EDITORCORE_NEWFILEMENU_HPP

#include <QDialog>
#include <QString>
#include "newfilemenuparams.hpp"

namespace editor {

class NewFileMenu: public QDialog {
	public:
		NewFileMenu(NewFileMenuParams);
		NewFileMenu(QWidget *parent);
		virtual QString path() = 0;
};

}

#endif
