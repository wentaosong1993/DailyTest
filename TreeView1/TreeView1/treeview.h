#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <QWidget>

class TreeView : public QWidget
{
    Q_OBJECT

public:
    TreeView(QWidget *parent = 0);
    ~TreeView();
};

#endif // TREEVIEW_H
