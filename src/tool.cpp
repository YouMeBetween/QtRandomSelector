#include "../inc/tool.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>

CTool::CTool(QWidget *parent)
    : QWidget(parent)
{
    return;
}

QString CTool::getItem(QString path, QString key)
{
    QFile file(path);
    QString value;
    QJsonParseError parseJsonErr;
    QJsonDocument document;
    QJsonObject jsonObject;

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    value = file.readAll();
    file.close();

    document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError)) {
        return "Configuration file error.\n";
    }

    jsonObject = document.object();
    return jsonObject[key].toString();
}

void CTool::setItem(QString path, QString key, QString value)
{
    QFile file(path), writeFile(path);
    QString element;
    QJsonParseError parseJsonErr;
    QJsonDocument document;
    QJsonObject jsonObject;

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    element = file.readAll();
    file.close();

    document = QJsonDocument::fromJson(element.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError)) {
        return;
    }

    jsonObject = document.object();
    jsonObject[key] = value;

    document.setObject(jsonObject);

    if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return;
    }

    QTextStream writeStream(&writeFile);
    writeStream << document.toJson();
    writeFile.close();
}
