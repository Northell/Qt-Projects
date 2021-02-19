#ifndef PRINTER_H
#define PRINTER_H

#include <QtWidgets>

#include <QtPrintSupport> //Для Qt 6 все тут

class Printer:public QWidget
{
    Q_OBJECT
private:
    QPrinter* m_pprinter;

protected:
    virtual void paintEvent(QPaintEvent* );
            void draw      (QPaintDevice* ppd);
public:
    Printer(QWidget* pwgt = 0);
    virtual ~Printer();

public slots:
    void slotPrint();
};

#endif // PRINTER_H
