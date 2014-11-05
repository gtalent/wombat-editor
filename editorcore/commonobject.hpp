#ifndef EDITORCORE_COMMONOBJECT_HPP
#define EDITORCORE_COMMONOBJECT_HPP

#include <QString>

namespace editor {

/**
 * Used to allow sharing of certain objects, such as dock widgets.
 */
class CommonObject {
	public:
		virtual QString objectId() const;
};

}

#endif
