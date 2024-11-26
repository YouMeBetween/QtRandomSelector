#ifndef _RESULT_SHOW_H_
#define _RESULT_SHOW_H_

#include "interfaceBase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class resultShow;
}
QT_END_NAMESPACE

class CResultShow : public CInterfaceBase
{
    Q_OBJECT

public:
    CResultShow(QString choice, QWidget *parent = nullptr);
    ~CResultShow();

private:
    Ui::resultShow *ui;

signals:
    void toMainMenu();

private slots:
    void quit();
};

#endif // _RESULT_SHOW_H_
