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
    ~ShortAnswerDialog();

private:
    Ui::DialogShortAnswer *ui;
};

#endif // SHORTANSWERDIALOG_H
