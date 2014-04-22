import QtQuick 2.2

Rectangle {
    id: tile
    property int tileWidth: 70
    property string value: ""

    // retourn une chaine vide si 0, sinon la valeur
    function valueToText(value) {
        if (parseInt(value, 10) === 0) {
            return "";
        }
        return value;
    }

    // retourne la couleur en fonction de la valeur
    function valueToColor(value) {
        var v = parseInt(value, 10);
        var color;
        switch(v) {
        case 2:
            color = "#eee4da";
            break;
        case 4:
            color = "#eae0c8";
            break;
        case 8:
            color = "#f59563";
            break;
        case 16:
            color = "#3399ff";
            break;
        case 32:
            color = "#ffa333";
            break;
        case 64:
            color = "#cef030";
            break;
        case 128:
            color = "#e8d8ce";
            break;
        case 256:
            color = "#990303";
            break;
        case 512:
            color = "#6ba5de";
            break;
        case 1024:
            color = "#dcad60";
            break;
        case 2048:
            color = "#b60022";
            break;
        default:
            color = "#cbbeb1";
        }

        return color;
    }

    function fontSize(value) {
        var v = parseInt(value, 10);
        if (v < 1024) {
            return tileWidth / 2.5;
        }
        return tileWidth / 3;
    }

    width: tileWidth
    height: tileWidth
    color: valueToColor(value)
    radius: tileWidth / 14

    Text {
        text: valueToText(value)
        font.pointSize: fontSize(value)
        anchors.centerIn: parent
        color: "black"
    }
}
