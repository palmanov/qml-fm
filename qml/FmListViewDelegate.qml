import QtQuick 2.15

Component {
    id: listViewDelegate

    Item {
        id: fileItem
        height: textMetric.boundingRect.height + 4 // TODO
        width: textMetric.boundingRect.width + 32 // TODO

        Row {
            anchors.fill: parent

            Image {
                source: "image://list_provider/" + model.path
            }

            Text {
                id: listText
                width: parent.width
                text: name
                horizontalAlignment: Text.AlignLeft
            }

            TextMetrics {
                id: textMetric
                font: listText.font
                text: listText.text
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                listView.currentIndex = index
                pathSelectedFile = path
                if (mouse.button == Qt.RightButton)
                    contextMenu.popup()
            }
            onDoubleClicked: {
                if (fileManager.isFile(path))
                    Qt.openUrlExternally("file://" + path)
                else
                    fileSystemModel.cd(path)
            }
        }
    }
}