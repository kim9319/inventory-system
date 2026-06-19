#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDateTime>
#include "login.h"
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //  Add categories (array)
    QString categories[] = {"💡Electronics", "🍗Food", "👕Clothing", "✏️Stationery", "Other"};

    for (const QString &cat : categories)
    {
        ui->categoryEdit->addItem(cat);
    }

    //  Table setup
    ui->tableWidget->setColumnCount(6);
    QStringList headers;
    headers << "Item Name" << "Quantity" << "Price"
            << "Category" << "Last Update" << "Action";

    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//  Show username
void MainWindow::setUsername(const QString &name)
{
    ui->welcomeLabel->setText("Welcome, " + name);
}

// Add item
void MainWindow::on_addButton_clicked()
{
    if (itemCount >= 100)
    {
        QMessageBox::warning(this, "Error", "Inventory full!");
        return;
    }

    Item item;
    item.name = ui->nameEdit->text();
    item.quantity = ui->quantityEdit->text().toInt();
    item.price = ui->priceEdit->text().toDouble();
    item.category = ui->categoryEdit->currentText();
    item.lastUpdated = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");

    if (item.name.isEmpty() || item.quantity <= 0)
    {
        QMessageBox::warning(this, "Warning", "Invalid input");
        return;
    }

    //  Check existing
    for (int i = 0; i < itemCount; i++)
    {
        if (items[i].name == item.name)
        {
            items[i].quantity += item.quantity;
            items[i].price = item.price;
            items[i].category = item.category;
            items[i].lastUpdated = item.lastUpdated;
            updateTable();
            return;
        }
    }

    //  Add to array
    items[itemCount] = item;
    itemCount++;

    updateTable();

    //  Clear inputs
    ui->nameEdit->clear();
    ui->quantityEdit->clear();
    ui->priceEdit->clear();
    ui->categoryEdit->setCurrentIndex(0);
}

//  Remove item
void MainWindow::on_removeButton_clicked()
{
    int row = ui->rowEdit->text().toInt() - 1;

    if (row < 0 || row >= itemCount)
        return;

    if (QMessageBox::question(this, "Confirm", QString("Delete this row %1?").arg(row + 1)) == QMessageBox::Yes){
        for (int i = row; i < itemCount - 1; i++)
        {
            items[i] = items[i + 1];
        }
        itemCount--;

        updateTable();
    }
}

//  Edit item
void MainWindow::on_editButton_clicked()
{
    int row = ui->rowEdit->text().toInt() - 1;

    if (row < 0 || row >= itemCount)
        return;

    Item &item = items[row];

    if (!ui->nameEdit->text().isEmpty())
        item.name = ui->nameEdit->text();

    int qty = ui->quantityEdit->text().toInt();
    if (qty > 0)
        item.quantity = qty;

    double price = ui->priceEdit->text().toDouble();
    if (price > 0)
        item.price = price;

    if (!ui->categoryEdit->currentText().isEmpty())
        item.category = ui->categoryEdit->currentText();

    item.lastUpdated = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm");

    updateTable();
}

//  Update table
void MainWindow::updateTable()
{
    ui->tableWidget->setRowCount(itemCount);

    for (int i = 0; i < itemCount; i++)
    {
        const Item &item = items[i];

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(item.name));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(item.quantity)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(item.price)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(item.category));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(item.lastUpdated));

        QPushButton *btn = new QPushButton("Detail");
        ui->tableWidget->setCellWidget(i, 5, btn);

        connect(btn, &QPushButton::clicked, this,[=]()  {
            showItemDetails(i);
        });
    }
}


//  Show details
void MainWindow::showItemDetails(int index)
{
    if (index < 0 || index >= itemCount)
        return;

    const Item &item = items[index];

    QString info =
        "Name: " + item.name + "\n" +
        "Quantity: " + QString::number(item.quantity) + "\n" +
        "Price: $" + QString::number(item.price) + "\n" +
        "Category: " + item.category + "\n" +
        "Last Updated: " + item.lastUpdated;

    QMessageBox::information(this, "Item Details", info);
}




//  Logout
void MainWindow::on_logoutButton_clicked()
{
    login *log = new login();
    log->show();
    this->close();
}



//save
void MainWindow::saveToFile(const QString &filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Cannot save file");
        return;
    }

    QTextStream out(&file);

    for (int i = 0; i < itemCount; i++)
    {
        out << items[i].name << ","
            << items[i].quantity << ","
            << items[i].price << ","
            << items[i].category << ","
            << items[i].lastUpdated << "\n";
    }

    file.close();
    QMessageBox::information(this, "Saved", "Data saved successfully!");
}

void MainWindow::loadFromFile(const QString &filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, "Error", "Cannot open file");
        return;
    }

    QTextStream in(&file);

    itemCount = 0;  // clear old data

    while (!in.atEnd())
    {
        QString line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() < 5)
            continue;

        Item item;
        item.name = parts[0];
        item.quantity = parts[1].toInt();
        item.price = parts[2].toDouble();
        item.category = parts[3];
        item.lastUpdated = parts[4];

        items[itemCount++] = item;
    }

    file.close();
    updateTable();

    QMessageBox::information(this, "Loaded", "Data imported successfully!");
}
void MainWindow::on_saveButton_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, "Save File", "", "CSV Files (*.csv)");
    if (!filePath.isEmpty())
        saveToFile(filePath);
}

void MainWindow::on_loadButton_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, "Open File", "", "CSV Files (*.csv)");
    if (!filePath.isEmpty())
        loadFromFile(filePath);
}