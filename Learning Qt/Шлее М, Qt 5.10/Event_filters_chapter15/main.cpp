//Листинг 15.1-15.3 Программа, демонстирующая перехват события


#include <QtWidgets>
#include "mousefilter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit txt("QLineEdit");
    txt.installEventFilter(new MouseFilter(&txt));
    txt.show();

    QLabel lbl("QLabel");
    lbl.installEventFilter(new MouseFilter(&lbl));
    lbl.show();

    QPushButton cmd("QPushButton");
    cmd.installEventFilter(new MouseFilter(&cmd));
    cmd.show();

    return a.exec();
}
