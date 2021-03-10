//Листинг 42.1-42.4 Реализация динамической библиотеки

#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel lbl ("this is an example text");
    QLibrary lib("dynlib");

    typedef QString (*Fct)(const QString&);
    Fct fct = (Fct)(lib.resolve("oddUpper"));
    if(fct)
    {
        lbl.setText(fct(lbl.text()));
    }
    lbl.show();

    return a.exec();
}
