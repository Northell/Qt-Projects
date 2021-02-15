//Листинг 16.1, 16.2 Программа, имитирующая нажатие пользователем
//             клавиш клавиатуры
/*
#include <QtWidgets>

void mousePress (QWidget*         pwgt,
                 int              x,
                 int              y,
                 Qt::MouseButton  bt  = Qt::LeftButton,
                 Qt::MouseButtons bts = Qt::LeftButton
        )
{
    if(pwgt)
    {
        QMouseEvent* pePress =
                new QMouseEvent(QEvent::MouseButtonPress,
                                QPoint(x,y),
                                bt,
                                bts,
                                Qt::NoModifier
                                );
        QApplication::postEvent(pwgt, pePress);
    }
}




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit txt("User input: ");
    txt.show();
    txt.resize(300,20);

    int i;

    for(i=0;i<Qt::Key_Z - Qt::Key_A+1; ++i)
    {

        QChar ch(65+i);
        int   nKey = Qt::Key_A +i;
        QKeyEvent keyPress(QEvent::KeyPress, nKey, Qt::NoModifier,ch);
        QApplication::sendEvent(&txt, &keyPress);

        QKeyEvent keyRelease (QEvent::KeyRelease, nKey, Qt::NoModifier, ch);
        QApplication::sendEvent(&txt, &keyRelease);

    }
    return a.exec();
}
*/

//Литсинг 16.3-16.4 Программа, демонстрирующая подмену события клавиатуры
/*
#include <QtWidgets>



class KeyFilter:public QObject
{
protected:
    bool eventFilter (QObject* pobj, QEvent* pe)
    {
        if(pe->type()== QEvent::KeyPress)
        {
            if (((QKeyEvent*)pe)->key() == Qt::Key_Z)
            {
                QKeyEvent keyEvent (QEvent::KeyPress,
                                    Qt::Key_A,
                                    Qt::NoModifier,
                                    "A"
                                    );
                QApplication::sendEvent(pobj,&keyEvent);
                return true;


            }
        }
        return false;
    }
public:
    KeyFilter(QObject* pobj = 0):QObject(pobj){}
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLineEdit txt("User input: ");
    txt.show();

    KeyFilter* pFilter = new KeyFilter(&txt);
    txt.installEventFilter(pFilter);

    return a.exec();
}
*/
