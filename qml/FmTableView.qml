import QtQuick 2.0
import QtQuick.Controls 1.4
import com.example.filemanager 1.0

TableView {
    id: tableView

    model: fileSystemModel

    TableViewColumn {
        role: "name"
        title: qsTr("Название")
    }

    TableViewColumn {
        role: "type"
        title: qsTr("Тип")
    }

    TableViewColumn {
        role: "size"
        title: qsTr("Размер")
    }

    TableViewColumn {
        role: "modifed"
        title: qsTr("Изменен")
    }

    onDoubleClicked: {
        var idx = fileSystemModel.index(row, 0)
        fileSystemModel.cd(fileSystemModel.data(idx, FileSystemModel.PathRole))
    }
}
