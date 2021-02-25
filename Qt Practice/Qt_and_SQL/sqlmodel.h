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
    QModelIndex                  index;                                      //Строки для окрашивания

    QVector<int>                 indexRows;
    QStringList                  m_horizontalHeader;

    bool                         b_enabledValue;



public:

   //Наследование
    SQLModel(QSqlQuery* query, int columns, QObject *parent = 0);
    QVariant data(const QModelIndex& index, int role) const override;
    int rowCount(const QModelIndex& parent = QModelIndex() ) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;

    QVariant headerData(int nSection, Qt::Orientation orientation, int nRole) const override;

    //Что то мое
    void setHorizontalHeaderLabels(QStringList const& labels);
    bool setHeaderData(int section, Qt::Orientation orientation, const QString &value, int role);

    QVariant downloadFile();
    bool checkFileInSQL(QVariant file);
    void setEnabledValue(bool value);





};

#endif // SQLMODEL_H
