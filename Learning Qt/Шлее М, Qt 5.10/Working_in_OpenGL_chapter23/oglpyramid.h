#ifndef OGLPYRAMID_H
#define OGLPYRAMID_H

#include <QtOpenGLWidgets>

class OGLPyramid:public QOpenGLWidget
{
private:
    GLuint  m_nPyramid;             //Хранит номер дисплейного списка
    GLfloat m_xRotate;
    GLfloat m_yRotate;
    QPoint  m_ptPosition;

protected:
    virtual void initializeGL();
    virtual void resizeGL    (int nWidth, int nHeight);
    virtual void paintGL();

    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent(QMouseEvent* pe);

            GLuint createPyramid (GLfloat fSize = 1.0f);
public:
    OGLPyramid(QWidget* pwgt = 0);
};

#endif // OGLPYRAMID_H
