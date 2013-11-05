#include <QVector>
#include "globs.hpp"

namespace wombat {
namespace editor {

QVector<DebugLogger*> debugLoggers;

void addDebugLogger(DebugLogger *logger) {
	debugLoggers.push_back(logger);
}

void logDebug(QString str) {
	for (auto l : debugLoggers)
		l->logDebug(str);
}

void writeModel(QString path, models::cyborgbear::Model &model) {
	model.writeJsonFile(path + ".json");
}

}
}
