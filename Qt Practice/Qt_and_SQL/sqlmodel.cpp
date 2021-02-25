#include "sqlmodel.h"
#include <QColor>

SQLModel::SQLModel(QSqlQuery* query, int columns, QObject *parent) : QAbstractTableModel(parent)
                                                      , m_nRows(0)
                                                      , m_nColumns(columns)
                                                      , b_enabledValue(true)

{

    const int MAX_nColumns =m_nColumns;

    m_hash.clear();         //Чистим, если был не пустой

    while (query->next())
    {
        for (m_nColumns = 0;m_nColumns<MAX_nColumns; ++m_nColumns)
        {

        index = createIndex(m_nRows, m_nColumns);
        QString str = QString(query->value(m_nColumns).toString());

//      Тут подумать об автоматизации

        if ((str!=nullptr) && (m_nColumns!=0))
        {
            indexRows.push_back(m_nRows);
        }

        m_hash[index] = str;


//        if (query->value(m_nColumns) == "Equipment")
//            indexRows.push_back(m_nRows);

//===============================================================


        }

        m_nRows++;
      //  m_nColumns = 0;
    }
    m_nColumns = MAX_nColumns;
}

QVariant SQLModel::data(const QModelIndex& index, int role) const
{

    if (!index.isValid())
    {
        return QVariant();
    }



    if(role == Qt::BackgroundRole)
    {

        for (int i = 0; i< indexRows.size(); ++i)
        {
             if(indexRows[i] == index.row())
                 {
                     return QBrush(QColor(Qt::darkYellow));
                 }


        }
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        //Тут подумать об автоматизации
        if ((index.column()==0)||(b_enabledValue))       return m_hash.value(index, QVariant());
        else if (m_hash[index]== "")                     return "[null]";
        else                                             {/*qDebug()<<m_hash[index] << "\n\n";*/ return "[data]";}

        //=============================
    }

        return QVariant();
}

//Переопределяем все гавно для наследования

int SQLModel::rowCount(const QModelIndex&) const
{
    return m_nRows;
}


int SQLModel::columnCount(const QModelIndex&) const
{
    return m_nColumns;
}



bool SQLModel::setHeaderData(int section, Qt::Orientation orientation, const QString &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal || section < 0)  { return false; }



    auto headerLabelsSize = m_horizontalHeader.size();

    if ((section == headerLabelsSize)||(section > headerLabelsSize))
    {
        m_horizontalHeader.push_back(value);
        emit headerDataChanged(orientation, section, section);
        return true;
    }

    m_horizontalHeader[section] = value;
    return true;

}

QVariant SQLModel::downloadFile()                           //Тут, достаем и переводим файл в bytea
{
    QFile file(":/RedGuy");
    if (!file.open(QIODevice::ReadOnly))
    {

    qDebug()<<"Can't open this file for download";
    exit(0);
    }

    QByteArray bytes = file.readAll();
    file.close();

    QString b_downloadFile;
    for(int i = 0; i < bytes.length(); i++)
    b_downloadFile+= bytes.at(i);

    //Отладка, потом убрать
    qDebug()<<"\n\n\n This is File For Download \n"<<QVariant(b_downloadFile);

    return b_downloadFile.toLatin1();

}

bool SQLModel::checkFileInSQL(QVariant file)
{


    const int MaxColumns = m_nColumns;
    const int MaxRows = m_nRows;
    for(m_nRows = 0; m_nRows < MaxRows; ++m_nRows)
    {
         for(m_nColumns = 1; m_nColumns<MaxColumns; ++m_nColumns)
         {
            index = createIndex(m_nRows,m_nColumns);
            if (m_hash[index]==file)
            {
                return true;
            }

         }
    }



    return false;

}

void SQLModel::setEnabledValue(bool b_value)
{
    b_enabledValue = b_value;

}




QVariant SQLModel::headerData(int nSection, Qt::Orientation orientation, int nRole) const
{
    if (nRole != Qt::DisplayRole || orientation != Qt::Horizontal || nSection >= m_horizontalHeader.size())
       {
           return QVariant();
       }

    else return  m_horizontalHeader[nSection];
}

void SQLModel::setHorizontalHeaderLabels(QStringList const& labels)
{

    for (int i = 0; i < labels.size(); ++i)
    {
        setHeaderData(i, Qt::Horizontal, labels[i], Qt::EditRole);
    }
}


