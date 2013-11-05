#include "wombatcanvas.hpp"

WombatCanvas::WombatCanvas(std::function<void(QGraphicsSceneMouseEvent*)> click) {
	m_clickListener = click;
}

void WombatCanvas::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	auto click = m_clickListener;
	if (click) {
		click(e);
	}
}
