import QtQuick 2.8
import QtQuick.Window 2.12
//import QtQuick.XmlListModel 2.0
import "qrc:/CDs.js" as CDs


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    //Листинг 59.1 Модель данных

//    ListModel
//    {
//        ListElement
//        {
//            artist: "Amarante"
//            album: "Amarante"
//            year: 2011
//            cover: "qrc:/RedGuy"
//        }
//        ListElement
//        {
//            artist: "Dark Princess"
//            album: "Without You"
//            year: 2011
//            cover: "qrc:/Image1"
//        }
//        ListElement
//        {
//            artist: "Within Templation"
//            album: "The Unforgiving"
//            year: 2011
//            cover: "qrc:/RedGuy"
//        }
//    }

    //Листинг 59.2-59.3 XML-модель
//    XMLListModel
//    {
//        source: "qrc:/CDs.xml"
//        query: "/CDs/CD"
//        XmlRole {name: "artist", query: "artist/string()"}
//        XmlRole {name: "album", query: "album/string()"}
//        XmlRole {name: "year", query: "year/string()"}
//        XmlRole {name: "cover", query: "cover/string()"}

//    }

    //Листинг 59.4 JSON данные(CDs.js)
    //Листинг 59.5 Использование элемента ListView
//    Rectangle
//    {
//        id: mainrect
//        color: "gold"
//        width: parent.width
//        height: parent.height

//        Component
//        {
//            id: delegate
//            Item
//            {
//                width: mainrect.width
//                height: 70
//                Row
//                {
//                    anchors.verticalCenter: parent.verticalCenter
//                    Image
//                    {
//                        width: 64
//                        height: 64
//                        source: modelData.cover
//                        smooth: true

//                    }
//                    Column
//                    {
//                        Text
//                        {
//                            color: "white"
//                            text: modelData.artist
//                            font.pointSize: 12
//                        }

//                        Text
//                        {
//                            color: "lime"
//                            text: modelData.album
//                            font.pointSize: 10
//                        }

//                        Text
//                        {
//                            color: "yellow"
//                            text: modelData.year
//                            font.pointSize: 8
//                        }
//                    }
//                }
//            }
//        }
//        ListView
//        {
//            focus: true
//            header: Rectangle
//            {
//                width: parent.width
//                height: 30
//                gradient: Gradient
//                {
//                    GradientStop {position: 0; color: "gray"}
//                    GradientStop {position:0.7; color: "black"}
//                }
//                Text
//                {
//                    anchors.centerIn: parent;
//                    color: "gray";
//                    text: "CDs"
//                    font.bold: true;
//                    font.pointSize:  20
//                }
//            }

//            footer: Rectangle
//            {
//                width: parent.width
//                height: 30
//                gradient: Gradient
//                {
//                    GradientStop {position: 0; color: "gray"}
//                    GradientStop {position:0.7; color: "black"}
//                }
//            }
//            highlight: Rectangle
//            {
//                width: parent.width
//                color: "darkblue"
//            }

//            anchors.fill: parent
//            model: CDs.jsonModel
//            delegate: delegate
//        }
//    }

    //Листинг 59.6 Использование элемента GridView

//    Rectangle
//    {
//        id: mainrect
//        color: "gray"
//        width: 380
//        height: 420
//        Component
//        {
//            id: delegate
//            Item
//            {
//                width: 120
//                height: 120
//                Column
//                {
//                    anchors.centerIn: parent
//                    Image
//                    {
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        width: 64
//                        height: 64
//                        //Тут, изменения source: cover не работает
//                        source: modelData.cover
//                        smooth: true

//                    }
//    //Тут, изменения text: artist не работает
//                    Text {color: "white";  text: modelData.artist; font.pointSize: 12}
//                    Text {color: "lime";   text: modelData.album;  font.pointSize: 10}
//                    Text {color: "yellow"; text: modelData.year;   font.pointSize: 8}
//                }
//            }
//        }

//        GridView
//        {
//            cellHeight: 120
//            cellWidth: 120
//            focus: true
//            header: Rectangle
//            {
//                width: parent.width
//                height: 30
//                gradient: Gradient
//                {
//                    GradientStop{position: 0; color: "gray"}
//                    GradientStop{position: 0.7; color: "black"}
//                }

//                Text
//                {
//                    anchors.centerIn: parent;
//                    color: "gray"
//                    text: "CDs"
//                    font.bold: true
//                    font.pointSize: 20
//                }
//            }

//            footer: Rectangle
//            {
//                width: parent.width
//                height: 30
//                gradient: Gradient
//                {
//                    GradientStop{position: 0; color: "gray"}
//                    GradientStop{position: 0.7; color: "black"}
//                }
//            }

//            highlight: Rectangle
//            {
//                width: parent.width
//                color: "darkblue"
//            }
//            anchors.fill: parent
//            model: CDs.jsonModel
//            delegate: delegate
//        }
//    }

    //Листинг 59.7 Использование элемента PathView
//    Rectangle
//    {
//        id: mainrect
//        color: "gray"
//        width: 380
//        height: 420
//        Component
//        {
//            id: delegate
//            Item
//            {
//                width: 120
//                height: 120
//                Column
//                {
//                    anchors.centerIn: parent
//                    Image
//                    {
//                        anchors.horizontalCenter: parent.horizontalCenter
//                        width: 64
//                        height: 64
//                        //Тут, изменения source: cover не работает
//                        source: modelData.cover
//                        smooth: true

//                    }
//    //Тут, изменения text: artist не работает
//                    Text {color: "white";  text: modelData.artist; font.pointSize: 12}
//                    Text {color: "lime";   text: modelData.album;  font.pointSize: 10}
//                    Text {color: "yellow"; text: modelData.year;   font.pointSize: 8}
//                }
//            }
//        }

//        Path
//        {
//            id: itemsPath
//            startX: 0
//            startY: 80
//            PathLine {x: 500; y: 80}
//        }

//        PathView
//        {
//            id: itemsView
//            anchors.fill: parent
//            model: CDs.jsonModel
//            delegate: delegate
//            path:itemsPath
//            pathItemCount :4
//        }

        //Листинг 59.8 3D карусель
//        Path
//        {
//            id: itemsPath
//            startX: 180
//            startY: 250
//            PathAttribute {name: "iconScale"; value: 1.0}
//            PathAttribute {name: "iconOpacity"; value: 1.0}

//            PathQuad {x:180; y:50; controlX: 460; controlY: 75}
//            PathAttribute {name: "iconScale"; value: 0.3}
//            PathAttribute {name: "iconOpecity"; value: 0.3}
//            PathQuad {x:180; y:250; controlX: -80; controlY: 75}



//        }
//                PathView
//                {
//                    id: itemsView
//                    anchors.fill: parent
//                    model: CDs.jsonModel
//                    delegate: delegate
//                    path:itemsPath
//                   // pathItemCount :4
//                }
//    }

    //Листинг 59.9 Фрагмент визуальной модели данных

    //Листинг 59.10 Отображение визуальной модели(файл CDs.qml)(Не робит)
    Rectangle
    {
        width: 250;
        height: 250
        color: "darkslategray"

        Flickable
        {
            id: view
            width: 250
            height: 500
            contentWidth: 250
            contentHeight: column.height
            anchors.fill: parent

            Column
            {
                id: column
                anchors.fill: view
                spacing: 5
                Repeater
                {
                    model: CDs.jsonModel
                }
            }
        }
    }
}
