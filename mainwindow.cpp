#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/mainMenu.h"
#include "inc/resultShow.h"
#include "inc/setting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    toMainMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toMainMenu()
{
    CMainMenu *mainMenu = new CMainMenu;
    mainMenu->setAttribute(Qt::WA_DeleteOnClose);
    connect(mainMenu, &CMainMenu::quitSignal, this, &MainWindow::close);
    connect(mainMenu, &CMainMenu::toResultShow, this, &MainWindow::toResultShow);
    connect(mainMenu, &CMainMenu::toSetting, this, &MainWindow::toSetting);
    setCentralWidget(mainMenu);
}

void MainWindow::toResultShow(QString result)
{
    CResultShow *resultShow = new CResultShow(result);
    resultShow->setAttribute(Qt::WA_DeleteOnClose);
    connect(resultShow, &CResultShow::toMainMenu, this, &MainWindow::toMainMenu);
    setCentralWidget(resultShow);
}

void MainWindow::toSetting()
{
    CSetting *setting = new CSetting;
    setting->setAttribute(Qt::WA_DeleteOnClose);
    connect(setting, &CSetting::toMainMenu, this, &MainWindow::toMainMenu);
    setCentralWidget(setting);
}
