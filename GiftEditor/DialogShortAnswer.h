#ifndef SHORTANSWERDIALOG_H
#define SHORTANSWERDIALOG_H

#include <QDialog>

namespace Ui {
class DialogShortAnswer;
}

class ShortAnswerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShortAnswerDialog(QWidget *parent = nullptr);
    bool editable = false;
    int index = 0;
    void setUpUI(QStringList data);
    ~ShortAnswerDialog();

private:
    Ui::DialogShortAnswer *ui;
};

#endif // SHORTANSWERDIALOG_H
