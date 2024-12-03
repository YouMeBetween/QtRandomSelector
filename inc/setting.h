#ifndef _SETTING_H_
#define _SETTING_H_

#include "interfaceBase.h"
#include <QTranslator>

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
    bool language;
    QTranslator trans;

signals:
    void toMainMenu();
    void changeLanguage(bool isChinese);

private slots:
    void weightSelectClicked();
    void dynamicWeightClicked();
    void chineseClicked();
    void englishClicked();
    void OKClicked();
    void changeEvent(QEvent *e);
};

#endif // _SETTING_H_
