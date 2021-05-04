#include "DialogMatchingSelection.h"
#include "ui_matchingselectiondialog.h"
#include "ControllerApp.h"
#include <QDebug>

MatchingSelectionDialog::MatchingSelectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMatchingSelection)
{
    ui->setupUi(this);
}

MatchingSelectionDialog::~MatchingSelectionDialog()
{
    delete ui;
}

//Добавление соответствия
void MatchingSelectionDialog::on_pushButton_2_clicked()
{
  ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

//Добавление вопроса
void MatchingSelectionDialog::on_pushButton_clicked()
{
    if (ui->tableWidget->isEnabled()) {
        ui->tableWidget->selectRow(0);
    }
    QString result = "Matching Selection{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n";
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        result = result + "=" + ui->tableWidget->item(i,0)->text() + " -> "+ ui->tableWidget->item(i,1)->text() + " \n";
    }
    result = result + "} \n";
    qDebug() << result;
    ControllerApp *newAppController = new ControllerApp();
    newAppController->acceptQuest(result);
    this->close();
}
