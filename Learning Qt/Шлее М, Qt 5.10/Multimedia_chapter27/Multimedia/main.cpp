//Qt6 не предоставляет библиотеку QMedia, поэтому будем юзать Qt5.12

//Листинг 27.1-27.10 Реализация медиаплеера
/*
#include <QtWidgets>
#include "soundplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SoundPlayer soundPlayer;

    soundPlayer.resize(320,75);
    soundPlayer.show();

    return a.exec();
}
*/

//Листинг 27.11 Расширение до видеоплеера

#include <QtWidgets>
#include "videoplayer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VideoPlayer videoPlayer;

    videoPlayer.resize(400,450);
    videoPlayer.show();

    return a.exec();
}

