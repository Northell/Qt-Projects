#include "sqlmodel.h"
#include <QColor>

SQLModel::SQLModel(QSqlQuery* query, QObject *parent) : QAbstractTableModel(parent)

{
    m_nColumns = 0;
    m_nRows = 0;
    const int MAX_nColumns =8;


    while (query->next())
    {
        for (;m_nColumns<MAX_nColumns; ++m_nColumns)
        {

        index = createIndex(m_nRows, m_nColumns);
        QString str = QString(query->value(m_nColumns).toString());
        m_hash[index] = str;

        if (query->value(m_nColumns) == "Equipment")
            indexRows.push_back(m_nRows);

        }

        m_nRows++;
        m_nColumns = 0;
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
                     return QBrush (QColor(Qt::green));
                 }

        }
    }

    if(role == Qt::DisplayRole || role == Qt::EditRole)
    {
        return m_hash.value(index, QVariant());
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
    if (role != Qt::EditRole || orientation != Qt::Horizontal || section < 0)
    {
        return false;
    }

    auto headerLabelsSize = m_horizontalHeader.size();

    if (section == headerLabelsSize)
    {
        m_horizontalHeader.push_back(value);

        emit headerDataChanged(orientation, section, section);

        return true;
    }

    if (section > headerLabelsSize)
    {

        m_horizontalHeader.push_back(value);

        emit headerDataChanged(orientation, section, section);

        return true;
    }

    m_horizontalHeader[section] = value;

    return true;

}



QVariant SQLModel::headerData(int nSection, Qt::Orientation orientation, int nRole) const
{
    if (nRole != Qt::DisplayRole || orientation != Qt::Horizontal || nSection >= m_horizontalHeader.size())
       {
           return QVariant();
       }

       return  m_horizontalHeader[nSection];
}

void SQLModel::setHorizontalHeaderLabels(QStringList const& labels)
{

    for (int i = 0; i < labels.size(); ++i)
    {
        setHeaderData(i, Qt::Horizontal, labels[i], Qt::EditRole);
    }
}


