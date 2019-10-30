#ifndef GAODEMAPENGINEDATA_H
#define GAODEMAPENGINEDATA_H
//#define UINT64_MAX 9223372036854775807
#include <QObject>
#include <QString>
#include <QHash>
#include <QDateTime>
#include "gaodecachedtileset.h"
class GaoDeCachedTileSet;
//-----------------------------------------------------------------------------
class GaoDeTile
{
public:
    GaoDeTile()
        : _x(0)
        , _y(0)
        , _z(0)
        , _set(UINT64_MAX)
        , _type(UrlFactory::Invalid)
    {
    }

    enum TyleState {
        StatePending = 0,
        StateDownloading,
        StateError,
        StateComplete
    };

    int                 x           () const { return _x; }
    int                 y           () const { return _y; }
    int                 z           () const { return _z; }
    qulonglong          set         () const { return _set;  }
    const QString       hash        () const { return _hash; }
    UrlFactory::MapType type        () const { return _type; }

    void                setX        (int x) { _x = x; }
    void                setY        (int y) { _y = y; }
    void                setZ        (int z) { _z = z; }
    void                setTileSet  (qulonglong set) { _set = set;  }
    void                setHash     (const QString& hash) { _hash = hash; }
    void                setType     (UrlFactory::MapType type) { _type = type; }

private:
    int         _x;
    int         _y;
    int         _z;
    qulonglong  _set;
    QString     _hash;
    UrlFactory::MapType _type;
};

//-----------------------------------------------------------------------------
class GaoDeCacheTile : public QObject
{
    Q_OBJECT
public:
    GaoDeCacheTile    (const QString hash, const QByteArray img, const QString format, UrlFactory::MapType type, qulonglong set = UINT64_MAX)
        : _set(set)
        , _hash(hash)
        , _img(img)
        , _format(format)
        , _type(type)
    {
    }
    GaoDeCacheTile    (const QString hash, qulonglong set)
        : _set(set)
        , _hash(hash)
    {
    }
    qulonglong          set     () { return _set;   }
    QString             hash    () { return _hash;  }
    QByteArray          img     () { return _img;   }
    QString             format  () { return _format;}
    UrlFactory::MapType type    () { return _type; }
private:
    qulonglong  _set;
    QString     _hash;
    QByteArray  _img;
    QString     _format;
    UrlFactory::MapType _type;
};

//-----------------------------------------------------------------------------
class GaoDeMapTask : public QObject
{
    Q_OBJECT
public:

    enum TaskType {
        taskInit,
        taskCacheTile,
        taskFetchTile,
        taskFetchTileSets,
        taskCreateTileSet,
        taskGetTileDownloadList,
        taskUpdateTileDownloadState,
        taskDeleteTileSet,
        taskPruneCache,
        taskReset
    };

    GaoDeMapTask(TaskType type)
        : _type(type)
    {}
    virtual ~GaoDeMapTask()
    {}

    virtual TaskType    type            () { return _type; }

    void setError(QString errorString)
    {
        emit error(_type, errorString);
    }

signals:
    void error          (GaoDeMapTask::TaskType type, QString errorString);

private:
    TaskType    _type;
};

//-----------------------------------------------------------------------------
class GaoDeFetchTileSetTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeFetchTileSetTask()
        : GaoDeMapTask(GaoDeMapTask::taskFetchTileSets)
    {}

    void setTileSetFetched(GaoDeCachedTileSet* tileSet)
    {
        emit tileSetFetched(tileSet);
    }

signals:
    void            tileSetFetched  (GaoDeCachedTileSet* tileSet);
};

//-----------------------------------------------------------------------------
class GaoDeCreateTileSetTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeCreateTileSetTask(GaoDeCachedTileSet* tileSet)
        : GaoDeMapTask(GaoDeMapTask::taskCreateTileSet)
        , _tileSet(tileSet)
        , _saved(false)
    {}

    ~GaoDeCreateTileSetTask();

    GaoDeCachedTileSet*   tileSet () { return _tileSet; }

    void setTileSetSaved()
    {
        //-- Flag as saved. Signalee wll maintain it.
        _saved = true;
        emit tileSetSaved(_tileSet);
    }

signals:
    void tileSetSaved   (GaoDeCachedTileSet* tileSet);

private:
    GaoDeCachedTileSet* _tileSet;
    bool              _saved;
};

//-----------------------------------------------------------------------------
class GaoDeFetchTileTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeFetchTileTask(const QString hash)
        : GaoDeMapTask(GaoDeMapTask::taskFetchTile)
        , _hash(hash)
    {}

    ~GaoDeFetchTileTask()
    {
    }

    void setTileFetched(GaoDeCacheTile* tile)
    {
        emit tileFetched(tile);
    }

    QString         hash() { return _hash; }

signals:
    void            tileFetched     (GaoDeCacheTile* tile);

private:
    QString         _hash;
};

//-----------------------------------------------------------------------------
class GaoDeSaveTileTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeSaveTileTask(GaoDeCacheTile* tile)
        : GaoDeMapTask(GaoDeMapTask::taskCacheTile)
        , _tile(tile)
    {}

    ~GaoDeSaveTileTask()
    {
        if(_tile)
            delete _tile;
    }

    GaoDeCacheTile*   tile() { return _tile; }

private:
    GaoDeCacheTile*   _tile;
};

//-----------------------------------------------------------------------------
class GaoDeGetTileDownloadListTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeGetTileDownloadListTask(qulonglong setID, int count)
        : GaoDeMapTask(GaoDeMapTask::taskGetTileDownloadList)
        , _setID(setID)
        , _count(count)
    {}

    qulonglong  setID() { return _setID; }
    int         count() { return _count; }

    void setTileListFetched(QList<GaoDeTile*> tiles)
    {
        emit tileListFetched(tiles);
    }

signals:
    void            tileListFetched  (QList<GaoDeTile*> tiles);

private:
    qulonglong  _setID;
    int         _count;
};

//-----------------------------------------------------------------------------
class GaoDeUpdateTileDownloadStateTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeUpdateTileDownloadStateTask(qulonglong setID, GaoDeTile::TyleState state, const QString& hash)
        : GaoDeMapTask(GaoDeMapTask::taskUpdateTileDownloadState)
        , _setID(setID)
        , _state(state)
        , _hash(hash)
    {}

    QString             hash    () { return _hash; }
    qulonglong          setID   () { return _setID; }
    GaoDeTile::TyleState  state   () { return _state; }

private:
    qulonglong          _setID;
    GaoDeTile::TyleState  _state;
    QString             _hash;
};

//-----------------------------------------------------------------------------
class GaoDeDeleteTileSetTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeDeleteTileSetTask(qulonglong setID)
        : GaoDeMapTask(GaoDeMapTask::taskDeleteTileSet)
        , _setID(setID)
    {}

    qulonglong  setID() { return _setID; }

    void setTileSetDeleted()
    {
        emit tileSetDeleted(_setID);
    }

signals:
    void tileSetDeleted(qulonglong setID);

private:
    qulonglong  _setID;
};

//-----------------------------------------------------------------------------
class GaoDePruneCacheTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDePruneCacheTask(quint64 amount)
        : GaoDeMapTask(GaoDeMapTask::taskPruneCache)
        , _amount(amount)
    {}

    quint64  amount() { return _amount; }

    void setPruned()
    {
        emit pruned();
    }

signals:
    void pruned();

private:
    quint64  _amount;
};

//-----------------------------------------------------------------------------
class GaoDeResetTask : public GaoDeMapTask
{
    Q_OBJECT
public:
    GaoDeResetTask()
        : GaoDeMapTask(GaoDeMapTask::taskReset)
    {}

    void setResetCompleted()
    {
        emit resetCompleted();
    }

signals:
    void resetCompleted();
};
#endif // GAODEMAPENGINEDATA_H

