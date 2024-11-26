#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/mainMenu.h"
#include "inc/resultShow.h"

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
    setCentralWidget(mainMenu);
}

void MainWindow::toResultShow(QString result)
{
    CResultShow *resultShow = new CResultShow(result);
    resultShow->setAttribute(Qt::WA_DeleteOnClose);
    connect(resultShow, &CResultShow::toMainMenu, this, &MainWindow::toMainMenu);
    setCentralWidget(resultShow);
}
