#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inc/items.h"
#include <QDebug>
#include <QFile>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CItems items(":config/config/cfg.csv");
    QString result = items.chooseOne();
    qDebug() << result;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::choose(QVector<QString> *item)
{
    return item->at(QRandomGenerator::global()->bounded(item->size()));
}
