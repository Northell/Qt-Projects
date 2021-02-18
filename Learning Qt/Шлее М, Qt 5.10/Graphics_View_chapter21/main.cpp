#include <QtWidgets>

//Листинг 21.1 Размещение на сцене четырех элементов
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QGraphicsScene scene(QRectF(-100,-100,300,300));
    QGraphicsView view(&scene);

    QGraphicsRectItem* pRectItem =
            scene.addRect(QRectF(-30,-30,120,80),
                      QPen(Qt::black),
                      QBrush(Qt::green)
                      );

    pRectItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pPixmapItem =
            scene.addPixmap(QPixmap(":/img"));
    pPixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsTextItem* pTextItem =
            scene.addText("Move us with your mouse");
    pTextItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsLineItem* pLineItem =
            scene.addLine(QLineF(-10,-10,80,80), QPen(Qt::red,2));
    pLineItem->setFlags(QGraphicsItem::ItemIsMovable);

    view.show();



    return a.exec();
}
*/

//Листинг 21.2-21.4 Cоздание собственного представления
/*
#include "myview.h"

class SimpleItem: public QGraphicsItem
{
private:
    enum {nPenWidth = 3};

public:
    virtual QRectF boundingRect() const
    {
        QPointF ptPosition (-10-nPenWidth, -10-nPenWidth);
        QSizeF size(20 + nPenWidth*2, 20 + nPenWidth*2);
        return QRectF(ptPosition,size);
    }

    virtual void paint(QPainter* painter,
                       const QStyleOptionGraphicsItem*,
                       QWidget*
                       )
    {
        painter->save();
        painter->setPen(QPen(Qt::blue, nPenWidth));
       // painter->drawEllipse(-10,-10,20,20);
        painter->restore();
    }

    virtual void mousePressEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::setOverrideCursor(Qt::PointingHandCursor);
        QGraphicsItem::mousePressEvent(pe);
    }

    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* pe)
    {
        QApplication::restoreOverrideCursor();
        QGraphicsItem::mouseReleaseEvent(pe);
    }
};


int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget wgt;
    QGraphicsScene scene (QRectF(-100,-100,640,480));

    MyView* pView                   = new MyView(&scene);
    QPushButton* pcmdZoomIn         = new QPushButton("Zoom In");
    QPushButton* pcmdZoomOut        = new QPushButton("Zoom Out");
    QPushButton* pcmdRotateLeft     = new QPushButton("Rotate Left");
    QPushButton* pcmdRotateRight    = new QPushButton("Rotate Right");

    pView->setRenderHint(QPainter::Antialiasing, true);

    SimpleItem* pSimpleItem = new SimpleItem();
    scene.addItem(pSimpleItem);
    pSimpleItem->setPos(0,0);
    pSimpleItem->setFlags(QGraphicsItem::ItemIsMovable);

    QGraphicsPixmapItem* pixmapItem =
            scene.addPixmap(QPixmap(":/img"));
    pixmapItem->setParentItem(pSimpleItem);
    pixmapItem->setFlags(QGraphicsItem::ItemIsMovable);

    QObject::connect(pcmdZoomIn, &QPushButton::clicked,
                     pView, &MyView::slotZoomIn);

    QObject::connect(pcmdZoomOut, &QPushButton::clicked,
                     pView, &MyView::slotZoomOut);

    QObject::connect(pcmdRotateLeft, &QPushButton::clicked,
                     pView, &MyView::slotRotateLeft);

    QObject::connect(pcmdRotateRight, &QPushButton::clicked,
                     pView, &MyView::slotRotateRight);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout;
    pvbxLayout->addWidget(pView);
    pvbxLayout->addWidget(pcmdZoomIn);
    pvbxLayout->addWidget(pcmdZoomOut);
    pvbxLayout->addWidget(pcmdRotateLeft);
    pvbxLayout->addWidget(pcmdRotateRight);

    wgt.setLayout(pvbxLayout);
    wgt.show();




    return app.exec();
}*/


int main(int argc, char** argv)
{
    QApplication app(argc,argv);

    QGraphicsScene scene(QRectF(0,0,400,400)); //Сцена
    QGraphicsView view(&scene);                //Представление

    QPushButton cmd("Quit");
    QGraphicsProxyWidget* proxyWgt = scene.addWidget(&cmd);  //С этим объектом можно совершать геом. преобразования
    QTransform            transform = proxyWgt->transform();

    transform.translate(100,350);
    transform.rotate(-45,Qt::YAxis);        //Поворот вокруг оси Y
    transform.scale(8,2);

    proxyWgt->setTransform(transform);
    QObject::connect(&cmd, SIGNAL(clicked()),
                     &app, SLOT (quit()));

    QDial dia;
    dia.setNotchesVisible(true);
    proxyWgt = scene.addWidget(&dia);
    transform = proxyWgt->transform();

    transform.scale(4,2);
    transform.rotate(-45,Qt::YAxis);
    proxyWgt -> setTransform(transform);

    QProgressBar prb;
    prb.setFixedSize(500,40);
    proxyWgt = scene.addWidget(&prb);
    transform = proxyWgt->transform();

    transform.translate(20,200);
    transform.scale(2,2);
    transform.rotate(80, Qt::YAxis);
    transform.rotate(30,Qt::XAxis);
    proxyWgt ->setTransform(transform);

    QObject::connect(&dia, SIGNAL(valueChanged(int)),
                     &prb, SLOT(setValue(int))
                     );

    view.rotate(15);
    view.resize(500,500);
    view.show();

    return app.exec();
}
