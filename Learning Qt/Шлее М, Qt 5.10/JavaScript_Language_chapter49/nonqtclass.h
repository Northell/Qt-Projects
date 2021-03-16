#ifndef NONQTCLASS_H
#define NONQTCLASS_H


class NonQtClass
{

private:
    bool m_bReadOnly;
public:
    NonQtClass();
    void setReadOnly(bool bReadOnly);
    bool isReadOnly() const;
};

#endif // NONQTCLASS_H
