#ifndef ESSAYDIALOG_H
#define ESSAYDIALOG_H

#include <QDialog>

namespace Ui {
class EssayDialog;
}

class DialogEssay : public QDialog
{
    Q_OBJECT

public:
    explicit DialogEssay(QWidget *parent = nullptr);
    bool editable = false;
    int index = 0;
    void setUpUI(QStringList data);
    ~DialogEssay();

private slots:
    void on_pushButton_clicked();

private:
    Ui::EssayDialog *ui;
};

#endif // ESSAYDIALOG_H
