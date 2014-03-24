#ifndef MISC_HPP
#define MISC_HPP

#include "models/editormodels.hpp"

namespace wombat {
namespace editor {

class DebugLogger {
	public:
		virtual void logDebug(QString str) = 0;
};

void addDebugLogger(DebugLogger *logger);

void logDebug(QString str);

}
}

#endif // MISC_HPP
