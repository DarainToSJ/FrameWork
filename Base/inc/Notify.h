#ifndef _NOTIFY_H_
#define _NOTIFY_H_
#include "Base_Export_Dll.h"
#include <QMap>
#include <memory>
#include <QList>
#include <QReadWriteLock>
typedef void (*notify_func)(int event, void *data, void *content);

class BASEDLLEXPORT Notify
{

public:
    enum NotifyType
    {
        MAINWINDOW_NOTIFY = 0,
    };

    static void ExecNotify(NotifyType, int event, void *data);

    static void AddNotify(NotifyType, notify_func func, void *content);

    static void DelNotify(notify_func, void *content);

    static void ClearNotify();

private:
    static QMap<NotifyType, QList<std::pair<notify_func, void *>>> s_notifys;
    static QReadWriteLock s_lock;
};

#endif //