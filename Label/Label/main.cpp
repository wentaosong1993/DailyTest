#include "widget.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    QLabel *label=new QLabel(&w);
    QString text;
    label->setWordWrap(true);
    //解决QLabel设置行距的问题
    //<p>----</p> 段落，语法参照html
    text.append(QStringLiteral("<p style='margin-top:10; color:red;'> 基于Qt5.7</p>"))
        .append(QStringLiteral("<p style='margin-top:3;'> minGW32位编译器</p>"))
        .append(QStringLiteral("<p style='margin-top:10;'> 开发环境</p>"));
    label->setText(text);
    w.show();

    return a.exec();
}
