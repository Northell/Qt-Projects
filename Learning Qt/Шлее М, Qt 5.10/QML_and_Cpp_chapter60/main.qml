//import QtQuick 2.8
//Rectangle {
//    color: "lightgreen"
//    width: 100
//    height: 100
//    Text {
//        objectName: "text"
//        anchors.centerIn: parent
//        text: "Hello QML"

//        function setFontSize(newSize)
//        {
//            var info = "PreviousSize=" + font.pixelSize
//            font.pixelSize = newSize
//            return info
//        }
//    }
//}

//import QtQuick 2.8
//import QtQuick.Controls 2.2
//import QtQuick.Window 2.2

//Window
//{
//    visible: true
//    width: 150
//    height: 150
//    Column
//    {
//        anchors.centerIn: parent
//        Button
//        {
//            signal infoCLicked(string str)
//            objectName: "InfoButton"
//            text: "Info"
//            onClicked: infoCLicked("Information")
//        }

//        Button
//        {
//            signal quitClicked()
//            objectName:  "QuitButton"
//            text: "Quit"
//            onClicked: quitClicked()
//        }
//    }
//}


//60.7-60.8
//import QtQuick 2.8
//Rectangle
//{
//    color: myColor
//    width: 200
//    height: 200
//    Text
//    {
//        anchors.centerIn: parent
//        text: myText

//    }
//    ListView
//    {
//        anchors.fill: parent
//        model: myModel
//        delegate: Text {text:model.display}
//    }

//    MouseArea
//    {
//        anchors.fill:parent
//        onPressed: {
//            myWidget.setWindowTitle("Hello from QML");
//            myWidget.slotDisplayDialog();
//        }
//    }
//}

//60.9-60.17

//import QtQuick 2.8
//import QtQuick.Controls 2.2
//import QtQuick.Layouts 1.3
//import com.myinc.Calculation 1.0

//ApplicationWindow
//{
//    title: "Factorial calc"
//    width: 250
//    height: 80
//    visible: true

//    Calculation
//    {
//        id: calc
//    }

//    ColumnLayout
//    {
//        anchors.fill: parent
//        RowLayout {//1. call of an invokable method
//            SpinBox
//            {
//                id: sbx
//                value: 0
//            }
//            Text
//            {
//                text: "Result: " + calc.factorial(sbx.value)
//            }
//    }
//        RowLayout {//2. using of the properties
//            SpinBox
//            {
//                value: 0
//                onValueChanged: calc.input = value
//            }
//            Text
//            {
//                text: "Result: " + calc.result
//            }

//        }
//    }
//}

//60.14-60.17
//import QtQuick 2.8
//import QtQuick.Controls 2.2
//import QtQuick.Window 2.2
//import com.myinc.Ellipse 1.0

//Window
//{
//    title: "PaintElement"
//    visible: true
//    width: 200
//    height: 100

//    Ellipse
//    {
//        anchors.fill: parent
//        color: "blue"
//    }

//}

//60.18-60.23
import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow
{
    title: qsTr("Image Brghtness")
    width: controls.width
    height: controls.height
    visible: true

    Column
    {
        id: controls
        Image
        {
            id: img
            source: "image://brightness/RedGuy;" + sld.brightnessValue
        }
        Slider
        {
            id: sld
            width: img.width
            value: 0.75
            stepSize: 0.01
            property int brightnessValue: (value*255-127)
        }
        Text
        {
            width: img.width
            text:"<h1>Brughtness: " + sld.brightnessValue + "</h1>"
        }
    }
}
