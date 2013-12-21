#ifndef NEWPROJECT_HPP
#define NEWPROJECT_HPP

#include <QString>
#include <QDialog>

namespace Ui {
	class NewProject;
}

class NewProject: public QDialog {
	Q_OBJECT
		
	private:
		Ui::NewProject *ui;
		QString strProjectDir;

	public:
		explicit NewProject(QWidget *parent = 0);
		~NewProject();

		QString projectDir();
		
	public slots:
		void accept();
		void browse();
};

#endif // NEWPrOJECT_HPP
