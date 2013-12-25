#ifndef ANIMATIONEDITOR_HPP
#define ANIMATIONEDITOR_HPP

#include <QWidget>


#include "models/editormodels.hpp"

#include "editorcore/editortab.hpp"

namespace Ui {
class AnimationEditor;
}

class AnimationEditor: public EditorTab {
	Q_OBJECT

	public:
		explicit AnimationEditor(QWidget *parent, QString path);
		~AnimationEditor();

	private:
		Ui::AnimationEditor *ui;
};

#endif // ANIMATIONEDITOR_HPP
