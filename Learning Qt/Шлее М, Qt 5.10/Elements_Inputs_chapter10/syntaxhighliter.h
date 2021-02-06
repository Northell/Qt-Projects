#ifndef SYNTAXHIGHLITER_H
#define SYNTAXHIGHLITER_H

#include <QSyntaxHighlighter>
#include <QTextDocument>

class SyntaxHighLiter:public QSyntaxHighlighter
{
    Q_OBJECT
private:
    QStringList m_lstKeywords;
protected:
    enum {NormalState = -1, InsideCStyleComment, InsideCString};

    virtual void highlightBlock(const QString& str);

    QString getKeyword(int i, const QString& str) const;
public:
    SyntaxHighLiter(QTextDocument* parent = 0);
};

#endif // SYNTAXHIGHLITER_H
