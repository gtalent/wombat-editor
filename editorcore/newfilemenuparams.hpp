#ifndef NEWFILEMENUPARAMS_HPP
#define NEWFILEMENUPARAMS_HPP

#include <QString>
#include <QWidget>

namespace wombat {
namespace editor {

struct NewFileMenuParams {
	QString projectPath;
	QString fileType;
	QWidget *parent;
};

}
}

#endif
