#include "mywidget1.h"
#include <QQuickWidget>
#include <QQmlContext>

MyWidget1::MyWidget1(QWidget *pwgt):QWidget(pwgt)
{
    QQuickWidget* pv = new QQuickWidget();
    pv->setSource(QUrl(":/main"));

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(pv);
    setLayout(layout);

    QQmlContext* pcon = pv->rootContext();
    QStringList lst;
    for(int i =0; i<100; ++i)
    {
        lst<<"Item" + QString::number(i);
    }

    QStringListModel* pmodel = new QStringListModel(this);
    pmodel->setStringList(lst);
    pcon->setContextProperty("myModel", pmodel);
    pcon->setContextProperty("myText", "pmodel");
    pcon->setContextProperty("myColor", QColor(Qt::yellow));
    pcon->setContextProperty("myWidget", this);



}

void MyWidget1::slotDisplayDialog()
{
    QMessageBox::information(0,"Message", "It's my message");

}
