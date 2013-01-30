#ifndef NEWPORJECT_HPP
#define NEWPORJECT_HPP

#include <QDialog>

namespace Ui {
class NewProject;
}

class NewProject : public QDialog {
		Q_OBJECT
		
	public:
		explicit NewProject(QWidget *parent = 0);
		~NewProject();
		
	private:
		Ui::NewProject *ui;

	public slots:
		void accept();
};

#endif // NEWPORJECT_HPP
