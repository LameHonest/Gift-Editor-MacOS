#ifndef NUMERICANSWERDIALOG_H
#define NUMERICANSWERDIALOG_H

#include <QDialog>

namespace Ui {
class DialogNumericAnswer;
}

class NumericAnswerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumericAnswerDialog(QWidget *parent = nullptr);
    bool editable = false;
    int index = 0;
    void setUpUI(QStringList data);
    ~NumericAnswerDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DialogNumericAnswer *ui;
};

#endif // NUMERICANSWERDIALOG_H
