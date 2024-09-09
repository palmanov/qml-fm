import QtQuick 2.15

GridView {
    id: grid
    anchors.fill: parent
    anchors.margins: 2 * 4 + 4

    model: fileSystemModel
    cellWidth: 96; cellHeight: 96
    delegate: FmGridViewDelegate {}
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

    flickableChildren: MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            grid.currentIndex = -1
            pathSelectedFile = ""
            if (mouse.button == Qt.RightButton)
                contextMenu1.popup()
        }
    }

    Component.onCompleted: currentIndex = -1
}
