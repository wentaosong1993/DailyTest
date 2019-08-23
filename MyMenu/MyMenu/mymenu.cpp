#include "mymenu.h"
#include <QMenu>
#include <QAction>

MyMenu::MyMenu(QWidget *parent)
    : QWidget(parent)
{
    menuButton = new QPushButton(QStringLiteral("菜单按钮"),this);
    menuButton->setFixedSize(100,30);
    menuButton->setStyleSheet("QPushButton:menu-indicator{image:None;}");//去掉按钮后面那个小箭头

    menu = new QMenu(menuButton);

    action1 = new QAction(QStringLiteral("菜单一"),menu);
    action2 = new QAction(QStringLiteral("菜单二"),menu);

///error:
/*  const *T
    QList<QAction> listActions;
    listActions.append(action1);
    listActions.append(action2);
    listActions[0] = action1;
    listActions[1] = action2;
    menu->addActions(listActions);
*/
    menu->addAction(action1);
    menu->addAction(action2);

    menuButton->setMenu(menu);

    connect(action1, SIGNAL(triggered(bool)), this, SLOT(textChanged1(bool)));
    connect(action2, SIGNAL(triggered(bool)), this, SLOT(textChanged2(bool)));


}

MyMenu::~MyMenu()
{
    delete menuButton;
    menuButton = nullptr;
}

void MyMenu::textChanged1(bool text)
{
    menuButton->setText(QStringLiteral("菜单一被触发"));
}

void MyMenu::textChanged2(bool text)
{
    menuButton->setText(QStringLiteral("菜单二被触发"));
}
