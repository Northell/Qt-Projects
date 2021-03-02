
//Листинг 31.1 Пример реализации меню
/*#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QMenuBar mnuBar;
    QMenu* pmnu = new QMenu("&Menu");               //всплыв.меню

    pmnu->addAction("&About Qt",
                    &app,
                    SLOT(aboutQt()),
                    Qt::CTRL + Qt::Key_Q
                    );

    pmnu->addSeparator();

    QAction* pCheckableAction = pmnu->addAction("&CheckableItem");
    pCheckableAction->setCheckable(true);
    pCheckableAction->setChecked(true);

    pmnu->addAction(QPixmap(":/RedGuy"), "&IconItem");
    QMenu* pmnuSubMenu = new QMenu ("&SubMenu", pmnu);
    pmnu->addMenu(pmnuSubMenu);
    pmnuSubMenu->addAction("&Test");

    QAction* pDisabledActioin = pmnu->addAction("&DisabledItem");
    pDisabledActioin->setEnabled(false);

    pmnu->addSeparator();                           //Разделитель
    pmnu->addAction("&Exit", &app, SLOT(quit()));

    mnuBar.addMenu(pmnu);
    mnuBar.show();


    return app.exec();
}*/


#include <QtWidgets>
#include "contextmenu.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    ContextMenu menu;

    menu.resize(150,150);
    menu.show();



    return a.exec();
}
