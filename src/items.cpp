#include "../inc/items.h"
#include <QFile>
#include <QDebug>
#include <QRandomGenerator>

CItems::CItems(QString file_dir, QWidget *parent) : QWidget(parent)
{
    QFile csv_data(file_dir);
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
    double total_weight = 0.0, choice = 0.0;
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
    choice = QRandomGenerator::global()->bounded(weight.back());
    for (auto iter = weight.begin(); iter != weight.end(); iter++) {
        if (choice < *iter){
            return items.at(std::distance(weight.begin(), iter)).name;
        }
    }
    return items.back().name;
}
