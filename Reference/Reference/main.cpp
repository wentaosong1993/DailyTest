#include <QCoreApplication>
#include <QtGlobal>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    int numberArray[] = {1,8,2,3,6};

    int maxNumber = numberArray[0];
    for(int i = 0; i < sizeof(numberArray)/sizeof(numberArray[0]); i++)
    {
//        maxNumber = numberArray[i];//每次都会重写该值
        maxNumber = qMax(maxNumber,numberArray[i]);
    }

    qInfo() << "maxNumber:" << maxNumber;

    return a.exec();
}
