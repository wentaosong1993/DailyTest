#ifndef HOSTTREEVIEW_H
#define HOSTTREEVIEW_H

#include <QTreeView>
#include <QStyledItemDelegate>
#include <QWidget>

class HostTreeView : public QTreeView
{
    Q_OBJECT

public:
    HostTreeView(QWidget* parent = Q_NULLPTR)
        : QTreeView(parent) { }
    ~HostTreeView(){}
protected:
    void paintEvent(QPaintEvent *e) Q_DECL_OVERRIDE;

    void drawRow(QPainter *painter,
                         const QStyleOptionViewItem &options,
                         const QModelIndex &index) const;

};

#endif // HOSTTREEVIEW_H


class TreeStyledItemDelegate : public QStyledItemDelegate
  {
      Q_OBJECT
  public:
      explicit TreeStyledItemDelegate(QObject *parent = Q_NULLPTR)
          : QStyledItemDelegate(parent) { }
      ~TreeStyledItemDelegate() { }

  public:
      void paint(QPainter *painter,
          const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;
      QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

  protected:

  };
