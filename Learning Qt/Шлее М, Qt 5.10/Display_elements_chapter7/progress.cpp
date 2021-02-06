#include "progress.h"



Progress::Progress(QWidget *pobj):QWidget(pobj), m_nStep(0)
{
    m_pprb = new QProgressBar();
    m_pprb->setRange(0, 5);
    m_pprb->setMinimumWidth(200);
    m_pprb->setAlignment(Qt::AlignCenter);

    QPushButton* pcmdStep = new QPushButton("&Step");
    QPushButton* pcmdReset = new QPushButton("&Reset");

    QObject::connect(pcmdStep, SIGNAL(clicked()), SLOT (slotStep()));
    QObject::connect(pcmdReset, SIGNAL(clicked()), SLOT (slotReset()));

    //LayoutSetup
    QHBoxLayout* phbxLayout = new QHBoxLayout();
    phbxLayout->addWidget(m_pprb);
    phbxLayout->addWidget(pcmdStep);
    phbxLayout->addWidget(pcmdReset);

    setLayout(phbxLayout);


}

void Progress::slotStep()
{
    m_pprb->setValue(++m_nStep);

//мой код для разнообразия

//    if (m_pprb->value()==5)
//    {
//       lbl = new QLabel();
//        QPixmap pix(":/Image1.png");

//        lbl->resize(pix.size());
//        lbl->setPixmap(pix);
//        lbl->show();
//    }
}

void Progress::slotReset()
{
    m_nStep=0;
    m_pprb->reset();

}

