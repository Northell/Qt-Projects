#ifndef DOWNLOADERGUI_H
#define DOWNLOADERGUI_H

#include <QtWidgets>
#include <QUrl>
#include "downloader.h"

class DownloaderGui:public QWidget
{
    Q_OBJECT
private:
    Downloader*   m_pdl;
    QProgressBar* m_ppb;
    QLineEdit*    m_ptxt;
    QPushButton*  m_pcmd;
    void showPic(const QString&);
public:
    DownloaderGui(QWidget*pwgt = 0);

private slots:
    void slotGo              ();
    void slotError           ();
    void slotDownloadProgress(quint64, quint64);
    void slotDone            (const QUrl&, const QByteArray&);

};

#endif // DOWNLOADERGUI_H
