#include "DialogMultipleChoise.h"
#include "ui_multiplechoisewindow.h"
#include <QDebug>
#include "ControllerApp.h"

MultipleChoiseWindow::MultipleChoiseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMultipleChoise)
{
    ui->setupUi(this);
}

MultipleChoiseWindow::~MultipleChoiseWindow()
{
    delete ui;
}

void MultipleChoiseWindow::setUpUi(QStringList data) {
    ui->lineEdit->setText(data[0]);
    ui->lineEdit_2->setText(data[1]);
    for (int i = 2; i < data.count(); i++) {
        ui->listWidget->addItem(data[i]);
    }
}

void MultipleChoiseWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item->setFlags(item->flags() | Qt::ItemIsEditable);
}

void MultipleChoiseWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    if (item->text().at(0) == "=") {
        item->setText("~" + item->text().right(item->text().length() - 1));
    } else {
        if (item->text().at(0) == "~") {
            item->setText("=" + item->text().right(item->text().length() - 1));
        } else {
            item->setText( "=" + item->text());
        }
    }
}


void MultipleChoiseWindow::on_pushButton_2_clicked()
{
    QListWidgetItem *item = new QListWidgetItem();
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    item->setText("=Новый ответ");
    ui->listWidget->addItem(item);
}

void MultipleChoiseWindow::on_pushButton_clicked()
{
    ControllerApp *newAppController = new ControllerApp();

    if (editable) {
        QStringList resultList;
        resultList.push_back(ui->lineEdit->text());
        resultList.push_back(ui->lineEdit_2->text());
        for (int i = 0; i < ui->listWidget->count(); i ++) {
            resultList.push_back(ui->listWidget->item(i)->text());
        }
        newAppController->editQuest(index,"Multiple Choise", resultList);
    } else {
        QString answers;
        for (int i = 0; i < ui->listWidget->count(); i++) {
            answers = answers + ui->listWidget->item(i)->text() + "\n";
        }
        newAppController->sendModelMultipleChoise(ui->lineEdit->text(), ui->lineEdit_2->text(), answers);
    }
    this->close();
}
