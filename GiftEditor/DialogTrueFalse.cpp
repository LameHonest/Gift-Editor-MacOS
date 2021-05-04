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
    QString result = "True False{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n";
    if (ui->checkBox->isChecked()) {
    result = result + "FALSE}\n";
    } else {
        result = result + "TRUE}\n";
    }
    qDebug() << result;
    ControllerApp *newAppController = new ControllerApp();
    newAppController->acceptQuest(result);
    this->close();
    }
}
