#include "downloadergui.h"


void DownloaderGui::showPic(const QString &strFileName)
{
    QPixmap pix(strFileName);
    pix = pix.scaled(pix.size()/2,
                     Qt::IgnoreAspectRatio,
                     Qt::SmoothTransformation);

    QLabel* plbl = new QLabel();
    plbl->setPixmap(pix);
    plbl->setFixedSize(pix.size());
    plbl->show();
}

DownloaderGui::DownloaderGui(QWidget *pwgt): QWidget(pwgt)
{
    m_pdl = new Downloader(this);
    m_ppb = new QProgressBar();
    m_ptxt = new QLineEdit();
    m_pcmd = new QPushButton(tr("&Go"));

    QString strDownloadLink = "http://qt-book.com/pic.jpg";
    m_ptxt->setText(strDownloadLink);

    connect(m_pcmd, SIGNAL(clicked()), SLOT(slotGo()));
    connect(m_pdl, SIGNAL(downloadProgress(quint64,quint64)),
            SLOT(slotDownloadProgress(quint64,quint64)));
    connect(m_pdl, SIGNAL(done(const QUrl&, const QByteArray&)),
            SLOT(slotDone(const QUrl&, const QByteArray&)));

    QGridLayout* layout = new QGridLayout();
    layout->addWidget(m_ptxt,0,0);
    layout->addWidget(m_pcmd,0,1);
    layout->addWidget(m_ppb,1,0,1,1);
    setLayout(layout);

}

void DownloaderGui::slotGo()
{
    m_pdl->download(QUrl(m_ptxt->text()));
}

void DownloaderGui::slotError()
{
    QMessageBox::critical(0,
                          tr("Error"),
                          tr("An error while download is occured"));
}

void DownloaderGui::slotDownloadProgress(quint64 nReceived, quint64 nTotal)
{
    if(nTotal<=0)
    {
        slotError();
        return;
    }
    m_ppb->setValue(100*nReceived/nTotal);
}

void DownloaderGui::slotDone(const QUrl &url, const QByteArray &ba)
{
    QString strFileName =
            QStandardPaths::writableLocation(QStandardPaths::PicturesLocation)
            + "/" + url.path().section('/',-1);
    QFile file(strFileName);
    if(file.open(QIODevice::WriteOnly))
    {
        file.write(ba);
        file.close();

        if(strFileName.endsWith(".jpg")
                || strFileName.endsWith(".png"))
        {
            showPic(strFileName);
        }
    }
}
