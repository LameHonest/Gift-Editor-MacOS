#ifndef MULTIPLECHOISEWINDOW_H
#define MULTIPLECHOISEWINDOW_H

#include <QDialog>
#include <QListWidget>
#include <QListWidgetItem>

namespace Ui {
class DialogMultipleChoise;
}

class MultipleChoiseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MultipleChoiseWindow(QWidget *parent = nullptr);
    void setUpUi (QStringList data);
    bool editable = false;
    int index = 0;
    ~MultipleChoiseWindow();

private slots:
    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_listWidget_itemClicked(QListWidgetItem *item);


    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogMultipleChoise *ui;
};

#endif // MULTIPLECHOISEWINDOW_H
