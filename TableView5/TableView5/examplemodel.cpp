#include "examplemodel.h"
#include <QFont>
#include <QBrush>
//#include <QComboBox>

ExampleModel::ExampleModel(QObject *parent)
{
    Q_UNUSED(parent);
    genderBox = new QComboBox(0);
}

ExampleModel::~ExampleModel()
{

}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return rowHeaderList_.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return colHeaderList_.size();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    int row = index.row();
    int col = index.column();

    switch(role)
    {
        case Qt::DisplayRole:
        {
            if (col == 1)
            {
                return (index.row() + 1);
            }
            else if(col == 0)
            {
                QStringList nameList = QStringList() << "ZhangSan" << "LiSi" << "WangEr" << "XiongEr" << "GuangTouQiang";
                return nameList[index.row()];
            }
            else if(col == 2)
            {
                QStringList gender = QStringList() << "Boy" << "Girl";
                return gender[index.row()%2];
            }
            else if(col == 3)
            {
                QStringList year = QStringList() << "21" << "22" << "20" << "19" << "22";
                return year[index.row()];
            }
            else
            {
                QList<int> score;
                score.clear();
                score.append(90);
                score.append(92);
                score.append(93);
                score.append(94);
                score.append(98);
                return score[index.row()];
            }
        }
        break;
        case Qt::FontRole:
        {
            if ( col == 0) //change font only for cell(X,0)
            {
                QFont boldFont;
                boldFont.setBold(true);
                return boldFont;
            }
        }
        break;
        case Qt::ForegroundRole:
        {
            if ( col == 3) //第3列
            {
                 QBrush redForground(Qt::red);
                 return redForground;
            }
        }
        break;
        case Qt::BackgroundRole:
        if ((col == 1 ))  //change background only for cell(X,1)
        {
           QBrush blueBackground(Qt::blue);
           return blueBackground;
        }
        break;
        case Qt::DecorationRole:
        {
            if (row == 0 )
            { //设置图片
//                 return QPixmap(":images/current_pic.png");
                return QPixmap("");
            }
        }
        break;
        case Qt::TextAlignmentRole:
        {
            return Qt::AlignCenter; //字体中间对齐
        }
        break;
        case Qt::CheckStateRole:
        {
            if (col ==  colNumberWithCheckBox_)//add a checkbox to cell(row,col)
            {
                return index.data().toBool() == Qt::Checked ? Qt::Checked : Qt::Unchecked;
            }
        }
        break;
   }

    return QVariant();
}

Qt::ItemFlags ExampleModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
       return 0;

    if (index.column() == colNumberWithCheckBox_)
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsUserCheckable;
    }
//    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; //若是想编辑可返回
    return  Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool ExampleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
       return false;

    if (role == Qt::CheckStateRole && index.column() == colNumberWithCheckBox_)
    {
    }
    return true;
}

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        if(section < colHeaderList_.size())
        {
            return colHeaderList_[section];
        }
    }
    else if(orientation == Qt::Vertical && role == Qt::DisplayRole)
    {
        if(section < rowHeaderList_.size())
        {
            return rowHeaderList_[section];
        }
    }
    return QVariant();
}

void ExampleModel::setHorizontalHeaderLabels(QStringList headerList)
{
    colHeaderList_ = headerList;
}

void ExampleModel::setVerticalHeaderLabels(QStringList headerList)
{
    rowHeaderList_ = headerList;
}
