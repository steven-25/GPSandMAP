/****************************************************************************
** Meta object code from reading C++ file 'gaodecacheworker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MuyiMapLocationPlugin/gaodecacheworker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gaodecacheworker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GaoDeCacheWorker_t {
    QByteArrayData data[7];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeCacheWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeCacheWorker_t qt_meta_stringdata_GaoDeCacheWorker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "GaoDeCacheWorker"
QT_MOC_LITERAL(1, 17, 12), // "updateTotals"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 10), // "totaltiles"
QT_MOC_LITERAL(4, 42, 9), // "totalsize"
QT_MOC_LITERAL(5, 52, 12), // "defaulttiles"
QT_MOC_LITERAL(6, 65, 11) // "defaultsize"

    },
    "GaoDeCacheWorker\0updateTotals\0\0"
    "totaltiles\0totalsize\0defaulttiles\0"
    "defaultsize"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeCacheWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::ULongLong, QMetaType::UInt, QMetaType::ULongLong,    3,    4,    5,    6,

       0        // eod
};

void GaoDeCacheWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeCacheWorker *_t = static_cast<GaoDeCacheWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTotals((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint64(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeCacheWorker::*_t)(quint32 , quint64 , quint32 , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeCacheWorker::updateTotals)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeCacheWorker::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_GaoDeCacheWorker.data,
      qt_meta_data_GaoDeCacheWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeCacheWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeCacheWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeCacheWorker.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int GaoDeCacheWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GaoDeCacheWorker::updateTotals(quint32 _t1, quint64 _t2, quint32 _t3, quint64 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
