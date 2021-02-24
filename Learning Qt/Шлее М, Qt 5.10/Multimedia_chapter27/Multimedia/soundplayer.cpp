#include "soundplayer.h"

QString SoundPlayer::msecsToString(qint64 n)
{
    int nHours = (n/(60*60*1000));
    int nMinutes = ((n% (60*60*1000))/(60*1000));
    int nSeconds = ((n%(60*1000))/1000);

    return QTime (nHours, nMinutes, nSeconds).toString("hh:mm:ss");
}

SoundPlayer::SoundPlayer(QWidget *pwgt):QWidget(pwgt)
{
    QPushButton* pcmdOpen = new QPushButton("Open");
    QDial*       pDialVolume = new QDial();

    m_pcmdPlay     = new QPushButton();
    m_pcmdStop     = new QPushButton();
    m_psldPosition = new QSlider();
    m_plblCurrent  = new QLabel(msecsToString(0));
    m_plblRemain   = new QLabel(msecsToString(0));
    m_pmp          = new QMediaPlayer();

    m_pcmdPlay->setEnabled(false);
    m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));

    m_pcmdStop->setEnabled(false);
    m_pcmdStop->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    m_psldPosition->setRange(0,0);
    m_psldPosition->setOrientation(Qt::Horizontal);

    pDialVolume->setRange(0,100);
    int nDefaultVolume = 50;
    m_pmp->setVolume(nDefaultVolume);
    pDialVolume->setValue(nDefaultVolume);

    connect(pcmdOpen, SIGNAL(clicked()),
             SLOT(slotOpen())
            );

    connect(m_pcmdPlay, SIGNAL(clicked()),
            SLOT(slotPlay())
            );

    connect(m_pcmdStop, SIGNAL(clicked()),
            m_pmp, SLOT(stop())
            );

    connect(pDialVolume, SIGNAL(valueChanged(int)),
            m_pmp, SLOT(setVolume(int)));

    connect(m_psldPosition, SIGNAL(sliderMoved(int)),
            SLOT(slotSetMediaPosition(int))
            );

    connect(m_pmp, SIGNAL(positionChanged(qint64)),
            SLOT(slotSetSliderPosition(qint64))
            );

    connect(m_pmp, SIGNAL(durationChanged(qint64)),
            SLOT(slotSetDuration(qint64))
            );

    connect(m_pmp, SIGNAL(stateChanged(QMediaPlayer::State)),
            SLOT(slotStatusChanged(QMediaPlayer::State))
            );

    //layout
    QHBoxLayout* phbxPlayControls = new QHBoxLayout();

    phbxPlayControls->addWidget(pcmdOpen);
    phbxPlayControls->addWidget(m_pcmdPlay);
    phbxPlayControls->addWidget(m_pcmdStop);
    phbxPlayControls->addWidget(pDialVolume);

    QHBoxLayout* phbxTimeControls = new QHBoxLayout();

    phbxTimeControls->addWidget(m_plblCurrent);
    phbxTimeControls->addWidget(m_psldPosition);
    phbxTimeControls->addWidget(m_plblRemain);

    m_layout = new QVBoxLayout();
    m_layout->addLayout(phbxPlayControls);
    m_layout->addLayout(phbxTimeControls);

    setLayout(m_layout);


}

void SoundPlayer::slotOpen()
{
    QString strFile = QFileDialog::getOpenFileName(this,"Open FIle");

    if (!strFile.isEmpty())
    {
        m_pmp->setMedia(QUrl::fromLocalFile(strFile));
        m_pcmdPlay -> setEnabled(true);
        m_pcmdStop -> setEnabled(true);
    }
}

void SoundPlayer::slotPlay()
{
    switch(m_pmp->state())
    {
    case QMediaPlayer::PlayingState:
        m_pmp->pause();
        break;
    default:
        m_pmp->play();
        break;
    }
}

void SoundPlayer::slotSetSliderPosition(qint64 n)
{
    m_psldPosition->setValue(n);

    m_plblCurrent->setText(msecsToString(n));
    int nDuration = m_psldPosition->maximum();
    m_plblRemain->setText(msecsToString(nDuration-n));
}

void SoundPlayer::slotSetMediaPosition(int n)
{
    m_pmp->setPosition(n);
}

void SoundPlayer::slotSetDuration(qint64 n)
{
    m_psldPosition->setRange(0,n);
    m_plblCurrent->setText(msecsToString(0));
    m_plblRemain->setText(msecsToString(n));
}

void SoundPlayer::slotStatusChanged(QMediaPlayer::State state)
{
    switch(state)
    {
    case QMediaPlayer::PlayingState:
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
        break;
    default:
        m_pcmdPlay->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
        break;
    }
}
