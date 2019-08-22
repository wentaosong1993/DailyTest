#include "mywidget.h"
#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();


//    QDialog *dialog = new QDialog();
//    dialog->setAttribute(Qt::WA_DeleteOnClose);
////    dialog->setModal(true);
//    dialog->setWindowModality(Qt::WindowModal);
//    dialog->show();



    return a.exec();
}
