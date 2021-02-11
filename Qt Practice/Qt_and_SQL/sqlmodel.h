#ifndef SQLMODEL_H
#define SQLMODEL_H


#include <QtWidgets>
#include <QtSql>

class SQLModel:public QAbstractTableModel
{

private:

    int                          m_nRows;
    int                          m_nColumns;
    QHash<QModelIndex, QVariant> m_hash;
    QModelIndex index;

    QVector<int>                 indexRows;
    QStringList                  m_horizontalHeader;


public:

   //Наследование
    SQLModel(QSqlQuery* query, QObject *parent = 0);
    QVariant data(const QModelIndex& index, int role) const override;
    int rowCount(const QModelIndex& parent = QModelIndex() ) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData(int nSection, Qt::Orientation orientation, int nRole) const override;

    //Что то мое
    void setHorizontalHeaderLabels(QStringList const& labels);
    bool setHeaderData(int section, Qt::Orientation orientation, const QString &value, int role);



};

#endif // SQLMODEL_H
