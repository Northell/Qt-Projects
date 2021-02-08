//Листинг 11.1, 11.2 Создание простого списка, Создание списка в режиме пиктограмм
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication     app(argc, argv);
    QStringList      lst;
    QListWidget      lwg;
    QListWidgetItem* pitem = 0;

    lwg.setIconSize(QSize(48,48));
    //11.2
    lwg.setSelectionMode(QAbstractItemView::MultiSelection);
    lwg.setViewMode(QListView::IconMode);
    //====

    lst << "Linux" <<"Windows"<<"MacOS X"<<"Android";

    foreach (QString str, lst) {
        pitem = new QListWidgetItem(str, &lwg);
        pitem->setIcon (QPixmap(":/" + str + ".jpg"));

        //11.2
        pitem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable |
                        Qt::ItemIsEditable | Qt::ItemIsDragEnabled);
        //====
    }


    lwg.resize(150,150);
    //lwg.resize(125,175);

    lwg.show();

    return app.exec();
}
*/

//Листинг 11.3, 11.4 Создание иерархического списка
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
   QApplication app(argc, argv);
   QTreeWidget  twg;
   QStringList  lst;

   lst << "Folders"<<"Used Space";
   twg.setHeaderLabels(lst);
   twg.setSortingEnabled(true);

   QTreeWidgetItem* ptwgItem = new QTreeWidgetItem(&twg);
   ptwgItem->setText(0,"Local Disk(C)");
   ptwgItem->setIcon(0,QPixmap(":/Linux.jpg"));

   QTreeWidgetItem* ptwgItemDir = 0;

   for (int i = 1; i<20; ++i)
   {
       ptwgItemDir=new QTreeWidgetItem(ptwgItem);
       ptwgItemDir->setText(0, "Directory" + QString::number(i));
       ptwgItemDir->setText(1, QString::number(i) + " MB");
       ptwgItemDir->setIcon(0, QPixmap(":/Android.jpg"));

   }
   ptwgItem->setExpanded(true);
   twg.resize(350,310);
   twg.show();


   return app.exec();

}
*/

//Листинг 11.5 Перезапись QtreeWidgetItem::operator<()
/*
bool MyТreeWidgetitem::operator(const QTreeWidgetitem& ptwiOther)
bool bRet false;
int nColumn treeWidget()->sortColumn();
if (nColumn == 0) {
QString strFormat = "dd.ММ.уууу";
bRet = QDate::fromString(text(nColumn))
< QDate::fromString(ptwi.text(nColumn) );
return bRet;
}*/

//Листинг 11.6 Создание табицы
/*
#include <QtWidgets>

int main (int argc, char** argv)
{
    const int MAX = 3;

    QApplication      app(argc, argv);
    QTableWidget      tbl(MAX, MAX);
    QTableWidgetItem* ptwi =0;
    QStringList       lst;

    lst << "First"<<"Second"<<"Third";
    tbl.setHorizontalHeaderLabels(lst);
    tbl.setVerticalHeaderLabels(lst);

    for(int i =0;i<MAX;++i)
    {
        for(int j=0;j<MAX; ++j)
        {
            ptwi = new QTableWidgetItem(QString ("%1,%2").arg(i).arg(j));
            tbl.setItem(i,j,ptwi);
        }
    }
    tbl.resize(370,135);
    tbl.show();

    return app.exec();

}
*/

//Листинг 11.7 Создание выпадающего списка
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QComboBox    cbo;
    QStringList  lst;

    lst << "John" << "Paul" << "George" << "Ringo";
    cbo.addItems(lst);
    cbo.setEditable(true);
    cbo.show();
    return app.exec();
}
*/

//Листинг 11.8 Организация вкладок
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QTabWidget   tab;
    QStringList  lst;

    lst << "Linux" << "Windows" << "MacOS X" << "Android";

    foreach (QString str, lst)
    {
        tab.addTab(new QLabel (str, &tab), QPixmap(":/" + str + ".jpg"), str);

    }
    tab.resize(420,100);
    tab.show();

    return app.exec();
}
*/

//Листинг 11.9 Создание панели инструментов
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QToolBox tbx;
    QStringList  lst;

    lst << "Linux" << "Windows" << "MacOS X" << "Android";

    foreach (QString str, lst)
    {
        tbx.addItem(new QLabel (str, &tbx), QPixmap(":/" + str + ".jpg"), str);

    }
    tbx.resize(420,100);
    tbx.show();

    return app.exec();
}
*/

