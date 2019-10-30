#include "qgeocodingmanagerenginegaode.h"
#include <QtCore/QVariantMap>
#include <QtCore/QUrl>
#include <QtCore/QUrlQuery>
#include <QtCore/QLocale>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtPositioning/QGeoCoordinate>
#include <QtPositioning/QGeoAddress>
#include <QtPositioning/QGeoShape>
#include <QtPositioning/QGeoRectangle>
#include <QNetworkReply>
#include "qgeocodereplygaode.h"
static QString addressToQuery(const QGeoAddress &address)
{
    return address.street()     + QStringLiteral(", ") +
           address.district()   + QStringLiteral(", ") +
           address.city()       + QStringLiteral(", ") +
           address.state()      + QStringLiteral(", ") +
           address.country();
}

static QString boundingBoxToLtrb(const QGeoRectangle &rect)
{
    return QString::number(rect.topLeft().longitude())      + QLatin1Char(',') +
           QString::number(rect.topLeft().latitude())       + QLatin1Char(',') +
           QString::number(rect.bottomRight().longitude())  + QLatin1Char(',') +
           QString::number(rect.bottomRight().latitude());
}
QGeoCodingManagerEngineGaoDe::QGeoCodingManagerEngineGaoDe(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString)
    : QGeoCodingManagerEngine(parameters), m_networkManager(new QNetworkAccessManager(this))
{
    if (parameters.contains(QStringLiteral("useragent")))
        m_userAgent = parameters.value(QStringLiteral("useragent")).toString().toLatin1();
    else
        m_userAgent = "Qt Location based application";
    *error = QGeoServiceProvider::NoError;
    errorString->clear();
}

QGeoCodingManagerEngineGaoDe::~QGeoCodingManagerEngineGaoDe()
{

}

QGeoCodeReply *QGeoCodingManagerEngineGaoDe::geocode(const QGeoAddress &address, const QGeoShape &bounds)
{
    return geocode(addressToQuery(address), -1, -1, bounds);
}

QGeoCodeReply *QGeoCodingManagerEngineGaoDe::geocode(const QString &address, int limit, int offset, const QGeoShape &bounds)
{
    Q_UNUSED(limit);
    Q_UNUSED(offset);

    QNetworkRequest request;
    request.setRawHeader("User-Agent", m_userAgent);// //"http://restapi.amap.com/v3/geocode/geo?parameters"

    QUrl url(QStringLiteral("http://restapi.amap.com/v3/geocode/geo?parameters"));//"http://maps.googleapis.com/maps/api/geocode/json"
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("sensor"), QStringLiteral("false"));
    query.addQueryItem(QStringLiteral("language"), locale().name().left(2));
    query.addQueryItem(QStringLiteral("address"), address);
    if (bounds.type() == QGeoShape::RectangleType)
    {
        query.addQueryItem(QStringLiteral("bounds"), boundingBoxToLtrb(bounds));
    }

    url.setQuery(query);
    request.setUrl(url);
    //qDebug() << url;

    QNetworkReply *reply = m_networkManager->get(request);
    reply->setParent(0);

    QGeoCodeReplyGaoDe *geocodeReply = new QGeoCodeReplyGaoDe(reply);

    connect(geocodeReply, SIGNAL(finished()), this, SLOT(replyFinished()));
    connect(geocodeReply, SIGNAL(error(QGeoCodeReply::Error,QString)),
            this, SLOT(replyError(QGeoCodeReply::Error,QString)));

    return geocodeReply;
}

QGeoCodeReply *QGeoCodingManagerEngineGaoDe::reverseGeocode(const QGeoCoordinate &coordinate, const QGeoShape &bounds)
{
    Q_UNUSED(bounds)

    QNetworkRequest request;
    request.setRawHeader("User-Agent", m_userAgent);//

    QUrl url(QStringLiteral("http://restapi.amap.com/v3/geocode/regeo?parameters"));//"http://maps.googleapis.com/maps/api/geocode/json"
    QUrlQuery query;
    query.addQueryItem(QStringLiteral("sensor"), QStringLiteral("false"));
    query.addQueryItem(QStringLiteral("language"), locale().name().left(2));
    query.addQueryItem(QStringLiteral("latlng"), QStringLiteral("%1,%2")
                       .arg(coordinate.latitude())
                       .arg(coordinate.longitude()));

    url.setQuery(query);
    request.setUrl(url);
    //qDebug() << url;

    QNetworkReply *reply = m_networkManager->get(request);
    reply->setParent(0);

    QGeoCodeReplyGaoDe *geocodeReply = new QGeoCodeReplyGaoDe(reply);

    connect(geocodeReply, SIGNAL(finished()), this, SLOT(replyFinished()));
    connect(geocodeReply, SIGNAL(error(QGeoCodeReply::Error,QString)),
            this, SLOT(replyError(QGeoCodeReply::Error,QString)));

    return geocodeReply;
}

void QGeoCodingManagerEngineGaoDe::replyFinished()
{
    QGeoCodeReply *reply = qobject_cast<QGeoCodeReply *>(sender());
    if (reply)
        emit finished(reply);
}

void QGeoCodingManagerEngineGaoDe::replyError(QGeoCodeReply::Error errorCode, const QString &errorString)
{
    QGeoCodeReply *reply = qobject_cast<QGeoCodeReply *>(sender());
    if (reply)
        emit error(reply, errorCode, errorString);
}
