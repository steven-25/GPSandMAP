#include "qgeotilefetchergaode.h"
#include "gaodemapengine.h"
#include "qgeomapreplygaode.h"
QGeoTileFetcherGaoDe::QGeoTileFetcherGaoDe(QGeoTiledMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , _networkManager(new QNetworkAccessManager(this))
{

}

QGeoTileFetcherGaoDe::~QGeoTileFetcherGaoDe()
{

}

QGeoTiledMapReply *QGeoTileFetcherGaoDe::getTileImage(const QGeoTileSpec &spec)
{
    QNetworkRequest request = getGaoDeMapEngine()->urlFactory()->getTileURL((UrlFactory::MapType)spec.mapId(), spec.x(), spec.y(), spec.zoom(), _networkManager);
    return new QGeoMapReplyGaoDe(_networkManager, request, spec);
}
