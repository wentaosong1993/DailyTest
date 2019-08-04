#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

private:
    QTableView *tableView1 = nullptr;
    QTableView *tableView2 = nullptr;
    QStandardItemModel *tableModel = nullptr;
};

#endif // WIDGET_H
