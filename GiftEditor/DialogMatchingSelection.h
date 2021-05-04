#ifndef MATCHINGSELECTIONDIALOG_H
#define MATCHINGSELECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DialogMatchingSelection;
}

class MatchingSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MatchingSelectionDialog(QWidget *parent = nullptr);
    ~MatchingSelectionDialog();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DialogMatchingSelection *ui;
};

#endif // MATCHINGSELECTIONDIALOG_H
