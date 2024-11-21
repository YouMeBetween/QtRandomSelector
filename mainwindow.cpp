#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QVector<QString> item = getItem();
    if (item.empty()) {
        return;
    }
    qDebug() << choose(&item) << Qt::endl;
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}

QVector<QString> MainWindow::getItem()
{
    QFile fin(":config/config/cfg.ini");
    QVector<QString> item;
    if (!fin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << tr("Unable to open file.");
        return item;
    }
    while (!fin.atEnd()) {
        item.push_back(fin.readLine());
    }
    fin.close();
    return item;
}

QString MainWindow::choose(QVector<QString> *item)
{
    return item->at(QRandomGenerator::global()->bounded(item->size()));
}
