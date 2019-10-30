#ifndef QGEOTILEFETCHERQGC_H
#define QGEOTILEFETCHERQGC_H

#include <QtLocation/private/qgeotilefetcher_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>
class QNetworkAccessManager;
class QGeoTileFetcherQGC : public QGeoTileFetcher
{
    Q_OBJECT
public:
    explicit QGeoTileFetcherQGC(QGeoTiledMappingManagerEngine *parent = 0);
    ~QGeoTileFetcherQGC();
private:
    QGeoTiledMapReply*      getTileImage    (const QGeoTileSpec &spec);
private:
    QNetworkAccessManager*  _networkManager;
};

#endif // QGEOTILEFETCHERQGC_H
