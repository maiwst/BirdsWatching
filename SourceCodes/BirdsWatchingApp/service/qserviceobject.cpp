#include "qserviceobject.h"

QServiceObject::QServiceObject(QObject *parent) : QObject(parent)
{

}

void QServiceObject::showObjectThreadID()
{
    qDebug()<<"# QServiceObject thread id = "<<QThread::currentThreadId();
}

void QServiceObject::slotOfThread()
{
    qDebug()<<" QServiceObject slot thread id = "<<QThread::currentThreadId();
    emit again();
}
