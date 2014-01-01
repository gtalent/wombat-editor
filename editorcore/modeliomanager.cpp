#include <QFile>
#include <QTextStream>
#include "modeliomanager.hpp"
#include "misc.hpp"

namespace wombat {
namespace editor {

QString ModelIoManager::read(QString path) {
	if (m_models.contains(path)) {
		return m_models[path];
	} else {
		QFile file(path);
		file.open(QIODevice::ReadOnly);
		QTextStream in(&file);
		auto content = in.readAll();

		updateListeners(path, content);

		return content;
	}
}

void ModelIoManager::write(QString path, QString value) {
	QFile file(path);
	file.open(QIODevice::WriteOnly);
	QTextStream(&file) << value;
	file.close();
	updateListeners(path, value);
}

void ModelIoManager::updateListeners(QString path, QString value) {
	auto listeners = m_updateListeners[path];
	for (auto l : listeners) {
		l(value);
	}
}

}
}
