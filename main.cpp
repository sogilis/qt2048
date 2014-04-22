#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "boardmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    BoardModel board;
    engine.rootContext()->setContextProperty("board", &board);
    engine.load(QUrl(QStringLiteral("qrc:///main.qml")));

    return app.exec();
}
