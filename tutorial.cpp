#include "tutorial.h"
#include "ui_tutorial.h"
#include "QMessageBox"
#include "login.h"
tutorial::tutorial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tutorial)
{
    ui->setupUi(this);
}

tutorial::~tutorial()
{
    delete ui;
}

void tutorial::on_backButton_clicked()
{
    this->close();
}



void tutorial::on_forgorButton_clicked()
{
    //use bool ok to check is int or not
    bool ok;
    int newPass = ui->forgorEdit->text().toInt(&ok);

    if (!ok)
    {
        QMessageBox::warning(this, "Error", "Enter numbers only");
        return;
    }

    *sharedPassword = newPass;

    QMessageBox::information(this, "Success", "Password changed!");
}



