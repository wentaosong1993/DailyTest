#ifndef SPINDELEGATE_H
#define SPINDELEGATE_H

#include <QItemDelegate>

class QSpinBox;
class QComboBox;

class SpinDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    SpinDelegate(QObject *parent = Q_NULLPTR);

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;


    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
public:
//    QSpinBox* box = nullptr;
//    QComboBox* genderBox = nullptr;
};

#endif // SPINDELEGATE_H
