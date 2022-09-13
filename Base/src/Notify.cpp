#include "../inc/Notify.h"
#include <QReadWriteLock>
#include <QWriteLocker>
#include <algorithm>
#include <QDebug>
#include <QThread>
QMap<Notify::NotifyType, QList<std::pair<notify_func, void *>>> Notify::s_notifys;
QReadWriteLock Notify::s_lock;
void Notify::ExecNotify(NotifyType ntype, int event, void *data)
{
    // qDebug() << __FUNCTION__ << QThread::currentThreadId() << "begin";

    QList<std::pair<notify_func, void *>> funs;

    {
        QReadLocker locker(&s_lock);
        auto it = s_notifys.find(ntype);
        if (it == s_notifys.end())
        {
            //            qDebug() << __FUNCTION__ << QThread::currentThreadId()<< "end";
            return;
        }
        funs = *it;
    }

    for (auto it = funs.begin(); it != funs.end(); ++it)
    {
        if (it->first)
        {
            it->first(event, data, it->second);
        }
    }

    //    qDebug() << __FUNCTION__ << QThread::currentThreadId() << "end";
}

void Notify::AddNotify(NotifyType ntype, notify_func func, void *context)
{
    //    qDebug() << __FUNCTION__ << QThread::currentThreadId() << "begin";
    QWriteLocker locker(&s_lock);
    s_notifys[ntype].push_back(std::make_pair(func, context));
    //    qDebug() << __FUNCTION__ << QThread::currentThreadId() << "end";
}

void Notify::DelNotify(notify_func func, void *context)
{
    //    qDebug() << __FUNCTION__ << QThread::currentThreadId() << "begin";

    QWriteLocker locker(&s_lock);
    for (auto it = s_notifys.begin(); it != s_notifys.end(); ++it)
    {
        auto funcIt = std::remove_if(it.value().begin(), it.value().end(), [=](const std::pair<notify_func, void *> &p) -> bool
                                     {
			if (p.first == func && p.second == context) {
				return true;
			}
			else {
				return false;
			} });
        it.value().erase(funcIt, it.value().end());
    }

    //    qDebug() << __FUNCTION__ << QThread::currentThreadId() << "end";
}

void Notify::ClearNotify()
{
    //    qWarning() << __FUNCTION__ << QThread::currentThreadId() << "begin";
    QWriteLocker locker(&s_lock);
    s_notifys.clear();

    //    qWarning() << __FUNCTION__ << QThread::currentThreadId() << "end";
}