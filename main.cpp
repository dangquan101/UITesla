#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <Controllers/system.h>
#include <Controllers/hvachandler.h>
#include <Controllers/audiocontroler.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // System m_systemHandler;
    qmlRegisterType < System > ("System", 1, 0, "System");
    HVACHandler m_driverHVACHandler;
    HVACHandler m_passengerHAVCHandler;
    AudioControler m_audioControler;

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/TestlaInfortament/Main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * context = engine.rootContext();
    context->setContextProperty("driverHVAC", &m_driverHVACHandler);
    context->setContextProperty("passengerHVAC", &m_passengerHAVCHandler);
    context->setContextProperty("audioControler", &m_audioControler);

    return app.exec();
}
