#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

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
    //QMessageBox::about(this, "My Title", "This is my custom message");
    //QMessageBox::aboutQt(this, "My Title");
    //QMessageBox::critical(this, "My Title", "This is my custom message");
    //QMessageBox::information(this, "My Title", "This is my custom message");
    QMessageBox::StandardButton reply = QMessageBox::question(this, "My Title", "This is my custom message",
                          QMessageBox::YesAll | QMessageBox::No);

    if(reply == QMessageBox::YesAll)
    {
        QApplication::quit();
    }
    else
    {
        qDebug() << "No is clicked";
    }

    //QMessageBox::warning(this, "My Title", "This is my custom message");

}

