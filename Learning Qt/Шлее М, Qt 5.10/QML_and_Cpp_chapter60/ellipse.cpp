#include "ellipse.h"

EEllipse::EEllipse(QQuickItem *pqi):QQuickPaintedItem(pqi), m_color(Qt::black)
{

}

void EEllipse::paint(QPainter *ppainter)
{
    ppainter->setRenderHint(QPainter::Antialiasing, true);
    ppainter->setBrush(QBrush(colorValue()));
    ppainter->setPen(Qt::NoPen);
    ppainter->drawEllipse(boundingRect());
}

QColor EEllipse::colorValue() const
{
    return m_color;
}

void EEllipse::setColorValue(const QColor &col)
{
    m_color = col;

}
