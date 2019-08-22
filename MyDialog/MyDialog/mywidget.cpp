#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
//    myDialog = new MyDialog(this); //这里必须设置弹框父对象
//    myDialog->setWindowTitle("modal Window");
//    myDialog->show();
}

MyWidget::~MyWidget()
{
    delete myDialog;
    myDialog = nullptr;
}
