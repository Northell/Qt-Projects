
//Листинг 14.1-14.3
#include "mouseobserver.h"


MouseObserver::MouseObserver(QWidget *pwgt): QLabel(pwgt)
{
    setAlignment(Qt::AlignCenter);
    setText("Mouse interactions\n(Press a mouse button)");
}

/*virtual*/ void MouseObserver::mousePressEvent(QMouseEvent *pe)
{
    dumpEvent (pe, "Mouse Pressed");
}

/*virtual*/ void MouseObserver::moseReleaseEvent(QMouseEvent *pe)
{
    dumpEvent (pe, "Mouse Released");
}

/*virtual*/ void MouseObserver::mouseMoveEvent(QMouseEvent *pe)
{
    dumpEvent (pe, "Mouse Moved");
}

void MouseObserver::dumpEvent(QMouseEvent *pe, const QString &strMessage)
{
    setText (strMessage
             + "\n buttons()= " + buttonsInfo(pe)
             + "\n x()= " + QString::number(pe->x())
             + "\n y()= " + QString::number(pe->y())
             + "\n globalX()= " + QString::number(pe->globalX())
             + "\n globalY()= " + QString::number(pe->globalY())
             + "\n modifiers()= " + modifiersInfo(pe)
             );
}

QString MouseObserver::modifiersInfo(QMouseEvent *pe)
{
    QString strModifiers;

    if(pe->modifiers() & Qt::ShiftModifier)
    {
        strModifiers+="Shift ";
    }

    if(pe->modifiers() & Qt::ControlModifier)
    {
        strModifiers+="Control ";
    }

    if(pe->modifiers() & Qt::AltModifier)
    {
        strModifiers+="Alt ";
    }

    return strModifiers;
}

QString MouseObserver::buttonsInfo(QMouseEvent *pe)
{
    QString strButtons;

    if (pe->buttons() & Qt::LeftButton)
    {
        strButtons += "Left";
    }

    if (pe->buttons() & Qt::RightButton)
    {
        strButtons += "Right";
    }

    if (pe->buttons() & Qt::MiddleButton)
    {
        strButtons += "<iddle";
    }
    return strButtons;
}
