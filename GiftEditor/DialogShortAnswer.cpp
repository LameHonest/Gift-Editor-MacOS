#include "DialogShortAnswer.h"
#include "ui_shortanswerdialog.h"

ShortAnswerDialog::ShortAnswerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogShortAnswer)
{
    ui->setupUi(this);
}

ShortAnswerDialog::~ShortAnswerDialog()
{
    delete ui;
}
