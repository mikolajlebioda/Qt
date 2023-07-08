#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <QFileDialog>

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
    QFile file("C:/Users/Draw2Cards/Documents/QFileDemo/my_file.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::information(this, "title", "File not open");
    }

    QTextStream out(&file);
    QString text = ui->plainTextEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_pushButton_2_clicked()
{
    QString filter = "All Files (*.*) ;; HTML(test) (*.html)";
    QString fileName =  QFileDialog::getOpenFileName(this,"Open ->", QDir::homePath(), filter);
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if(!file.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(this, "title", "File not open");
        }

        QTextStream in(&file);
        QString text = in.readAll();
        ui->plainTextEdit->setPlainText(text);
        file.close();
    }
}
