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
    QStandardItemModel *tableModel = nullptr;
    QTableView *tableView = nullptr;
};

#endif // WIDGET_H
