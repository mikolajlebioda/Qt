#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Option A");
    ui->comboBox->addItem("Option B");
    ui->comboBox->addItem("Option C");

    for(int i = 0; i < 10; ++i)
    {
        ui->comboBox->addItem(QIcon(":/rec/rec/new.png"),"*New* Option " + QString::number(i));
    }

    ui->comboBox->insertItem(2, "*Obsolete* " + ui->comboBox->itemText(2));
    ui->comboBox->removeItem(3);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Title", ui->comboBox->currentText());
}

