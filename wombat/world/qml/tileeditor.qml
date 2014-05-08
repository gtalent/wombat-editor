import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

ApplicationWindow {
	SystemPalette {
		id: syspal
	}
	color: syspal.window
	width: 800
	height: 600
	title: "Tile Editor"
	ColumnLayout {
		anchors.left: parent.left
		anchors.right: parent.horizontalCenter
		anchors.top: parent.top
		anchors.bottom: parent.bottom
		Label {
			text: "Upper Animation Layers"
		}
		RowLayout {
			anchors.leftMargin: 15
			TableView {
				Layout.fillWidth: true
				Layout.fillHeight: true
				id: upperLayers
				TableViewColumn {
					title: "Animation"
					role:  "animation"
				}
			}
		}
		Label {
			text: "Lower Animation Layers"
		}
		RowLayout {
			TableView {
				id: lowerLayers
				Layout.fillWidth: true
				Layout.fillHeight: true
				TableViewColumn {
					title: "Animation"
					role:  "animation"
				}
			}
		}
	}
	ColumnLayout {
		anchors.left: parent.horizontalCenter
		anchors.right: parent.right
		anchors.top: parent.top
		anchors.bottom: parent.bottom
	}
}
