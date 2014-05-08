#ifndef EDITORCORE_MISC_HPP
#define EDITORCORE_MISC_HPP

#include "models/editormodels.hpp"

namespace editor {

class DebugLogger {
	public:
		virtual void logDebug(QString str) = 0;
};

void addDebugLogger(DebugLogger *logger);

void logDebug(QString str);

}

#endif // MISC_HPP
