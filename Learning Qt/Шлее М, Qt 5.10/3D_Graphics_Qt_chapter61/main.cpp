
//Листинг 61.1 Объединение элменетов в сушность
//Entity
//{
//    Mesh{id: myMesh;...}
//    PhongMaterial {id: myMaterial...}
//          Transform {id: myTransform;...}
//           component: [myMesh, myMaterial, myTransform]
//}

//Листинг 61.2 Создание элемента точечного света
//PointLight
//{
//    color: "#afaffff"
//}

//Листинг 61.3 Создание элемента камеры
//Camera
//{
//    projectionType: CameraLens.PerspectiveProjection
//            fieldOfView: 90
//        position: Qt.vector3d(0.0,0.0,40.0)
//}

//Листинг 61.4 Файл Pyramid.obj Пирамида в формате OBJ
//# Blender v2. 79 (sub 0) OBJ File: ''
//# www.Ыender.org
//о Shape_IndexedFaceSet
//v 1.000000 -1.000000 -1.000000
//v -1.000000 -1.000000 -1.000000
//v -1.000000 -1.000000 1.000000
//v 1.000000 -1.000000 1.000000
//v 0.000000 1.000000 -0.000000
//vn 0.0000 0.4472 -0.8944
//vn -0.8944 0.4472 -0.0000
//vn -0.0000 0.4472 0.8944
//vn 0.8944 0.4472 0.0000
//f 1//1 2//1 5//1
//f 2//2 3//2 5//2
//f 3//3 4//3 5//3
//f 4//4 1//4 5//4

//#include <QCoreApplication>

//int main(int argc, char *argv[])
//{
//    QCoreApplication a(argc, argv);

//    return a.exec();
//}


//Листинг 61.4-61.6 3D СФера
#include <QGuiApplication>
#include <QQuickView>
int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);
    QQuickView view;
    view.resize(300,300);
    view.setResizeMode(QQuickView::SizeRootObjectToView);
    view.setSource(QUrl("qrc:/main"));
    view.show();
    return app.exec();
}
