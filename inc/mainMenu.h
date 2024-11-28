#ifndef MAINMENU_H
#define MAINMENU_H

#include "interfaceBase.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class mainMenu;
}
QT_END_NAMESPACE

class CMainMenu : public CInterfaceBase
{
    Q_OBJECT

public:
    CMainMenu(QWidget *parent = nullptr);
    ~CMainMenu();

private:
    Ui::mainMenu *ui;

signals:
    void quitSignal();
    void toResultShow(QString result);
    void toSetting();

private slots:
    void startChoose();
    void settingClicked();
    void quit();
};

#endif // MAINMENU_H
