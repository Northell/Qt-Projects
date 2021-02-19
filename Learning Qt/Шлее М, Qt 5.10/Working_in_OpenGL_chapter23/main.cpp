//Листинг 23.1-23.6 Программа, отображающая четырехугольник с вершинами разного цвета и сглаживанием
/*
#include <QApplication>
#include "oglquad.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLQuad      oglQuad;

    oglQuad.resize(200,200);
    oglQuad.show();

    return a.exec();
}
*/

//Листинг 23.7-23.13 Программа формирует различные фигуры, построенные на одних и тех же вершинах

/*
#include <QApplication>
#include "qgldraw.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGLDraw      qglDraw;

    qglDraw.resize(400,200);
    qglDraw.show();

    return a.exec();
}
*/

//Листинг 23.14-23.22 Пирамида в трехмерном пространстве

#include <QApplication>
#include "oglpyramid.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    OGLPyramid   oglPyramid;

    oglPyramid.resize(200,200);
    oglPyramid.show();

    return a.exec();
}
