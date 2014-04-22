#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractListModel>
#include "board.h"

class BoardModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int score READ score NOTIFY scoreChanged)
    Q_PROPERTY(bool gameEnded READ gameEnded NOTIFY gameStatusChanged)
    Q_PROPERTY(bool win READ win NOTIFY gameStatusChanged)

public:
    explicit BoardModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    Q_INVOKABLE void moveUp();
    Q_INVOKABLE void moveRight();
    Q_INVOKABLE void moveDown();
    Q_INVOKABLE void moveLeft();

    int score() const;
    bool gameEnded();
    bool win();

signals:
    void scoreChanged();
    void gameStatusChanged();


public slots:
    void onDataChanged();

private:
    Board board_;

};

#endif // BOARDMODEL_H
