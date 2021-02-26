#include "drop.h"

void Drop::dragEnterEvent(QDragEnterEvent *pe)
{
    if (pe->mimeData()->hasFormat ("text/uri-list")) // Тут, за каким-то хером вместо url-list uri-list
    {
        pe->acceptProposedAction();
    }
}

void Drop::dropEvent(QDropEvent *pe)
{
    QList<QUrl> urlList = pe->mimeData()->urls();
    QString     str;
    foreach(QUrl url, urlList) {
        str += url.toString() + "\n";
    }
    setText("Dropped:\n" + str);
}

Drop::Drop(QWidget *pwgt): QLabel("Drop Area", pwgt)
{
   // this->resize(200,200);
    setAcceptDrops(true);
}
