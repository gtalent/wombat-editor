#include <QFile>
#include <QTextStream>
#include "modeliomanager.hpp"
#include "misc.hpp"

namespace editor {

QString ModelIoManager::readAbsolutePath(QString path) {
	if (m_models.contains(path)) {
		return m_models[path]->model;
	} else {
		QFile file(path);
		file.open(QIODevice::ReadOnly);
		QTextStream in(&file);
		auto content = in.readAll();

		updateListeners(path, content);

		return content;
	}
}

int ModelIoManager::writeAbsolutePath(QString path, QString value) {
	QFile file(path);
	file.open(QIODevice::WriteOnly);
	QTextStream(&file) << value;
	file.close();

	updateListeners(path, value);

	return 0;
}

void ModelIoManager::updateListeners(QString path, QString value) {
	if (m_models.contains(path)) {
		emit m_models[path]->update(value);
	}
}

void ModelIoManager::connectOnUpdate(QString path, const QObject *receiver, const char *method) {
	ModelWrapper *wrapper;
	if (m_models.contains(path)) {
		wrapper = m_models[path];
	} else {
		QFile file(path);
		file.open(QIODevice::ReadOnly);
		QTextStream in(&file);
		auto content = in.readAll();

		wrapper = m_models[path] = new ModelWrapper(content);
	}
	wrapper->refCount++;
	QObject::connect(wrapper, SIGNAL(update(QString)), receiver, method);
}

void ModelIoManager::disconnectOnUpdate(QString path, const QObject *receiver, const char *method) {
	if (m_models.contains(path)) {
		auto wrapper = m_models[path];
		QObject::disconnect(wrapper, SIGNAL(update(QString)), receiver, method);
		wrapper->refCount--;

		if (wrapper->refCount < 1) {
			m_models.remove(path);
			delete wrapper;
		}
	}
}

}
