#include "lcdnumber.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LCDNumber w;
    w.show();

    return a.exec();
}
