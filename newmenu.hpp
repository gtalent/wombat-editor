#ifndef NEWMENU_HPP
#define NEWMENU_HPP

#include <QString>
#include <QDialog>

namespace Ui {
class NewMenu;
}

class NewMenu : public QDialog {
		Q_OBJECT

	public:
		explicit NewMenu(QWidget *parent = 0, QString projectDir = "");
		~NewMenu();

	private:
		Ui::NewMenu *ui;

	public slots:
		void accept();
};

#endif // NEWMENU_HPP
