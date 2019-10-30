#ifndef GAODECACHEWORKER_H
#define GAODECACHEWORKER_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QtSql/QSqlDatabase>
class GaoDeMapTask;
class GaoDeCachedTileSet;
class GaoDeCacheWorker : public QThread
{
    Q_OBJECT
public:
    GaoDeCacheWorker();
    ~GaoDeCacheWorker();

    void    quit            ();
    bool    enqueueTask     (GaoDeMapTask* task);
    void    setDatabaseFile (const QString& path);

protected:
    void    run             ();

private:
    void        _saveTile               (GaoDeMapTask* mtask);
    void        _getTile                (GaoDeMapTask* mtask);
    void        _getTileSets            (GaoDeMapTask* mtask);
    void        _createTileSet          (GaoDeMapTask* mtask);
    void        _getTileDownloadList    (GaoDeMapTask* mtask);

    void        _updateTileDownloadState(GaoDeMapTask* mtask);
    void        _deleteTileSet          (GaoDeMapTask* mtask);
    void        _resetCacheDatabase     (GaoDeMapTask* mtask);
    void        _pruneCache             (GaoDeMapTask* mtask);

    bool        _findTile               (const QString hash);
    bool        _findTileSetID          (const QString name, quint64& setID);
    void        _updateSetTotals        (GaoDeCachedTileSet* set);
    bool        _init                   ();
    void        _createDB               ();
    quint64     _getDefaultTileSet      ();
    void        _updateTotals           ();

signals:
    void        updateTotals            (quint32 totaltiles, quint64 totalsize, quint32 defaulttiles, quint64 defaultsize);

private:
    QQueue<GaoDeMapTask*>     _taskQueue;
    QMutex                  _mutex;
    QMutex                  _waitmutex;
    QWaitCondition          _waitc;
    QString                 _databasePath;
    QSqlDatabase*           _db;
    bool                    _valid;
    bool                    _failed;
    quint64                 _defaultSet;
    quint64                 _totalSize;
    quint32                 _totalCount;
    quint64                 _defaultSize;
    quint32                 _defaultCount;
    time_t                  _lastUpdate;
    int                     _updateTimeout;
};

#endif // GAODECACHEWORKER_H
