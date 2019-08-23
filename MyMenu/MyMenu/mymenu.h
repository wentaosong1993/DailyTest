#ifndef MYMENU_H
#define MYMENU_H

#include <QWidget>
#include <QPushButton>

class MyMenu : public QWidget
{
    Q_OBJECT

public:
    MyMenu(QWidget *parent = 0);
    ~MyMenu();

public slots:
    void textChanged1(bool text);
    void textChanged2(bool text);

private:
    QPushButton *menuButton = nullptr;
    QMenu *menu = nullptr;
    QAction *action1 = nullptr;
    QAction *action2 = nullptr;
};

#endif // MYMENU_H
