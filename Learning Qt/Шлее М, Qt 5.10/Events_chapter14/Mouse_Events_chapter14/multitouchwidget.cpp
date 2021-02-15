#include "multitouchwidget.h"
#include <QtGui>


/*virtual*/ void MultiTouchWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int nColsCount = m_lstCols.count();

    foreach(QTouchEvent::TouchPoint tp, m_lstTps)
    {
        switch(tp.state())
        {
        case Qt::TouchPointStationary:
            continue;

        default:
            QColor c(m_lstCols.at(tp.id()% nColsCount));
            painter.setPen(c);
            painter.setBrush(c);

            QRectF r1(tp.position(), QSize(20,20)); //Тут вместо pos position
            QRectF r2(tp.pressPosition(), QSize(20,20)); //Тут вместо startPosition pressPosition

            painter.drawEllipse(r1.translated(-10,-10));
            painter.drawEllipse(r2.translated(-10,-10));

            painter.drawLine(tp.position(), tp.pressPosition());
        }
    }
}

/*virtual*/ bool MultiTouchWidget::event(QEvent *pe)
{
    switch (pe->type())
    {
    case QEvent::TouchBegin:
    case QEvent::TouchUpdate:
    case QEvent::TouchEnd:
    {
    QTouchEvent* pte = static_cast<QTouchEvent*> (pe);
    m_lstTps = pte-> points();      //Тут вместо touchPoints() просто points()
    update();
    }
    default:
        return QWidget::event(pe);
    }
    return true;
}

MultiTouchWidget::MultiTouchWidget(QWidget* pwgt): QWidget (pwgt)
{
    setAttribute(Qt::WA_AcceptTouchEvents); //Включаем обработку мультитач-событий

    m_lstCols << Qt::cyan << Qt::green<<Qt::blue<<Qt::black
              << Qt::red << Qt::magenta << Qt::darkYellow
              <<Qt::gray << Qt::darkCyan<<Qt::darkBlue;
}
