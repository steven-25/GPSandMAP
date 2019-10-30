#include "qgeotilefetcherqgc.h"
#include <QtCore/QLocale>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include <QNetworkAccessManager>
#include "gaodemapengine.h"
#include "qgeomapreplygaode.h"
QGeoTileFetcherQGC::QGeoTileFetcherQGC(QGeoTiledMappingManagerEngine *parent) : QGeoTileFetcher(parent)
  , _networkManager(new QNetworkAccessManager(this))
{

}

QGeoTileFetcherQGC::~QGeoTileFetcherQGC()
{

}

QGeoTiledMapReply *QGeoTileFetcherQGC::getTileImage(const QGeoTileSpec &spec)
{
    //-- Build URL
    QNetworkRequest request = getGaoDeMapEngine()->urlFactory()->getTileURL((UrlFactory::MapType)spec.mapId(), spec.x(), spec.y(), spec.zoom(), _networkManager);
    return new QGeoMapReplyGaoDe(_networkManager, request, spec);
}

