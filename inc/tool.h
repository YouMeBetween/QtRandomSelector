#ifndef _JSON_TOOL_H_
#define _JSON_TOOL_H_

#include <QWidget>

class CTool : public QWidget
{
    Q_OBJECT

public:
    CTool(QWidget *parent = nullptr);
    QString getItem(QString path, QString key);
    void setItem(QString path, QString key, QString value);
};

#endif // _JSON_TOOL_H_
