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
	view->setSource(QUrl(path));
	m_layout->addWidget(QWidget::createWindowContainer(view));
}

int QtQuickEditorWidget::saveFile() {
	return 0;
}

}
