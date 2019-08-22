#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include "mydialog.h"

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = 0);
    ~MyWidget();

private:
    MyDialog *myDialog = nullptr;
};

#endif // MYWIDGET_H
