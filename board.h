#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QStringList>

typedef int8_t t_index;
typedef uint16_t t_value;
typedef uint32_t t_score;
static const t_index kSize = 4;
static const t_value kValueOfLastTile = 2048;

class Board : public QObject {
    Q_OBJECT

public:
    explicit Board(QObject *parent = 0);

    void print() const;

    bool moveUp();
    bool moveRight();
    bool moveDown();
    bool moveLeft();

    t_value get(const t_index x, const t_index y) const;
    t_score score() const;
    bool gameEnded();
    bool win();

signals:
    void boardChangedAfterMovement();
    void scoreChanged();
    void gameStatusChanged();

public slots:

private:
    t_value board_[kSize][kSize];
    t_score score_;
    t_value higherTile_;

    enum Directions {
        Up = 0,
        Left,
        Down,
        Right
    };

    void initGame();
    void initRand();
    t_value nextTileValue() const;
    void addRandomTile();

    bool move(Directions direction);
    bool moveTilesUpwards();
    void waitAndAddTile();

    void rotateToRight();
    bool slide(t_value array[kSize]);
    t_index findTarget(t_value array[kSize], const t_index pos, const t_index stop) const;
    bool findPairDown() const;
    t_value countEmpty() const;
};

#endif // BOARD_H
