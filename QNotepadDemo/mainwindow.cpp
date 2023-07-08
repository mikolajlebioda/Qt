#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColorDialog>
#include <QColor>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    filePath.clear();
    ui->textEdit->clear();
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open...");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "...", "file not open");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "...", "file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save...");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "...", "file not open");
        return;
    }

    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionAbout_Notepad_triggered()
{
    QMessageBox::about(this,"about", "This is my notepad");
}


void MainWindow::on_actionFont_triggered()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
}


void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::black, this, "Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}


void MainWindow::on_actionBackground_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}


void MainWindow::on_actionBackground_2_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose color");

    if(color.isValid())
    {
        QPalette palette;
        palette.setColor(QPalette::Base, color);
        ui->textEdit->setPalette(palette);
    }
}


void MainWindow::on_actionPrint_triggered()
{

    QPrinter printer;
    printer.setPrinterName("random printer name");
    QPrintDialog dialog(&printer, this);
    if(dialog.exec() == QDialog::Rejected)
    {
        return;
    }
    ui->textEdit->print(&printer);

}

