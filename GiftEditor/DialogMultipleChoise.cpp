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
    QString result = "Multiple Choise{!SPLIT_CARACT!}::" + ui->lineEdit->text() +"::" + ui->lineEdit_2->text() + "{ \n";
    for (int i = 0; i < ui->listWidget->count(); i++) {
           result = result + ui->listWidget->item(i)->text() + "\n";
    }
    result = result + "} \n";
    qDebug() << result;
    ControllerApp *newAppController = new ControllerApp();
    newAppController->acceptQuest(result);
    this->close();
}
