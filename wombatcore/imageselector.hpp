#ifndef IMAGESELECTOR_HPP
#define IMAGESELECTOR_HPP

#include <QDialog>
#include <QString>

namespace Ui {
class ImageSelector;
}

class ImageSelector: public QDialog {
	Q_OBJECT

	public:
		explicit ImageSelector(QWidget *parent, QString path);
		~ImageSelector();

	private:
		Ui::ImageSelector *ui;
};

#endif // IMAGESELECTOR_HPP
