#include "videoplayer.h"
#include <QVideoWidget>

VideoPlayer::VideoPlayer(QWidget *pwgt):SoundPlayer(pwgt)
{
    QVideoWidget* pvw = new QVideoWidget();
    pvw->setMinimumSize(300,300);

    m_layout->addWidget(pvw);
    m_pmp->setVideoOutput(pvw);
}
