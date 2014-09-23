#ifndef EDITORCORE_MODELIOMANAGER_HPP
#define EDITORCORE_MODELIOMANAGER_HPP

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

		ModelWrapper(QString model) {
			this->model = model;
		}

	signals:
		void update(QString model);
};

class ModelIoManager: public QObject {
	Q_OBJECT
	private:
		QMap<QString, ModelWrapper*> m_models;

	public:
		QString read(QString path);

		int write(QString path, QString value);

		void connectOnUpdate(QString path, const QObject *receiver, const char *method);

		void disconnectOnUpdate(QString path, const QObject *receiver, const char *method);

	private:
		void updateListeners(QString path, QString value);
};

}

#endif
