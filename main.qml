import QtQuick 2.2
import QtQuick.Window 2.1
import QtQuick.Layouts 1.1

Window {
    id: main
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
                    font.pointSize: Math.min(main.width, main.height) / 12
                    font.family: "Verdana"
                    Layout.fillWidth: true
                }
                Text {
                    text: board.score
                    color: "#f3eaea"
                    opacity: 0.3
                    font.pointSize: Math.min(main.width, main.height) / 12
                    font.family: "Verdana"
                }
            }
            Rectangle {
                id: mainBoard
                Layout.fillHeight: true
                Layout.fillWidth: true

                function step() {
                    return Math.min(mainBoard.width, mainBoard.height) / 33;
                }

                width: 330
                height: 330
                color: "#baaa9e"

                Grid {
                    y: mainBoard.step()
                    anchors.horizontalCenter: parent.horizontalCenter
                    rows: 4
                    columns: 4
                    spacing: mainBoard.step()

                    Repeater {
                        id: boardRepeater
                        model: board
                        delegate: Tile {
                            value: display
                            tileWidth: mainBoard.step() * 7
                        }
                    }
                }
            }
        }
    }
}
