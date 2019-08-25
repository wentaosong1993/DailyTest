#ifndef MSGBOX_H
#define MSGBOX_H

#include <QWidget>

class MsgBox : public QWidget
{
    Q_OBJECT

public:
    MsgBox(QWidget *parent = 0);
    ~MsgBox();
};

#endif // MSGBOX_H
