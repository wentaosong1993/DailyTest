#include "widget.h"
#include <QApplication>
#include "stringlistmodel.h"
#include <QListView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QStringList numbers;
    numbers << "One" << "Two" << "Three" << "Four" << "Five";

    QAbstractItemModel *model = new StringListModel(numbers);
    //要注意的是，这里把StringListModel作为一个QAbstractItemModel来使用。这样我们就可以
    //使用model中的抽象接口，而且如果将来我们用别的model代替了当前这个model,这些代码也会照样工作。
    //QListView提供的列表视图足以满足当前这个model的需要了。
    QListView *view = new QListView;
    view->setModel(model);
    view->show();

    return a.exec();
}
