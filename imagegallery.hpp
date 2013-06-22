#ifndef IMAGEGALLERY_HPP
#define IMAGEGALLERY_HPP

#include <QDialog>

namespace Ui {
class ImageGallery;
}

class ImageGallery : public QDialog
{
		Q_OBJECT
		
	public:
		explicit ImageGallery(QWidget *parent = 0);
		~ImageGallery();
		
	private:
		Ui::ImageGallery *ui;
};

#endif // IMAGEGALLERY_HPP
