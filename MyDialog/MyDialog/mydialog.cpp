#include "mydialog.h"

MyDialog::MyDialog(QWidget *parent, Qt::WindowFlags f)
    :QDialog(parent,f)
{
//    this->resize(100,200);
#if 1
    //方法一：
    this->setWindowFlags(/*Qt::FramelessWindowHint |*/ Qt::Dialog | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);
    this->setWindowModality(Qt::WindowModal);
#endif

#if 0
    //方法二：
    this->setModal(true);
#endif
}
