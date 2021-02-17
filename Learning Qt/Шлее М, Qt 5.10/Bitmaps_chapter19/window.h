#ifndef WINDOW_H
#define WINDOW_H

#include <QtWidgets>
//#include <QLabel>

class Window: public QLabel
{
private:
    QPoint m_ptPosition;

protected:
    virtual void mousePressEvent(QMouseEvent* pe)
    {
        m_ptPosition = pe->pos();
    }

    virtual void mouseMoveEvent(QMouseEvent* pe)
    {
        move(pe->globalPos()-m_ptPosition);
    }
public:
    Window(QWidget* pwgt = 0): QLabel(pwgt, Qt::FramelessWindowHint | Qt::Window)
    {

    }
};

#endif // WINDOW_H
