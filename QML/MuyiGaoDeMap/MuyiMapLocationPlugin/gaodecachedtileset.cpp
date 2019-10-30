#include "gaodecachedtileset.h"
#include "gaodemapengine.h"
#include "gaodemapenginedata.h"
#include <QSettings>
#include <math.h>
#include <QLoggingCategory>


#define TILE_BATCH_SIZE      256
GaoDeCachedTileSet::GaoDeCachedTileSet(const QString &name, const QString &description)
    : _name(name)
    , _description(description)
    , _topleftLat(0.0)
    , _topleftLon(0.0)
    , _bottomRightLat(0.0)
    , _bottomRightLon(0.0)
    , _numTiles(0)
    , _tilesSize(0)
    , _savedTiles(0)
    , _savedSize(0)
    , _minZoom(3)
    , _maxZoom(3)
    , _defaultSet(false)
    , _deleting(false)
    , _downloading(false)
    , _id(0)
    , _type(UrlFactory::Invalid)
    , _networkManager(NULL)
    , _errorCount(0)
    , _noMoreTiles(false)
    , _batchRequested(false)
{

}

GaoDeCachedTileSet::~GaoDeCachedTileSet()
{
    if(_networkManager) {
        delete _networkManager;
    }
}

void GaoDeCachedTileSet::createDownloadTask()
{
    if(!_downloading)
    {
        _errorCount   = 0;
        _downloading  = true;
        _noMoreTiles  = false;
        emit downloadingChanged();
        emit errorCountChanged();
    }
    GaoDeGetTileDownloadListTask* task = new GaoDeGetTileDownloadListTask(_id, TILE_BATCH_SIZE);
    connect(task, &GaoDeGetTileDownloadListTask::tileListFetched, this, &GaoDeCachedTileSet::_tileListFetched);
    getGaoDeMapEngine()->addTask(task);
    emit numTilesChanged();
    emit tilesSizeChanged();
    _batchRequested = true;
}

void GaoDeCachedTileSet::resumeDownloadTask()
{
    //-- Reset and download error flag (for all tiles)
    GaoDeUpdateTileDownloadStateTask* task = new GaoDeUpdateTileDownloadStateTask(_id, GaoDeTile::StatePending, "*");
    getGaoDeMapEngine()->addTask(task);
    //-- Start download
    createDownloadTask();
}

void GaoDeCachedTileSet::cancelDownloadTask()
{
    if(_downloading)
    {
        _downloading = false;
        emit downloadingChanged();
    }
}

QString GaoDeCachedTileSet::numTilesStr()
{
    return GaoDeMapEngine::numberToString(_numTiles);
}

QString GaoDeCachedTileSet::tilesSizeStr()
{
    return GaoDeMapEngine::bigSizeToString(_tilesSize);
}

QString GaoDeCachedTileSet::savedTilesStr()
{
    return GaoDeMapEngine::numberToString(_savedTiles);
}

QString GaoDeCachedTileSet::savedSizeStr()
{
    return GaoDeMapEngine::bigSizeToString(_savedSize);
}

QString GaoDeCachedTileSet::downloadStatus()
{
    if(_defaultSet)
    {
        return tilesSizeStr();
    }
    if(_numTiles == _savedTiles)
    {
        return savedSizeStr();
    }
    else
    {
        return savedSizeStr() + " / " + tilesSizeStr();
    }
}

QString GaoDeCachedTileSet::errorCountStr()
{
    return GaoDeMapEngine::numberToString(_errorCount);
}

void GaoDeCachedTileSet::_tileListFetched(QList<GaoDeTile *> tiles)
{
    _batchRequested = false;

    if(tiles.size() < TILE_BATCH_SIZE)
    {
        _noMoreTiles = true;
    }
    if(!tiles.size())
    {
        return;
    }

    if (!_networkManager)
    {
        _networkManager = new QNetworkAccessManager(this);
    }
    _tilesToDownload += tiles;
    _prepareDownload();
}

void GaoDeCachedTileSet::_networkReplyFinished()
{
    //-- Figure out which reply this is
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());
    if(!reply)
    {
        qWarning() << "GaoDeCachedTileSet::networkReplyFinished() NULL Reply";
        return;
    }
    //-- Get tile hash
    const QString hash = reply->request().attribute(QNetworkRequest::User).toString();
    if(!hash.isEmpty())
    {
        if(_replies.contains(hash))
        {
            _replies.remove(hash);
        }
        else
        {
            qWarning() << "GaoDeCachedTileSet::networkReplyFinished() Reply not in list: " << hash;
        }
        if (reply->error() != QNetworkReply::NoError)
        {
            qWarning() << "GaoDeCachedTileSet::networkReplyFinished() Error:" << reply->errorString();
            return;
        }
        QByteArray image = reply->readAll();
        UrlFactory::MapType type = getGaoDeMapEngine()->hashToType(hash);
        QString format = getGaoDeMapEngine()->urlFactory()->getImageFormat(type, image);
        if(!format.isEmpty())
        {
            //-- Cache tile
            getGaoDeMapEngine()->cacheTile(type, hash, image, format, _id);
            GaoDeUpdateTileDownloadStateTask* task = new GaoDeUpdateTileDownloadStateTask(_id, GaoDeTile::StateComplete, hash);
            getGaoDeMapEngine()->addTask(task);
            //-- Updated cached (downloaded) data
            _savedSize += image.size();
            _savedTiles++;
            emit savedSizeChanged();
            emit savedTilesChanged();
            //-- Update estimate
            if(_savedTiles % 10 == 0)
            {
                quint32 avg = _savedSize / _savedTiles;
                _tilesSize = avg * _numTiles;
                emit tilesSizeChanged();
            }
        }
        //-- Setup a new download
        _prepareDownload();
    }
    else
    {
        qWarning() << "GaoDeCachedTileSet::networkReplyFinished() Empty Hash";
    }
    reply->deleteLater();
}

void GaoDeCachedTileSet::_networkReplyError(QNetworkReply::NetworkError error)
{
    //-- Figure out which reply this is
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(QObject::sender());
    if (!reply)
    {
        return;
    }
    //-- Upodate error count
    _errorCount++;
    emit errorCountChanged();
    //-- Get tile hash
    QString hash = reply->request().attribute(QNetworkRequest::User).toString();

    if(!hash.isEmpty())
    {
        if(_replies.contains(hash))
        {
            _replies.remove(hash);
        }
        else
        {
            qWarning() << "GaoDeCachedTileSet::networkReplyError() Reply not in list: " << hash;
        }
        if (error != QNetworkReply::OperationCanceledError)
        {
            qWarning() << "GaoDeCachedTileSet::networkReplyError() Error:" << reply->errorString();
        }
        GaoDeUpdateTileDownloadStateTask* task = new GaoDeUpdateTileDownloadStateTask(_id, GaoDeTile::StateError, hash);
        getGaoDeMapEngine()->addTask(task);
    }
    else
    {
        qWarning() << "GaoDeCachedTileSet::networkReplyError() Empty Hash";
    }
    _prepareDownload();
    reply->deleteLater();
}

void GaoDeCachedTileSet::_prepareDownload()
{
    if(!_tilesToDownload.count())
    {
        //-- Are we done?
        if(_noMoreTiles)
        {
            if(!_errorCount)
            {
                _numTiles  = _savedTiles;
                _tilesSize = _savedSize;
            }
            emit numTilesChanged();
            emit tilesSizeChanged();
            emit savedSizeChanged();
            emit savedTilesChanged();
            _downloading = false;
            emit downloadingChanged();
            emit completeChanged();
        }
        else
        {
            if(!_batchRequested)
                createDownloadTask();
        }
        return;
    }
    //-- Prepare queue (QNetworkAccessManager has a limit for concurrent downloads)
    for(int i = _replies.count(); i < GaoDeMapEngine::concurrentDownloads(_type); i++)
    {
        if(_tilesToDownload.count())
        {
            GaoDeTile* tile = _tilesToDownload.first();
            _tilesToDownload.removeFirst();
            QNetworkRequest request = getGaoDeMapEngine()->urlFactory()->getTileURL(tile->type(), tile->x(), tile->y(), tile->z(), _networkManager);
            request.setAttribute(QNetworkRequest::User, tile->hash());
            QNetworkReply* reply = _networkManager->get(request);
            reply->setParent(0);
            connect(reply, &QNetworkReply::finished, this, &GaoDeCachedTileSet::_networkReplyFinished);
            connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), this, &GaoDeCachedTileSet::_networkReplyError);
            _replies.insert(tile->hash(), reply);
            delete tile;
            //-- Refill queue if running low
            if(!_batchRequested && !_noMoreTiles && _tilesToDownload.count() < (GaoDeMapEngine::concurrentDownloads(_type) * 10))
            {
                //-- Request new batch of tiles
                createDownloadTask();
            }
        }
    }
}
