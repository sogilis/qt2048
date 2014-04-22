#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractListModel>
#include "board.h"

class BoardModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit BoardModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();

signals:

public slots:
    void onDataChanged();

private:
    Board board_;

};

#endif // BOARDMODEL_H
