#include "qgeoserviceproviderfactorygaode.h"

#include <QtLocation/private/qgeotiledmappingmanagerengine_p.h>
#include "qgeocodingmanagerenginegaode.h"
#include "qgeotiledmappingmanagerenginegaode.h"
Q_EXTERN_C Q_DECL_EXPORT const char *qt_plugin_query_metadata();
Q_EXTERN_C Q_DECL_EXPORT QT_PREPEND_NAMESPACE(QObject) *qt_plugin_instance();

//-----------------------------------------------------------------------------
const QT_PREPEND_NAMESPACE(QStaticPlugin) qt_static_plugin_QGeoServiceProviderFactoryGaoDe()
{
    QT_PREPEND_NAMESPACE(QStaticPlugin) plugin = { qt_plugin_instance, qt_plugin_query_metadata};
    return plugin;
}
QGeoCodingManagerEngine *QGeoServiceProviderFactoryGaoDe::createGeocodingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return new QGeoCodingManagerEngineGaoDe(parameters, error, errorString);
}

QGeoMappingManagerEngine *QGeoServiceProviderFactoryGaoDe::createMappingManagerEngine(const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const
{
    return new QGeoTiledMappingManagerEngineGaoDe(parameters, error, errorString);
}

QGeoRoutingManagerEngine *QGeoServiceProviderFactoryGaoDe::createRoutingManagerEngine(const QVariantMap &, QGeoServiceProvider::Error *, QString *) const
{
    return NULL;
}

QPlaceManagerEngine *QGeoServiceProviderFactoryGaoDe::createPlaceManagerEngine(const QVariantMap &, QGeoServiceProvider::Error *, QString *) const
{
    return NULL;
}
