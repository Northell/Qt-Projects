//Листинг 53.1 Созданный QML Код

import QtQuick 2.12
import QtQuick.Window 2.12

Window //Item  //Если не запускается слой вместо Window
     {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MouseArea {
        anchors.fill: parent
        onClicked:
        {
            console.log(qsTr('Clicked on backgruond. Text: "' + textEdit.text + '"'))

        }
    }
    TextEdit
    {
        id: textEdit
        text: qsTr("Enter some text...")
        verticalAlignment: Text.AlignVCenter
        anchors.horizontalCenterOffset: 2
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        Rectangle
        {
            anchors.fill: parent
            anchors.margins: -10
            color: "transparent"
            border.width: 1
        }
    }
}
