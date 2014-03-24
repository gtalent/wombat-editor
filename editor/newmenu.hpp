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
		explicit NewMenu(QWidget *parent, QString projectDir, QVector<QString> itemTypes);
		~NewMenu();

		/**
		 * @brief newWhat returns what the user wants to make a new instance of
		 * @return what the user wants to make a new instance of
		 */
		QString newWhat();

	private:
		Ui::NewMenu *ui;
		QString strNewWhat;

	public slots:
		void accept();
};

#endif // NEWMENU_HPP
