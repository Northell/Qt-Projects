//Листинг 40.1-40.2 Чтение xml документа и вывод его данных на экран
/*
#include <QCoreApplication>
#include <QtXml>

void traverseNode (const QDomNode& node)
{
    QDomNode domNode = node.firstChild();
    while(!domNode.isNull())
    {
        if (domNode.isElement())
        {
            QDomElement domElement = domNode.toElement();
            if(!domNode.isNull())
            {
                if(domElement.tagName() == "contact")
                {
                    qDebug() << "Attr: " << domElement.attribute("number", "");
                }
                else
                {
                    qDebug() << "TagName: " << domElement.tagName()
                             << "\tText: " <<domElement.text();
                }
            }
        }
        traverseNode(domNode);
        domNode = domNode.nextSibling();
    }
}


int main(int argc, char *argv[])
{
    QDomDocument domDoc;
    QFile   file(":/addressbook.xml");

    if(file.open(QIODevice::ReadOnly))
    {
        if(domDoc.setContent(&file))
        {
            QDomElement domElement = domDoc.documentElement();
            traverseNode(domElement);
        }
        file.close();
    }
    return 0;
}

*/

//Листинг 40.3 Создание XML-документа

/*

#include <QtXml>
#include <QDomDocument>
#include <QDomElement>

QDomElement makeElement(QDomDocument & domDoc,
                        const QString& strName,
                        const QString& strArr = QString(),
                        const QString& strText = QString())
{
    QDomElement domElement = domDoc.createElement(strName);
    if(!strArr.isEmpty())
    {
        QDomAttr domAttr = domDoc.createAttribute("number");
        domAttr.setValue(strArr);
        domElement.setAttributeNode(domAttr);

    }

    if(!strText.isEmpty())
    {
        QDomText domText = domDoc.createTextNode(strText);
        domElement.appendChild(domText);
    }
    return domElement;
}
QDomElement contact( QDomDocument& domDoc,
                     const QString& strName,
                     const QString& strPhone,
                     const QString& strEmail
                     )
{
    static int nNumber = 1;
    QDomElement domElement = makeElement(domDoc, "contact", QString().setNum(nNumber));

    domElement.appendChild(makeElement(domDoc, "name", "" , strName));
    domElement.appendChild(makeElement(domDoc, "phone ", "" , strPhone));
    domElement.appendChild(makeElement(domDoc, "email", "" , strEmail));
    nNumber++;
    return domElement;

}

int main(int argc, char *argv[])
{
    QDomDocument doc("AddresBook");
    QDomElement  domElement = doc.createElement("addresbook");
    doc.appendChild(domElement);

    QDomElement contact1 =
            contact(doc, "Piggy", "+777777", "piggy@mega.de");

    QDomElement contact2 =
            contact(doc, "Kermit", "2020202", "djdjdj@djdj,de");

    QDomElement contact3 =
            contact(doc, "pupka", "2023330202", "djdjdj@djdj,de");

    domElement.appendChild(contact1);
    domElement.appendChild(contact2);
    domElement.appendChild(contact3);

    QFile   file("addressbook.xml");


    if(file.open(QIODevice::WriteOnly))
    {
        QTextStream(&file) << doc.toString();
        file.close();
    }

    return 0;
}
*/

//Листинг 40.6-40.7 Чтение XML документа через Sax

//Qt6 исключил возможность работы с SAX

//Листинг 40.8 Чтение при помощи класса QxmlStreamReader
/*
 #include <QtXml>

int main()
{
    QFile file(":/addressbook.xml");
    if(file.open(QIODevice::ReadOnly))
    {
        QXmlStreamReader sr(&file);
        do
        {
            sr.readNext();
            qDebug() << sr.tokenString() << sr.name() << sr.text();
        } while (!sr.atEnd());
        if(sr.hasError())
        {
            qDebug() << "Error: " << sr.errorString();
        }
        file.close();
    }
    return 0;
}
*/

//Листинг 40.9 Интерпретатор xQuery
#include <QtCore>
#include <QtXmlPatterns>
