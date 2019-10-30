#ifndef URLFACTORY_H
#define URLFACTORY_H

#include <QObject>
#include <QString>
#include <QPoint>
#include <QByteArray>
#include <QNetworkProxy>
#include <QNetworkReply>
#include <QMutex>

#define MAX_MAP_ZOOM (20.0)
class UrlFactory : public QObject
{
    Q_OBJECT
public:
     UrlFactory(QObject *parent = 0);

    enum MapType
    {
        Invalid                 = -1,
        GaoDeMap                = 1,
        GaoDeSatellite          = 4,
        MapBoxStreets           = 6000,
        MapBoxLight             = 6001,
        MapBoxDark              = 6002,
        MapBoxSatellite         = 6003,
        MapBoxHybrid            = 6004,
        MapBoxWheatPaste        = 6005,
        MapBoxStreetsBasic      = 6006,
        MapBoxComic             = 6007,
        MapBoxOutdoors          = 6008,
        MapBoxRunBikeHike       = 6009,
        MapBoxPencil            = 6010,
        MapBoxPirates           = 6011,
        MapBoxEmerald           = 6012,
        MapBoxHighContrast      = 6013
    };
    ~UrlFactory();
    QNetworkRequest getTileURL          (MapType type, int x, int y, int zoom, QNetworkAccessManager* networkManager);
    QString         getImageFormat      (MapType type, const QByteArray& image);

    static quint32  averageSizeForType  (MapType type);

private slots:
    void    _networkReplyError          (QNetworkReply::NetworkError error);
    void    _replyDestroyed             ();

private:
    QString _getURL                     (MapType type, int x, int y, int zoom, QNetworkAccessManager* networkManager);
    int     _getServerNum               (int x, int y, int max);
    QString _tileXYToQuadKey            (int tileX, int tileY, int levelOfDetail);

private:
    QNetworkReply*  _gaodeReply;
    QByteArray                 _userAgent;
};

#endif // URLFACTORY_H
