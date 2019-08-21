#include "mylabel.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPixmap>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>
#include <QString>

MyLabel::MyLabel(QWidget *parent)
    : QWidget(parent)
{
//    pushButton = new QPushButton(this);
//    pushButton->setText("按钮");

    label = new QLabel(this);
//    label->setText("<a href='www.baidu.com'>百度一下</a>");
//    connect(label, SIGNAL(linkActivated(QString)), this, SLOT(linkClicked(QString)));
    label->setPixmap(QPixmap("./first.png"));

    //D:/GitHub/DailyTest/MyLabel/MyLabel/Debug/debug --- Qt
    //D:\GitHub\DailyTest\MyLabel\MyLabel\Debug\debug --- Windows
    qDebug() << QCoreApplication::applicationDirPath(); //包含可执行文件的目录路径



}

MyLabel::~MyLabel()
{

}

void MyLabel::linkClicked(QString str)
{
    QDesktopServices::openUrl(QUrl(str));
}
