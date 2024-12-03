#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/filePath.h"
#include "inc/jsonTool.h"
#include "inc/mainMenu.h"
#include "inc/resultShow.h"
#include "inc/setting.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    CJsonTool jsonTool;
    changeLanguage(jsonTool.getItem(SETTING_JSON_PATH, "language") == "chinese");

    toMainMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toMainMenu()
{
    CMainMenu *mainMenu = new CMainMenu;
    connect(mainMenu, &CMainMenu::quitSignal, this, &MainWindow::close);
    connect(mainMenu, &CMainMenu::toResultShow, this, &MainWindow::toResultShow);
    connect(mainMenu, &CMainMenu::toSetting, this, &MainWindow::toSetting);
    setCentralWidget(mainMenu);
}

void MainWindow::toResultShow(QString result)
{
    CResultShow *resultShow = new CResultShow(result);
    connect(resultShow, &CResultShow::toMainMenu, this, &MainWindow::toMainMenu);
    setCentralWidget(resultShow);
}

void MainWindow::toSetting()
{
    CSetting *setting = new CSetting;
    connect(setting, &CSetting::toMainMenu, this, &MainWindow::toMainMenu);
    connect(setting, &CSetting::changeLanguage, this, &MainWindow::changeLanguage);
    setCentralWidget(setting);
}

void MainWindow::changeLanguage(bool isChinese)
{
    if (isChinese) {
        if (!trans.load(":/trans/trans/chinese.qm")) {
            return;
        }
    } else {
        if (!trans.load(":/trans/trans/english.qm")) {
            return;
        }
    }
    qApp->installTranslator(&trans);
}

void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange: {
            ui->retranslateUi(this);
            break;
        }
        default: {
            break;
        }
    }
}
