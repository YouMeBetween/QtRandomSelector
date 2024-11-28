#include "../inc/interfaceBase.h"
#include <QFile>
#include <QJsonParseError>
#include <QJsonObject>

CInterfaceBase::CInterfaceBase(QWidget *parent)
    : QWidget(parent)
{
    return;
}

QString CInterfaceBase::getItem(QString path, QString key)
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
        qDebug() << tr("Configuration file error.\n");
        return "Configuration file error.\n";
    }

    jsonObject = document.object();
    return jsonObject[key].toString();
}

void CInterfaceBase::setItem(QString path, QString key, QString value)
{
    QFile file(path);
    QString element;
    QJsonParseError parseJsonErr;
    QJsonDocument document;
    QJsonObject jsonObject;

    file.open(QIODevice::ReadOnly | QIODevice::Text);
    element = file.readAll();
    file.close();

    document = QJsonDocument::fromJson(element.toUtf8(), &parseJsonErr);
    if (!(parseJsonErr.error == QJsonParseError::NoError)) {
        qDebug() << tr("Configuration file error.\n");
        return;
    }

    jsonObject = document.object();
    jsonObject[key] = value;

    /* 将jsonObject设置为本文档的主要对象 */
    document.setObject(jsonObject);

    /* 重写打开的文件，覆盖原有文件，达到删除文件全部内容的效果 */
    QFile writeFile(path);
    if (!writeFile.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        qDebug() << tr("Configuration file error.\n");
        return;
    }

    /* 将修改后的内容写入文件 */
    QTextStream writeStream(&writeFile);
    writeStream << document.toJson();       /* 写入文件 */
    writeFile.close();                      /* 关闭文件 */
}
