#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QtWidgets>
#include "soundplayer.h"


class VideoPlayer:public SoundPlayer
{
    Q_OBJECT
public:
    VideoPlayer(QWidget *pwgt = 0);

};

#endif // VIDEOPLAYER_H
