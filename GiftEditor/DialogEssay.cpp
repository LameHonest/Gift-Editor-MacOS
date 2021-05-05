#include "DialogEssay.h"
#include "ui_essaydialog.h"
#include "ControllerApp.h"

DialogEssay::DialogEssay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EssayDialog)
{
    ui->setupUi(this);
}

DialogEssay::~DialogEssay()
{
    delete ui;
}

void DialogEssay::setUpUI(QStringList data) {
    ui->lineEdit->setText(data[0]);
    ui->lineEdit_2->setText(data[1]);
}

void DialogEssay::on_pushButton_clicked()
{
    ControllerApp *newAppController = new ControllerApp();
    if (editable) {
            QStringList resultList;
            resultList.push_back(ui->lineEdit->text());
            resultList.push_back(ui->lineEdit_2->text());
            resultList.push_back("");
            newAppController->editQuest(index,"Essay", resultList);
        } else {
            newAppController->sendModelEssay(ui->lineEdit->text(), ui->lineEdit_2->text());
        }
    this->close();
}
