#ifndef ANIMATIONEDITOR_HPP
#define ANIMATIONEDITOR_HPP

#include <QWidget>

#include "models/editormodels.hpp"

#include "editorcore/editorwidget.hpp"
#include "editorcore/editorwidgetparams.hpp"

namespace Ui {
class AnimationEditor;
}

namespace wombat {
namespace editor {

using namespace wombat::editor;

class AnimationEditor: public EditorWidget {
	Q_OBJECT

	private:
		QString m_projectPath;

	public:
		explicit AnimationEditor(EditorWidgetParams);
		~AnimationEditor();
		bool saveFile();

	public slots:
		void addBtnClick();

	private:
		Ui::AnimationEditor *ui;
};

}
}

#endif // ANIMATIONEDITOR_HPP
