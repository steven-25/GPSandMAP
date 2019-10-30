#include "qgeotiledmappingmanagerenginegaode.h"
#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>

#include <QtLocation/private/qgeotiledmap_p.h>

#include <QDir>
#include <QStandardPaths>
#include "gaodemapengine.h"
#include "gaodemapenginedata.h"
#include "qgeotilefetchergaode.h"
QGeoTiledMapGaoDe::QGeoTiledMapGaoDe(QGeoTiledMappingManagerEngine *engine, QObject *parent)
: QGeoTiledMap(engine, parent)
{

}

QGeoTiledMappingManagerEngineGaoDe::QGeoTiledMappingManagerEngineGaoDe(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString)
:   QGeoTiledMappingManagerEngine()
{
    QGeoCameraCapabilities cameraCaps;
    cameraCaps.setMinimumZoomLevel(2.0);
    cameraCaps.setMaximumZoomLevel(MAX_MAP_ZOOM);
    cameraCaps.setSupportsBearing(true);
    setCameraCapabilities(cameraCaps);

    setTileSize(QSize(256, 256));


    QList<QGeoMapType> mapTypes;
    mapTypes << QGeoMapType(QGeoMapType::SatelliteMapDay,   "Gao de Satellite Map",     "Gao de satellite map",         false,  false,  UrlFactory::GaoDeSatellite);
    mapTypes << QGeoMapType(QGeoMapType::StreetMap,         "Gao de Street Map",        "Gao de street map",            false,  false,  UrlFactory::GaoDeMap);


    setSupportedMapTypes(mapTypes);

    //-- Users (QML code) can define a different user agent
    if (parameters.contains(QStringLiteral("useragent")))
    {
        getGaoDeMapEngine()->setUserAgent(parameters.value(QStringLiteral("useragent")).toString().toLatin1());
    }

    _setCache(parameters);


    setTileFetcher(new QGeoTileFetcherGaoDe(this));

    *error = QGeoServiceProvider::NoError;
    errorString->clear();


    if (parameters.contains(QStringLiteral("mapping.copyright")))
        m_customCopyright = parameters.value(QStringLiteral("mapping.copyright")).toString().toLatin1();

}

QGeoTiledMappingManagerEngineGaoDe::~QGeoTiledMappingManagerEngineGaoDe()
{

}

QGeoMap *QGeoTiledMappingManagerEngineGaoDe::createMap()
{
    return new QGeoTiledMapGaoDe(this);
}

QString QGeoTiledMappingManagerEngineGaoDe::customCopyright() const
{
    return m_customCopyright;
}

void QGeoTiledMappingManagerEngineGaoDe::_setCache(const QVariantMap &parameters)
{
    QString cacheDir;
    if (parameters.contains(QStringLiteral("mapping.cache.directory")))
        cacheDir = parameters.value(QStringLiteral("mapping.cache.directory")).toString();
    else {
        cacheDir = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/QGCMapCache55");
        if(!QDir::root().mkpath(cacheDir)) {
            qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
            cacheDir = QDir::homePath() + QLatin1String("/.qgcmapscache/");
        }
    }
    if(!QFileInfo(cacheDir).exists()) {
        if(!QDir::root().mkpath(cacheDir)) {
            qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
            cacheDir.clear();
        }
    }
    //-- Memory Cache
    int memLimit = 0;
    if (parameters.contains(QStringLiteral("mapping.cache.memory.size"))) {
      bool ok = false;
      memLimit = parameters.value(QStringLiteral("mapping.cache.memory.size")).toString().toUInt(&ok);
      if (!ok)
          memLimit = 0;
    }
    if(!memLimit)
    {
        //-- Value saved in MB
        memLimit = getGaoDeMapEngine()->getMaxMemCache() * (1024 * 1024);
    }
    //-- It won't work with less than 1M of memory cache
    if(memLimit < 1024 * 1024)
        memLimit = 1024 * 1024;
    //-- Disable Qt's disk cache (set memory cache otherwise Qtlocation won't work)
    QGeoFileTileCache* pTileCache = createTileCacheWithDir(cacheDir);
    if(pTileCache)
    {
        //-- We're basically telling it to use 100k of disk for cache. It doesn't like
        //   values smaller than that and I could not find a way to make it NOT cache.
        pTileCache->setMaxDiskUsage(1024 * 100);
        pTileCache->setMaxMemoryUsage(memLimit);
    }
}
