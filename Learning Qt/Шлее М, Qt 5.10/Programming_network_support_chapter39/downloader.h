#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QtWidgets>
#include <QNetworkReply>
#include <QUrl>
class Downloader:public QObject
{
    Q_OBJECT
private:
    QNetworkAccessManager* m_pnam;

public:
    Downloader(QObject* pobj = 0);

    void download(const QUrl&);

signals:
    void downloadProgress(quint64, quint64);
    void done(const QUrl&, const QByteArray&);
    void error();

private slots:
    void slotFinished(QNetworkReply*);
};

#endif // DOWNLOADER_H
