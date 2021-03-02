//Листинг 32.1-32.6 Создание собственного диалог. окна

/*
#include <QtWidgets>
#include "startdialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartDialog startDialog;

    startDialog.show();

    return a.exec();
}*/

//Листинг 32.7 Использование диалогового окна для записи файла

/*
#include <QtWidgets>

void writeFile()
{
    QPixmap pix(320,200);
    QString strFilter;
    QString str = QFileDialog::getSaveFileName(0,
                                               tr("Save Pixmap"),
                                               "Pixmap",
                                               "*.png;; *.jpg;; *,bmp",
                                               &strFilter
                                               );

    if(!str.isEmpty())
    {
        if (strFilter.contains("jpg"))
        {
            pix.save(str, "JPG");

        }
        else if (strFilter.contains("bmp"))
        {
                 pix.save(str, "BMP");
        }
        else
        {
            pix.save(str,"PNG");
        }
    }

}
*/

//Листинг 32.8 Диалоговое окно Мастера

#include <QtWidgets>
#include "wizard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Wizard wizard;

    wizard.show();


    return a.exec();
}
