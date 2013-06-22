#ifndef IMPORTMENU_HPP
#define IMPORTMENU_HPP

#include <QDialog>
#include <QString>

namespace Ui {
	class ImportMenu;
}

class ImportMenu: public QDialog {
	Q_OBJECT
	private:
		Ui::ImportMenu *ui;

		QString m_projectDir;

	public:
		explicit ImportMenu(QWidget *parent, QString projectDir);
		~ImportMenu();

		void run();
};

#endif // IMPORTMENU_HPP
