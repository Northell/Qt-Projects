#ifndef SOUNDPLAYER_H
#define SOUNDPLAYER_H


#include <QtWidgets>
#include <QMediaPlayer>

class SoundPlayer:public QWidget
{
    Q_OBJECT
protected:
    QMediaPlayer* m_pmp;
    QVBoxLayout*  m_layout;

private:
    QPushButton* m_pcmdPlay;
    QPushButton* m_pcmdStop;

    QSlider*     m_psldPosition;
    QLabel*      m_plblCurrent;
    QLabel*      m_plblRemain;

    QString msecsToString(qint64 n);

public:
    SoundPlayer(QWidget* pwgt =0);

private slots:
    void slotOpen              ();                      //Открытие файлов
    void slotPlay              ();                      //Управление воспроизведением
    void slotSetSliderPosition (qint64);                //Управление ползунком и обновление времени воспроизведения
    void slotSetMediaPosition  (int);                   //Устанавливает позицию для воспроизведения в объекте класса QMediaPlayer
    void slotSetDuration       (qint64);                //Получает общее время воспроизведения
    void slotStatusChanged     (QMediaPlayer::State);   //Получает актуальный статус объекта QMediaPlayer
};

#endif // SOUNDPLAYER_H
