#include <vector>
#include "globs.hpp"

namespace wombat {
namespace editor {

std::vector<DebugLogger*> debugLoggers;

void addDebugLogger(DebugLogger *logger) {
	debugLoggers.push_back(logger);
}

void logDebug(QString str) {
	for (unsigned i = 0; i < debugLoggers.size(); i++)
		debugLoggers[i]->logDebug(str);
}

}
}
