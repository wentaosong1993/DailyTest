#ifndef MYLABEL_H
#define MYLABEL_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class MyLabel : public QWidget
{
    Q_OBJECT

public:
    MyLabel(QWidget *parent = 0);
    ~MyLabel();

public slots:
    void linkClicked(QString str);

private:
    QPushButton *pushButton = nullptr;
    QLabel *label = nullptr;
};

#endif // MYLABEL_H
