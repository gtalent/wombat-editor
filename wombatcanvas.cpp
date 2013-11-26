#include "wombatcanvas.hpp"

WombatCanvas::WombatCanvas(QWidget *w, std::function<void(QMouseEvent*)> click): QGraphicsView(w) {
	m_clickListener = click;
}

void WombatCanvas::mousePressEvent(QMouseEvent *e) {
	m_clickListener(e);
}
