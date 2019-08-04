#include "widget.h"

#include <QTableView>
#include <QHeaderView>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    example_model =new ExampleModel(this); //(自定义的数据层model)
    QStringList colHeaderList;
    colHeaderList << QStringLiteral("名字") << QStringLiteral("序号")<< QStringLiteral("性别") << QStringLiteral("年龄") << QStringLiteral("成绩");
    example_model->setHorizontalHeaderLabels(colHeaderList);

    QStringList rowHeadList;
    rowHeadList << "1" << "2" << "3" << "4" << "5";
    example_model->setVerticalHeaderLabels(rowHeadList);
    //表头
    exampleTableView = new QTableView(this);
    exampleTableView->setModel(example_model); //（model,数据层）
    exampleTableView->horizontalHeader()->setStretchLastSection(true);
    exampleTableView->setSortingEnabled(true);
//    exampleTableView->setSizePolicy(1);
    exampleTableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    this->resize(this->width(), this->height());

     //把表格的背景调成相间色
    exampleTableView->setAlternatingRowColors(true);
    exampleTableView->verticalHeader()->setVisible(true); //垂直表头不显示
    exampleTableView->setContextMenuPolicy(Qt::CustomContextMenu);  //在QTableView中使用右键菜单，需启用该属性

    connect(exampleTableView,SIGNAL(clicked(QModelIndex)),this,SLOT(exampleTableViewClicked(QModelIndex)));
    connect(exampleTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(exampleTableViewDoubleClicked(QModelIndex)));

    connect( exampleTableView,SIGNAL(customContextMenuRequested(const QPoint)),this,SLOT(ShowMouseRightButton(const QPoint)));
}

Widget::~Widget()
{

}

void Widget::exampleTableViewClicked(QModelIndex)
{

}

void Widget::exampleTableViewDoubleClicked(QModelIndex)
{

}

void Widget::ShowMouseRightButton(const QPoint)
{

}
