#ifndef TRUEFALSEDIALOG_H
#define TRUEFALSEDIALOG_H

#include <QDialog>

namespace Ui {
class DialogTrueFalse;
}

class TrueFalseDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrueFalseDialog(QWidget *parent = nullptr);
    bool editable = false;
    int index = 0;
    void setUpUI(QStringList data);
    ~TrueFalseDialog();

private slots:
    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogTrueFalse *ui;
};

#endif // TRUEFALSEDIALOG_H
