#include "boardmodel.h"

BoardModel::BoardModel(QObject *parent) :
    QAbstractListModel(parent)
{
    connect(&board_, &Board::boardChangedAfterMovement, this, &BoardModel::onDataChanged);
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

void BoardModel::moveUp() {
    board_.moveUp();
}

void BoardModel::moveRight() {
    board_.moveRight();
}

void BoardModel::moveDown() {
    board_.moveDown();
}

void BoardModel::moveLeft() {
    board_.moveLeft();
}

void BoardModel::onDataChanged() {
    emit dataChanged(createIndex(0, 0), createIndex(rowCount() - 1, 0));
}
