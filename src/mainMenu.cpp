#include "../inc/mainMenu.h"
#include "../inc/items.h"
#include "ui_mainMenu.h"

CMainMenu::CMainMenu(QWidget *parent)
    : CInterfaceBase(parent)
    , ui(new Ui::mainMenu)
{
    ui->setupUi(this);

    connect(ui->start, &QPushButton::clicked, this, &CMainMenu::startChoose);
    connect(ui->quit, &QPushButton::clicked, this, &CMainMenu::quit);
}

CMainMenu::~CMainMenu()
{
    delete ui;
}

void CMainMenu::startChoose()
{
    CItems items;
    QString result = items.chooseOne();
    qDebug() << result;
}

void CMainMenu::quit()
{
    emit quitSignal();
}
