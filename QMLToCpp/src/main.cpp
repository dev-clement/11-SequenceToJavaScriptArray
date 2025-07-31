#include "cppclass.hpp"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CppClass test;
    qmlRegisterType<CppClass>("com.franco.custom", 0, 1, "CppClass");
    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QMLToCpp", "Main");

    return app.exec();
}
