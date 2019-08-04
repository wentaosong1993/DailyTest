#include "widget.h"
#include <QDebug>
#include <QSplitter>
#include <QItemSelectionModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tableView1 = new QTableView();
    tableView2 = new QTableView();

    tableModel = new QStandardItemModel(this);
    tableModel->setHorizontalHeaderItem(0, new QStandardItem("Column 0"));
    tableModel->setHorizontalHeaderItem(1, new QStandardItem("Column 1"));

    tableModel->setVerticalHeaderItem(0, new QStandardItem("Row 0"));
    tableModel->setVerticalHeaderItem(1, new QStandardItem("Row 1"));
    tableModel->setVerticalHeaderItem(2, new QStandardItem("Row 2"));
    tableModel->setVerticalHeaderItem(3, new QStandardItem("Row 3"));

    for(int row = 0; row < tableModel->rowCount(QModelIndex()); row++)
    {
        for(int col = 0; col < tableModel->columnCount(QModelIndex()); col++)
        {
//            QStandardItem *curItem = tableModel->item(row, col);
//            if(curItem)
//            {
//                curItem->setText(QString("(%1, %2)").arg(row).arg(col));
//                curItem->setTextAlignment(Qt::AlignCenter);
//            }
//            else
//            {
//                qDebug() << "null"; //为空，因为先前没有创建单元格内容
//            }
            tableModel->setItem(row, col, new QStandardItem(QString("(%1, %2)").arg(row).arg(col)));
            tableModel->item(row, col)->setTextAlignment(Qt::AlignCenter);
        }
    }


    QSplitter *splitter = new QSplitter(this);
//    QListView *listview = new QListView;
//    QTreeView *treeview = new QTreeView;
//    QTextEdit *textedit = new QTextEdit;
//    splitter->addWidget(listview);
//    splitter->addWidget(treeview);
//    splitter->addWidget(textedit);
    splitter->addWidget(tableView1);
    splitter->addWidget(tableView2);

    tableView1->setModel(tableModel);
//    tableView1->setAlternatingRowColors(true); //相间色
    tableView1->show();

    tableView2->setModel(tableModel);
//    tableView2->setAlternatingRowColors(true);
    tableView2->show();

    ///注意是setSelectionModel,而不是setSelectionMode
    tableView2->setSelectionModel(tableView1->selectionModel());//views都在同样的选择模型上操作，数据与选择项都保持同步
//    tableView1->setSelectionModel(tableView2->selectionModel());//用一个就可以
    this->resize(this->width(), this->height());
}

Widget::~Widget()
{
    if(tableView1)
    {
        delete tableView1;
        tableView1 = nullptr;
    }
    if(tableView2)
    {
        delete tableView2;
        tableView2 = nullptr;
    }
    if(tableModel)
    {
        delete tableModel;
        tableModel = nullptr;
    }
}
