#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "tutorial.h"
#include <QApplication>
//default password is 1234
int *sharedPassword = new int(1234);

login::login(QDialog *parent)
    : QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_loginButton_clicked()
{
    int check=0;
    int f=0;
    QString user = ui->usernameEdit->text();
    QString pass = ui->passwordEdit->text();
    f = pass.toInt();
    check = checkuser(f);
    if ( check == 456789)
    {
        MainWindow *inventory = new MainWindow();

        inventory->setUsername(user);

        inventory->show();
        this->hide();
    }
    else
    {
        QMessageBox::warning(this, "Login Failed", "Wrong username or password");
    }



}
void login::on_tutorialButton_clicked()
{
    tutorial *guide = new tutorial(this);
    guide->show();
}

void login::on_exitButton_clicked()
{
    QApplication::quit();
}

int checkuser(int pas)
{
    int n=0;
    if (pas == *sharedPassword)
    {
        n=456789;
    }
    else
    {
        n=0;
    }

    return (n);

}