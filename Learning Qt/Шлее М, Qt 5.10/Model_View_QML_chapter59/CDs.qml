import QtQuick 2.8
VisualItemModel
{
    Row
    {
        Image
        {
            width: 64
            height: 64
            source: "qrc:/RedGuy"
            smooth: true
        }

        Column
        {
            Text {color: "white"; text: "Evanescence"; font.pointSize: 12}
            Text {color: "lime"; text: "Fallen"; font.pointSize: 10}
            Text {color: "yellow"; text: "2003"; font.pointSize: 8}

        }
    }

    Rectangle
    {
        width: parent.width
        height: 64
        color: "yellow"
        Text
        {
            anchors.centerIn: parent
            color: "Red"
            text: "Blank"
        }
    }
    Row
    {
        Image
        {

            width: 64
            height: 64
            source: "qrc:/Image1"
            smooth: true
        }
        Column
        {
            Text {color: "white"; text: "Tristania"; font.pointSize: 12}
            Text {color: "lime"; text: "Rubicon"; font.pointSize: 10}
            Text {color: "yellow"; text: "2003"; font.pointSize: 8}

        }
    }
}
