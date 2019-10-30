#include "gaodemapengine.h"
#include <math.h>
#include <QSettings>
#include <QStandardPaths>
#include <QDir>
#include <stdio.h>
#include <QList>
#include "gaodemapenginedata.h"
#include <qmath.h>
Q_DECLARE_METATYPE(GaoDeMapTask::TaskType)
Q_DECLARE_METATYPE(GaoDeTile)
Q_DECLARE_METATYPE(QList<GaoDeTile*>)
//#define M_PI		3.14159265358979323846
static const char* kDbFileName = "qgcMapCache.db";
static QLocale kLocale;

struct stQGeoTileCacheGaoDeMapTypes {
    const char* name;
    UrlFactory::MapType type;
};

//-- IMPORTANT
//   Changes here must reflect those in QGeoTiledMappingManagerEngineQGC.cpp

stQGeoTileCacheGaoDeMapTypes kMapTypes[] = {
    {"Gao De Street Map",       UrlFactory::GaoDeMap},
    {"Gao De Satellite Map",    UrlFactory::GaoDeSatellite},

};

#define NUM_MAPS (sizeof(kMapTypes) / sizeof(stQGeoTileCacheGaoDeMapTypes))

stQGeoTileCacheGaoDeMapTypes kMapBoxTypes[] = {
    {"MapBox Street Map",       UrlFactory::MapBoxStreets},
    {"MapBox Satellite Map",    UrlFactory::MapBoxSatellite},
    {"MapBox High Contrast Map",UrlFactory::MapBoxHighContrast},
    {"MapBox Light Map",        UrlFactory::MapBoxLight},
    {"MapBox Dark Map",         UrlFactory::MapBoxDark},
    {"MapBox Hybrid Map",       UrlFactory::MapBoxHybrid},
    {"MapBox Wheat Paste Map",  UrlFactory::MapBoxWheatPaste},
    {"MapBox Streets Basic Map",UrlFactory::MapBoxStreetsBasic},
    {"MapBox Comic Map",        UrlFactory::MapBoxComic},
    {"MapBox Outdoors Map",     UrlFactory::MapBoxOutdoors},
    {"MapBox Run, Byke and Hike Map",   UrlFactory::MapBoxRunBikeHike},
    {"MapBox Pencil Map",       UrlFactory::MapBoxPencil},
    {"MapBox Pirates Map",      UrlFactory::MapBoxPirates},
    {"MapBox Emerald Map",      UrlFactory::MapBoxEmerald}
};

#define NUM_MAPBOXMAPS (sizeof(kMapBoxTypes) / sizeof(stQGeoTileCacheGaoDeMapTypes))

static const char* kMapBoxTokenKey  = "MapBoxToken";
static const char* kMaxDiskCacheKey = "MaxDiskCache";
static const char* kMaxMemCacheKey  = "MaxMemoryCache";
//-----------------------------------------------------------------------------
// Singleton
static GaoDeMapEngine* kMapEngine = NULL;
GaoDeMapEngine*
getGaoDeMapEngine()
{
    if(!kMapEngine)
        kMapEngine = new GaoDeMapEngine();
    return kMapEngine;
}

//-----------------------------------------------------------------------------
void
destroyMapEngine()
{
    if(kMapEngine) {
        delete kMapEngine;
        kMapEngine = NULL;
    }
}
//-----------------------------------------------------------------------------
int Random(int low, int high)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return low + qrand() % (high - low);
}
//-----------------------------------------------------------------------------
GaoDeMapEngine::GaoDeMapEngine(QObject *parent) : QObject(parent)
  , _urlFactory(new UrlFactory())
  , _userAgent("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:31.0) Gecko/20130401 Firefox/31.0")
  , _maxDiskCache(0)
  , _maxMemCache(0)
  , _prunning(false)
{
    _userAgent = QString("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:%1.0) Gecko/%2%3%4 Firefox/%5.0.%6").arg(QString::number(Random(3,14))).arg( QString::number(Random(QDate().currentDate().year() - 4, QDate().currentDate().year())))
            .arg( (Random(0,12)), 2, 10, QLatin1Char('0')).arg( (Random(0,30)), 2, 10, QLatin1Char('0')).arg( QString::number(Random(3,14))).arg( QString::number(Random(1,10)));
    qRegisterMetaType<GaoDeMapTask::TaskType>();
    qRegisterMetaType<GaoDeTile>();
    qRegisterMetaType< QList<GaoDeTile*> >();
    connect(&_worker, &GaoDeCacheWorker::updateTotals, this, &GaoDeMapEngine::_updateTotals);
}

GaoDeMapEngine::~GaoDeMapEngine()
{
    _worker.quit();
    _worker.wait();
    if(_urlFactory)
        delete _urlFactory;
}

void GaoDeMapEngine::init()
{

    QString cacheDir = QStandardPaths::writableLocation(QStandardPaths::GenericCacheLocation) + QLatin1String("/QGCMapCache55");
    if(!QDir::root().mkpath(cacheDir))
    {
        qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
        cacheDir = QDir::homePath() + QLatin1String("/.qgcmapscache/");
        if(!QDir::root().mkpath(cacheDir))
        {
            qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
            cacheDir.clear();
        }
    }
    _cachePath = cacheDir;
    if(!_cachePath.isEmpty())
    {
        _cacheFile = kDbFileName;
        _worker.setDatabaseFile(_cachePath + "/" + _cacheFile);
        qDebug() << "Map Cache in:" << _cachePath << "/" << _cacheFile;
    }
    else
    {
        qCritical() << "Could not find suitable map cache directory.";
    }
    GaoDeMapTask* task = new GaoDeMapTask(GaoDeMapTask::taskInit);
    _worker.enqueueTask(task);
}

void GaoDeMapEngine::addTask(GaoDeMapTask *task)
{
    _worker.enqueueTask(task);
}

void GaoDeMapEngine::cacheTile(UrlFactory::MapType type, int x, int y, int z, const QByteArray &image, const QString &format, qulonglong set)
{
    QString hash = getTileHash(type, x, y, z);
    cacheTile(type, hash, image, format, set);
}

void GaoDeMapEngine::cacheTile(UrlFactory::MapType type, const QString &hash, const QByteArray &image, const QString &format, qulonglong set)
{
    GaoDeSaveTileTask* task = new GaoDeSaveTileTask(new GaoDeCacheTile(hash, image, format, type, set));
    _worker.enqueueTask(task);
}

GaoDeFetchTileTask *GaoDeMapEngine::createFetchTileTask(UrlFactory::MapType type, int x, int y, int z)
{
    QString hash = getTileHash(type, x, y, z);
    GaoDeFetchTileTask* task = new GaoDeFetchTileTask(hash);
    return task;
}

QStringList GaoDeMapEngine::getMapNameList()
{
    QStringList mapList;
    for(size_t i = 0; i < NUM_MAPS; i++)
    {
        mapList << kMapTypes[i].name;
    }
    if(!getMapBoxToken().isEmpty())
    {
        for(size_t i = 0; i < NUM_MAPBOXMAPS; i++)
        {
            mapList << kMapBoxTypes[i].name;
        }
    }
    return mapList;
}

UrlFactory::MapType GaoDeMapEngine::hashToType(const QString &hash)
{
    QString type = hash.mid(0,4);
    return (UrlFactory::MapType)type.toInt();
}

QString GaoDeMapEngine::getMapBoxToken()
{
    if(_mapBoxToken.isEmpty())
    {
        QSettings settings;
        _mapBoxToken = settings.value(kMapBoxTokenKey).toString();
    }
    return _mapBoxToken;
}

void GaoDeMapEngine::setMapBoxToken(const QString &token)
{
    QSettings settings;
    settings.setValue(kMapBoxTokenKey, token);
    _mapBoxToken = token;
}

quint32 GaoDeMapEngine::getMaxDiskCache()
{
    if(!_maxDiskCache)
    {
        QSettings settings;
        _maxDiskCache = settings.value(kMaxDiskCacheKey, 1024).toUInt();
    }
    return _maxDiskCache;
}

void GaoDeMapEngine::setMaxDiskCache(quint32 size)
{
    QSettings settings;
    settings.setValue(kMaxDiskCacheKey, size);
    _maxDiskCache = size;
}

quint32 GaoDeMapEngine::getMaxMemCache()
{
    if(!_maxMemCache)
    {
        QSettings settings;

        _maxMemCache = settings.value(kMaxMemCacheKey, 128).toUInt();

    }
    return _maxMemCache;
}

void GaoDeMapEngine::setMaxMemCache(quint32 size)
{
    QSettings settings;
    settings.setValue(kMaxMemCacheKey, size);
    _maxMemCache = size;
}

GaoDeTileSet GaoDeMapEngine::getTileCount(int zoom, double topleftLon, double topleftLat, double bottomRightLon, double bottomRightLat, UrlFactory::MapType mapType)
{
    if(zoom <  1) zoom = 1;
    if(zoom > 20) zoom = 20;
    GaoDeTileSet set;
    set.tileX0 = long2tileX(topleftLon,     zoom);
    set.tileY0 = lat2tileY(topleftLat,      zoom);
    set.tileX1 = long2tileX(bottomRightLon, zoom);
    set.tileY1 = lat2tileY(bottomRightLat,  zoom);
    set.tileCount = (quint64)((quint64)set.tileX1 - (quint64)set.tileX0 + 1) * (quint64)((quint64)set.tileY1 - (quint64)set.tileY0 + 1);
    set.tileSize  = UrlFactory::averageSizeForType(mapType) * set.tileCount;
    return set;
}

int GaoDeMapEngine::long2tileX(double lon, int z)
{
    return (int)(floor((lon + 180.0) / 360.0 * pow(2.0, z)));
}

int GaoDeMapEngine::lat2tileY(double lat, int z)
{
    return (int)(floor((1.0 - log( tan(lat * M_PI/180.0) + 1.0 / cos(lat * M_PI/180.0)) / M_PI) / 2.0 * pow(2.0, z)));
}

QString GaoDeMapEngine::getTileHash(UrlFactory::MapType type, int x, int y, int z)
{
    return QString().sprintf("%04d%08d%08d%03d", (int)type, x, y, z);
}

UrlFactory::MapType GaoDeMapEngine::getTypeFromName(const QString &name)
{
    size_t i;
    for(i = 0; i < NUM_MAPS; i++)
    {
        if(name.compare(kMapTypes[i].name, Qt::CaseInsensitive) == 0)
            return kMapTypes[i].type;
    }
    for(i = 0; i < NUM_MAPBOXMAPS; i++)
    {
        if(name.compare(kMapBoxTypes[i].name, Qt::CaseInsensitive) == 0)
            return kMapBoxTypes[i].type;
    }
    return UrlFactory::Invalid;
}

QString GaoDeMapEngine::bigSizeToString(quint64 size)
{
    if(size < 1024)
        return kLocale.toString(size);
    else if(size < 1024 * 1024)
        return kLocale.toString((double)size / 1024.0, 'f', 1) + "kB";
    else if(size < 1024 * 1024 * 1024)
        return kLocale.toString((double)size / (1024.0 * 1024.0), 'f', 1) + "MB";
    else if(size < 1024.0 * 1024.0 * 1024.0 * 1024.0)
        return kLocale.toString((double)size / (1024.0 * 1024.0 * 1024.0), 'f', 1) + "GB";
    else
        return kLocale.toString((double)size / (1024.0 * 1024.0 * 1024.0 * 1024), 'f', 1) + "TB";
}

QString GaoDeMapEngine::numberToString(quint32 number)
{
    return kLocale.toString(number);
}

int GaoDeMapEngine::concurrentDownloads(UrlFactory::MapType type)
{
    switch(type) {
    case UrlFactory::GaoDeMap:
    case UrlFactory::GaoDeSatellite:
        return 12;
    default:
        break;
    }
    return 6;
}

void GaoDeMapEngine::_updateTotals(quint32 totaltiles, quint64 totalsize, quint32 defaulttiles, quint64 defaultsize)
{
    emit updateTotals(totaltiles, totalsize, defaulttiles, defaultsize);
    quint64 maxSize = getMaxDiskCache() * 1024 * 1024;
    if(!_prunning && defaultsize > maxSize)
    {
        //-- Prune Disk Cache
        _prunning = true;
        GaoDePruneCacheTask* task = new GaoDePruneCacheTask(defaultsize - maxSize);
        connect(task, &GaoDePruneCacheTask::pruned, this, &GaoDeMapEngine::_pruned);
        getGaoDeMapEngine()->addTask(task);
    }
}

void GaoDeMapEngine::_pruned()
{
     _prunning = false;
}

//-----------------------------------------------------------------------------
GaoDeCreateTileSetTask::~GaoDeCreateTileSetTask()
{
    //-- If not sent out, delete it
    if(!_saved && _tileSet)
        delete _tileSet;
}

