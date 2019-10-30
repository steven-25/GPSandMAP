#ifndef QGEOCODEREPLYGAODE_H
#define QGEOCODEREPLYGAODE_H

#include <QObject>
#include <QtNetwork/QNetworkReply>
#include <QtLocation/QGeoCodeReply>
class QGeoCodeReplyGaoDe : public QGeoCodeReply
{
    Q_OBJECT

public:
    explicit QGeoCodeReplyGaoDe(QNetworkReply *reply, QObject *parent = 0);
    ~QGeoCodeReplyGaoDe();

    void abort();

private Q_SLOTS:
    void networkReplyFinished();
    void networkReplyError(QNetworkReply::NetworkError error);

private:
    QNetworkReply *m_reply;
};

#endif // QGEOCODEREPLYGAODE_H
