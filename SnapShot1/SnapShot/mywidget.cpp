#include "mywidget.h"
#include <QApplication>
#include <QScreen>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
//方式2：
//    screen = QApplication::primaryScreen();
//    screen->grabWindow(this->winId()).save("third.png");
}

MyWidget::~MyWidget()
{

}
