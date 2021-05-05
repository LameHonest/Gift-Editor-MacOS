#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Окно Множественный выбор
void MainWindow::on_pushButton_7_clicked()
{
    MultipleChoiseWindow *newMPWindow = new MultipleChoiseWindow();
    newMPWindow->exec();
    updateListWidget();
}

//Окно Пропущенное слово
void MainWindow::on_pushButton_6_clicked()
{
    MissedWordDialog *newMWWindow = new MissedWordDialog();
    newMWWindow->exec();
    updateListWidget();
}

//Окно Короткий ответ
void MainWindow::on_pushButton_2_clicked()
{
    ShortAnswerDialog *newSAWindow = new ShortAnswerDialog();
    newSAWindow->exec();
    updateListWidget();
}

//Окно Верно-неверно
void MainWindow::on_pushButton_5_clicked()
{
    TrueFalseDialog *newTFWindow = new TrueFalseDialog();
    newTFWindow->exec();
    updateListWidget();
}

//Окно выбор соотвествия
void MainWindow::on_pushButton_4_clicked()
{
    MatchingSelectionDialog *newMSWindow = new MatchingSelectionDialog();
    newMSWindow->exec();
    updateListWidget();
}

//Окно числовой ответ
void MainWindow::on_pushButton_3_clicked()
{
    NumericAnswerDialog *newNAWindow = new NumericAnswerDialog();
    newNAWindow->exec();
    updateListWidget();
}

//Окно Эссе
void MainWindow::on_pushButton_clicked()
{
    DialogEssay *newEWindow = new DialogEssay();
    newEWindow->exec();
    updateListWidget();
}
//Открыть файл
void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file", "Gift File", tr("Gift (*.gift *.GIFT *.txt)"));
    QFile file(fileName);
    QString currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file : " + file.errorString());
        return;
    }
    modelClear();
    ControllerApp *newApp = new ControllerApp();
    addItemsToView(newApp->parseFile(file));
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();

}

//Обновить QListWidget
void MainWindow::updateListWidget() {
    ControllerApp *newAppController = new ControllerApp();
    ui->listWidget->clear();
    addItemsToView(newAppController->requestModelData());
}

void MainWindow::addItemsToView(QStringList strList) {
    for (int i = 0; i < strList.count(); i++){
        QListWidgetItem *item = new QListWidgetItem(strList[i]);
        ui->listWidget->addItem(item);
    }

}

//Редактирование вопросов
void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item){
    ControllerApp *newController = new ControllerApp();
    int index = ui->listWidget->row(item);
    QString qType = newController->requestQuestType(index);
    QStringList data = newController->getQuestData(index);
    if (qType == "Multiple Choise") {
        MultipleChoiseWindow *newMPWindow = new MultipleChoiseWindow();
        newMPWindow->editable = true;
        newMPWindow->index = index;
        newMPWindow->setUpUi(data);
        newMPWindow->exec();
    }
    if (qType == "Short Answer") {
        ShortAnswerDialog *newSAWindow = new ShortAnswerDialog();
        newSAWindow->editable = true;
        newSAWindow->index = index;
        //newSAWindow->setUpUI(data);
        newSAWindow->exec();
    }
    if (qType == "True False") {
        TrueFalseDialog *newTFWindow = new TrueFalseDialog();
        newTFWindow->editable = true;
        newTFWindow->index = index;
        newTFWindow->setUpUI(data);
        newTFWindow->exec();
    }
    if (qType == "Matching Selection") {
        MatchingSelectionDialog *newMSWindow = new MatchingSelectionDialog();
        newMSWindow->editable = true;
        newMSWindow->index = index;
        newMSWindow->setUpUI(data);
        newMSWindow->exec();
    }
    if (qType == "Numeric Answer") {
        NumericAnswerDialog *newNAWindow = new NumericAnswerDialog();
        newNAWindow->editable = true;
        newNAWindow ->index = index;
        newNAWindow->setUpUI(data);
        newNAWindow->exec();
    }
    if (qType == "Essay") {
        DialogEssay *newEWindow = new DialogEssay();
        newEWindow->editable = true;
        newEWindow->index = index;
        newEWindow->setUpUI(data);
        newEWindow->exec();
    }

    updateListWidget();
}

//Сохранить как
void MainWindow::on_action_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as", "Test", tr("Gift (*.gift *.GIFT *.txt)"));
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot save file : " + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream out (&file);
    QString text;
    for (int i = 0; i < ui->listWidget->count(); i++) {
        text = text + ui->listWidget->item(i)->text().toUtf8() + "\n";
    }
    out << text;
    file.close();
    modelClear();
}

//Отчистить модель
void MainWindow::modelClear(){
    ControllerApp *newAppController = new ControllerApp();
    newAppController->clearModel();
    updateListWidget();
    ui->listWidget->takeItem(0);
    setWindowTitle("No file");
}
//Новый файл
void MainWindow::on_action_2_triggered()
{
    modelClear();
    setWindowTitle("New File");
}
