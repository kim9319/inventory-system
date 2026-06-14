#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct Item {
    QString name;
    int quantity;
    double price;
    QString category;
    QString lastUpdated;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setUsername(const QString &name);

private slots:
    void on_addButton_clicked();
    void on_removeButton_clicked();
    void on_editButton_clicked();
    void on_logoutButton_clicked();

    void showItemDetails(int index);

private:
    Ui::MainWindow *ui;

    Item items[199];   // ✅ array
    int itemCount = 0; // ✅ number of items

    void updateTable();


};


#endif // MAINWINDOW_H
