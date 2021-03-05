#ifndef PROGRESSEVENT_H
#define PROGRESSEVENT_H

#include <QtWidgets>
class ProgressEvent:public QEvent
{
private:
    int m_nValue;

public:
    enum {ProgressType = User+1};

    ProgressEvent();
    void setValue(int n);

    int value() const;
};

#endif // PROGRESSEVENT_H
