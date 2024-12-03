#ifndef _INTERFACE_BASE_H_
#define _INTERFACE_BASE_H_

#include <QWidget>

class CInterfaceBase : public QWidget
{
    Q_OBJECT

public:
    CInterfaceBase(QWidget *parent = nullptr);
};

#endif // _INTERFACE_BASE_H_
