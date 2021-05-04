#ifndef MISSEDWORDDIALOG_H
#define MISSEDWORDDIALOG_H

#include <QDialog>

namespace Ui {
class DialogMissedWord;
}

class MissedWordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MissedWordDialog(QWidget *parent = nullptr);
    ~MissedWordDialog();

private:
    Ui::DialogMissedWord *ui;
};

#endif // MISSEDWORDDIALOG_H
