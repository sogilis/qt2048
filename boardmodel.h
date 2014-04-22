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

signals:

public slots:

private:
    Board board_;

};

#endif // BOARDMODEL_H
