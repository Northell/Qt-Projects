//Листинг 3.2 Перенаправление потока вывода сообщений в файл (создание protocol.log)
/*
#include <QApplication>
#include <QFile>
#include <QDateTime>


void messageToFile(QtMsgType                 type,
                   const QMessageLogContext& context,
                   const QString&            msg
                   ) //Это обязательные параметры для передачи в qInstallMessageHandler()
{
    QFile file("protocol.log");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        return;

    QString strDateTime =
            QDateTime::currentDateTime().toString("dd.MM.yy-hh:mm");

    QTextStream out(&file);
    switch(type) {
        case QtDebugMsg:
            out << strDateTime << "Debug: "<<msg<<", "<<context.file << "\n";
            break;

        case QtWarningMsg:
            out << strDateTime << "Warning: " << msg << ", " <<context.file << "\n";
            break;
        case QtCriticalMsg:
            out << strDateTime << "Critical: " << msg << ", " << context.file <<"\n";
            break;
        case QtFatalMsg:
            out << strDateTime << "Fatal: " << msg << ", "<<context.file << "\n";
            abort();

    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qInstallMessageHandler(messageToFile);

    qDebug() <<"Chlen: \n ";

    qInstallMessageHandler(0);
    qDebug() << "Pis'ka \n";

    return a.exec();
} */
//Листинг 3.3 Сокрытие информации, выводимой функциями qDebug(), qWarning(), qFatal()
/*
//Если вывод в релизной версии не желателен, и все сообщения должны отображаться
//только в отладочной версии программы, то можно реализовать пустую функцию для
//управдения выводом dummyOutput() и установить ее в qInstallMessageHandler()
#include <QApplication>

void dumyOutput(QtMsgType, const QMessageLogContext&, const QString&)
{

}

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
#ifndef QT_DEBUG
    qInstallMessageHandler(dumyOutput());
#endif
    qDebug() << "Test1" << 123 << "Test2" <<456;
    return app.exec();
}
*/

