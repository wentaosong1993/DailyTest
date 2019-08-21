#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
class QPushButton;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void myButtonClick(bool isCheck);

private:
    QPushButton *pushButton;
};

#endif // WIDGET_H
