#include <QDebug>
#include <QFile>
#include <QTextStream>
#include "modeliomanager.hpp"
#include "misc.hpp"

namespace editor {

// Connection

ModelIoManager::Connection::Connection(QString path, const QObject *receiver, const char *method) {
	m_path = path;
	m_receiver = receiver;
	m_method = method;
}

bool ModelIoManager::Connection::operator<(const Connection &c) const {
	return (m_path < c.m_path) || (m_path == c.m_path && m_receiver < c.m_receiver) ||
	       (m_path == c.m_path && m_receiver == c.m_receiver && m_method < c.m_method);
}


// ModelIoManager

void ModelIoManager::setProjectPath(QString projectPath) {
	m_projectPath = cleanupPath(projectPath);
}

QString ModelIoManager::getProjectPath() {
	return m_projectPath;
}

QString ModelIoManager::read(QString path) {
	return readAbsolutePath(m_projectPath + path);
}

int ModelIoManager::write(QString path, QString value) {
	return writeAbsolutePath(m_projectPath + path, value);
}

QString ModelIoManager::readAbsolutePath(QString path) {
	if (!path.endsWith(MODEL_FILE_EXTENSION)) {
		path += MODEL_FILE_EXTENSION;
	}
	path = cleanupPath(path);
	if (m_models.contains(path)) {
		return m_models[path]->model;
	} else {
		auto content = loadFileAbsolutePath(path);
		return content;
	}
}

int ModelIoManager::writeAbsolutePath(QString path, QString value) {
	if (!path.endsWith(MODEL_FILE_EXTENSION)) {
		path += MODEL_FILE_EXTENSION;
	}
	path = cleanupPath(path);
	QFile file(path);
	file.open(QIODevice::WriteOnly);
	QTextStream(&file) << value;
	file.close();

	updateFile(path, value);

	return 0;
}

void ModelIoManager::updateFile(QString path, QString value) {
	path = cleanupPath(path);
	if (m_models.contains(path)) {
		m_models[path]->model = value;
		emit m_models[path]->update(value);
	}
}

void ModelIoManager::connectOnUpdate(QString path, const QObject *receiver, const char *method) {
	if (!path.endsWith(MODEL_FILE_EXTENSION)) {
		path += MODEL_FILE_EXTENSION;
	}
	path = toAbsolutePath(path);
	Connection conn(path, receiver, method);
	if (!m_onUpdateConnections[conn]) {
		m_onUpdateConnections[conn] = true;
		ModelWrapper *wrapper = nullptr;
		if (m_models.contains(path)) {
			wrapper = m_models[path];
		} else {
			QFile file(path);
			file.open(QIODevice::ReadOnly);
			QTextStream in(&file);
			auto content = in.readAll();

			m_models[path] = wrapper = new ModelWrapper(content);
		}
		wrapper->refCount++;

		QObject::connect(wrapper, SIGNAL(update(QString)), receiver, method);
	}
}

void ModelIoManager::disconnectOnUpdate(QString path, const QObject *receiver, const char *method) {
	if (!path.endsWith(MODEL_FILE_EXTENSION)) {
		path += MODEL_FILE_EXTENSION;
	}
	path = toAbsolutePath(path);
	Connection conn(path, receiver, method);
	m_onUpdateConnections.remove(conn);

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

QString ModelIoManager::loadFileAbsolutePath(QString path) {
	QFile file(path);
	file.open(QIODevice::ReadOnly);
	return QTextStream(&file).readAll();
}

QString ModelIoManager::toAbsolutePath(QString path) {
	return QFileInfo(m_projectPath + path).absoluteFilePath();
}

QString ModelIoManager::cleanupPath(QString path) {
	return QFileInfo(path).absoluteFilePath();
}

}
