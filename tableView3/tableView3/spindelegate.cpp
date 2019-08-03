#include "spindelegate.h"
#include <QSpinBox>
#include <QComboBox>
#include <QPainter>

SpinDelegate::SpinDelegate(QObject *parent)
{
}

QWidget *SpinDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if(index.column() == 1) // 返回下拉框
    {
       QSpinBox *box = new QSpinBox(parent);
       box->setMinimum(0);
       box->setMaximum(100);
       return box;
    }

    if(index.column() == 2) //下拉框
    {
       QComboBox *genderBox = new QComboBox(parent);
       QStringList genderList;
       genderList << QStringLiteral("男") << QStringLiteral("女");
       genderBox->addItems(genderList);
       return genderBox;
    }

    return QItemDelegate::createEditor(parent, option, index);
}

void SpinDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    painter->save();
    painter->setRenderHint(QPainter::TextAntialiasing, true);
    painter->setPen(Qt::SolidLine);
    if (option.state & QStyle::State_MouseOver)
    {
        painter->setBrush(option.palette.color(QPalette::Highlight));
    }
    else if(option.state & QStyle::State_On)
    {
        painter->setBrush(option.palette.color(QPalette::Highlight));
    }
    else
    {
        QItemDelegate::paint(painter, option, index);
    }
    painter->restore();
}
