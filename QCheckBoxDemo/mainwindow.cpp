#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if (ui->checkBox->isChecked())
    {
        QMessageBox::information(this, "Title", "Yes! :D");
    }
    else
    {
        QMessageBox::information(this, "Title", "No! :C");
    }
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
    {
        QMessageBox::information(this, "Title", "Yes! :D");
    }
    else
    {
        QMessageBox::information(this, "Title", "No! :C");
    }
}

