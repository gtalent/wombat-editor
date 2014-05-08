#include <QString>
#include <QQmlContext>
#include <QQuickView>
#include <QUrl>
#include "qtquickeditorwidget.hpp"

namespace editor {

QtQuickEditorWidget::QtQuickEditorWidget(QString path, EditorWidgetParams args):
	EditorWidget(args) {
	m_layout = new QGridLayout(this);

	auto *view = new QQuickView();
	auto context = view->rootContext();
	context->setContextProperty("modelio", args.models);
	context->setContextProperty("signals", &m_signaler);
	view->setSource(QUrl(path));
	m_layout->addWidget(QWidget::createWindowContainer(view));
}

int QtQuickEditorWidget::saveFile() {
	emit m_signaler.saveFile();
	return 0;
}

}
