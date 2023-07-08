#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QListWidgetItem *item = new QListWidgetItem(QIcon(":/res/rec/new.png"), "*New* Item");

    ui->listWidget->addItem("Item A");
    ui->listWidget->addItem("Item B");
    ui->listWidget->addItem("Item C");
    ui->listWidget->addItem(item);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //QMessageBox::information(this, "Title", ui->listWidget->currentItem()->text());
    ui->listWidget->currentItem()->setBackground(Qt::red);
    ui->listWidget->currentItem()->setForeground(Qt::blue);
}

