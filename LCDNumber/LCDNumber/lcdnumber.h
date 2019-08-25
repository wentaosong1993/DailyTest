#ifndef LCDNUMBER_H
#define LCDNUMBER_H

#include <QWidget>
class QLCDNumber;

class LCDNumber : public QWidget
{
    Q_OBJECT

public:
    LCDNumber(QWidget *parent = 0);
    ~LCDNumber();

public slots:
    void onOverFlow();
private:
    QLCDNumber *lcdNumber = nullptr;
};

#endif // LCDNUMBER_H
