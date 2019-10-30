#ifndef QGEOMAPREPLYGAODE_H
#define QGEOMAPREPLYGAODE_H

#include <QtNetwork/QNetworkReply>
#include <QtLocation/private/qgeotiledmapreply_p.h>
#include "gaodemapenginedata.h"

class QGeoMapReplyGaoDe : public QGeoTiledMapReply
{
    Q_OBJECT
public:
     QGeoMapReplyGaoDe(QNetworkAccessManager*  networkManager, const QNetworkRequest& request, const QGeoTileSpec &spec, QObject *parent = 0);
    ~QGeoMapReplyGaoDe();
    void abort();

private slots:
    void replyDestroyed         ();
    void networkReplyFinished   ();
    void networkReplyError      (QNetworkReply::NetworkError error);
    void cacheReply             (GaoDeCacheTile* tile);
    void cacheError             (GaoDeMapTask::TaskType type, QString errorString);

private:
    QNetworkReply*          _reply;
    QNetworkRequest         _request;
    QNetworkAccessManager*  _networkManager;
    QByteArray              _badMapBox;
    QByteArray              _badTile;
};

#endif // QGEOMAPREPLYGAODE_H
