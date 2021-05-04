#include "DialogMissedWord.h"
#include "ui_missedworddialog.h"

MissedWordDialog::MissedWordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogMissedWord)
{
    ui->setupUi(this);
}

MissedWordDialog::~MissedWordDialog()
{
    delete ui;
}
