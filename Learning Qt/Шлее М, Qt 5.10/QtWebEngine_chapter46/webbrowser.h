#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QtWidgets>
#include <QWebEngineView>
#include <QtWebEngineWidgets>
class WebBrowser: public QWidget
{
    Q_OBJECT
private:
    QLineEdit*  m_ptxt;
    QWebEngineView* m_pwv;
    QPushButton* m_pcmdBack;
    QPushButton* m_pcmdForward;
public:
    WebBrowser(QWidget* pwgt = 0);

private slots:
    void slotGo();
    void slotFinished(bool);
};

#endif // WEBBROWSER_H
