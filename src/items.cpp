#include "../inc/items.h"
#include <QFile>
#include <QDebug>
#include <QRandomGenerator>
#include <QDir>

void CItems::adjustWeights(int choice)
{
    items[choice].weight /= 2;
    if (items.at(choice).weight <= 2) {
        for (auto iter = items.begin(); iter != items.end(); iter++) {
            iter->weight *= 2;
        }
    }
}

void CItems::writeCsv()
{
    QFile csv_data("../QtRandomSelector/cfg/cfg.csv");
    if (!csv_data.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << tr("Unable to open fiile.\n");
        return;
    }
    QTextStream out(&csv_data);
    out << "项目,权重\n";
    for (auto iter = items.begin(); iter != items.end(); iter++) {
        out << iter->name << "," << iter->weight << "\n";
    }
    csv_data.close();
}

CItems::CItems(QWidget *parent) : QWidget(parent)
{
    QFile csv_data("../QtRandomSelector/cfg/cfg.csv");
    QString line;
    QStringList words;
    Item temp;
    if (!csv_data.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << tr("Unable to open file.\n");
        exit(1);
    }
    csv_data.readLine();
    while (!csv_data.atEnd()) {
        line = csv_data.readLine();
        words = line.split(",");
        temp.name = words[0];
        temp.weight = words[1].toInt();
        items.push_back(temp);
    }
    csv_data.close();
}

QVector<Item> CItems::getItems()
{
    return items;
}

QString CItems::chooseOne()
{
    double total_weight = 0.0, random_result = 0.0;
    int choice = -1;
    QVector<double> weight;
    for (auto iter = items.begin(); iter != items.end(); iter++) {
        total_weight += iter->weight;
    }
    if (fabs(total_weight) < 1e-6) {
        return tr("No options");
    }
    weight.push_back(0.0);
    for (auto iter = items.begin(); iter != items.end(); iter++) {
        weight.push_back(iter->weight + weight.back());
    }
    weight.erase(weight.cbegin());
    random_result = QRandomGenerator::global()->bounded(weight.back());
    for (auto iter = weight.begin(); iter != weight.end(); iter++) {
        if (random_result < *iter){
            choice = std::distance(weight.begin(), iter);
            break;
        }
    }
    this->adjustWeights(choice);
    this->writeCsv();
    return items.at(choice).name;
}
