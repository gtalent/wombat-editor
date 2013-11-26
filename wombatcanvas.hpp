#include <QString>
#include <QMap>
#include <QGraphicsView>
#include <QMouseEvent>

class WombatCanvas: public QGraphicsView {
	private:
		std::function<void(QMouseEvent*)> m_clickListener;
	public:
		WombatCanvas(QWidget *w, std::function<void(QMouseEvent*)> click);
		virtual void mousePressEvent(QMouseEvent *e);
};
