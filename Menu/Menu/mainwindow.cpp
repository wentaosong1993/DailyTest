#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QDir>
#include <QDebug>
#include <QFileDialog>
#include <QApplication>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->newAction, SIGNAL(triggered(bool)),this, SLOT(newFile()));
    connect(ui->openAction, SIGNAL(triggered(bool)),this, SLOT(openFile()));
    connect(ui->saveAction, SIGNAL(triggered(bool)),this, SLOT(saveFile()));
    connect(ui->saveAsAction, SIGNAL(triggered(bool)),this, SLOT(saveAsFile()));
    connect(ui->quitAction, SIGNAL(triggered(bool)),this, SLOT(quitFile()));
    ui->textEdit->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    //调用外部应用程序
/*
//    QString program = "C:\\WINDOWS\\system32\\notepad.exe";
//    int ret = QProcess::execute(QDir::fromNativeSeparators(program),QStringList(""));
//    if(-2 == ret)
//    {
//        qDebug() << "program is normally opened";
//    }
//    else if(-1 == ret)
//    {
//        qDebug() << "program crashed";
//    }
//    else
//    {
//        qDebug() << "program error";
//    }
*/

    ui->textEdit->setVisible(true);


}

void MainWindow::openFile()
{
    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                        QApplication::applicationFilePath(),tr("(*.txt)"));

    if(fileName.isEmpty())
    {
        qDebug() << "file does not exist";
    }
    else
    {
        qDebug() << "fileName:" << fileName;
         QFile file(fileName);
         if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         {
             return;
         }
         else
         {
             QString content = QString::fromLocal8Bit(file.readAll());
             ui->textEdit->setPlainText(content);
             file.close();
         }
    }

}

void MainWindow::saveFile()
{
    QString newContent = ui->textEdit->toPlainText();
    if(fileName.isEmpty())
    {
        qDebug() << "file does not exist";
        return;
    }
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    else
    {
        file.write(newContent.toLocal8Bit());
        file.close();
    }
}

void MainWindow::saveAsFile()
{
        QString newContent = ui->textEdit->toPlainText();
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                                                    QApplication::applicationFilePath(),
                                                    tr("(*.txt)"));
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    else
    {
        file.write(newContent.toLocal8Bit());
        file.close();
    }


}

void MainWindow::printFile()
{

}

void MainWindow::quitFile()
{
    saveFile();
    this->close();
}
