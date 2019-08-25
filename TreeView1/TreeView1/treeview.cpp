#include "treeview.h"
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QHeaderView>

TreeView::TreeView(QWidget *parent)
    : QWidget(parent)
{
    /*
    this->setGeometry(100,100,500,500);
    QTreeWidget *treeWidget=new QTreeWidget(this);
    treeWidget->setGeometry(10,10,300,300);
    treeWidget->setColumnCount(1);
    //    treeWidget->header()->setVisible(false);
    //隐藏表头
//    treeWidget->setHeaderHidden(true);
    //重命名表头
    treeWidget->setHeaderLabel(QStringLiteral("表头"));
    //利用item设置表头
    QTreeWidgetItem *itemh=new QTreeWidgetItem();
    itemh->setText(0,QStringLiteral("头"));
    treeWidget->setHeaderItem(itemh);


    QTreeWidgetItem *item1=new QTreeWidgetItem();
    item1->setText(0,QStringLiteral("父节点"));
    //子节点
    QTreeWidgetItem *item2=new QTreeWidgetItem();
    item2->setText(0,QStringLiteral("子节点"));
    //关联父子节点
    item1->addChild(item2);
    //设置顶层item
    treeWidget->addTopLevelItem(item1);

    */


    QTreeWidget *treeWidget = new QTreeWidget(this);//一定要指定父对象
    treeWidget->setGeometry(10,10,300,300);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderHidden(true);
    QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
        items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
//    treeWidget->insertTopLevelItems(0, items);//全部作为一级节点

    QTreeWidgetItem *headItem = new QTreeWidgetItem();
    headItem->setText(0, "fu jie dian");
    headItem->addChildren(items); //作为二级节点
    treeWidget->addTopLevelItem(headItem);
}

TreeView::~TreeView()
{

}
