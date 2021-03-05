#include "downloader.h"

Downloader::Downloader(QObject *pobj):QObject(pobj)
{
    m_pnam = new QNetworkAccessManager(this);
    connect(m_pnam, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(slotFinished(QNetworkReply*)));
}

void Downloader::download(const QUrl &url)
{
    QNetworkRequest request(url);
    QNetworkReply* pnr = m_pnam->get(request);

    connect(pnr,  SIGNAL(downloadProgress(quint64,quint64)),
            this, SIGNAL(downloadProgress(quint64,quint64)));
}

void Downloader::slotFinished(QNetworkReply *pnr)
{
    if(pnr->error() != QNetworkReply::NoError)
    {
        emit error();
    }

    else
    {
        emit done (pnr->url(), pnr->readAll());
    }
    pnr->deleteLater();
}
