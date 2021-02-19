#ifndef QGLDRAW_H
#define QGLDRAW_H

#include <QtOpenGLWidgets>

class QGLDraw:public QOpenGLWidget
{
protected:
    virtual void initializeGL();
    virtual void resizeGL    (int nWidth, int nHeight);
    virtual void paintGL();

public:
    QGLDraw(QWidget* pwgt = 0);

    void draw(int xOffset, int yOffset, GLenum type);
};

#endif // QGLDRAW_H
