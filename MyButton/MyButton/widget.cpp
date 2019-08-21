#include "widget.h"
#include <QPushButton>
#include <QDebug>
#include <QKeySequence>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    pushButton = new QPushButton(this);
    //方法一：
//    pushButton->setText("&Download");
//    pushButton->setText("Down&load");//&在谁前面，Alt+谁 就是对应的快捷键

    //方法二：
    pushButton->setShortcut(QKeySequence("Ctrl+P"));
    connect(pushButton,SIGNAL(clicked(bool)),this,SLOT(myButtonClick(bool)));
}

Widget::~Widget()
{

}

void Widget::myButtonClick(bool isCheck)
{
    qDebug() << QStringLiteral("状态：") << isCheck;
}
