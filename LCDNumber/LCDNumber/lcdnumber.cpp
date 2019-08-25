#include "lcdnumber.h"
#include <QLCDNumber>
#include <QDebug>

LCDNumber::LCDNumber(QWidget *parent)
    : QWidget(parent)
{
    lcdNumber = new QLCDNumber(this);
    lcdNumber->setSegmentStyle(QLCDNumber::Flat);
    lcdNumber->resize(200,200);
//    lcdNumber->setDecMode();
    lcdNumber->setDigitCount(6);
    lcdNumber->setSmallDecimalPoint(true);
    lcdNumber->display("iF");//不能显示超过F的字母

    connect(lcdNumber,SIGNAL(overflow()),this, SLOT(onOverFlow()));

}

LCDNumber::~LCDNumber()
{

}

void LCDNumber::onOverFlow()
{
    qDebug() << "over flow";
}
