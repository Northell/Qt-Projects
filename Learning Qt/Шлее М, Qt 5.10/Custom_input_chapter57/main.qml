import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Листинг 57.1 Область мыши
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        color: "lime"
//        Text
//        {
//            id: txt
//            anchors.centerIn: parent
//            text: "<h1>Click Me! <br> (use or right mouse button) </h1>"
//            horizontalAlignment: Text.AlignHCenter
//        }
//        MouseArea
//        {
//            anchors.fill:parent
//            acceptedButtons: Qt.LeftButton | Qt.RightButton
//            onPressed:
//            {
//                if(mouse.button == Qt.RightButton)
//                {
//                    parent.color = "gold"
//                }
//                else
//                {
//                    parent.color = "khaki"
//                }
//            }
//            onReleased:  parent.color = "lime"
//        }
//    }

    //Листинг 57.2-57.3 Обработка мыши hover
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        color: mousearea.containsMouse? "red" : "lime"

//        Text
//        {
//            anchors.centerIn: parent
//            text: "<h1> Hover Me </h1>"
//        }

////        MouseArea
////        {
////            id:mousearea
////            anchors.fill: parent
////            hoverEnabled: true
////        }

//        //57.3 Алтернативное решение
//        MouseArea
//        {
//            id: mousearea
//            anchors.fill: parent
//            hoverEnabled: true
//            onEntered: parent.color = "yellow"
//            onExited: parent.color = "lime"
//        }
//    }

    //Листинг 57.4 Собственный сигнал
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height

//        signal mousePositionChanged(int x, int y)

//        onMousePositionChanged: txt.text = "<h1>X:" + x +"; Y:" + y+ "</h1>"

//        Text
//        {
//            id: txt
//            text: "<h1> Move the Mouse </h1>"
//            anchors.centerIn: parent
//        }

//        MouseArea
//        {
//            anchors.fill:parent
//            hoverEnabled:  true
//            onMouseXChanged:  parent.mousePositionChanged(mouseX,mouseY)
//            onMouseYChanged:  parent.mousePositionChanged(mouseX,mouseY)
//        }
//    }

   //Листинг 57.5-57.8 Кнопка с сигналом, свойстом, блэкджеком и шлюхами

//    Button
//    {
//        anchors.centerIn: parent
//        text: "Please, Click me!"
////        onClicked:
////        {
////            text = "Clicked"
////        }
//        onClickedChanged:
//        {
//            text = "Changed"
//        }
//    }

//    Rectangle
//    {
//        width: 200
//        height:  100
//        TextInput
//        {
//            anchors.centerIn: parent
//            color: "red"
//            text: "Text"
//            font.pixelSize: 32
//            focus: true
//        }
//    }

    //Листинг 57.10 Фокус между двумя полями ввода
//    Item
//    {
//        width: 200
//        height: 80
//        TextEdit
//        {
//            anchors.left: parent.left
//            anchors.right: parent.right

//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            text: "TextEdit1\nTextEdit1\nTextEdit1"
//            font.pixelSize: 20
//            color: focus? "red":"black"
//            focus: true
//        }
//        TextEdit
//        {
//            anchors.left: parent.horizontalCenter
//            anchors.right: parent.right

//            anchors.top: parent.top
//            anchors.bottom: parent.bottom
//            text: "TextEdit2\nTextEdit2\nTextEdit2"
//            font.pixelSize: 20
//            color: focus? "red":"black"

//        }
//    }
//Листинг 57.11 Изменение фокуса клавишей табуляции
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        anchors.centerIn: parent
//        color: focus ? "red" : "lime"
//        KeyNavigation.tab: childrect

//        Rectangle
//        {
//            id:childrect
//            width: 150
//            height: 150
//            anchors.centerIn: parent
//            color: focus ? "red" : "lime"
//            KeyNavigation.tab: parent
//            focus: true
//        }

//        Text
//        {
//            anchors.centerIn: parent
//            text: "Press TAB"
//        }
//    }

//Листинг 57.12 Перемещение элемента при помощи клавиш управления курсором
//    Rectangle
//    {
//        width: 200
//        height: 100
//        Text
//        {
//            x: 20
//            y:20
//            text: "Move this <br> (use the cursor-keys)"
//            horizontalAlignment: Text.AlignHCenter
//            Keys.onLeftPressed: x-=3
//            Keys.onRightPressed: x+=3
//            Keys.onDownPressed: y+=3
//            Keys.onUpPressed: y-=3
//            focus:true
//        }
//    }


//Листинг 57.13 - 57.14 Обработка событий клавиатуры

//    Rectangle
//    {
//       Keys.onPressed:
//       {
//           if(event.key == Qt.Key_left)
//           {
//               x-=3;
//           }
//           else if(event.key == Qt.Key_Right)
//           {
//               x+=3;
//           }
//           else if(event.key == Qt.Key_Down)
//           {
//               y+=3;
//           }
//           else if(event.key == Qt.Key_Up)
//           {
//               y-=3;
//           }

//           //57.14
//           else if(event.key == Qt.Plus)
//           {
//               font.pixelSize++
//           }
//           else if(event.key == Qt.Key_Minus)
//           {
//               font.pixelSize++
//           }
//       }

//    }

    //Лисинг 57.15 Обработка мультитач-событий

    Rectangle
    {
        width: 400
        height: 400
        color: "gold"

        MultiPointTouchArea
        {
            anchors.fill: parent
            minimumTouchPoints: 1
            maximumTouchPoints: 5
            touchPoints:
            [
                TouchPoint {},
                TouchPoint {},
                TouchPoint {},
                TouchPoint {},
                TouchPoint {}

            ]

            Repeater
            {
                model: parent.touchPoints
                Rectangle
                {
                    color: "lime"
                    x: modelData.x
                    y: modelData.y
                    width:  30
                    height: 30
                    visible:  modelData.pressed
                }
            }
        }
    }
}
