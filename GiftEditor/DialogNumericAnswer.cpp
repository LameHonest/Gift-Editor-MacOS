#include "DialogNumericAnswer.h"
#include "ui_numericanswerdialog.h"
#include "ControllerApp.h"

NumericAnswerDialog::NumericAnswerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNumericAnswer)
{
    ui->setupUi(this);
}

NumericAnswerDialog::~NumericAnswerDialog()
{
    delete ui;
}

void NumericAnswerDialog::setUpUI(QStringList data) {
    ui->lineEdit->setText(data[0]);
    ui->lineEdit_2->setText(data[1]);
    data[2].remove(0,1);
    ui->lineEdit_3->setText(data[2]);
}
void NumericAnswerDialog::on_pushButton_clicked()
{
    ControllerApp *newAppController = new ControllerApp();
    if (editable) {
            QStringList resultList;
            resultList.push_back(ui->lineEdit->text());
            resultList.push_back(ui->lineEdit_2->text());
            resultList.push_back("#" + ui->lineEdit_3->text());
            newAppController->editQuest(index,"Numeric Answer", resultList);
        } else {
            newAppController->sendModelNumericAnswer(ui->lineEdit->text(), ui->lineEdit_2->text(), ui->lineEdit_3->text());
        }
    //QString result = "Numeric Answer{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n" + "#" + ui->lineEdit_3->text()+ "\n}";
    this->close();
}
