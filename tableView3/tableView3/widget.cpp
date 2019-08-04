#include "widget.h"
#include "spindelegate.h"
#include <QBrush>
#include <QColor>
#include <QFont>
#include <QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    tableView = new QTableView(this);
    tableModel = new QStandardItemModel;
    tableModel->setColumnCount(3);
    tableModel->setHeaderData(0,Qt::Horizontal, QStringLiteral("姓名"));
    tableModel->setHeaderData(1,Qt::Horizontal, QStringLiteral("年龄"));
    tableModel->setHeaderData(2,Qt::Horizontal, QStringLiteral("性别"));

    tableModel->setRowCount(3);
    tableModel->setHeaderData(0,Qt::Vertical, QStringLiteral("记录一"));
    tableModel->setHeaderData(1,Qt::Vertical, QStringLiteral("记录二"));
    tableModel->setHeaderData(2,Qt::Vertical, QStringLiteral("记录三"));

    tableModel->setItem(0, 0, new QStandardItem(QStringLiteral("张三")));
    tableModel->setItem(0, 1, new QStandardItem("3"));
    tableModel->setItem(0, 2, new QStandardItem(QStringLiteral("男")));

    tableModel->setItem(1, 0, new QStandardItem(QStringLiteral("李四")));
    tableModel->setItem(1, 1, new QStandardItem("3"));
    tableModel->setItem(1, 2, new QStandardItem(QStringLiteral("男")));

    tableModel->setItem(2, 0, new QStandardItem(QStringLiteral("王二")));
    tableModel->setItem(2, 1, new QStandardItem("3"));
    tableModel->setItem(2, 2, new QStandardItem(QStringLiteral("男")));

    for(int row = 0; row < tableModel->rowCount(QModelIndex()); row++)
    {
        for(int col = 0; col < tableModel->columnCount(QModelIndex()); col++)
        {
            QStandardItem *curItem = tableModel->item(row,col);
            if(curItem)
            {
                curItem->setTextAlignment(Qt::AlignCenter);
                curItem->setForeground(QBrush(QColor(255, 0, 0)));
                curItem->setFont( QFont("Times", 10, QFont::Black | QFont::Bold));
            }
            else
            {
                break;
            }
        }
    }

    tableView->setModel(tableModel);
    tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
//    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);//单元格不可编辑
//    tableView->setContextMenuPolicy(Qt::CustomContextMenu);//自定义右键菜单
//    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); //这个实现各列平均分配，并且占满整个tableview
//    tableView->resizeRowsToContents();//所有行高度自适应
//    tableView->resizeColumnsToContents();
    tableView->horizontalHeader()->setStretchLastSection(true);
    int w = this->width();
    int h = this->height();
    tableView->resize(w,h);
    this->resize(w, h);
    /*设置代理*/
    tableView->setItemDelegate(new SpinDelegate(this));

}

Widget::~Widget()
{

}
