#include "jstools.h"

JsTools::JsTools(QObject *pobj):QObject(pobj)
{

}

void JsTools::print(const QString &str)
{
    qDebug() <<str;
}

void JsTools::alert(const QString &strMessage)
{
    QMessageBox::information(0, "", strMessage);
}

void JsTools::quitApplication()
{
    qApp->quit();
}

QStringList JsTools::dirEntryList(const QString &strDir, const QString &strExt)
{
 QDir dir(strDir);
 return dir.entryList(strExt.split(" "), QDir::Files);
}
