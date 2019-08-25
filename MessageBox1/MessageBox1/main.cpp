#include "msgbox.h"
#include <QApplication>
#include <QMessageBox>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    MsgBox w;
    //    w.show();


    qDebug() << QString::fromLocal8Bit("你好，Qt!");//这种可以
    qDebug() << QString::fromUtf8("你好，Qt!");//这种方式不能解决乱码的问题；


    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Critical);
    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret)
    {
    case QMessageBox::Save:
        // Save was clicked
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        break;
    default:
        // should never be reached
        break;
    }



    return a.exec();
}
