#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/mainMenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CMainMenu *main_menu = new CMainMenu;
    setCentralWidget(main_menu);

    connect(main_menu, &CMainMenu::quitSignal, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
