#include "customstyle.h"


void CustomStyle::polish(QWidget *pwgt)
{
    if (qobject_cast<QPushButton*>(pwgt))
    {
        pwgt->setAttribute(Qt::WA_Hover, true);
        //При наведении мыши на объект кнопка будет создавать событие перерисовки
    }
}

void CustomStyle::unpolish(QWidget *pwgt)
{
    if (qobject_cast<QPushButton*>(pwgt))
    {
        pwgt->setAttribute(Qt::WA_Hover, false);
    }
}

void CustomStyle::drawPrimitive(QStyle::PrimitiveElement elem, const QStyleOption *popt, QPainter *ppainter, const QWidget *pwgt) const
{
    switch(elem)
    {
    case PE_PanelButtonCommand:
    {
        const QStyleOptionButton* pOptionButton =
                qstyleoption_cast<const QStyleOptionButton*>(popt);
        if (pOptionButton)
        {
            bool bDown = (pOptionButton->state & State_Sunken)
                    || (pOptionButton->state & State_On);

            QPixmap pix = bDown ? QPixmap(":/btnprs.bmp")
                                : QPixmap(":/btn.bmp");

            ppainter->drawPixmap(pOptionButton->rect, pix);

            bool bHover = (pOptionButton->state & State_MouseOver);
            if (bHover)
            {
                ppainter->fillRect(pOptionButton->rect,
                                   QColor(25,93,45,83)
                                   );

            }


        }
        break;
    }
    default:
        QCommonStyle::drawPrimitive(elem,popt,ppainter,pwgt);
        break;
    }
}
