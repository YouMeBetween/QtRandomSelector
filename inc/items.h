#ifndef _ITEMS_H_
#define _ITEMS_H_

#include <QWidget>
#include <QString>
#include <QVector>

typedef struct Item {
    QString name;
    int weight{};
    Item() {}
} Item;

class CItems : public QWidget
{
    Q_OBJECT

private:
    QVector<Item> items;
    void adjustWeights(int choice);
    void writeCsv();

public:
    CItems(QWidget *parent = 0);
    QVector<Item> getItems();
    QString chooseOne();
};

#endif // _ITEMS_H_
