import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
//Листинг 55.1-55.4 Размещение элемента в центре
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        color: "lightgreen" //55.5
//        Text
//        {
//            text: "Centered"
//            anchors.centerIn: parent

//            //55.2
////            anchors.horizontalCenter: parent.horizontalCenter
////            anchors.verticalCenter:   parent.verticalCenter

//            //55.3 Заполнение всей области элемента
////            anchors.left: parent.left
////            anchors.right: parent.right
////            anchors.top: parent.top
////            anchors.bottom: parent.bottom

//            //55.4 Заполнение всей области элемента
//            anchors.fill: text
//        }
//    }
// Листинг 55.6 Фиксация с перекрытием элемента
//    Item
//    {
//        width: parent.width
//        height: parent.height
//        Rectangle
//        {
//            id: redrect
//            color: "red"
//            width: parent.width/1.5
//            height: parent.height/1.5
//            anchors.top: parent.top
//            anchors.left: parent.left
//        }

//        Rectangle
//        {
//            opacity: 0.5
//            color: "green"
//            anchors.top: redrect.verticalCenter
//            anchors.bottom: parent.bottom
//            anchors.left: redrect.horizontalCenter
//            anchors.right: parent.right

//        }

//    }

//Листинг 55.7 Контроль размеров среднего элемента
   // Item
//    {
//        width:  parent.width
//        height: parent.height
//        Rectangle
//        {
//            id: redrect
//            color: "red"
//            anchors.left: parent.left
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            width: 60
//        }

//        Rectangle
//        {

//            color: "yellow"
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            anchors.left: redrect.right
//            anchors.right: greenrect.left

//        }

//        Rectangle
//        {
//            id: greenrect
//            color: "green"
//            anchors.right: parent.right
//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            width: 60
//        }

//    }

//Листинг 55.8 Использование отступов
/*
    Item
    {
        width:  parent.width
        height: parent.height
        Rectangle
        {
            id: redrect
            color: "red"
            anchors
            {
                right: parent.horizontalCenter
                left: parent.left
                top: parent.top
                bottom: parent.bottom
                leftMargin: 5
                topMargin: 5
                rightMargin: 5
                bottomMargin: 5
            }
        }



        Rectangle
        {
            id: greenrect
            color: "green"

            anchors
            {
                left: parent.horizontalCenter
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                leftMargin: 20
                topMargin: 20
                rightMargin: 20
                bottomMargin: 20
            }
        }

    }
*/

//Листинг 55.9 Горизонтальное размещение с использованием элемента Row
//    Item
//    {
//        width: parent.width
//        height: parent.height

//        Row
//        {
//            anchors.centerIn: parent
//            spacing: 10
//            Rectangle
//            {
//                width: 64; height: 64; color: "red"
//            }

//            Rectangle
//            {
//                width: 64; height: 64; color: "blue"
//            }
//            Rectangle
//            {
//                width: 64; height: 64; color: "pink"
//            }

//        }
//    }

//Листинг 55.10 Горизонтальное размещение с использованием элемента RowLayout
//    Item
//    {
//        width: parent.width
//        height: parent.height

//        RowLayout
//        {
//            anchors.fill: parent
//            anchors.margins: 10
//            spacing:  10

//            Rectangle
//            {
//                Layout.fillHeight: true
//                Layout.minimumWidth: 64
//                Layout.minimumHeight: 64
//                color: "red"
//            }
//            Rectangle
//            {
//                Layout.fillWidth: true
//                Layout.minimumWidth: 64
//                Layout.minimumHeight: 64
//                color: "blue"
//            }
//            Rectangle
//            {
//                Layout.fillHeight: true
//                Layout.minimumWidth: 64
//                Layout.minimumHeight: 64
//                color: "pink"
//            }
//        }
//    }

//Листинг 55.11 Табличное размещение

//    Item
//    {
//        width: parent.width
//        height: parent.height

//        Grid
//        {
//            rows: 2
//            columns: 2
//            anchors.centerIn: parent
//            spacing:  10

//            Rectangle
//            {
//                width: 64; height: 64; color: "red"
//            }
//            Rectangle
//            {
//                width: 64; height: 64; color: "blue"
//            }
//            Rectangle
//            {
//                width: 64; height: 64; color: "pink"
//            }
//            Rectangle
//            {
//                width: 64; height: 64; color: "purple"
//            }
//        }
//    }

//Листинг 55.12 Поточное размещение
    Item
    {
        width: parent.width
        height: parent.height

        Flow
        {
            anchors.fill: parent
            anchors.margins:
                20
            spacing:  20

           Repeater
           {
               model:
               {

                   var v = new Array(10);
                   for (var i = 0;i<v.length; ++i)
                   {
                       v[i] = i%2? "green" : "magenta"
                   }
                   return v;
               }
               Rectangle
               {
                   width: 64
                   height: 64
                   radius: 32
                   color: modelData
                   Text
                   {

                       color: "silver"
                       font.pixelSize: 48
                       font.family: "Courier"
                       anchors.centerIn: parent
                       text: index

                   }
               }
           }
        }
    }



}
