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

void MatchingSelectionDialog::setUpUI(QStringList data) {
    ui->lineEdit->setText(data[0]);
    ui->lineEdit_2->setText(data[1]);
    int j = 0;
    for (int i = 2; i < data.count(); i=i+2) {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(j,0, new QTableWidgetItem(data[i]));
        ui->tableWidget->setItem(j,1, new QTableWidgetItem(data[i+1]));
        j++;
     }
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
    ControllerApp *newAppController = new ControllerApp();
    if (editable) {
            QStringList resultList;
            resultList.push_back(ui->lineEdit->text());
            resultList.push_back(ui->lineEdit_2->text());
            for (int i = 0; i < ui->tableWidget->rowCount(); i ++) {
                resultList.push_back(ui->tableWidget->item(i,0)->text());
                resultList.push_back(ui->tableWidget->item(i,1)->text());
            }
            newAppController->editQuest(index,"Matching Selection", resultList);
        } else {
            QString answers;
            for (int i = 0; i < ui->tableWidget->rowCount(); i ++) {
                answers = answers + "=" + ui->tableWidget->item(i,0)->text() + " -> "+ ui->tableWidget->item(i,1)->text() + " \n";
            }
            newAppController->sendModelMatchingSelection(ui->lineEdit->text(), ui->lineEdit_2->text(), answers);
        }
    QString result = "Matching Selection{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n";
    for (int i = 0; i < ui->tableWidget->rowCount(); i++) {
        result = result + "=" + ui->tableWidget->item(i,0)->text() + " -> "+ ui->tableWidget->item(i,1)->text() + " \n";
    }
    this->close();
}
