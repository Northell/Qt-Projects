
//Листинг 41.1 Функция соединения с базой данных

#include <QtSql>


static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("AddressBook");
    db.setUserName("elton");
    db.setHostName("epica");
    db.setPassword("password");
    if(!db.open())
    {
        qDebug() <<"Cannot open database: " << db.lastError();
        return false;
    }
    return true;
}


//Листинг 41.2 Исполнение команд SQL. Раскомментить 41.1
/*
#include <QtSql>


int main(int argc, char *argv[])
{

    if(!createConnection())
    {
        return-1;
    }

    //Создаеи бд
    QSqlQuery query;
    QString str = "CREATE TABLE addressbook ("
                  "number INTEGER PRIMARY KEY NOT NULL,"
                  "name  VARCHAR(15), "
                  "phone VARCHAR(12),"
                  "email VARCHAR(15)"
                  ");";
    if(!query.exec(str))
    {
        qDebug() << "Unable to create a table";
    }

    //Добавляем данные в таблицу
    QString strF =
            "INSERT INTO addressbook (number, name, phone, email) "
            "Values('%1','%2','%3','%4');";
    str = strF.arg("1")
            .arg("Piggy")
            .arg("+78788778+")
            .arg("pigge@jfjfj.ti");

    if(!query.exec(str))
    {
        qDebug() << "Unable to make insert operation";
    }

    str = strF.arg("2")
            .arg("Pig2gy")
            .arg("+787288778+")
            .arg("pigge2@jfjfj.ti");
    if(!query.exec(str))
    {
        qDebug() << "Unable to make insert operation";
    }
    str = strF.arg("3")
            .arg("Pig3gy")
            .arg("+787388778+")
            .arg("pigge3@jfjfj.ti");

    if(!query.exec(str))
    {
        qDebug() << "Unable to make insert operation";
    }
    if(!query.exec("SELECT * FROM addressbook;"))
    {
        qDebug() << "UNABLE to execute query - exiting";
        return 1;
    }




    Считываем данные из бд
    QSqlRecord rec = query.record();
    int nNumber = 0;
    QString strName;
    QString strPhone;
    QString strEmail;

    while (query.next())
    {
        nNumber =  query.value(rec.indexOf("number")).toInt();
        strName =  query.value(rec.indexOf("name")).toString();
        strPhone = query.value(rec.indexOf("phone")).toString();
        strEmail = query.value(rec.indexOf("email")).toString();

        qDebug() << nNumber << " " <<strName << ";\t"
                << strPhone << ";\t"<<strEmail;
    }

    return 0;
}
*/

//Листинг 41.3 Использвание модели опроса. Раскомментить 41.1
/*
#include <QtWidgets>
//#include <QtSql>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    if(!createConnection())
    {
        return -1;
    }

    QTableView view;
    QSqlQueryModel model;
    model.setQuery("SELECT phone, email "
                    "FROM AddressBook "
                    "WHERE name = 'Piggy'; ");

    if(model.lastError().isValid())
    {
        qDebug() << model.lastError();
    }

    view.setModel(&model);
    view.show();

    return app.exec();
}
*/

//Листинг 41.4 Использование табличной модели. Раскомментить 41.1
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
   QApplication app(argc, argv);

   if(!createConnection())
   {
       return -1;
   }

   QTableView view;
   QSqlTableModel model;
   model.setTable ("status");
   model.select();
   model.setEditStrategy(QSqlTableModel::OnFieldChange);

   view.setModel(&model);
   view.show();

   return app.exec();
}
*/

//Листинг 41.5 Использование реляционной модели
#include <QtWidgets>
//#include <QtSql>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    if(!createConnection())
    {
        return -1;
    }

    QTableView view;
    QSqlRelationalTableModel model;

    model.setTable("addressbook");
    model.setRelation(0, QSqlRelation("status", "number", "married"));
    model.select();


    view.setModel(&model);
    view.show();

    return app.exec();
}


