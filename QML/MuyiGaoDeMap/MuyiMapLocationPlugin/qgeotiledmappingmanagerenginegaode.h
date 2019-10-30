#ifndef QGEOTILEDMAPPINGMANAGERENGINEGAODE_H
#define QGEOTILEDMAPPINGMANAGERENGINEGAODE_H

#include <QtLocation/QGeoServiceProvider>

#include <QtLocation/private/qgeotiledmap_p.h>

#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>

class QGeoTiledMapGaoDe : public QGeoTiledMap
{
    Q_OBJECT
public:
    QGeoTiledMapGaoDe(QGeoTiledMappingManagerEngine *engine, QObject *parent = 0);
};

class QGeoTiledMappingManagerEngineGaoDe : public QGeoTiledMappingManagerEngine
{
    Q_OBJECT
public:
    QGeoTiledMappingManagerEngineGaoDe(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString);
    ~QGeoTiledMappingManagerEngineGaoDe();

    QGeoMap *createMap();
    QString customCopyright() const;

private:

    QString m_customCopyright;
    void _setCache(const QVariantMap &parameters);

};

#endif // QGEOTILEDMAPPINGMANAGERENGINEGAODE_H
