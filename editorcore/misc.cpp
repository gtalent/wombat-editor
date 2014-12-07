#include <QVector>
#include "misc.hpp"

namespace editor {

const QString MODEL_FILE_EXTENSION = ".json";

QVector<DebugLogger*> debugLoggers;

void addDebugLogger(DebugLogger *logger) {
	debugLoggers.push_back(logger);
}

void logDebug(QString str) {
	for (auto l : debugLoggers)
		l->logDebug(str);
}

}
