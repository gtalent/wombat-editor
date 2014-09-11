#ifndef EDITORCORE_NEWFILEMENUPARAMS_HPP
#define EDITORCORE_NEWFILEMENUPARAMS_HPP

#include <QString>
#include <QWidget>

namespace editor {

struct NewFileMenuParams {
	QString projectPath;
	QString fileType;
	QString appTitle;
	QWidget *parent;
};

}

#endif
