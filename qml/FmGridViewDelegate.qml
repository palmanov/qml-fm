import QtQuick 2.15

Component {
    id: gridViewDelegate

    Item {
        id: fileItem
        width: grid.cellWidth - 8
        height: grid.cellHeight - 8

        Column {
            anchors.fill: parent

            Image {
                source: "image://provider/" + model.path
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                width: parent.width
                anchors.left: parent.left
                anchors.right: parent.right
                text: name
                horizontalAlignment: Text.AlignHCenter
                elide: Text.ElideRight
                wrapMode: (grid.currentIndex == index) ? Text.WrapAnywhere : Text.NoWrap
            }
        }

        MouseArea {
            anchors.fill: parent
            acceptedButtons: Qt.LeftButton | Qt.RightButton
            onClicked: {
                grid.currentIndex = index
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
