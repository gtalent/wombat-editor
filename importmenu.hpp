#ifndef IMPORTMENU_HPP
#define IMPORTMENU_HPP

#include <QDialog>

namespace Ui {
	class ImportMenu;
}

class ImportMenu: public QDialog {
	Q_OBJECT

	public:
		explicit ImportMenu(QWidget *parent = 0);
		~ImportMenu();

		QString importWhat();
	private:
		Ui::ImportMenu *ui;

		QString strImportWhat;
};

#endif // IMPORTMENU_HPP
