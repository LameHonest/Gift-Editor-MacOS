#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidget>
#include "ControllerApp.h"
//подключаем ui вопросов
#include "DialogMatchingSelection.h"
#include "DialogEssay.h"
#include "DialogMissedWord.h"
#include "DialogMultipleChoise.h"
#include "DialogNumericAnswer.h"
#include "DialogShortAnswer.h"
#include "DialogTrueFalse.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_actionOpen_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    void modelClear();
    void updateListWidget ();
    void addItemsToView(QStringList);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
