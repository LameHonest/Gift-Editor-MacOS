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

void DialogEssay::on_pushButton_clicked()
{
    QString result = "Essay{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{} \n";
    ControllerApp *newAppController = new ControllerApp();
    newAppController->acceptQuest(result);
    this->close();
}
