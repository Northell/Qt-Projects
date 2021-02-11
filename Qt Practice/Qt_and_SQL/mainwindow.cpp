#include "mainwindow.h"


void MainWindow::slotBtnClicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setDatabaseName("post_mobile_1");
    db.setHostName("192.168.1.36");
    db.setPort(5445);
    db.setUserName("admin");
    db.setPassword("2575");

    db.open();

    if(!db.open())
    {

        QMessageBox::warning(this, "Error", db.lastError().text());
    }
    else
    {
    QMessageBox::information(this, "Ok", "Succesfull");

    QSqlQuery query;
    const QString str ("SELECT totype.id "
                       ",totype.name "
                       ",totype.idtype "
                       ",totype.descr "

                       ",toobject.id "
                       ",toobject.idtype "
                       ",toobject.name "
                       ",toobject.datereg "
               "FROM public.totype JOIN public.toobject "
               "ON totype.id = toobject.idtype");

    query.exec(str);






    QStringList horizontalHeader;


    horizontalHeader.append("_id.totype");     //0
    horizontalHeader.append("name");           //1 //
    horizontalHeader.append("idtype");         //2
    horizontalHeader.append("descr");          //3

    horizontalHeader.append("_id.toobject");   //4//
    horizontalHeader.append("idtype.toobject");//5
    horizontalHeader.append("name.toobject");  //6//
    horizontalHeader.append("datereg");        //7






    model = new SQLModel(&query);
    model->setHorizontalHeaderLabels(horizontalHeader);



    tbl->setModel(model);
    tbl->resizeColumnsToContents();
    tbl->resizeRowsToContents();


   }

    db.close();
}

MainWindow::MainWindow(QWidget *pwgt)
{
    pwgt->resize(400,400);


    tbl = new QTableView();
    btnOk = new QPushButton("Run");



    QWidget::connect(btnOk, &QPushButton::clicked, this, &MainWindow::slotBtnClicked);

    //Layout setup
    QVBoxLayout *layout = new QVBoxLayout();

    layout->addWidget(tbl);
    layout->addWidget(btnOk);
    pwgt->setLayout(layout);


}


