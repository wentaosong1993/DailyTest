#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "examplemodel.h"

class QTableView;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void exampleTableViewClicked(QModelIndex);
    void exampleTableViewDoubleClicked(QModelIndex);
    void ShowMouseRightButton(const QPoint);
private:
    ExampleModel *example_model = nullptr;
    QTableView *exampleTableView = nullptr;
};

#endif // WIDGET_H
