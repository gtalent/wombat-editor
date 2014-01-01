#include <QVector>
#include "misc.hpp"

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

}
}
