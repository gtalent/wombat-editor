import QtQuick 2.1
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Controls.Styles 1.1

Item {
	RowLayout {
		anchors.right: parent.right
		anchors.left: parent.left
		anchors.top: parent.top
		anchors.bottom: parent.bottom
		ColumnLayout {
			anchors.right: parent.horizontalCenter
			anchors.left: parent.left
			anchors.top: parent.top
			anchors.bottom: parent.bottom

			// Upper layers
			ColumnLayout {
				anchors.right: parent.right
				anchors.left: parent.left
				anchors.top: parent.top
				anchors.bottom: parent.verticalCenter
				GroupBox {
					title: "Upper Animation Layers"
					anchors.right: parent.right
					anchors.left: parent.left
					anchors.top: parent.top
					anchors.bottom: parent.bottom
					ColumnLayout {
						anchors.right: parent.right
						anchors.left: parent.left
						anchors.top: parent.top
						anchors.bottom: parent.bottom
						TableView {
							id: upperLayers
							anchors.right: parent.right
							anchors.left: parent.left
							anchors.top: parent.top
							anchors.bottom: parent.bottom
							TableViewColumn {
								title: "Animation"
								role:  "animation"
							}
						}
					}
				}
			}

			// Lower layers
			ColumnLayout {
				anchors.right: parent.right
				anchors.left: parent.left
				anchors.top: parent.verticalCenter
				anchors.bottom: parent.bottom
				GroupBox {
					title: "Lower Animation Layers"
					anchors.right: parent.right
					anchors.left: parent.left
					anchors.top: parent.top
					anchors.bottom: parent.bottom
					ColumnLayout {
						anchors.right: parent.right
						anchors.left: parent.left
						anchors.top: parent.top
						anchors.bottom: parent.bottom
						TableView {
							id: lowerLayers
							anchors.right: parent.right
							anchors.left: parent.left
							anchors.top: parent.top
							anchors.bottom: parent.bottom
							TableViewColumn {
								title: "Animation"
								role:  "animation"
							}
						}
					}
				}
			}
		}
	}
}
