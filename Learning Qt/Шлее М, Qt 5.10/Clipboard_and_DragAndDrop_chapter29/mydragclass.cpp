#include "mydragclass.h"

void MyDragClass::startDrag()
{
    QImage     img(":/RedGuy");
    QByteArray data;
    QBuffer    buf(&data);
    QMimeData* pMimeData = new QMimeData();

    buf.open(QIODevice::WriteOnly);
    img.save(&buf, "JPG");
    pMimeData->setData("image/jpg", data);

    QDrag* pDrag = new QDrag(this);
    pDrag->setMimeData(pMimeData);
    pDrag->exec(Qt::MoveAction);
}

MyDragClass::MyDragClass()
{

}
