import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

//Листинг 56.1-56.2 Отображение графического файла
//    Image
//    {
//        id: img
//        x: 0
//        y: 0
//        smooth: true
//        source: "qrc:/RedGuy"
//        //56.2
//        transform:
//        [
//            Scale
//            {
//                origin.x: width/2
//                origin.y: height/2
//                xScale: 0.75
//                yScale: 0.75
//            },
//            Rotation
//            {
//                origin.x: width/2
//                origin.y: height/2
//                angle: -30.0
//            }
//        ]

//    }

//    //Листинг 56.3  Загрузка и показ растрового изображения из Интернета
//    Rectangle
//    {
//        color: "aqua"
//        width: parent.width
//        height: parent.height

//        Image
//        {
//            id: img
//            anchors.fill: parent
//            smooth: true
//            source: "http://qt-book.com/pic.jpg"
//           Column
//           {
//               anchors.centerIn: parent
//               visible: img.status == Image.Loading? true: false
//               Text
//               {
//                   text: "Loading..."
//               }
//               BusyIndicator
//               {

//               }
//           }

//        }
//    }
    //Листинг 56.4 Масштабируемое изображение
//    BorderImage
//    {
//        source: "qrc:/RedGuy"
//        width: 100
//        height: 45
//        border
//        {
//            left: 30
//            top: 15
//            right:30
//            bottom:15
//        }
//    }

    //Листинг 56.5 Линейный градиент
//    Rectangle
//    {
//        width: 200
//        height: 200
//        gradient: Gradient
//        {
//            GradientStop {position: 0.0; color: "blue"}
//            GradientStop {position: 0.7; color: "gold"}
//            GradientStop {position: 1.0; color: "black"}

//        }
//    }
    //Листинг 56.6 Рисование на элементе холста(см. гл. 52, пример с черепашкой)
    //Листинг 56.7 Рисование прямоугольника с градиентом на элементе холста
//    Canvas
//    {
//        id: canv
//        width: 320
//        height: 320
//        onPaint:
//        {
//            var ctx = getContext("2d")
//            ctx.strokeStyle = "blue"
//            ctx.lineWidth = 15

//            var gradient = ctx.createLinearGradient(canv.width, canv.height, 0, 0)
//            gradient.addColorStop(0,   "indigo")
//            gradient.addColorStop(0.5, "#FFE4C4")
//            gradient.addColorStop(1,   "lime")

//            ctx.fillStyle = gradient
//            ctx.fillRect  (0,0,canv.width, canv.height)
//            ctx.strokeRect(0,0,canv.width, canv.height)
//        }
//    }

    //Листинг 56.8 Рисование текста со свечением на элементе холста

//    Canvas
//    {
//        id: canv
//        width: parent.width
//        height: parent.height

//        onPaint:
//        {
//            var ctx = getContext("2d")
//            ctx.fillStyle = "black"
//            ctx.fillRect(0,0,canv.width,canv.height)

//            ctx.strokeStyle = "yellow"
//            ctx.shadowColor = "yellow"
//            ctx.shadowOffsetY = 5;
//            ctx.shadowBlur = 5
//            ctx.font = "48px Arial"
//            ctx.fillStyle = "yellow"
//            ctx.fillText("Text with shadow",10,canv.height/2)
//        }
//    }

    //Листинг 56.9 Использование шейдера инвертирования (не робит)
//    Rectangle
//    {
//        width:  sourceImage.width
//        height: sourceImage.height
//        color: "black"

//        ShaderEffect
//        {
//            Image
//            {
//                id: sourceImage
//                width:   sourceWidth
//                height:  sourceHeight
//                visible: false
//                source: "qrc:/RedGuy"
//            }

//            width:  sourceImage.width
//            height: sourceImage.height

//            property variant source: sourceImage
//            fragmentShader:
//         "uniform sampler2D source;
//          uniform lowp float qt_Opacity;
//          varying highp vec2 qt_TexCoord0;

//          void main() {
//              gl_FragColor =
//                abs(texture2D(source, qt_TexCoord0) * qt_Opacity - 1.0);
//          }\n"

//        }
//    }

    //Листинг 56.10 Эффект размытия (не робит из-за модуля)
    Column
    {
        FastBlur
        {
            id: blur
            Image
            {
                id:sourceImage
                visible: false
                source: "qrc:/RedGuy"
            }
            width: sourceImage.width
            height: sourceImage.height
            source: sourceImage
        }
        Slider
        {
            id: sld
            width: sourceImage.width
            value: 0
            from: 0
            to: 64
            stepSize: 1
            onValueChanged:
            {
                blur. radius = value
            }
        }
    }
}
