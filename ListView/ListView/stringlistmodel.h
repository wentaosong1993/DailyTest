#ifndef STRINGLISTMODEL_H
#define STRINGLISTMODEL_H

#include <QAbstractListModel>

class StringListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    ///
    /// \构造函数 StringListModel
    /// \param strings
    /// \param parent
    ///
    StringListModel(const QStringList &strings,QObject *parent = Q_NULLPTR)
        :QAbstractListModel(parent),stringList(strings){}

    /// \获取行数 rowCount
    /// \param parent
    /// \return
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    /// 获取数据方法 data
    /// \param index
    /// \param role
    /// \return
    QVariant data(const QModelIndex &index, int role) const;


    /// 获取标题数据方法 headerData
    /// \param section
    /// \param orientation
    /// \param role
    /// \return
    QVariant headerData(int section, Qt::Orientation orientation,
                             int role = Qt::DisplayRole) const;

    /// \数据可编辑标志方法 flags
    /// \param index
    /// \return
    Qt::ItemFlags flags(const QModelIndex &index) const;

    /// \编辑数据的方法 setData
    /// \param index
    /// \param value
    /// \param role
    /// \return
    bool setData(const QModelIndex &index, const QVariant &value,
                     int role = Qt::EditRole);

    /// \插入行方法 insertRows
    /// \param position
    /// \param rows
    /// \param index
    /// \return
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());

    /// \删除行方法 removeRows
    /// \param position
    /// \param rows
    /// \param index
    /// \return
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());


private:
    QStringList stringList;
};

#endif // STRINGLISTMODEL_H
