#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qdir.h>
#include <qmessagebox.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QDir dir("C:/Users/Draw2Cards/Documents/QDirDemo");
//    if(dir.exists())
//    {
//        QMessageBox::information(this, "title", "Ok");
//    }
//    else
//    {
//        QMessageBox::information(this, "title", "Error");
//    }

    QDir dir;
    foreach (QFileInfo var, dir.drives())
    {
        ui->comboBox->addItem(var.absoluteFilePath());
    }
    QDir dir2("C:/Users/Draw2Cards/Documents/QDirDemo");
    foreach (QFileInfo var, dir2.entryInfoList())
    {
        if(var.isDir())
        {
            ui->listWidget->addItem("Dir: " + var.absoluteFilePath());
        }
        else
        {
            ui->listWidget->addItem("File: " + var.absoluteFilePath());
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QDir dir("C:/Users/Draw2Cards/Documents/QDirDemo/new");

    if(dir.exists())
    {
        QMessageBox::information(this,"title", "'new' folder already exists!");
    }
    else
    {
        dir.mkpath("C:/Users/Draw2Cards/Documents/QDirDemo/new");
    }

}

