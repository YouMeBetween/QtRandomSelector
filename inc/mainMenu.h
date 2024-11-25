#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainMenu;
}
QT_END_NAMESPACE

class CMainMenu : public QWidget
{
    Q_OBJECT

public:
    CMainMenu(QWidget *parent = nullptr);
    ~CMainMenu();

private:
    Ui::mainMenu *ui;

signals:
    void quitSignal();

private slots:
    void startChoose();
    void quit();
};

#endif // MAINMENU_H
