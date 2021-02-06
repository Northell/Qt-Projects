#include <QtWidgets>
//Листинг 10.1 Создание однострочных полей
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    QLabel* plblDisplay = new QLabel();
    plblDisplay->setFrameStyle(QFrame::Box | QFrame::Raised);
    plblDisplay->setLineWidth(2); //Толщина рамки
    plblDisplay->setFixedHeight(50);

    QLabel*    plblText = new QLabel("&Text");
    QLineEdit* ptxt     = new QLineEdit();
    plblText->setBuddy(ptxt);

    QObject::connect(ptxt, SIGNAL (textChanged(const QString&)),
                     plblDisplay, SLOT(setText(const QString&))
                     );

    QLabel*    plblPassword = new QLabel("&Password:");
    QLineEdit* ptxtPassword = new QLineEdit();

    plblPassword->setBuddy(ptxtPassword);
    ptxtPassword->setEchoMode(QLineEdit::Password);

    QObject::connect(ptxtPassword, SIGNAL (textChanged(const QString&)),
                     plblDisplay, SLOT(setText(const QString&))
                     );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();

    pvbxLayout->addWidget(plblDisplay);
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);
    pvbxLayout->addWidget(plblPassword);
    pvbxLayout->addWidget(ptxtPassword);

    wgt.setLayout(pvbxLayout);

    wgt.show();
    return a.exec();
}
*/
//Листинг 10.2 Программа отображения Html документа
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextEdit    txt;
    txt.setHtml ("<HTML>"
                 //"<BODY BGCOLOR = YELLOW>"
                 "<CENTER><IMG SRC =\":/RedGuy.png\"></CENTER>"
                 "<H2><CENTER>Red Guy</CENTER><H2>"
                 "<FONT COLOR = BLUE>"
                 "<P ALIGN = \"center\""
                 "<I>"
                 "Magic! Magic! <BR>"
                 "Go Fuck YourSelf!)<BR>"
                 "Magic! Magic! <BR>"
                 "..."
                 "</I>"
                 "</P>"
                 "</FONT></BODY></HTML>"
                );
    txt.resize(320,350);
    txt.show();
    return a.exec();
}*/

//Листинг 10.3, 10.4 Запись в формате ODF, Запись в формате PDF
/*
#include <QtWidgets>

int main(int argc, char** argv)
    {

    QApplication app(argc, argv);

    QTextEdit* ptxt = new QTextEdit("This is a <b>TEST</b>");
    //Листинг 10.3
    //    QTextDocumentWriter writer;

    //    writer.setFormat("odf");
    //    writer.setFileName("output.odf");
    //    writer.write(ptxt->document());
    //=================
    //Листинг 10.4
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("output,pdf");
    ptxt->document()->print(&printer);


    return app.exec();
    }
*/


//Листинг 10.5-10.9 Создание редактора, обеспечивающего расцветку синтаксиса
/*
#include <QtWidgets>
#include "syntaxhighliter.h"

int main(int argc, char**argv)
{
    QApplication app(argc, argv);
    QTextEdit    txt;

    QFont fnt("Lucida Console", 9, QFont::Normal);
    txt.document()->setDefaultFont(fnt);

    new SyntaxHighLiter (txt.document()); //создаем объект расцветки, иначе не робит

    QPalette pal = txt.palette();
    pal.setColor(QPalette::Base, Qt::darkBlue);
    pal.setColor(QPalette::Text, Qt::yellow);
    txt.setPalette(pal);


    txt.show();
    txt.resize(640,480);

    QFile file(":/SyntaxHighliter.cpp");
    file.open(QFile::ReadOnly);
    txt.setPlainText(QLatin1String(file.readAll()));

    return app.exec();


}

*/
//Листинг 10.10, 10.11 Создание счетчика, Создание виджета,
//                     отображающего дату и время

/*
#include <QtWidgets>

int main(int argc, char**argv)
{
    QApplication app(argc, argv);
    QSpinBox     spb;

    spb.setRange(1,100);
    spb.setSuffix(" MB");
    spb.setButtonSymbols(QSpinBox::PlusMinus);
    spb.setWrapping(true);
    spb.show();
    spb.resize(100,30);

    //10.11
    QDateTimeEdit dateTimeEdit(QDateTime::currentDateTime());
    dateTimeEdit.show();


    QApplication::setStyle("Windows");
    return app.exec();

}*/

//Листинг 10.12, 10.13 Создание котроллера
/*
#include <QtWidgets>
#include <QRegularExpression>


class NameValidator:public QValidator
{
public:
    NameValidator(QObject* parent):QValidator(parent){}

    virtual State validate (QString& str, int& pos) const
    {
        QRegularExpression rxp = QRegularExpression("[0-9]");
        if (str.contains(rxp))
        {
            return Invalid;
        }
        return Acceptable;
    }
};

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QLabel* plblText =
            new QLabel("&Name (The digits will not be accepted!):");

    QLineEdit* ptxt = new QLineEdit();

    NameValidator* pnameValidator = new NameValidator(ptxt);
    ptxt->setValidator(pnameValidator);
    plblText->setBuddy(ptxt);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(plblText);
    pvbxLayout->addWidget(ptxt);

    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}*/
