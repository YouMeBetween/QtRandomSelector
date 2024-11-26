#include "../inc/resultShow.h"
#include "ui_resultShow.h"

CResultShow::CResultShow(QString choice, QWidget *parent)
    : CInterfaceBase(parent)
    , ui(new Ui::resultShow)
{
    ui->setupUi(this);

    connect(ui->qButtonOK, &QPushButton::clicked, this, &CResultShow::quit);

    ui->qLabelResult->setText(choice);
}

CResultShow::~CResultShow()
{
    delete ui;
}

void CResultShow::quit()
{
    emit toMainMenu();
    close();
}
