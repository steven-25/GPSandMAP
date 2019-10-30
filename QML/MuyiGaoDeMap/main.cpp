#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QtCore/qplugin.h>
#include "MuyiMapLocationPlugin/gaodemapengine.h"
Q_IMPORT_PLUGIN(QGeoServiceProviderFactoryGaoDe)
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

