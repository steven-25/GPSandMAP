QT  += location-private positioning-private network sql quickwidgets  positioning


contains(QT_VERSION, 5.5.1) {

    message(Using Local QtLocation headers for Qt 5.5.1)

    INCLUDEPATH += \
        $$PWD/qtlocation/include \

} else {

    message(Using Default QtLocation headers)

    INCLUDEPATH += $$QT.location.includes

}

HEADERS += \
    $$PWD/qgeotilefetcherqgc.h \
    $$PWD/urlfactory.h \
    $$PWD/gaodemapengine.h \
    $$PWD/gaodemapenginedata.h \
    $$PWD/qgeomapreplygaode.h \
    $$PWD/gaodecachedtileset.h \
    $$PWD/gaodecacheworker.h \
    $$PWD/qgeoserviceproviderfactorygaode.h \
    $$PWD/qgeocodingmanagerenginegaode.h \
    $$PWD/qgeocodereplygaode.h \
    $$PWD/qgeotiledmappingmanagerenginegaode.h \
    $$PWD/qgeotilefetchergaode.h

SOURCES += \
    $$PWD/qgeotilefetcherqgc.cpp \
    $$PWD/urlfactory.cpp \
    $$PWD/gaodemapengine.cpp \
    $$PWD/qgeomapreplygaode.cpp \
    $$PWD/gaodecachedtileset.cpp \
    $$PWD/gaodecacheworker.cpp \
    $$PWD/qgeoserviceproviderfactorygaode.cpp \
    $$PWD/qgeocodingmanagerenginegaode.cpp \
    $$PWD/qgeocodereplygaode.cpp \
    $$PWD/qgeotiledmappingmanagerenginegaode.cpp \
    $$PWD/qgeotilefetchergaode.cpp

DISTFILES += \
    $$PWD/gaode_maps_plugin.json
