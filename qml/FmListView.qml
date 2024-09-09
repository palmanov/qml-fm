import QtQuick 2.15

ListView {
    id: listView
    anchors.fill: parent

    model: fileSystemModel
    delegate: FmListViewDelegate {}
    highlight: Rectangle { color: "lightsteelblue"; radius: 5 }

    flickableChildren: MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onClicked: {
            listView.currentIndex = -1
            pathSelectedFile = ""
            if (mouse.button == Qt.RightButton)
                contextMenu1.popup()
        }
    }

    Component.onCompleted: currentIndex = -1
}
