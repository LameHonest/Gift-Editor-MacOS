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

void NumericAnswerDialog::on_pushButton_clicked()
{
    QString result = "Numeric Answer{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n" + "#" + ui->lineEdit_3->text()+ "\n}";
    ControllerApp *newAppController = new ControllerApp();
    newAppController->acceptQuest(result);
    this->close();
}
