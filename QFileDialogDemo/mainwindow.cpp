#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <qmessagebox.h>
#include <qdir.h>

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
    QString fileName =  QFileDialog::getOpenFileName(this,"Open ->", QDir::homePath());
    QMessageBox::information(this,"",fileName);
}

