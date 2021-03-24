import QtQuick 2.0
import Qt3D.Core 2.0
import Qt3D.Render 2.0
import Qt3D.Input 2.0
import Qt3D.Extras 2.0
import QtQuick.Scene3D 2.0

Rectangle
{
    color: "black"
    Scene3D
    {
        anchors.fill: parent
        focus: true
        aspects: ["input", "logic"]
        cameraAspectRatioMode: Scene3D.AutomaticAspectRatio
        Entity
        {
            Camera
            {
                id: camera
                nearPlane:  0.1
                farPlane: 1000.0
                position: Qt.vector3d(0.0, 0.0, 50.0)
            }
            FirstPersonCameraController
            {
                camera: camera
                linearSpeed: 1000.0
                acceleration: 0.1
                deceleration: 1.0
            }
            components: [
            RenderSettings
            {
                activeFrameGraph:
                    ForwardRenderer
                {
                    camera: camera
                    clearColor: "transparent"
                }
            },
            InputSettings{}
            ]

            DirectionalLight{ //Свет
                color: "#afafff"
            }

//            Entity
//            {
//                PhongMaterial
//                {
//                    id: phongMaterial
//                    ambient: Qt.rgba(0.3, 0.3, 0.3, 1.0)
//                    diffuse: Qt.rgba(1,1,1,1)

//                }
//                SphereMesh
//                {
//                    id: sphereMesh
//                    radius: 6
//                }
//                components: [sphereMesh, phongMaterial]
//            }
//        }
//    }

//    //Листинг 61.7 Фрагмент программы "Конус с трансформацией
//    Entity
//    {
//        ConeMesh
//        {
//            id: coneMesh1
//            topRadius: 0
//            bottomRadius: 1
//            length: 5
//            rings: 50
//        }
//        Transform
//        {
//            id: coneTransform1
//            scale: 0.5
//            translation: Qt.vector3d(0,14,4)
//            rotationX: 90
//        }

//        PhongMaterial
//        {
//            id: coneMaterial
//            diffuse: Qt.rgba(1, 0.3, 0.2, 1)

//        }
//        components: [coneMesh1, coneMaterial, coneTransform1]
//    }


    //Листинг 61.8 Анимация сферы
    Entity
    {
        PhongMaterial{
            id: phongMaterial
            ambient:  Qt.rgba(0.3, 0.3, 0.3, 1.0)
            diffuse: Qt.rgba(1,1,1,1)

        }
        SphereMesh
        {
            id: sphereMesh
            radius: 6

        }
        Transform
        {
            id: sphereTransform
            property real myParam: 0
            matrix:
            {
                var mat = Qt.matrix4x4();
                mat.rotate(myParam, Qt.vector3d(24,0,0));
                return mat
            }
        }
        components: [sphereMesh, phongMaterial, sphereTransform]

        NumberAnimation {
            target: sphereTransform
            property: "myParam"
            duration: 1000
            from: 0
            to: 360
            loops: Animation.Infinite
            running: true
                }
            }
        }
        //Листинг 61.9 Анимация пирамиды( не стал делать, одно и то же)
    }
}

