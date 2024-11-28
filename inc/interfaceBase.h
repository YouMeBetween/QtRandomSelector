#ifndef _INTERFACE_BASE_H_
#define _INTERFACE_BASE_H_

#include <QWidget>

class CInterfaceBase : public QWidget
{
    Q_OBJECT

public:
    CInterfaceBase(QWidget *parent = nullptr);

protected:
    QString getItem(QString path, QString key);
    void setItem(QString path, QString key, QString value);
};

#endif // _INTERFACE_BASE_H_
