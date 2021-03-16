#ifndef TURTLEWORKAREA_H
#define TURTLEWORKAREA_H

#include <QtWidgets>
#include <QJSEngine>
#include "turtle.h"

class TurtleWorkArea:public QWidget
{
    Q_OBJECT

private:
    QTextEdit* m_ptxt;
    QJSEngine m_scriptEngine;
    Turtle* m_pTurtle;

public:
    TurtleWorkArea(QWidget* pwgt = 0);

private slots:
    void slotEvaluate();
    void slotApplyCode(int);
};

#endif // TURTLEWORKAREA_H
