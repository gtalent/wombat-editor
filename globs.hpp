#ifndef GLOBS_HPP
#define GLOBS_HPP

#include <QString>

class DebugLogger {
	public:
		virtual void logDebug(QString str) = 0;
};

void addDebugLogger(DebugLogger *logger);

void logDebug(QString str);

#endif // GLOBS_HPP
