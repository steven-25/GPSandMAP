#include "qgeomapreplygaode.h"
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QFile>
#include "gaodemapengine.h"
QGeoMapReplyGaoDe::QGeoMapReplyGaoDe(QNetworkAccessManager *networkManager, const QNetworkRequest &request, const QGeoTileSpec &spec, QObject *parent)
    : QGeoTiledMapReply(spec, parent)
    , _reply(NULL)
    , _request(request)
    , _networkManager(networkManager)
{
    if(_request.url().isEmpty())
    {
        if(!_badMapBox.size())
        {
            QFile b(":/res/notile.png");
            if(b.open(QFile::ReadOnly))
                _badMapBox = b.readAll();
        }
        setMapImageData(_badMapBox);
        setMapImageFormat("png");
        setFinished(true);
        setCached(false);
    }
    else
    {
        GaoDeFetchTileTask* task = getGaoDeMapEngine()->createFetchTileTask((UrlFactory::MapType)spec.mapId(), spec.x(), spec.y(), spec.zoom());
        connect(task, &GaoDeFetchTileTask::tileFetched, this, &QGeoMapReplyGaoDe::cacheReply);
        connect(task, &GaoDeMapTask::error, this, &QGeoMapReplyGaoDe::cacheError);
        getGaoDeMapEngine()->addTask(task);
    }
}

QGeoMapReplyGaoDe::~QGeoMapReplyGaoDe()
{
    if (_reply)
    {
        _reply->deleteLater();
        _reply = 0;
    }
}

void QGeoMapReplyGaoDe::abort()
{
    if (_reply)
        _reply->abort();
}

void QGeoMapReplyGaoDe::replyDestroyed()
{
    _reply = 0;
}

void QGeoMapReplyGaoDe::networkReplyFinished()
{
    if (!_reply)
    {
        return;
    }
    if (_reply->error() != QNetworkReply::NoError)
    {
        return;
    }
    QByteArray a = _reply->readAll();
    setMapImageData(a);
    QString format = getGaoDeMapEngine()->urlFactory()->getImageFormat((UrlFactory::MapType)tileSpec().mapId(), a);
    if(!format.isEmpty())
    {
        setMapImageFormat(format);
        getGaoDeMapEngine()->cacheTile((UrlFactory::MapType)tileSpec().mapId(), tileSpec().x(), tileSpec().y(), tileSpec().zoom(), a, format);
    }
    setFinished(true);
    _reply->deleteLater();
    _reply = 0;
}

void QGeoMapReplyGaoDe::networkReplyError(QNetworkReply::NetworkError error)
{
    if (!_reply)
    {
        return;
    }
    if (error != QNetworkReply::OperationCanceledError)
    {
        qWarning() << "Fetch tile error:" << _reply->errorString();
    }
    _reply->deleteLater();
    _reply = 0;
    if(!_badTile.size())
    {
        QFile b(":/res/notile.png");
        if(b.open(QFile::ReadOnly))
            _badTile = b.readAll();
    }
    setMapImageData(_badTile);
    setMapImageFormat("png");
    setFinished(true);
    setCached(false);
}

void QGeoMapReplyGaoDe::cacheReply(GaoDeCacheTile *tile)
{
    setMapImageData(tile->img());
    setMapImageFormat(tile->format());
    setFinished(true);
    setCached(true);
    tile->deleteLater();
}

void QGeoMapReplyGaoDe::cacheError(GaoDeMapTask::TaskType type, QString /*errorString*/)
{
    if(type != GaoDeMapTask::taskFetchTile)
    {
        qWarning() << "QGeoMapReplyGaoDe::cacheError() for wrong task";
    }
    _reply = _networkManager->get(_request);
    _reply->setParent(0);
    connect(_reply, SIGNAL(finished()),                         this, SLOT(networkReplyFinished()));
    connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
    connect(_reply, SIGNAL(destroyed()),                        this, SLOT(replyDestroyed()));
}
