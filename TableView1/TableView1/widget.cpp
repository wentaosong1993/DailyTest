#include "widget.h"
#include <QStandardItemModel>
#include <QHeaderView>
#include <QDebug>

#include <QTooltip>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    m_tableView = new QTableView(this);
    QStandardItemModel *tableModel = new QStandardItemModel();
    tableModel->setColumnCount(3);
//    tableModel->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("卡号"));
//    tableModel->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("姓名"));
    QStringList labels = QString(QStringLiteral("频率,功率,误差")).simplified().split(",");
    tableModel->setHorizontalHeaderLabels(labels);


    m_tableView->setModel(tableModel);

    //表头信息显示居左
    m_tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);

    //设置列宽不可变
    m_tableView->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    m_tableView->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Fixed);
    m_tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Fixed);
    m_tableView->setColumnWidth(0,100);
    m_tableView->setColumnWidth(1,100);
    m_tableView->setColumnWidth(2,100);

    for(int i = 0; i < 3; i++)
    {
        tableModel->setItem(i,0,new QStandardItem(QString("%1").arg((i+1)*3)));
        //设置字符颜色
        tableModel->item(i,0)->setForeground(QBrush(QColor(255, 0, 0)));//red
         //设置字符位置
        tableModel->item(i,0)->setTextAlignment(Qt::AlignCenter);

        tableModel->setItem(i,1,new QStandardItem(QString::fromLocal8Bit("%1").arg(i+1)));
        tableModel->item(i,1)->setTextAlignment(Qt::AlignCenter);
        tableModel->setItem(i,2,new QStandardItem(QString::fromLocal8Bit("%2").arg((i+1)*2)));
        tableModel->item(i,2)->setTextAlignment(Qt::AlignCenter);
    }

    m_tableView->setSortingEnabled(true);//排序

    int width = this->width();
    int height = this->height();
    qInfo() << QStringLiteral("主窗口宽和高：") << width << height;
//    this->resize(450,300);
    this->resize(width,height);
    m_tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    m_tableView->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    m_tableView->setShowGrid(true);
    m_tableView->setGridStyle(Qt::SolidLine); //实线

    m_tableView->setStyleSheet("QTableView { border: none;" \
                               "selection-background-color: #8EDE21;" \
                               "color: red;}");
//    m_tableView->verticalHeader()->hide();
//    m_tableView->verticalHeader()->setVisible(false);
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectItems);

    //鼠标跟随
    m_tableView->setMouseTracking(true);


    connect(m_tableView,SIGNAL(clicked(const QModelIndex)),this,SLOT(clickSlots(QModelIndex)));

    //activated enter pressed when in the current item
    connect(m_tableView,SIGNAL(activated(const QModelIndex)),this, SLOT(clickSlots(QModelIndex)));

    //悬浮效果
    connect(m_tableView,SIGNAL(entered(const QModelIndex)),this, SLOT(showToolTip(QModelIndex)));

}

Widget::~Widget()
{

}

void Widget::clickSlots(QModelIndex curIndex)
{
    if(!curIndex.isValid())
    {
        return ;
    }
    qDebug() << "curIndex:(row,column):" << curIndex.row() << curIndex.column() << curIndex.data(Qt::EditRole);
}

void Widget::showToolTip(const QModelIndex &index)
{
    if(!index.isValid())
       return;

    int row = index.row();
    QString name = index.data(Qt::DisplayRole).toString();

    if(name.isEmpty())
       return;

    QToolTip::showText(QCursor::pos(), name);
}

