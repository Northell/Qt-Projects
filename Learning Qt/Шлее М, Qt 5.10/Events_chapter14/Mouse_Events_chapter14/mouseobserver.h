#ifndef MOUSEOBSERVER_H
#define MOUSEOBSERVER_H
#include<QtWidgets>
//Листинг 14.1-14.3
class MouseObserver:public QLabel
{
public:
    MouseObserver(QWidget* pwgt=0);

protected:
    virtual void mousePressEvent  (QMouseEvent* pe);
    virtual void moseReleaseEvent (QMouseEvent* pe);
    virtual void mouseMoveEvent   (QMouseEvent* pe);

    void dumpEvent       (QMouseEvent* pe, const QString& strMessage);
    QString modifiersInfo(QMouseEvent* pe);
    QString buttonsInfo  (QMouseEvent* pe);

};

#endif // MOUSEOBSERVER_H
