import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    color: "#baaa9e"
    Grid {
        y: 10
        anchors.horizontalCenter: parent.horizontalCenter
        rows: 4
        columns: 4
        spacing: 10

        Repeater {
            model: board
            delegate: Tile {
                value: display
            }
        }
    }
}
