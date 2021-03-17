//Листинг 54.1-54.2 Отображение потомка

/*
import QtQuick 2.12
import QtQuick.Window 2.12

Window
{
    visible: true
    width: 640
    height: 480
    title: qsTr("elements")


    Item {
        id: rectangle
        width: 360
        height: 360

        Rectangle
        {
            color: "darkkhaki"
            x: 100
            y: 50
            width: 170
            height: 200
            border.color: "darkgreen"
            border.width: 10
            radius: 40
            smooth: true
        }
    }

}
*/

//Листинг 54.3 Использование свойство parent и id

import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5 // 54.11
import QtQuick.Dialogs 1.2  // 54.12 Не робит

Window
{
    visible: true

    title: qsTr("elements")

//    Item
//    {
//        width:360
//        height:360
//        Rectangle
//        {
//            id:redrect;
//            color: "red"
//            x: 0
//            y: 0
//            width:parent.width/2
//            height: parent.height/2
//        }

//        Rectangle
//        {
//            color: "green";
//            x: redrect.width
//            y: redrect.height
//            width:  redrect.width
//            height: redrect.height
//        }
//    }

////Листинг 54.4 Вывод текущей ширины и высоты при изменении размеров окна

//    Item
//    {
//        width: 640
//        height: 480
//        Rectangle
//        {
//            width:parent.width
//            height: parent.height
//            onWidthChanged:
//            {
//                console.log("width changed:" + width)
//            }
//            onHeightChanged:
//            {
//                console.log("height changed:" + height)
//            }
//        }
//    }

//Листинг 54.5 Дополнение элемента свойствами
//    Item
//    {
//        width: 200
//        height: 100

//        Item {
//            id: myelement
//            property string name: "My Element"
//            property int ver: 1
//            property real pi: 3.14159
//            property bool condition: true
//            property var variant: 53.1
//            property url link: "http://www.bhv.com/"

//        }
//        Text
//        {
//            x:0
//            y:0
//            text: myelement.name + "<br>"
//                + myelement.ver  + "<br>"
//                + myelement.pi   + "<br>"
//                + myelement.condition + "<br>"
//                + myelement.variant   + "<br>"
//                + myelement.link
//        }
//    }

//Листинг 54.6-54.7 Создание собственных элементов
//    Item
//    {
//        width: 150
//        height: 100

//        TextField
//        {
//            x: 10
//            y: 20
//            color: "yellow"
//            text: "Text <br> Text"
//            border.width: 1

//        }
//    }

//Листинг 54.8 Файл описания модуля
//    #Module description "qmldir"
//    module QtBookControls
//    ColorPicker 1.1 ColorPicker-1.1.qml
//    ColorPicker 1.0 ColorPicker-1.0.qml
//    ToolTip 1.1 ToolTip-1.1.qml
//    ToolTip 1.0 ToolTip-1.0.qml

//Листинг 54.9 Отображение потомка Flickable

//    Flickable
//    {
//        id: view
//        width: 250
//        height: 250
//        contentWidth: 500
//        contentHeight: 500

//        Repeater
//        {
//            model: ["red", "white", "green", "yellow", "blue"]
//            Rectangle
//            {
//                color: modelData
//                width: view.contentWidth-index*100
//                height: view.contentHeight-index*100
//                x: view.contentWidth/2 - width/2
//                y: view.contentHeight-height/2
//            }
//        }
//    }

//Листинг 54.10 Элемент окна приложения с кнопкой

    /*
ApplicationWindow
{
    width: buttons.width
    height: buttons.height
    visible: true
    title: "Buttons"

    Column
    {
        id: buttons
        CheckBox {text: "Check Box"}
        DelayButton {text: "DelayButton"}
        RadioButton {text: "Radio Button"}
        RoundButton {text: "Round Button"}
        Switch{text:"Switch"}
        ToolButton{text: "Tool Button"}
        Button{text: "Quit"; onClicked: Qt.quit()}
    }

}*/

//Листинг 54.11 Окно приложения с элементами
//    ApplicationWindow
//    {
//        visible: true
//        width: 200
//        height: 200
//        title: "COntrols"
//        header: ToolBar
//        {
//            Button
//            {
//                text: "Quit"
//                onClicked: Qt.quit();
//            }
//        }
//        footer: ToolBar
//        {
//            id: statusbar
//            Label
//            {
//                id: statuslbl
//            }
//        }
//        ProgressBar
//        {
//            x: 0
//            y: 0
//            width: parent.width
//            height: parent.height/2
//            value: slider.value
//        }
//        Dial
//        {
//            id: slider
//            x: 0
//            y: parent.height/2
//            width: parent.width
//            height: parent.height/2
//            value: 0.75
//            stepSize: 0.1
//            onValueChanged: statuslbl.text = slider.value
//        }
//    }

//Листинг 54.12  Диалоговые окна выбора цвета и вывода сообщений
//    ApplicationWindow
//    {
//        width: 200
//        height: 150
//        visible: true
//        title: "Dialogs Demo"

//        Repeater
//        {
//            id: repeater
//            model: [colorDialog, fontDialog, fileDialog]
//            Button
//            {
//                y: index*(parent.height/repeater.count)
//                height: parent.height/repeater.count
//                width: parent.width
//                text: modelData.title
//                onClicked:
//                {
//                    messageDialog.visible = false;
//                    modelData.visible = true;

//                }
//            }
//        }

//        ColorDialog
//        {
//            id: colorDialog
//            visible: false
//            modality: Qt.WindowModal
//            title: "Select Color"
//            color: "blue"
//            onAccepted
//            {
//                messageDialog.informativeText = "Selected color: " + color
//                messageDialog.visible = true
//            }
//        }
//                FontDialog
//                {
//                    id: fontDialog
//                    visible: false
//                    modality: Qt.WindowModal
//                    title: "Select font"
//                    onAccepted:
//                    {
//                        messageDialog.informativeText = "Selected font: " + font
//                        messageDialog.visible = true
//                    }
//                }

//                FileDialog
//                {
//                    id: fileDialog
//                    visible: false
//                    modality: Qt.WindowModal
//                    title: "Select file"
//                    folder: "file://Users/"
//                    nameFilters: ["Doc (* .txt *.html)", "All files(*)"]
//                    onAccepted:
//                {
//                        messageDialog.informativeText = "Selected file: " + fileUrls
//                        messageDialog.visible = true
//                    }
//                }

//                MessageDialog
//                {
//                    id: messageDialog
//                    visible: false
//                    modality: Qt.NonModal
//                    title: "Message"
//                }
//    }
}




