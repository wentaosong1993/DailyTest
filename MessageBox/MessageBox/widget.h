#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QMessageBox;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QMessageBox * megBox = nullptr;

};

#endif // WIDGET_H
