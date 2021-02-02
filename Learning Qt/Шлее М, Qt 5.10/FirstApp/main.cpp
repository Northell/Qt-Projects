#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl ("Hello World");
    lbl.show();
    return a.exec();
}
