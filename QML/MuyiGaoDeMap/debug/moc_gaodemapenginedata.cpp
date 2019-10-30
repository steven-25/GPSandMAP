/****************************************************************************
** Meta object code from reading C++ file 'gaodemapenginedata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MuyiMapLocationPlugin/gaodemapenginedata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gaodemapenginedata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GaoDeCacheTile_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeCacheTile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeCacheTile_t qt_meta_stringdata_GaoDeCacheTile = {
    {
QT_MOC_LITERAL(0, 0, 14) // "GaoDeCacheTile"

    },
    "GaoDeCacheTile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeCacheTile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GaoDeCacheTile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GaoDeCacheTile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GaoDeCacheTile.data,
      qt_meta_data_GaoDeCacheTile,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeCacheTile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeCacheTile::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeCacheTile.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GaoDeCacheTile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GaoDeMapTask_t {
    QByteArrayData data[6];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeMapTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeMapTask_t qt_meta_stringdata_GaoDeMapTask = {
    {
QT_MOC_LITERAL(0, 0, 12), // "GaoDeMapTask"
QT_MOC_LITERAL(1, 13, 5), // "error"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 22), // "GaoDeMapTask::TaskType"
QT_MOC_LITERAL(4, 43, 4), // "type"
QT_MOC_LITERAL(5, 48, 11) // "errorString"

    },
    "GaoDeMapTask\0error\0\0GaoDeMapTask::TaskType\0"
    "type\0errorString"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeMapTask[] = {

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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    4,    5,

       0        // eod
};

void GaoDeMapTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeMapTask *_t = static_cast<GaoDeMapTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->error((*reinterpret_cast< GaoDeMapTask::TaskType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeMapTask::*_t)(GaoDeMapTask::TaskType , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeMapTask::error)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeMapTask::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_GaoDeMapTask.data,
      qt_meta_data_GaoDeMapTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeMapTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeMapTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeMapTask.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int GaoDeMapTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void GaoDeMapTask::error(GaoDeMapTask::TaskType _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDeFetchTileSetTask_t {
    QByteArrayData data[5];
    char stringdata0[66];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeFetchTileSetTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeFetchTileSetTask_t qt_meta_stringdata_GaoDeFetchTileSetTask = {
    {
QT_MOC_LITERAL(0, 0, 21), // "GaoDeFetchTileSetTask"
QT_MOC_LITERAL(1, 22, 14), // "tileSetFetched"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 19), // "GaoDeCachedTileSet*"
QT_MOC_LITERAL(4, 58, 7) // "tileSet"

    },
    "GaoDeFetchTileSetTask\0tileSetFetched\0"
    "\0GaoDeCachedTileSet*\0tileSet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeFetchTileSetTask[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void GaoDeFetchTileSetTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeFetchTileSetTask *_t = static_cast<GaoDeFetchTileSetTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileSetFetched((*reinterpret_cast< GaoDeCachedTileSet*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GaoDeCachedTileSet* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeFetchTileSetTask::*_t)(GaoDeCachedTileSet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeFetchTileSetTask::tileSetFetched)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeFetchTileSetTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeFetchTileSetTask.data,
      qt_meta_data_GaoDeFetchTileSetTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeFetchTileSetTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeFetchTileSetTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeFetchTileSetTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeFetchTileSetTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GaoDeFetchTileSetTask::tileSetFetched(GaoDeCachedTileSet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDeCreateTileSetTask_t {
    QByteArrayData data[5];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeCreateTileSetTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeCreateTileSetTask_t qt_meta_stringdata_GaoDeCreateTileSetTask = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GaoDeCreateTileSetTask"
QT_MOC_LITERAL(1, 23, 12), // "tileSetSaved"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 19), // "GaoDeCachedTileSet*"
QT_MOC_LITERAL(4, 57, 7) // "tileSet"

    },
    "GaoDeCreateTileSetTask\0tileSetSaved\0"
    "\0GaoDeCachedTileSet*\0tileSet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeCreateTileSetTask[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void GaoDeCreateTileSetTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeCreateTileSetTask *_t = static_cast<GaoDeCreateTileSetTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileSetSaved((*reinterpret_cast< GaoDeCachedTileSet*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GaoDeCachedTileSet* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeCreateTileSetTask::*_t)(GaoDeCachedTileSet * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeCreateTileSetTask::tileSetSaved)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeCreateTileSetTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeCreateTileSetTask.data,
      qt_meta_data_GaoDeCreateTileSetTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeCreateTileSetTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeCreateTileSetTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeCreateTileSetTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeCreateTileSetTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GaoDeCreateTileSetTask::tileSetSaved(GaoDeCachedTileSet * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDeFetchTileTask_t {
    QByteArrayData data[5];
    char stringdata0[53];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeFetchTileTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeFetchTileTask_t qt_meta_stringdata_GaoDeFetchTileTask = {
    {
QT_MOC_LITERAL(0, 0, 18), // "GaoDeFetchTileTask"
QT_MOC_LITERAL(1, 19, 11), // "tileFetched"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 15), // "GaoDeCacheTile*"
QT_MOC_LITERAL(4, 48, 4) // "tile"

    },
    "GaoDeFetchTileTask\0tileFetched\0\0"
    "GaoDeCacheTile*\0tile"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeFetchTileTask[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void GaoDeFetchTileTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeFetchTileTask *_t = static_cast<GaoDeFetchTileTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileFetched((*reinterpret_cast< GaoDeCacheTile*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< GaoDeCacheTile* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeFetchTileTask::*_t)(GaoDeCacheTile * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeFetchTileTask::tileFetched)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeFetchTileTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeFetchTileTask.data,
      qt_meta_data_GaoDeFetchTileTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeFetchTileTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeFetchTileTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeFetchTileTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeFetchTileTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void GaoDeFetchTileTask::tileFetched(GaoDeCacheTile * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDeSaveTileTask_t {
    QByteArrayData data[1];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeSaveTileTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeSaveTileTask_t qt_meta_stringdata_GaoDeSaveTileTask = {
    {
QT_MOC_LITERAL(0, 0, 17) // "GaoDeSaveTileTask"

    },
    "GaoDeSaveTileTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeSaveTileTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GaoDeSaveTileTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GaoDeSaveTileTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeSaveTileTask.data,
      qt_meta_data_GaoDeSaveTileTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeSaveTileTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeSaveTileTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeSaveTileTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeSaveTileTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GaoDeGetTileDownloadListTask_t {
    QByteArrayData data[5];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeGetTileDownloadListTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeGetTileDownloadListTask_t qt_meta_stringdata_GaoDeGetTileDownloadListTask = {
    {
QT_MOC_LITERAL(0, 0, 28), // "GaoDeGetTileDownloadListTask"
QT_MOC_LITERAL(1, 29, 15), // "tileListFetched"
QT_MOC_LITERAL(2, 45, 0), // ""
QT_MOC_LITERAL(3, 46, 17), // "QList<GaoDeTile*>"
QT_MOC_LITERAL(4, 64, 5) // "tiles"

    },
    "GaoDeGetTileDownloadListTask\0"
    "tileListFetched\0\0QList<GaoDeTile*>\0"
    "tiles"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeGetTileDownloadListTask[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void GaoDeGetTileDownloadListTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeGetTileDownloadListTask *_t = static_cast<GaoDeGetTileDownloadListTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileListFetched((*reinterpret_cast< QList<GaoDeTile*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeGetTileDownloadListTask::*_t)(QList<GaoDeTile*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeGetTileDownloadListTask::tileListFetched)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeGetTileDownloadListTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeGetTileDownloadListTask.data,
      qt_meta_data_GaoDeGetTileDownloadListTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeGetTileDownloadListTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeGetTileDownloadListTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeGetTileDownloadListTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeGetTileDownloadListTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
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
void GaoDeGetTileDownloadListTask::tileListFetched(QList<GaoDeTile*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask_t {
    QByteArrayData data[1];
    char stringdata0[33];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask_t qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask = {
    {
QT_MOC_LITERAL(0, 0, 32) // "GaoDeUpdateTileDownloadStateTask"

    },
    "GaoDeUpdateTileDownloadStateTask"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeUpdateTileDownloadStateTask[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void GaoDeUpdateTileDownloadStateTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GaoDeUpdateTileDownloadStateTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask.data,
      qt_meta_data_GaoDeUpdateTileDownloadStateTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeUpdateTileDownloadStateTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeUpdateTileDownloadStateTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeUpdateTileDownloadStateTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeUpdateTileDownloadStateTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_GaoDeDeleteTileSetTask_t {
    QByteArrayData data[4];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeDeleteTileSetTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeDeleteTileSetTask_t qt_meta_stringdata_GaoDeDeleteTileSetTask = {
    {
QT_MOC_LITERAL(0, 0, 22), // "GaoDeDeleteTileSetTask"
QT_MOC_LITERAL(1, 23, 14), // "tileSetDeleted"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 5) // "setID"

    },
    "GaoDeDeleteTileSetTask\0tileSetDeleted\0"
    "\0setID"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeDeleteTileSetTask[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::ULongLong,    3,

       0        // eod
};

void GaoDeDeleteTileSetTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeDeleteTileSetTask *_t = static_cast<GaoDeDeleteTileSetTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tileSetDeleted((*reinterpret_cast< qulonglong(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeDeleteTileSetTask::*_t)(qulonglong );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeDeleteTileSetTask::tileSetDeleted)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject GaoDeDeleteTileSetTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeDeleteTileSetTask.data,
      qt_meta_data_GaoDeDeleteTileSetTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeDeleteTileSetTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeDeleteTileSetTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeDeleteTileSetTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeDeleteTileSetTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
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
void GaoDeDeleteTileSetTask::tileSetDeleted(qulonglong _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GaoDePruneCacheTask_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDePruneCacheTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDePruneCacheTask_t qt_meta_stringdata_GaoDePruneCacheTask = {
    {
QT_MOC_LITERAL(0, 0, 19), // "GaoDePruneCacheTask"
QT_MOC_LITERAL(1, 20, 6), // "pruned"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "GaoDePruneCacheTask\0pruned\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDePruneCacheTask[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GaoDePruneCacheTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDePruneCacheTask *_t = static_cast<GaoDePruneCacheTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pruned(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDePruneCacheTask::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDePruneCacheTask::pruned)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GaoDePruneCacheTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDePruneCacheTask.data,
      qt_meta_data_GaoDePruneCacheTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDePruneCacheTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDePruneCacheTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDePruneCacheTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDePruneCacheTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
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
void GaoDePruneCacheTask::pruned()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_GaoDeResetTask_t {
    QByteArrayData data[3];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GaoDeResetTask_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GaoDeResetTask_t qt_meta_stringdata_GaoDeResetTask = {
    {
QT_MOC_LITERAL(0, 0, 14), // "GaoDeResetTask"
QT_MOC_LITERAL(1, 15, 14), // "resetCompleted"
QT_MOC_LITERAL(2, 30, 0) // ""

    },
    "GaoDeResetTask\0resetCompleted\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GaoDeResetTask[] = {

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
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void GaoDeResetTask::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        GaoDeResetTask *_t = static_cast<GaoDeResetTask *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resetCompleted(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (GaoDeResetTask::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&GaoDeResetTask::resetCompleted)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GaoDeResetTask::staticMetaObject = {
    { &GaoDeMapTask::staticMetaObject, qt_meta_stringdata_GaoDeResetTask.data,
      qt_meta_data_GaoDeResetTask,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *GaoDeResetTask::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GaoDeResetTask::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GaoDeResetTask.stringdata0))
        return static_cast<void*>(this);
    return GaoDeMapTask::qt_metacast(_clname);
}

int GaoDeResetTask::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GaoDeMapTask::qt_metacall(_c, _id, _a);
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
void GaoDeResetTask::resetCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
