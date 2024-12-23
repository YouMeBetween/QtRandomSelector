#include "../inc/setting.h"
#include "../inc/filePath.h"
#include "../inc/tool.h"
#include "ui_setting.h"

CSetting::CSetting(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qSettingWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    connect(ui->qWeightSelectSwitchButton, &SwitchButton::sigSwitchChanged, this, &CSetting::weightSelectClicked);
    connect(ui->qDynamicWeightSwitchButton, &SwitchButton::sigSwitchChanged, this, &CSetting::dynamicWeightClicked);
    connect(ui->qChineseRadioButton, &QRadioButton::clicked, this, &CSetting::chineseClicked);
    connect(ui->qEnglishRadioButton, &QRadioButton::clicked, this, &CSetting::englishClicked);
    connect(ui->qOKPushButton, &QPushButton::clicked, this, &CSetting::OKClicked);

    CTool tool;

    weightSelect = tool.getItem(SETTING_JSON_PATH, "weightSelect") == "true";
    dynamicWeight = tool.getItem(SETTING_JSON_PATH, "dynamicWeight") == "true";
    language = tool.getItem(SETTING_JSON_PATH, "language") == "chinese";

    ui->qWeightSelectSwitchButton->setSwitch(weightSelect);
    ui->qDynamicWeightSwitchButton->setSwitch(dynamicWeight);
    if (language) {
        ui->qChineseRadioButton->setChecked(true);
        chineseClicked();
    } else {
        ui->qEnglishRadioButton->setChecked(true);
        englishClicked();
    }
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

void CSetting::chineseClicked()
{
    if (trans.load(":trans/trans/chinese.qm")) {
        qApp->installTranslator(&trans);
    }
}

void CSetting::englishClicked()
{
    if (trans.load(":trans/trans/english.qm")) {
        qApp->installTranslator(&trans);
    }
}

void CSetting::OKClicked()
{
    CTool tool;

    if (weightSelect != ui->qWeightSelectSwitchButton->getSwitch()) {
        tool.setItem(SETTING_JSON_PATH, "weightSelect", !weightSelect ? "true" : "false");
    }
    if (dynamicWeight != ui->qDynamicWeightSwitchButton->getSwitch()) {
        tool.setItem(SETTING_JSON_PATH, "dynamicWeight", !dynamicWeight ? "true" : "false");
    }
    if (!language && ui->qChineseRadioButton->isChecked()) {
        tool.setItem(SETTING_JSON_PATH, "language", "chinese");
        emit changeLanguage(true);
    } else if (language && ui->qEnglishRadioButton->isChecked()) {
        tool.setItem(SETTING_JSON_PATH, "language", "english");
        emit changeLanguage(false);
    }
    emit toMainMenu();
    close();
}

void CSetting::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
        case QEvent::LanguageChange: {
            ui->retranslateUi(this);
            break;
        }
        default: {
            break;
        }
    }
}
