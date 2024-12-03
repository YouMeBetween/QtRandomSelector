#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTranslator trans;

private slots:
    void toMainMenu();
    void toResultShow(QString result);
    void toSetting();
    void changeLanguage(bool isChinese);
    void changeEvent(QEvent *e);
};
#endif // MAINWINDOW_H
