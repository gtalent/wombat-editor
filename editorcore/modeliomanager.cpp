#include <QFile>
#include <QTextStream>
#include <QDebug>
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
	return m_path < c.m_path && m_receiver < c.m_receiver && m_method < c.m_method;
}


// ModelIoManager

void ModelIoManager::setProjectPath(QString projectPath) {
	m_projectPath = cleanupPath(projectPath);
}

QString ModelIoManager::getProjectPath() {
	return m_projectPath;
}

QString ModelIoManager::readAbsolutePath(QString path) {
	path = cleanupPath(path);
	if (m_models.contains(path)) {
		return m_models[path]->model;
	} else {
		auto content = loadFileAbsolutePath(path);
		updateListeners(path, content);
		return content;
	}
}

int ModelIoManager::writeAbsolutePath(QString path, QString value) {
	path = cleanupPath(path);
	QFile file(path);
	file.open(QIODevice::WriteOnly);
	QTextStream(&file) << value;
	file.close();

	updateListeners(path, value);

	return 0;
}

void ModelIoManager::updateListeners(QString path, QString value) {
	path = cleanupPath(path);
	if (m_models.contains(path)) {
		emit m_models[path]->update(value);
	}
}

void ModelIoManager::connectOnUpdate(QString path, const QObject *receiver, const char *method) {
	path = cleanupPath(path);
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

			wrapper = m_models[path] = new ModelWrapper(content);
		}
		wrapper->refCount++;

		QObject::connect(wrapper, SIGNAL(update(QString)), receiver, method);
	}
}

void ModelIoManager::disconnectOnUpdate(QString path, const QObject *receiver, const char *method) {
	path = cleanupPath(path);
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
	return QFileInfo(m_projectPath + "/" + path).absolutePath();
}

QString ModelIoManager::cleanupPath(QString path) {
	return QFileInfo(path).absoluteFilePath();
}

}
