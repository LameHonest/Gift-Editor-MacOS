#include "DialogTrueFalse.h"
#include "ui_truefalsedialog.h"
#include "ControllerApp.h"
#include <QDebug>

TrueFalseDialog::TrueFalseDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogTrueFalse)
{
    ui->setupUi(this);
}

TrueFalseDialog::~TrueFalseDialog()
{
    delete ui;
}

void TrueFalseDialog::setUpUI(QStringList data) {
    ui->lineEdit->setText(data[0]);
    ui->lineEdit_2->setText(data[1]);
    if (data[2] == "TRUE" || data[2] == " TRUE " || data[2] == "T" || data[2] == " T ") {
        ui->checkBox_2->setCheckState(Qt::Checked);
    }
    if (data[2] == "FALSE" || data[2] == " FALSE " || data[2] == "F" || data[2] == " F ") {
        ui->checkBox->setCheckState(Qt::Checked);
    }
}
void TrueFalseDialog::on_checkBox_clicked()
{
    if (ui->checkBox_2->isChecked()) {
        ui->checkBox_2->setCheckState(Qt::Unchecked);
    }
}

void TrueFalseDialog::on_checkBox_2_clicked()
{
    if (ui->checkBox->isChecked()) {
        ui->checkBox->setCheckState(Qt::Unchecked);
    }
}

void TrueFalseDialog::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked() || ui->checkBox_2->isChecked()) {
    ControllerApp *newAppController = new ControllerApp();
    QString result;
    if (ui->checkBox->isChecked()) {
    result = "FALSE";
    } else {
        result = "TRUE";
    }
    if (editable) {
            QStringList resultList;
            resultList.push_back(ui->lineEdit->text());
            resultList.push_back(ui->lineEdit_2->text());
            resultList.push_back(result);
            newAppController->editQuest(index,"True False", resultList);
        } else {
            newAppController->sendModelTrueFalse(ui->lineEdit->text(), ui->lineEdit_2->text(), result);
        }
    this->close();
    }
}
