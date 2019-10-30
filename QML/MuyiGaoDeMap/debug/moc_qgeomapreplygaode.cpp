/****************************************************************************
** Meta object code from reading C++ file 'qgeomapreplygaode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MuyiMapLocationPlugin/qgeomapreplygaode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgeomapreplygaode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGeoMapReplyGaoDe_t {
    QByteArrayData data[14];
    char stringdata0[190];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGeoMapReplyGaoDe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGeoMapReplyGaoDe_t qt_meta_stringdata_QGeoMapReplyGaoDe = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QGeoMapReplyGaoDe"
QT_MOC_LITERAL(1, 18, 14), // "replyDestroyed"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 20), // "networkReplyFinished"
QT_MOC_LITERAL(4, 55, 17), // "networkReplyError"
QT_MOC_LITERAL(5, 73, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(6, 101, 5), // "error"
QT_MOC_LITERAL(7, 107, 10), // "cacheReply"
QT_MOC_LITERAL(8, 118, 15), // "GaoDeCacheTile*"
QT_MOC_LITERAL(9, 134, 4), // "tile"
QT_MOC_LITERAL(10, 139, 10), // "cacheError"
QT_MOC_LITERAL(11, 150, 22), // "GaoDeMapTask::TaskType"
QT_MOC_LITERAL(12, 173, 4), // "type"
QT_MOC_LITERAL(13, 178, 11) // "errorString"

    },
    "QGeoMapReplyGaoDe\0replyDestroyed\0\0"
    "networkReplyFinished\0networkReplyError\0"
    "QNetworkReply::NetworkError\0error\0"
    "cacheReply\0GaoDeCacheTile*\0tile\0"
    "cacheError\0GaoDeMapTask::TaskType\0"
    "type\0errorString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGeoMapReplyGaoDe[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x08 /* Private */,
       7,    1,   44,    2, 0x08 /* Private */,
      10,    2,   47,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11, QMetaType::QString,   12,   13,

       0        // eod
};

void QGeoMapReplyGaoDe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGeoMapReplyGaoDe *_t = static_cast<QGeoMapReplyGaoDe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->replyDestroyed(); break;
        case 1: _t->networkReplyFinished(); break;
        case 2: _t->networkReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        case 3: _t->cacheReply((*reinterpret_cast< GaoDeCacheTile*(*)>(_a[1]))); break;
        case 4: _t->cacheError((*reinterpret_cast< GaoDeMapTask::TaskType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GaoDeCacheTile* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGeoMapReplyGaoDe::staticMetaObject = {
    { &QGeoTiledMapReply::staticMetaObject, qt_meta_stringdata_QGeoMapReplyGaoDe.data,
      qt_meta_data_QGeoMapReplyGaoDe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QGeoMapReplyGaoDe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGeoMapReplyGaoDe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGeoMapReplyGaoDe.stringdata0))
        return static_cast<void*>(this);
    return QGeoTiledMapReply::qt_metacast(_clname);
}

int QGeoMapReplyGaoDe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGeoTiledMapReply::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
