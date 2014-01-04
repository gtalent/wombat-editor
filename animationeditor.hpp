#ifndef ANIMATIONEDITOR_HPP
#define ANIMATIONEDITOR_HPP

#include <QWidget>


#include "models/editormodels.hpp"

#include "editorcore/editortab.hpp"
#include "editorcore/editortabparams.hpp"

namespace Ui {
class AnimationEditor;
}

namespace wombat {
namespace editor {

class AnimationEditor: public EditorTab {
	Q_OBJECT

	public:
		explicit AnimationEditor(EditorTabParams);
		~AnimationEditor();
		bool saveFile();

	private:
		Ui::AnimationEditor *ui;
};

}
}

#endif // ANIMATIONEDITOR_HPP
