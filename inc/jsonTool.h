#ifndef _JSON_TOOL_H_
#define _JSON_TOOL_H_

#include <QWidget>

class CJsonTool : public QWidget
{
    Q_OBJECT

public:
    CJsonTool(QWidget *parent = nullptr);
    QString getItem(QString path, QString key);
    void setItem(QString path, QString key, QString value);
};

#endif // _JSON_TOOL_H_
