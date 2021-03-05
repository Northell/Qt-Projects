#include "myclient.h"

MyClient::MyClient(const QString &strHost, int nPort, QWidget *pwgt)
                    :QWidget(pwgt), m_nNextBlockSize(0)
{
    m_pTcpsocket = new QTcpSocket(this);

   m_pTcpsocket->connectToHost(strHost, nPort);
   connect(m_pTcpsocket, SIGNAL(connected()),SLOT (slotConnected()));
   connect(m_pTcpsocket, SIGNAL(readyRead()),SLOT (slotReadyRead()));
    //Qt6 Исправление
   connect(m_pTcpsocket, SIGNAL(errorOccurred(QAbstractSocket::SocketError)),
           this,         SLOT(slotError(QAbstractSocket::SocketError)));
    //==========
    m_ptxtInfo = new QTextEdit();
    m_ptxtInput = new QLineEdit();

    m_ptxtInfo->setReadOnly(true);

    QPushButton* pcmd = new QPushButton("&Send");
    connect(pcmd, SIGNAL(clicked()), SLOT(slotSendToServer()));


    connect(m_ptxtInput, SIGNAL(returnPressed())
            ,this,  SLOT(slotSendToServer()));

    //Layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(new QLabel("<h1>Client </H1>"));
    layout->addWidget(m_ptxtInfo);
    layout->addWidget(m_ptxtInput);
    layout->addWidget(pcmd);
    setLayout(layout);

}

void MyClient::slotReadyRead()
{
    QDataStream in (m_pTcpsocket);
    in.setVersion(QDataStream::Qt_6_0);
    for(;;)
    {
        if (!m_nNextBlockSize)
        {
            if(m_pTcpsocket->bytesAvailable()<sizeof(quint16))
            {
                break;
            }
            in>>m_nNextBlockSize;
        }
        if(m_pTcpsocket->bytesAvailable()<m_nNextBlockSize)
        {
            break;
        }
        QTime time;
        QString str;
        in>>time>>str;
        m_ptxtInfo->append(time.toString() + " " + str);
        m_nNextBlockSize = 0;
    }
}

void MyClient::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
            "Error: " + (err==QAbstractSocket::HostNotFoundError?
                             "The host was not found." :
                             err == QAbstractSocket::RemoteHostClosedError?
                                 "The remote host is closed.":
                             err == QAbstractSocket::ConnectionRefusedError?
                                 "the connection was refused." :
                             QString(m_pTcpsocket->errorString()));
    m_ptxtInfo->append(strError);
}

void MyClient::slotSendToServer()
{
    QByteArray arrBlock;
    QDataStream out (&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    out << quint16(0) << QTime::currentTime()<<m_ptxtInput->text();

    out.device()->seek(0);
    out << quint16(arrBlock.size()-sizeof (quint16));

    m_pTcpsocket->write(arrBlock);
    m_ptxtInput->setText("");
}

void MyClient::slotConnected()
{
    m_ptxtInfo->append("Received the connected() signal");
}
