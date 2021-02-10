//Листинг 12.1 Разделение выделения элементов между тремя представлениями
/*
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget      wgt;

    QStringListModel model;
    model.setStringList(QStringList() << "Itme1" << "Item2" << "Item3");

    QTreeView* pTreeView = new QTreeView();
    pTreeView->setModel(&model);

    QListView* pListView = new QListView();
    pListView->setModel(&model);

    QTableView* pTableView = new QTableView();
    pTableView->setModel(&model);

    QItemSelectionModel selection (&model);
    pTreeView->setSelectionModel(&selection);
    pListView->setSelectionModel(&selection);
    pTableView->setSelectionModel(&selection);

    //Layout setup
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(pTreeView);
    layout->addWidget(pListView);
    layout->addWidget(pTableView);

    wgt.setLayout(layout);

    wgt.show();

    return app.exec();
}
*/

//Листинг 12.2 Реализация простого делегата

/*
#include <QApplication>
#include <QtWidgets>

class SimpleDelegate: public QStyledItemDelegate {
public:
    SimpleDelegate(QObject* pobj =0) : QStyledItemDelegate(pobj)
    {

    }


    void paint (QPainter*                  pPainter,
                const QStyleOptionViewItem& option,
                const QModelIndex&          index
                ) const
    {
        if (option.state& QStyle::State_MouseOver)
        {
            QRect               rect = option.rect;
            QLinearGradient     gradient (0,0,rect.width(),rect.height());

            gradient.setColorAt(0, Qt::white);
            gradient.setColorAt(0.5, Qt::blue);
            gradient.setColorAt(1, Qt::red);

            pPainter->setBrush(gradient);
            pPainter->drawRect(rect);
        }
        QStyledItemDelegate::paint(pPainter,option,index);
    }

    QSize sizeHint (const QStyleOptionViewItem& option,
                    const QModelIndex& //sindex
                    ) const
    {
        return QSize(option.rect.width(),55);
    }
};

int main(int argc, char *argv[])
{
    QApplication     app(argc, argv);

    QStringListModel model;
    model.setStringList(QStringList() << "Item1" <<"Item2" << "Item3");

    QListView listView;
    listView.setModel(&model);
    listView.setItemDelegate(new SimpleDelegate(&listView));
    listView.viewport()->setAttribute(Qt::WA_Hover); //Это для того, чтобы представление реагировало на перемещения курсора
    listView.show();


    return app.exec();
}
*/

//Листинг 12.3 Отображение иерархических данных
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QStandardItemModel model (5,3);

    for(int nTopRow=0; nTopRow<5; ++nTopRow)
    {
        QModelIndex index = model.index(nTopRow,0);
        model.setData(index, "item"+QString::number(nTopRow+1));

        model.insertRows(0,4,index);
        model.insertColumns(0,3,index);

        for(int nRow = 0; nRow<4; ++nRow)
        {
            for(int nCol=0;nCol<3; ++ nCol)
            {
                QString strPos = QString("%1,%2").arg(nRow).arg(nCol);
                model.setData(model.index(nRow, nCol, index), strPos);
            }
        }
    }

    QTreeView treeView;
    treeView.setModel(&model);
    treeView.show();

    return app.exec();
}
*/

//Листинг 12.4 Отображение каталогов и файлов
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication     app(argc,argv);
    QFileSystemModel model;
    QTreeView        treeView;

    model.setRootPath(QDir::rootPath());
    treeView.setModel(&model);
    treeView.show();

   return app.exec();
}
*/

//Листинг 12.5 Программа обозреватель
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication     app(argc,argv);
    QSplitter        spl(Qt::Horizontal);
    QFileSystemModel model;



    model.setRootPath(QDir::rootPath());

    QTreeView* treeView = new QTreeView();
    treeView->setModel(&model);

    QTreeView* tableView = new QTreeView();
    tableView->setModel(&model);

    QObject::connect(treeView, &QTreeView::clicked,
                     tableView, &QTreeView::setRootIndex);

    QObject::connect(treeView, &QTreeView::activated,
                     tableView, &QTreeView::setCurrentIndex);

    QObject::connect(treeView, &QTreeView::activated,
                     tableView, &QTreeView::setRootIndex);

    spl.addWidget(treeView);
    spl.addWidget(tableView);
    spl.show();

   return app.exec();
}
*/


//Листинг 12.6 Применение и установка ролей
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
        QStringList  lst;
        lst << "Linux" << "Windows" << "MacOs" << "Android";

        QStandardItemModel model(lst.size(), 1);
        for (int i = 0; i < model.rowCount(); ++i) {
            QModelIndex index = model.index(i, 0);
            QString     str   = lst.at(i);
            model.setData(index, str, Qt::DisplayRole);
            model.setData(index, "ToolTip for " + str, Qt::ToolTipRole);
            model.setData(index, QIcon(":/" + str), Qt::DecorationRole);
        }

        QListView listView;
        listView.setViewMode(QListView::IconMode);
        listView.setModel(&model);
        listView.show();

        return app.exec();

}
*/

//Листинг 12.7-12.17 Отображение данных модели целых чисел

/*
#include <QtWidgets>
#include "initlistmodel.h"

int main(int argc, char** argv)
{

    QApplication app(argc, argv);
    InitListModel model(QList<int>() << 123 <<2341<<32<<5342<<723);

    QListView list;
    list.setModel(&model);
    list.show();

    QTableView table;
    table.setModel(&model);
    table.show();

    return app.exec();
}
*/

//Листинг 12.17 Отображение табличной модели данных

/*
#include <QtWidgets>

class TableModel : public QAbstractTableModel
{
private:
    int                          m_nRows;
    int                          m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;

public:

    TableModel (int nRows, int nColumns, QObject* pobj =0)
        :QAbstractTableModel(pobj)
        , m_nRows(nRows)
        , m_nColumns(nColumns)
    {

    }

    QVariant data(const QModelIndex& index, int nRole) const
    {
        if (!index.isValid())
        {
            return QVariant();
        }
        QString str = QString("%1,%2").arg(index.row() +1).arg(index.column() +1);
        return (nRole == Qt::DisplayRole || nRole == Qt::EditRole)
                ? m_hash.value(index,QVariant(str))
                : QVariant();
    }

    bool setData(const QModelIndex& index,
                 const QVariant&    value,
                 int                nRole
                 )
    {
        if (index.isValid() && nRole == Qt::EditRole)
        {
            m_hash[index] = value;
            emit dataChanged(index, index);
            return true;
        }
        return false;
    }

    int rowCount (const QModelIndex&) const
    {
        return m_nRows;
    }

    int columnCount (const QModelIndex&) const
    {
        return m_nColumns;
    }

    Qt::ItemFlags flags(const QModelIndex& index) const
    {
        Qt::ItemFlags flags = QAbstractTableModel::flags(index);
        return index.isValid() ? (flags | Qt::ItemIsEditable)
                               :flags;
    }

};


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    TableModel model (200, 200);

    QTableView tableView;
    tableView.setModel(&model);
    tableView.show();

    return app.exec();

}
*/

//Листинг 12.18 Отбор элементов
/*
#include <QtWidgets>


int main(int argc, char**argv)
{
    QApplication app(argc,argv);
    QWidget      wgt;

    QStringListModel model;
    model.setStringList(QStringList() << "Xandria"
                                      <<"Epica"
                                      <<"Therion"
                                      <<"Evanescense"
                                      <<"Nightwish"
                        );

    QSortFilterProxyModel proxyModel;
    proxyModel.setSourceModel(&model);
    proxyModel.setFilterWildcard("E*"); //Которые начинаются на Е

    QListView* pListView1 = new QListView();
    pListView1->setModel(&model);

    QListView* pListView2 = new QListView();
    pListView2->setModel(&proxyModel);


    //layout setup
    QHBoxLayout* layout = new QHBoxLayout();
    layout->addWidget(pListView1);
    layout->addWidget(pListView2);

    wgt.setLayout(layout);
    wgt.show();
    return app.exec();
}
*/

//Листинг 12.19 Получение доступа к модели
/*
#include <QtWidgets>

int main( int argc, char** argv)
{
    QApplication     app(argc,argv);
    QStringList      lst;
    QListWidget      lwg;
    QListWidgetItem* pitem =0;

    lwg.setIconSize(QSize(48,48));
    lst << "Linux" << "Windows" << "MacOs" << "Android";

    foreach(QString str, lst)
    {
        pitem = new QListWidgetItem(str, &lwg);
        pitem->setIcon(QPixmap(":/" + str));
    }

    lwg.setWindowTitle("ListWidget");
    lwg.show();

    QListView listView;
    listView.setModel(lwg.model());
    listView.setSelectionModel(lwg.selectionModel());
    listView.setWindowTitle("listView");
    listView.show();

    return app.exec();
}
*/

