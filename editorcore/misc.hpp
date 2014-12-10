#ifndef EDITORCORE_MISC_HPP
#define EDITORCORE_MISC_HPP

#include <models/models.hpp>

namespace editor {

extern const QString MODEL_FILE_EXTENSION;

class DebugLogger {
	public:
		virtual void logDebug(QString str) = 0;
};

void addDebugLogger(DebugLogger *logger);

void logDebug(QString str);

}

#endif
