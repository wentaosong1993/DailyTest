#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    megBox = new QMessageBox(this);
    megBox->addButton(QStringLiteral("是"),QMessageBox::AcceptRole);
    megBox->addButton(QStringLiteral("否"),QMessageBox::RejectRole);
    megBox->setText(QStringLiteral("退出游戏？"));
    megBox->move((QApplication::desktop()->screenGeometry().width()/2 - megBox->width()/2),(QApplication::desktop()->screenGeometry().height()/2 - megBox->height()/2));
    int ret= megBox->exec();
    switch(ret)
    {
    case QMessageBox::AcceptRole:
    {
        qDebug() << "close";
        break;
    }
    default:
        break;
    }
}

Widget::~Widget()
{

}
