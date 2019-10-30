#ifndef QGEOTILEFETCHERGAODE_H
#define QGEOTILEFETCHERGAODE_H

#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>
#include "urlfactory.h"

class QGeoTiledMappingManagerEngine;
class QNetworkAccessManager;

class QGeoTileFetcherGaoDe :public QGeoTileFetcher
{
    Q_OBJECT
public:
    explicit QGeoTileFetcherGaoDe             (QGeoTiledMappingManagerEngine *parent = 0);
    ~QGeoTileFetcherGaoDe();
private:
    QGeoTiledMapReply*      getTileImage    (const QGeoTileSpec &spec);
private:
    QNetworkAccessManager*  _networkManager;
};

#endif // QGEOTILEFETCHERGAODE_H
