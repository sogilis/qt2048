import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Layouts 1.1

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

        ColumnLayout {
            anchors.fill: parent
            RowLayout {
                Text {
                    text: {
                        if (board.win) {
                            return "YOU WIN!"
                        } else if (board.gameEnded) {
                            return "GAME OVER";
                        } else {
                            return "";
                        }
                    }
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: 30
                    font.family: "Verdana"
                    Layout.fillWidth: true
                }
                Text {
                    text: board.score
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: 30
                    font.family: "Verdana"
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
}
