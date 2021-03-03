#include "grabwidget.h"

GrabWidget::GrabWidget(QWidget *pwgt):QWidget(pwgt)
{
    resize(640,480);
    m_plbl = new QLabel();

    QPushButton* pcmd = new QPushButton("Capture Screen");

    connect(pcmd, &QPushButton::clicked,
            this, &GrabWidget::slotGrabScreen);

    //layout
    QVBoxLayout* layout = new QVBoxLayout();

    layout->addWidget(pcmd);
    layout->addWidget(m_plbl);
    setLayout(layout);
}

void GrabWidget::slotGrabScreen() //Изменен в соответствии с Qt6
{

    QPixmap pix;
    QScreen *screen = QGuiApplication::primaryScreen();
    if (screen)
    pix=screen->grabWindow(0);

    m_plbl->setPixmap(pix.scaled(m_plbl->size()));

}
