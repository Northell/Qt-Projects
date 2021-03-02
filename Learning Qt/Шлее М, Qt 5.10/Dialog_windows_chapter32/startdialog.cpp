#include "startdialog.h"

StartDialog::StartDialog(QWidget *pwgt):QPushButton("Press Me", pwgt)
{
    connect(this,SIGNAL(clicked()), SLOT(slotButtonClicked()));
}

void StartDialog::slotButtonClicked()
{
    InputDialog* pInputDialog = new InputDialog();

    if(pInputDialog->exec() == QDialog::Accepted)        //Запуск диалог. окна
    {
        QMessageBox::information(0,
                                 "Information",
                                 "First Name"
                                 + pInputDialog->firstName()
                                 +"\nLast Name: "
                                 + pInputDialog->lastName()
                                 );

        delete pInputDialog;
    }
}
