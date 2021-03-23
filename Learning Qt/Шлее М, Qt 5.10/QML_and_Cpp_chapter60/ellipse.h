#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QPainter>
#include <QtQuick>
#include <QQuickPaintedItem>

class EEllipse:public QQuickPaintedItem
{
    Q_OBJECT
private:
    Q_PROPERTY(QColor color WRITE  setColorValue
                            READ   colorValue
              )

    QColor m_color;
public:
    EEllipse(QQuickItem* pqi = 0);

    void paint(QPainter* ppainter);
    QColor colorValue() const;
    void setColorValue(const QColor& col);
};

#endif // ELLIPSE_H
