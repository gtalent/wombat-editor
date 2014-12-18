#ifndef EDITORCORE_MODELIOMANAGER_HPP
#define EDITORCORE_MODELIOMANAGER_HPP

#include <QDir>
#include <QObject>
#include <QMap>
#include <QString>
#include <editorcore/misc.hpp>
#include <models/models.hpp>

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
	public:
		class Connection {
			private:
				ModelIoManager *m_parent = nullptr;
				QString m_path;
				const QObject *m_receiver = nullptr;
				QString m_method;

			public:
				Connection() = default;

				Connection(ModelIoManager *parent, QString path, const QObject *receiver, const char *method);

				bool operator<(const Connection &c) const;

				void disconnect();
		};

		mutable QMap<QString, ModelWrapper*> m_models;
		mutable QMap<Connection, bool> m_onUpdateConnections;
		// trick needed to access this in a mutable manner in non-const methods
		mutable ModelIoManager *m_me = this;
		QString m_projectPath;

	private:
		ModelIoManager(const ModelIoManager&);
		ModelIoManager &operator=(const ModelIoManager&);

	public:
		ModelIoManager() = default;

		void setProjectPath(QString projectPath);

		/**
		 * Gets the absolute path of the project of this ModelIoManager.
		 * @return the absolute path of the project of this ModelIoManager.
		 */
		QString getProjectPath() const;

		/**
		 * Reads all JSON files in the given directory path as Models and
		 * places associates them with their filenames in the returned QMap.
		 */
		template<typename Model>
		QMap<QString, Model> readModels(QString path) const;

		template<typename Model>
		Model readModelAbsolutePath(QString path) const;

		template<typename Model>
		Model readModel(QString path) const;

		QString read(QString path) const;

		int write(QString path, QString value) const;

		QString readAbsolutePath(QString path) const;

		int writeAbsolutePath(QString path, QString value) const;

		/**
		 * @path relative path from the root of the project directory
		 */
		Connection connectOnUpdate(QString path, const QObject *receiver, const char *method) const;

		/**
		 * @path relative path from the root of the project directory
		 */
		void disconnectOnUpdate(QString path, const QObject *receiver, const char *method) const;

	private:
		void updateFile(QString path, QString value) const;

		QString loadFileAbsolutePath(QString path) const;

		QString toAbsolutePath(QString path) const;

		/**
		 * Returns a cleaned up version the given path,
		 * removing extra slashes, ".."s, etc.
		 */
		QString cleanupPath(QString path) const;
};

template<typename Model>
QMap<QString, Model> ModelIoManager::readModels(QString path) const {
	path += "/";
	path = toAbsolutePath(path);

	QMap<QString, Model> out;
	QDir dir(path);
	auto files = dir.entryInfoList();

	for (auto &file : files) {
		QString json;
		auto filePath = file.absoluteFilePath();
		if (filePath.endsWith(MODEL_FILE_EXTENSION)) {
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
Model ModelIoManager::readModelAbsolutePath(QString path) const {
	Model m;
	m.fromJson(readAbsolutePath(path));
	return m;
}

template<typename Model>
Model ModelIoManager::readModel(QString path) const {
	return readModelAbsolutePath<Model>(toAbsolutePath(path));
}

}

#endif
