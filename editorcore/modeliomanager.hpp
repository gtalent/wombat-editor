#ifndef EDITORCORE_MODELIOMANAGER_HPP
#define EDITORCORE_MODELIOMANAGER_HPP

#include <QDir>
#include <QObject>
#include <QMap>
#include <QString>
#include <models/editormodels.hpp>

namespace editor {

class ModelWrapper: public QObject {
	Q_OBJECT
	public:
		QString model;
		int refCount = 0;

		ModelWrapper() = default;

		ModelWrapper(QString model, int refCount = 0) {
			this->model = model;
			this->refCount = refCount;
		}

	signals:
		void update(QString model);
};

class ModelIoManager: public QObject {
	private:
		class Connection {
			private:
				QString m_path;
				const QObject *m_receiver = nullptr;
				QString m_method;

			public:
				Connection(QString path, const QObject *receiver, const char *method);

				bool operator<(const Connection &c) const;
		};

		QMap<QString, ModelWrapper*> m_models;
		QMap<Connection, bool> m_onUpdateConnections;
		QString m_projectPath;

	public:
		void setProjectPath(QString projectPath);

		/**
		 * Gets the absolute path of the project of this ModelIoManager.
		 * @return the absolute path of the project of this ModelIoManager.
		 */
		QString getProjectPath();

		/**
		 * Reads all JSON files in the given directory path as Models and
		 * places associates them with their filenames in the returned QMap.
		 */
		template<typename Model>
		QMap<QString, Model> readModels(QString path);

		template<typename Model>
		Model readModelAbsolutePath(QString path);

		template<typename Model>
		Model readModel(QString path);

		QString read(QString path);

		int write(QString path, QString value);

		QString readAbsolutePath(QString path);

		int writeAbsolutePath(QString path, QString value);

		/**
		 * @path relative path from the root of the project directory
		 */
		void connectOnUpdate(QString path, const QObject *receiver, const char *method);

		/**
		 * @path relative path from the root of the project directory
		 */
		void disconnectOnUpdate(QString path, const QObject *receiver, const char *method);

	private:
		void updateFile(QString path, QString value);

		QString loadFileAbsolutePath(QString path);

		QString toAbsolutePath(QString path);

		/**
		 * Returns a cleaned up version the given path,
		 * removing extra slashes, ".."s, etc.
		 */
		QString cleanupPath(QString path);
};

template<typename Model>
QMap<QString, Model> ModelIoManager::readModels(QString path) {
	path += "/";
	path = toAbsolutePath(path);

	QMap<QString, Model> out;
	QDir dir(path);
	auto files = dir.entryInfoList();

	for (auto &file : files) {
		QString json;
		auto filePath = file.absoluteFilePath();
		if (filePath.endsWith(".json")) {
			if (m_models.contains(filePath)) {
				json = m_models[filePath]->model;
			} else {
				json = readAbsolutePath(filePath);
			}
		}
		out[file.fileName()].fromJson(json);
	}

	out.remove(".");
	out.remove("..");
	return out;
}

template<typename Model>
Model ModelIoManager::readModelAbsolutePath(QString path) {
	Model m;
	m.fromJson(readAbsolutePath(path));
	return m;
}

template<typename Model>
Model ModelIoManager::readModel(QString path) {
	return readModelAbsolutePath<Model>(toAbsolutePath(path));
}

}

#endif
