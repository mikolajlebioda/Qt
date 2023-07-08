#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        QMessageBox::information(this, "Tite", "You selected option A");
    }
    else if(ui->radioButton_2->isChecked())
    {
        QMessageBox::information(this, "Tite", "You selected option B");
    }
    else
    {
        QMessageBox::information(this, "Tite", "Please, select option A or B");
    }
}

