#ifndef TUTORIAL_H
#define TUTORIAL_H

#include <QDialog>
//In C++, the extern keyword primarily tells the compiler that a variable or function exists and is defined in another source file (translation unit).
extern int *sharedPassword;
namespace Ui {
class tutorial;
}

class tutorial : public QDialog
{
    Q_OBJECT

public:
    explicit tutorial(QWidget *parent = nullptr);
    ~tutorial();

private slots:
    void on_backButton_clicked();
    void on_forgorButton_clicked();

private:
    Ui::tutorial *ui;
};

#endif // TUTORIAL_H