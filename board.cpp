#include "board.h"
#include <QTime>
#include <QTimer>

#include <iostream>
using namespace std;

Board::Board(QObject *parent) :
    QObject(parent) {
    initRand();
    initGame();
}

void Board::initGame() {
    memset(board_, 0, sizeof(board_));
    score_ = 0;
    higherTile_ = 0;
    addRandomTile();
    addRandomTile();
}

void Board::print() const {
    cout << endl;
    t_index x, y;
    for (y = 0; y < kSize; y++) {
        for (x = 0; x < kSize; x++) {
            cout << board_[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

bool Board::move(Directions direction) {
    bool success = false;

    int i;
    for(i = Up; i < direction; i++) {
        rotateToRight();
    }
    success = moveTilesUpwards();
    for(i = direction; i <= Right; i++) {
        rotateToRight();
    }
    if (success) {
        addRandomTile();
        emit boardChangedAfterMovement();
    }

    if(win() || gameEnded()) {
        emit gameStatusChanged();
        return false;
    }

    return success;
}

bool Board::moveTilesUpwards() {
    if (win() || gameEnded()) {
        return false;
    }
    bool success = false;
    t_index x;
    for (x = 0; x < kSize; x++) {
        success |= slide(board_[x]);
    }
    return success;
}

bool Board::moveUp() {
    return move(Up);
}

bool Board::moveLeft() {
    return move(Left);
}

bool Board::moveDown() {
    return move(Down);
}

bool Board::moveRight() {
    return move(Right);
}

t_value Board::get(const t_index x, const t_index y) const {
    return board_[x][y];
}

t_score Board::score() const {
    return score_;
}

void Board::initRand() {
    auto time = QTime::currentTime();
    qsrand((uint) time.msec());
}

t_value Board::nextTileValue() const {
    return ((qrand() % 10) / 9 + 1) * 2;
}

void Board::addRandomTile() {
    t_index x, y;
    t_value list[kSize * kSize][2];
    t_value len = 0;
    t_value r;

    for(x = 0; x < kSize; x++) {
        for(y = 0; y < kSize; y++) {
            if(board_[x][y] == 0) {
                list[len][0] = x;
                list[len][1] = y;
                len++;
            }
        }
    }

    if (len > 0) {
        r = qrand() % len;
        x = list[r][0];
        y = list[r][1];
        board_[x][y] = nextTileValue();
    }
}

void Board::rotateToRight() {
    t_index i, j;
    t_value tmp;
    for (i = 0; i < kSize / 2; i++) {
        for (j = i; j < kSize - i - 1; j++) {
            tmp                          = board_[i][j];
            board_[i][j]                 = board_[j][kSize-i-1];
            board_[j][kSize-i-1]         = board_[kSize-i-1][kSize-j-1];
            board_[kSize-i-1][kSize-j-1] = board_[kSize-j-1][i];
            board_[kSize-j-1][i]         = tmp;
        }
    }
}

bool Board::slide(t_value array[kSize]) {
    bool success = false;
    t_index pos, target, stop = 0;
    t_value mergeValue;

    for (pos = 0; pos < kSize; pos++) {
        if (array[pos] != 0) {
            target = findTarget(array, pos, stop);
            if (target != pos) {
                // need to move (0) or merge (!0)
                if (array[target] != 0) {
                    stop = target + 1; // don't cascade merges
                    mergeValue = array[target] + array[pos];
                    score_ += mergeValue;
                    emit scoreChanged();
                    higherTile_ = max(higherTile_, mergeValue);
                }
                array[target] += array[pos]; // merge or move (target is 0)
                array[pos] = 0;
                success = true;
            }
        }
    }

    return success;
}

t_index Board::findTarget(t_value array[kSize], const t_index pos, const t_index stop) const {
    t_index target;
    if (pos == 0) {
        return pos;
    }
    for (target = pos - 1; target >= 0; target--) {
        if (array[target] != 0) {
            if (array[target] != array[pos]) {
                // unable to merge or move
                return target + 1;
            }
            // merge is possible
            return target;
        } else {
            if (target == stop) {
                return target;
            }
        }
    }
    return pos;
}

bool Board::findPairDown() const {
    bool success = false;
    t_index x, y;
    for (x = 0; x < kSize; x++) {
        for (y = 0; y < kSize - 1; y++) {
            if (board_[x][y] == board_[x][y+1]) {
                return true;
            }
        }
    }

    return success;
}

t_value Board::countEmpty() const {
    t_index x, y;
    t_value count = 0;
    for (x = 0; x < kSize; x++) {
        for (y = 0; y < kSize; y++) {
            if (board_[x][y] == 0) {
                count++;
            }
        }
    }
    return count;
}

bool Board::gameEnded() {
    bool ended = true;
    if (countEmpty() > 0) {
        return false;
    }
    if (findPairDown()) {
        return false;
    }
    rotateToRight();
    if (findPairDown()) {
        ended = false;
    }
    rotateToRight();
    rotateToRight();
    rotateToRight();
    return ended;
}

bool Board::win() {
    return higherTile_ == kValueOfLastTile;
}
