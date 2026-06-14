#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include <QMessageBox>
#include "tutorial.h"
#include <QApplication>

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
    QString user = ui->usernameEdit->text();
    QString pass = ui->passwordEdit->text();

    if (pass == "1234")
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

