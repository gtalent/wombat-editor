#include <QString>
#include <QMap>
#include <QGraphicsScene>
#include <QMouseEvent>

class WombatCanvas: public QGraphicsScene {
	private:
		std::function<void(QGraphicsSceneMouseEvent*)> m_clickListener;
	public:
		WombatCanvas(std::function<void(QGraphicsSceneMouseEvent*)> click);
		virtual void mousePressEvent(QGraphicsSceneMouseEvent *e);
};
