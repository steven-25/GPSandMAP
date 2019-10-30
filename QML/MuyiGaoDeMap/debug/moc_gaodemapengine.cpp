/****************************************************************************
** Meta object code from reading C++ file 'gaodemapengine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MuyiMapLocationPlugin/gaodemapengine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gaodemapengine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GaoDeMapEngine_t {
    QByteArrayData data[9];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeMapEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeMapEngine_t qt_meta_stringdata_GaoDeMapEngine = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GaoDeMapEngine"
QT_MOC_LITERAL(1, 15, 12), // "updateTotals"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 10), // "totaltiles"
QT_MOC_LITERAL(4, 40, 9), // "totalsize"
QT_MOC_LITERAL(5, 50, 12), // "defaulttiles"
QT_MOC_LITERAL(6, 63, 11), // "defaultsize"
QT_MOC_LITERAL(7, 75, 13), // "_updateTotals"
QT_MOC_LITERAL(8, 89, 7) // "_pruned"

    },
    "GaoDeMapEngine\0updateTotals\0\0totaltiles\0"
    "totalsize\0defaulttiles\0defaultsize\0"
    "_updateTotals\0_pruned"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeMapEngine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    4,   38,    2, 0x08 /* Private */,
       8,    0,   47,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::ULongLong, QMetaType::UInt, QMetaType::ULongLong,    3,    4,    5,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::ULongLong, QMetaType::UInt, QMetaType::ULongLong,    3,    4,    5,    6,
    QMetaType::Void,

       0        // eod
};

void GaoDeMapEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeMapEngine *_t = static_cast<GaoDeMapEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateTotals((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint64(*)>(_a[4]))); break;
        case 1: _t->_updateTotals((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint64(*)>(_a[2])),(*reinterpret_cast< quint32(*)>(_a[3])),(*reinterpret_cast< quint64(*)>(_a[4]))); break;
        case 2: _t->_pruned(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeMapEngine::*_t)(quint32 , quint64 , quint32 , quint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeMapEngine::updateTotals)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeMapEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GaoDeMapEngine.data,
      qt_meta_data_GaoDeMapEngine,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeMapEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeMapEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeMapEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GaoDeMapEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GaoDeMapEngine::updateTotals(quint32 _t1, quint64 _t2, quint32 _t3, quint64 _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
