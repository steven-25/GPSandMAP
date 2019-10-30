/****************************************************************************
** Meta object code from reading C++ file 'qgeocodereplygaode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MuyiMapLocationPlugin/qgeocodereplygaode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qgeocodereplygaode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QGeoCodeReplyGaoDe_t {
    QByteArrayData data[6];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QGeoCodeReplyGaoDe_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QGeoCodeReplyGaoDe_t qt_meta_stringdata_QGeoCodeReplyGaoDe = {
    {
QT_MOC_LITERAL(0, 0, 18), // "QGeoCodeReplyGaoDe"
QT_MOC_LITERAL(1, 19, 20), // "networkReplyFinished"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 17), // "networkReplyError"
QT_MOC_LITERAL(4, 59, 27), // "QNetworkReply::NetworkError"
QT_MOC_LITERAL(5, 87, 5) // "error"

    },
    "QGeoCodeReplyGaoDe\0networkReplyFinished\0"
    "\0networkReplyError\0QNetworkReply::NetworkError\0"
    "error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QGeoCodeReplyGaoDe[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x08 /* Private */,
       3,    1,   25,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void QGeoCodeReplyGaoDe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QGeoCodeReplyGaoDe *_t = static_cast<QGeoCodeReplyGaoDe *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->networkReplyFinished(); break;
        case 1: _t->networkReplyError((*reinterpret_cast< QNetworkReply::NetworkError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply::NetworkError >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QGeoCodeReplyGaoDe::staticMetaObject = {
    { &QGeoCodeReply::staticMetaObject, qt_meta_stringdata_QGeoCodeReplyGaoDe.data,
      qt_meta_data_QGeoCodeReplyGaoDe,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *QGeoCodeReplyGaoDe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QGeoCodeReplyGaoDe::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QGeoCodeReplyGaoDe.stringdata0))
        return static_cast<void*>(this);
    return QGeoCodeReply::qt_metacast(_clname);
}

int QGeoCodeReplyGaoDe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGeoCodeReply::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
