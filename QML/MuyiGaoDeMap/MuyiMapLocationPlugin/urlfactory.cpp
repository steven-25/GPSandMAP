#include "urlfactory.h"
#include <QRegExp>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include <QString>
#include <QByteArray>
UrlFactory::UrlFactory(QObject *parent) : QObject(parent)
{
    _gaodeReply = NULL;
}

UrlFactory::~UrlFactory()
{
    if(_gaodeReply)
        _gaodeReply->deleteLater();
}

QNetworkRequest UrlFactory::getTileURL(UrlFactory::MapType type, int x, int y, int zoom, QNetworkAccessManager *networkManager)
{
    QNetworkRequest request;
    QString url = _getURL(type, x, y, zoom, networkManager);

    qInfo()<<url;
    if(url.isEmpty())
    {
        return request;
    }

    request.setUrl(QUrl(url));
    request.setRawHeader("Accept", "*/*");
    request.setRawHeader("User-Agent", _userAgent);

    switch (type) {
        case GaoDeMap:
        case GaoDeSatellite:
            request.setRawHeader("Referrer","http://www.amap.com/");

            break;

        default:
            break;
    }
    return request;
}

QString UrlFactory::getImageFormat(UrlFactory::MapType type, const QByteArray &image)
{
    QString format;
    if(image.size() > 2)
    {
        if((char)image[0] == (char)0xff && (char)image[1] == (char)0xd8)
        {
            format = "jpg";
        }
        else if((char)image[0] == (char)0x89 && (char)image[1] == (char)0x50)
        {
            format = "png";
        }
        else {
            switch (type) {
                case GaoDeMap:
                case GaoDeSatellite:
                    format = "png";
                    break;
                default:
                    qWarning("UrlFactory::getImageFormat() Unknown map id %d", type);
                    break;
            }
        }
    }
    return format;
}
#define AVERAGE_GAODE_STREET_MAP   4913
#define AVERAGE_GAODE_SAT_MAP      56887
#define AVERAGE_TILE_SIZE           13652
quint32 UrlFactory::averageSizeForType(UrlFactory::MapType type)
{
    switch (type) {
    case GaoDeMap:
        return AVERAGE_GAODE_STREET_MAP;

    case GaoDeSatellite:
        return AVERAGE_GAODE_SAT_MAP;

    default:
        break;
    }
    return AVERAGE_TILE_SIZE;
}

void UrlFactory::_networkReplyError(QNetworkReply::NetworkError error)
{
    qWarning() << "Could not connect to google maps. Error:" << error;
    if(_gaodeReply)
    {
        _gaodeReply->deleteLater();
        _gaodeReply = NULL;
    }
}

void UrlFactory::_replyDestroyed()
{
    _gaodeReply = NULL;
}

QString UrlFactory::_getURL(UrlFactory::MapType type, int x, int y, int zoom, QNetworkAccessManager *networkManager)
{
    switch (type) {
    case GaoDeMap:
    {
        return QString("https://webst0%4.is.autonavi.com/appmaptile?style=7&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom).arg(_getServerNum(x, y, 4) + 1);

    }
    break;
    case GaoDeSatellite:
    {
       return QString("https://webst0%4.is.autonavi.com/appmaptile?style=6&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom).arg(_getServerNum(x, y, 4) + 1);
    }
    break;

    default:
        qWarning("Unknown map id %d\n", type);
        break;
    }
    return QString::null;
}

int UrlFactory::_getServerNum(int x, int y, int max)
{
    return (x + 2 * y) % max;
}

QString UrlFactory::_tileXYToQuadKey(int tileX, int tileY, int levelOfDetail)
{
    QString quadKey;
    for (int i = levelOfDetail; i > 0; i--)
    {
        char digit = '0';
        int mask   = 1 << (i - 1);
        if ((tileX & mask) != 0)
        {
            digit++;
        }
        if ((tileY & mask) != 0)
        {
            digit++;
            digit++;
        }
        quadKey.append(digit);
    }
    return quadKey;
}



