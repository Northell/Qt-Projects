#ifndef HELPBROWSER_H
#define HELPBROWSER_H


#include <QtWidgets>
class HelpBrowser:public QWidget
{
    Q_OBJECT

public:
    HelpBrowser(const QString& strPath,
                const QString& strFileName=0,
                      QWidget* pwgt = 0
            );
};

#endif // HELPBROWSER_H
