#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>
#include <QComboBox>

class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    ExampleModel(QObject *parent = 0);
    ~ExampleModel();
    int rowCount(const QModelIndex &parent) const;

    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool setData(const QModelIndex &index, const QVariant &value, int role);

    QVariant headerData( int section, Qt::Orientation orientation, int role ) const;

    void setHorizontalHeaderLabels(QStringList headerList);//设置表头
    void setVerticalHeaderLabels(QStringList headerList); //设置表头

private:
    int colNumberWithCheckBox_; //有QCheckBox的列，为0 表示第0列
    QStringList colHeaderList_;  //表头
    QStringList rowHeaderList_; //表头
    QComboBox *genderBox = nullptr;
};

#endif // EXAMPLEMODEL_H
