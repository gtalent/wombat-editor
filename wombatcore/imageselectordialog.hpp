#ifndef IMAGESELECTORDIALOG_HPP
#define IMAGESELECTORDIALOG_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class ImageSelectorDialog;
}

class ImageSelectorDialog: public QDialog {
	Q_OBJECT

	public:
		explicit ImageSelectorDialog(QWidget *parent, QString path);
		~ImageSelectorDialog();

	private:
		Ui::ImageSelectorDialog *ui;
};

#endif // IMAGESELECTOR_HPP
