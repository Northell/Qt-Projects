#include "qgldraw.h"

void QGLDraw::initializeGL()
{
    QOpenGLFunctions* pFunc =
            QOpenGLContext::currentContext()->functions();
    pFunc->glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void QGLDraw::resizeGL(int nWidth, int nHeight)
{

    glMatrixMode(GL_PROJECTION);                   //Установка матрицы проектирования текущей
    glLoadIdentity();                              //Текущая матрица ставится в единичную
    glViewport(0,0,(GLint)nWidth, (GLint)nHeight); //Ставим видовое окно
    glOrtho(0,400,200,0,-1,1);
}

void QGLDraw::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
                                         //Тут, третий параметр тип фигуры, а 1,2 координаты начала постройки фигуры
    draw(0,0,GL_POINTS);                 // Отображаться должны только точки
    draw(100,0,GL_LINES);                //Каждая пара вершин отрезки
    draw(200,0,GL_LINE_STRIP);           //Ломаная линия
    draw(300,0,GL_LINE_LOOP);            //Ломаная линия + посл. точка соединяется с первой

    draw(0,100,GL_TRIANGLE_STRIP);       //Треугольники с общей стороной
    draw(100,100,GL_POLYGON);            //Многоугольник
    draw(200,100,GL_QUADS);              //Четырехугольник
    draw(300,100,GL_TRIANGLES);          //Каждые 3 вершины задают тругольник

}

QGLDraw::QGLDraw(QWidget *pwgt):QOpenGLWidget(pwgt)
{

}

void QGLDraw::draw(int xOffset, int yOffset, GLenum type)
{
    int n =8;

    glPointSize(2);                        //Задание размеров точки
    glBegin(type);
        glColor3f(0,0,0);                  //Черный цвет для вершин
        for(int i = 0; i<n; ++i)
        {
            float fAngle = 2*3.14*i/n;
            int   x      = (int)(50+cos(fAngle)*40+xOffset);
            int   y      = (int)(50+sin(fAngle)*40+yOffset);
            glVertex2f(x,y);                //Задает расположение вершин
        }
    glEnd();

}
