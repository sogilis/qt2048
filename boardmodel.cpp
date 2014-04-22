#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent) :
    QAbstractListModel(parent)
{
}

int BoardModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)

    return kSize * kSize;
}

QVariant BoardModel::data(const QModelIndex &index, int role) const {
    t_index x, y;
    if (index.row() < 0 || index.row() >= kSize * kSize) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        x = index.row() % kSize;
        y = index.row() / kSize;
        QString str = QString::number(board_.get(x, y));
        return str;
    }
    return QVariant();
}
