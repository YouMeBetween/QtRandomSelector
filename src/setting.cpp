#include "../inc/setting.h"
#include "../inc/filePath.h"
#include "ui_setting.h"

CSetting::CSetting(QWidget *parent)
    : CInterfaceBase(parent)
    , ui(new Ui::qSettingWidget)
{
    ui->setupUi(this);

    connect(ui->qWeightSelectSwitchButton, &SwitchButton::sigSwitchChanged, this, &CSetting::weightSelectClicked);
    connect(ui->qDynamicWeightSwitchButton, &SwitchButton::sigSwitchChanged, this, &CSetting::dynamicWeightClicked);
    connect(ui->qOKPushButton, &QPushButton::clicked, this, &CSetting::OKClicked);

    weightSelect = getItem(SETTING_JSON_PATH, "weightSelect") == "true";
    dynamicWeight = getItem(SETTING_JSON_PATH, "dynamicWeight") == "true";

    ui->qWeightSelectSwitchButton->setSwitch(weightSelect);
    ui->qDynamicWeightSwitchButton->setSwitch(dynamicWeight);
}

CSetting::~CSetting()
{
    delete ui;
}

void CSetting::weightSelectClicked()
{
    if (!ui->qWeightSelectSwitchButton->getSwitch() && ui->qDynamicWeightSwitchButton->getSwitch()) {
        ui->qDynamicWeightSwitchButton->setSwitch(false);
    }
}

void CSetting::dynamicWeightClicked()
{
    if (ui->qDynamicWeightSwitchButton->getSwitch() && !ui->qWeightSelectSwitchButton->getSwitch()) {
        ui->qWeightSelectSwitchButton->setSwitch(true);
    }
}

void CSetting::OKClicked()
{
    if (weightSelect != ui->qWeightSelectSwitchButton->getSwitch()) {
        setItem(SETTING_JSON_PATH, "weightSelect", !weightSelect ? "true" : "false");
    }
    if (dynamicWeight != ui->qDynamicWeightSwitchButton->getSwitch()) {
        setItem(SETTING_JSON_PATH, "dynamicWeight", !dynamicWeight ? "true" : "false");
    }
    emit toMainMenu();
    close();
}
