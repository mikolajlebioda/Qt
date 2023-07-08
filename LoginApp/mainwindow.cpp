#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "secdialog.h"
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/resources/img/login.jpg");
    ui->picLabel->setPixmap(pix.scaled(ui->picLabel->width(),ui->picLabel->height(),Qt::KeepAspectRatio));
    ui->statusbar->addPermanentWidget(ui->label_3);
    ui->statusbar->addPermanentWidget(ui->progressBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginButton_clicked()
{
    QString user = ui->userEdit->text();
    QString pass = ui->passEdit->text();

    if(user == "admin" && pass == "admin1")
    {
//        hide();
//        QMessageBox::information(this,"Login", "You are in!");
//        SecDialog secDlg(this);
//        secDlg.setModal(true);
//        secDlg.exec();
        ui->statusbar->showMessage("You are in!", 2000);
        ui->label_3->setText("OK!");
    }
    else
    {
//        QMessageBox::warning(this, "Login", "Password or username is incorrect!");
        ui->statusbar->showMessage("Password or username is incorrect!", 2000);
        ui->label_3->setText("ERROR!");
    }
}

