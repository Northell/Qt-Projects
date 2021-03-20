import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Particles 2.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Листинг 58.1 Анимация при изменении координат x и y
//    Rectangle
//    {
//        color: "black"
//        width: parent.width
//        height: parent.height
//        Image
//        {
//            id: img
//            x:0
//            y:0
//            source: "qrc:/RedGuy"
//        }

//        PropertyAnimation
//        {
//            target: img
//            properties: "x,y"
//            from:0
//            to: 300-img.height
//            duration: 1500
//            running: true
//            loops: Animation.Infinite
//            easing.type: Easing.OutExpo
//        }
//    }
//Листинг 58.2 Анимация с использованием элемента NumberAnimation
//    Rectangle
//    {
//        width:  parent.width
//        height: parent.height
//        color: "gold"

//        Rectangle
//        {
//            x: 0
//            y: 0
//            height: 100
//            color: "red"
//            NumberAnimation on width
//            {
//                from: 640
//                to: 0
//                duration: 2000
//                easing.type: Easing.InOutCubic
//            }
//        }
//    }

    //Листинг 58.3 Агимация с использованием элемента ColorAnimation

//    Rectangle
//    {
//        width: 200
//        height: 200
//        ColorAnimation on color
//        {
//            from: Qt.rgba(1,0.5,0,1)
//            to: Qt.rgba(0.5,0,1,1)
//            duration: 1500
//            running: true
//            loops: Animation.Infinite
//        }
//    }

    //Листинг 58.4 Анимация с использованием элемента RotationAnimation

//    Rectangle
//    {
//        width: 150
//        height: 150
//        Image
//        {
//            source: "qrc:/RedGuy"
//            anchors.centerIn: parent
//            smooth: true

//            RotationAnimation on rotation
//            {
//                from: 0
//                to: 360
//                duration: 2000
//                loops: Animation.Infinite
//                easing.type: Easing.InOutBack
//            }
//        }
//    }

    //Листинг 58.5 Анимация поведения

//    Rectangle
//    {
//        id: rect
//        width: parent.width
//        height: parent.height
//        Image
//        {
//            id: img
//            source: "qrc:/RedGuy"
//            x:10
//            y:10
//            smooth: true
//            Text
//            {
//                anchors.verticalCenter: img.verticalCenter
//                anchors.top: img.bottom
//                text: "Move the mouse"

//            }
//            Behavior on x
//            {
//                NumberAnimation
//                {
//                    duration: 1000
//                    easing.type: Easing.OutBounce
//                }
//            }
//            Behavior on y
//            {
//                NumberAnimation
//                {
//                    duration: 1000
//                    easing.type: Easing.OutBounce
//                }
//            }
//        }

//        MouseArea
//        {
//            anchors.fill: rect
//            hoverEnabled: true

//            onMouseXChanged: img.x = mouseX
//            onMouseYChanged: img.y = mouseY
//        }
//    }

    //Листинг 58.6 Параллельная анимация
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        Image
//        {
//            id: img
//            source: "qrc:/RedGuy"
//            smooth: true
//            anchors.centerIn: parent

//        }

//        ParallelAnimation
//        {
//            NumberAnimation
//            {
//                target: img
//                properties: "scale"
//                from: 0.1;
//                to: 3.0;
//                duration: 2000
//                easing.type: Easing.InOutCubic
//            }
//            NumberAnimation
//            {
//                target: img
//                properties: "opacity"
//                from: 1.0
//                to: 0
//                duration: 2000

//            }
//            running: true
//            loops: Animation.Infinite
//        }
//    }

    //Листинг 58.7 Последовательная анимация
//    Rectangle
//    {
//        width: parent.width
//        height: parent.height
//        Image
//        {
//            id: img
//            source: "qrc:/RedGuy"
//            smooth: true
//            Text
//            {
//                anchors.horizontalCenter: img.horizontalCenter
//                anchors.top: img.bottom
//                text: "Click me"
//            }

//            MouseArea
//            {
//                anchors.fill: img
//                onClicked:  anim.running = true

//            }

//            SequentialAnimation
//            {
//                id: anim
//                NumberAnimation
//                {
//                    target: img
//                    from: 20
//                    to: 300
//                    properties: "y"
//                    easing.type: Easing.OutBounce
//                    duration:  1000
//                }

//                RotationAnimation
//                {
//                    target:  img
//                    from: 0
//                    to: 360
//                    properties: "rotation"
//                    direction: RotationAnimation.Clockwise
//                    duration: 1000
//                }

//                PauseAnimation
//                {
//                    duration: 500
//                }

//                NumberAnimation
//                {
//                    target: img
//                    from: 300
//                    to: 20
//                    properties: "y"
//                    easing.type: Easing.OutBack
//                    duration: 1000
//                }
//            }
//        }
//    }

    //Листинг 58.8 Состояния

//    Rectangle
//    {
//        id: rect
//        width: 360
//        height: 360
//        state: "State2"

//        Text
//        {
//            id: txt
//            anchors.centerIn: parent
//        }

//        states:
//        {
//            State
//            {
//                name: "State1"
//                PropertyChanges
//                {
//                    target: rect
//                    color: "gold"
//                    width: 150
//                    height: 60

//                }
//                PropertyChanges
//                {
//                    target: txt
//                    text: "State2: Click Me"
//                }
//            }
//            State
//            {
//                name: "State2"
//                PropertyChanges
//                {
//                    target: rect
//                    color: "yellow"
//                    width: 200
//                    height: 120
//                }
//                PropertyChanges
//                {
//                    target: txt
//                    text: "State1: Click Me"
//                }
//            }
//        }
//        MouseArea
//        {
//            anchors.fill: parent
//            onClicked: parent.state = (parent.state == "State1") ? "State2":"State1"
//        }
//    }

    //Листинг 58.9 Переходы
//    Item
//    {
//        width: 300
//        height: 300
//        Rectangle
//        {
//            id:rect
//            width: 100
//            height:100
//            color: "magenta"
//            state: "State1"

//            Text
//            {
//                anchors.centerIn: parent
//                text: "Click me"

//            }

//            MouseArea
//            {
//                anchors.fill: rect
//                onClicked: rect.state = (rect.state == "State1") ?"State2":"State1"
//            }
//            states:
//                [
//                State
//                {
//                    name: "State1"
//                    PropertyChanges
//                    {target: rect; x: 0; y: 0}
//                },
//                State
//                {
//                    name: "State2"
//                    PropertyChanges
//                    {target: rect; x: 200; y: 200}
//                }
//            ]
//                transitions: [
//                Transition
//                {
//                    from: "State1" ; to: "State2"
//                    PropertyAnimation
//                    {
//                        target: rect;
//                        properties: "x,y";
//                        easing.type: Easing.InCirc
//                        duration: 1000
//                    }
//                },
//                Transition
//                {
//                    from: "State2" ; to: "State1"
//                    PropertyAnimation
//                    {
//                        target: rect;
//                        properties: "x,y";
//                        easing.type: Easing.InBounce
//                        duration: 1000
//                    }
//                }
//                ]


//        }
//    }

    //Листинг 58.10 Шаблонный метод
//    transitions:
//        Transition
//    {
//        from: "*"; to: "*"
//        PropertyAnimation
//        {
//            target: rect;
//            properties: "x,y";
//            easing.type: Easing.InCirc
//            duration: 1000
//        }
//    }

    Rectangle
    {
        width: parent.width
        height: parent.height
        color: "midnightblue"

        ParticleSystem
        {
            anchors.fill: parent

            ImageParticle
            {
                source: "qrc:/RedGuy"
            }

            Emitter
            {
                width: parent.width
                height: parent.height
                anchors.bottom: parent.bottom
                lifeSpan: 10000
                sizeVariation: 16
                emitRate: 20
                velocity:
                    AngleDirection
                {
                    angle:90
                    angleVariation: 10
                    magnitude: 100
                }
            }
            //58.12 Добавляем ветер
            Gravity
            {
                y: parent.height/2
                width: parent.width
                height: parent.height
                angle: 0
                acceleration: 250
            }

        }
    }
}
