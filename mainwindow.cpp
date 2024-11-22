#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/items.h"
#include <QString>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CItems items;
    QString result = items.chooseOne();
    qDebug() << result;
}

MainWindow::~MainWindow()
{
    delete ui;
}
