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
    label->setFixedSize(400,400);
//    label->setText("<a href='www.baidu.com'>百度一下</a>");
//    connect(label, SIGNAL(linkActivated(QString)), this, SLOT(linkClicked(QString)));
//    label->setPixmap(QPixmap("./first.png"));

    QPixmap pix("../first.png");
    QPixmap pix2 = pix.scaled(label->width(), label->height());//设置大小和标签大小相适应
    label->setPixmap(pix2);


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
