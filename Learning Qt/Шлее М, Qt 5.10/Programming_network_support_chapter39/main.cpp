//Листинг 39.1-39.13 Реализация простого tcp сервера и клиента, принимающего и подтверждающего получение зпросов клиентов
/*
#include <QtWidgets>
#include "myserver.h"
#include "myclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyServer server(2323);



    MyClient client("localhost", 2323);
    server.show();
    client.show();

    return a.exec();
}
*/

//Листинг 39.14-39.19 Реализация UDP сервера и UDP клиента
/*
#include <QtWidgets>
#include "udpclient.h"
#include "udpserver.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPServer server;
    UDPClient client;

    server.show();
    client.show();


    return a.exec();
}*/

//Листинг 39.20-39.31 Загрузка файлов с http
/*
#include <QtWidgets>
#include "downloadergui.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DownloaderGui downloader;

    downloader.show();
    downloader.resize(280,100);


    return a.exec();
}*/

//Листинг 39.32 TCP-сервер с применением блокирующего подхода

/*
#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>




int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QTcpServer   tcpServer;
    QThread      thread;
    int          nPort = 2424;

    if(!tcpServer.listen(QHostAddress::Any,nPort))
    {
        qDebug() << "Can't listen on port: " << nPort;
        return 0;
    }

    forever
    {
        while (tcpServer.waitForNewConnection(1000))
        {
            do
            {
                QTcpSocket* pSocket = tcpServer.nextPendingConnection();
                QString strDateTime =
                        QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
                pSocket->write(strDateTime.toLatin1());
                pSocket->flush();
                qDebug() << "Server date & time: " + strDateTime;
                pSocket->disconnectFromHost();
                if(pSocket->state() == QAbstractSocket::ConnectedState)
                {
                    pSocket->waitForDisconnected();
                }
                delete pSocket;


            } while (tcpServer.hasPendingConnections());

        }
    }
}*/

//Листинг 39.33 TCP-клиент с применением блокирующего подхода
/*
#include <QTcpSocket>
#include <QTcpServer>
#include <QCoreApplication>

int main(int argc, char**argv)
{
    QCoreApplication a(argc, argv);

    QTcpSocket socket;
    socket.connectToHost(QHostAddress::LocalHost,2424);
    socket.waitForConnected();



    qDebug() << socket.readAll();


    return 0;
}*/

//Листинг 39.34 Установка прокси-сервера

#include <QCoreApplication>
#include <QNetworkProxy>

int main(int argc, char**argv)
{
    QCoreApplication a(argc, argv);
    QNetworkProxy proxy;

    proxy.setType(QNetworkProxy::HttpProxy);
    proxy.setHostName("192.168.178.1");
    proxy.setPort(8080);
    proxy.setUser("User");
    proxy.setPassword("Password");
    QNetworkProxy::setApplicationProxy(proxy);





    return a.exec();
}
