#include "mywidget.h"
#include <QScreen>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyWidget w;
//    w.show();
///方法1:
    QScreen *screen = QApplication::primaryScreen();
    screen->grabWindow(0).save("first.png");

    return a.exec();
}
