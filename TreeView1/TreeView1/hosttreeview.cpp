#include "hosttreeview.h"
#include <QHeaderView>
#include <QStylePainter>
#include <QFont>
#include <QRadioButton>

HostTreeView::HostTreeView()
{

}

void HostTreeView::paintEvent(QPaintEvent *e)
{
    if (this->model() == nullptr)
    {
        QHeaderView::paintEvent(e);
        return;
    }
    QStylePainter p(this->viewport());
    QPainter* painter = &p;

    painter->save();  // 状态保存与恢复


    QFont font(QStringLiteral("微软雅黑"));
    font.setBold(true);
    painter->setFont(font);

    painter->setPen(QPen("#ffffff"));

}


void TreeStyledItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
      if(!index.isValid())
      {
          QStyledItemDelegate::paint(painter, option, index);
          return;
      }

      if(index.column() == 0 && index.parent().isValid())   //有父对象且在第一列
      {
           QRadioButton* radioButton = new QRadioButton(this);
           index.

      }
}
