import QtQuick 2.0

BorderImage
{
    property alias text:txt.text
    signal clicked;
    property bool clicked;

    source: "qrc:/RedGuy"

    border {left: 15; top:12; right: 15; bottom: 12}

    Text
    {
        id:txt
        color: "white"
        anchors.centerIn: parent
    }

    MouseArea
    {
        anchors.fill: parent;

        onPressed:
        {
            parent.source = "qrc:/Image1"
            parent.clicked = false;
        }
        onReleased:
        {
            parent.source = "qrc:/RedGuy"
            parent.clicked = true
        }
    }
}
