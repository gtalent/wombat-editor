#ifndef ANIMATIONEDITOR_HPP
#define ANIMATIONEDITOR_HPP

#include <QWidget>

namespace Ui {
class AnimationEditor;
}

class AnimationEditor: public QWidget {
		Q_OBJECT
		
	public:
		explicit AnimationEditor(QWidget *parent = 0);
		~AnimationEditor();
		
	private:
		Ui::AnimationEditor *ui;
};

#endif // ANIMATIONEDITOR_HPP
