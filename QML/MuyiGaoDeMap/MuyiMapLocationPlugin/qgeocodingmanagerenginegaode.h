#ifndef QGEOCODINGMANAGERENGINEGAODE_H
#define QGEOCODINGMANAGERENGINEGAODE_H

#include <QtLocation/QGeoServiceProvider>
#include <QtLocation/QGeoCodingManagerEngine>
#include <QtLocation/QGeoCodeReply>
#include <QGeoCoordinate>
QT_BEGIN_NAMESPACE
class QNetworkAccessManager;
class QGeoCodingManagerEngineGaoDe : public QGeoCodingManagerEngine
{
    Q_OBJECT
    public:
    QGeoCodingManagerEngineGaoDe(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString);
    ~QGeoCodingManagerEngineGaoDe();

    QGeoCodeReply* geocode          (const QGeoAddress &address, const QGeoShape &bounds) Q_DECL_OVERRIDE;
    QGeoCodeReply* geocode          (const QString &address, int limit, int offset, const QGeoShape &bounds) Q_DECL_OVERRIDE;
    QGeoCodeReply* reverseGeocode   (const QGeoCoordinate &coordinate, const QGeoShape &bounds) Q_DECL_OVERRIDE;

private Q_SLOTS:
    void replyFinished  ();
    void replyError     (QGeoCodeReply::Error errorCode, const QString &errorString);

private:
    QNetworkAccessManager *m_networkManager;
    QByteArray m_userAgent;
};
QT_END_NAMESPACE
#endif // QGEOCODINGMANAGERENGINEGAODE_H
