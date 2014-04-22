import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    Rectangle {
        color: "#baaa9e"
        anchors.fill: parent
        focus: true
        Keys.onPressed: {
          switch (event.key) {
          case Qt.Key_Up:
              board.moveUp();
              break;
          case Qt.Key_Right:
              board.moveRight();
              break;
          case Qt.Key_Down:
              board.moveDown();
              break;
          case Qt.Key_Left:
              board.moveLeft();
              break;
          }
        }

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
}
