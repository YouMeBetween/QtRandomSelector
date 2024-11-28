#ifndef _SETTING_H_
#define _SETTING_H_

#include "interfaceBase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class qSettingWidget;
}
QT_END_NAMESPACE

class CSetting : public CInterfaceBase
{
    Q_OBJECT

public:
    CSetting(QWidget *parent = nullptr);
    ~CSetting();

private:
    Ui::qSettingWidget *ui;
    bool weightSelect;
    bool dynamicWeight;

signals:
    void toMainMenu();

private slots:
    void OKClicked();
};

#endif // _SETTING_H_
