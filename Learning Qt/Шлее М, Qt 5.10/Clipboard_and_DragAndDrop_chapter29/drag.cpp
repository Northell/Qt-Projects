#include "drag.h"

void Drag::startDrag()
{
    QMimeData* pMimeData = new QMimeData();
    pMimeData ->setText(text());

    QDrag* pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->setPixmap(QPixmap(":/RedGuy"));
    pDrag->exec();

}

void Drag::mousePressEvent(QMouseEvent *pe)
{
    if (pe->button() == Qt::LeftButton)
    {
        m_prDragPos = pe->pos();
    }
    QWidget::mousePressEvent(pe);

}

void Drag::mouseMoveEvent(QMouseEvent *pe)
{
    if (pe->buttons()&Qt::LeftButton)
    {
        int distance = (pe->pos() - m_prDragPos).manhattanLength();
        if (distance > QApplication::startDragDistance())
        {
            startDrag();
        }
    }
    QWidget::mouseMoveEvent(pe);
}

Drag::Drag(QWidget *pwgt):QLabel("This is a draggable text",pwgt)
{

}
