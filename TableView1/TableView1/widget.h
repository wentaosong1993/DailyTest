#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTableView>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void clickSlots(QModelIndex curIndex);
    void showToolTip(const QModelIndex &index);
//    void horizontalHeaderShowToolTip(int &loginIndex);

private:
    QTableView *m_tableView = nullptr;
};

#endif // WIDGET_H
