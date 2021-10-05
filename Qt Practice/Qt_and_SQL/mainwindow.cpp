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
        query.exec("SET NAMES 'unicode'");

        //    const QString str ("SELECT totype.id "
        //                       ",totype.name "
        //                       ",totype.idtype "
        //                       ",totype.descr "

        //                       ",toobject.id "
        //                       ",toobject.idtype "
        //                       ",toobject.name "
        //                       ",toobject.datereg "
        //               "FROM public.totype JOIN public.toobject "
        //               "ON totype.id = toobject.idtype");


        const QString str = txt->toPlainText();
        query.exec(str);

        QStringList headers = ParsingHeader(str);
        model = new SQLModel(&query, headers.size());
        model->setHorizontalHeaderLabels(headers);
        qDebug() << model ->checkFileInSQL(model->downloadFile());

        if (!enabledValues->isChecked()) model->setEnabledValue(false);
        else model->setEnabledValue(true);

        tbl->setModel(model);
        tbl->resizeColumnsToContents();
        tbl->resizeRowsToContents();

    }

    db.close();
    lbl->setText("Результат поиска по запросу:");
    layout->removeWidget(txt);
    layout->insertWidget(1,tbl);

}

MainWindow::MainWindow(QWidget *pwgt):QWidget(pwgt)
{
    lbl = new QLabel("Request in SQL:");
    tbl = new QTableView();
    enabledValues = new QCheckBox("Show Data");
    btnOk = new QPushButton("Run");
    txt = new QTextEdit ("SELECT id  as id"
                         "       ,to_getparbyt('TemplateIcon', 'Y', id) as modelIcon "
                         "       ,to_getparbyt('TemplateImgGreen', 'Y', id) as modelIconGreen "
                         "       ,to_getparbyt('TemplateImgYellow', 'Y', id) as modelIconYellow "
                         "       ,to_getparbyt('TemplateImgGray', 'Y', id) as modelIconGray "
                         "       ,to_getparbyt('TemplateImgRed', 'Y', id) as modelIconRed"
                         "       FROM toobject WHERE idtype = to_getidtype('Template') "
                         "       AND datedel IS null");

    //    txt = new QTextEdit ("SELECT totype.id as totype_id "
    //"                       ,totype.name as totype_name "
    //"                       ,totype.idtype as totype_idtype "
    //"                       ,totype.descr as totype_descr "

    //"                       ,toobject.id as toobject_id "
    //"                       ,toobject.idtype as toobject_idtype "
    //"                       ,toobject.name as toobject_name "
    //"                       ,toobject.datereg as toobject_datereg "
    //"                       FROM public.totype JOIN public.toobject "
    //"                       ON totype.id = toobject.idtype");

    //Connections
    QWidget::connect(btnOk, &QPushButton::clicked, this, &MainWindow::slotBtnClicked);

    //Layout setup
    layout = new QVBoxLayout();

    layout->addWidget(lbl);
    layout->addWidget(txt);
    layout->addWidget(enabledValues);
    layout->addWidget(btnOk);

    this->setLayout(layout);
}

/*
 * Parsing Header
 */
QStringList MainWindow::ParsingHeader(QString str)
{

    QString subResult;
    QStringList  horizontalHeader;

    str = str.split("FROM").takeFirst();

    for (int i = 2; i< str.length(); ++i)
    {
        if (((str[i-2] == 'a') && (str[i-1] == 's'))
                || ((str[i-2] == 'A') && (str[i-1] == 'S')))
        {
            while((str[i]!=',') && (i+1<str.length()))
            {
                subResult+=str[i];
                i++;
            }

            horizontalHeader.append(subResult);
            subResult = nullptr;
        }
    }
    return horizontalHeader;
}


