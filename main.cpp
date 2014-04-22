#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "board.h"

int main(int argc, char *argv[])
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    Board board;

    board.print();
    board.moveUp();
    board.print();
    board.moveRight();
    board.print();
    board.moveUp();
    board.print();
    board.moveRight();
    board.print();

    return 0;
}
